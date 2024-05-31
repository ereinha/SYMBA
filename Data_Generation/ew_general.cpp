#include "marty.h"
#include <fstream>
#include <string_view>
#include <vector>
#include <sstream>
#include <exception>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
using namespace csl;
using namespace mty;
using namespace std::chrono;

std::ofstream dtout;

string getParticleString(const Insertion& insertion) {
    string particle_string;
    
    if (insertion.isOnShell()) {
        if (insertion.isParticle()) {
            particle_string = "";
        } else {
            particle_string = "AntiPart ";
        }
    } else {
        if (insertion.isParticle()) {
            particle_string = "OffShell ";
        } else {
            particle_string = "AntiPart OffShell ";
        }
    }
    
    particle_string += toString(GetExpression(insertion));
    return particle_string;
}

template<typename Func>
auto callWithTimeout(std::chrono::minutes timeout_duration, Func func) -> decltype(func()) {
    std::mutex m;
    std::condition_variable cv;
    bool completed = false;
    decltype(func()) result;

    std::thread t([&cv, &result, &completed, func]() {
        result = func();
        completed = true;
        cv.notify_one();
    });

    {
        std::unique_lock<std::mutex> l(m);
        if (!cv.wait_for(l, timeout_duration, [&completed]{ return completed; })) {
            t.detach(); // Detach if still running and timeout occurred
            throw std::runtime_error("Timeout");
        } else {
            t.join(); // Ensure the thread finishes before returning
        }
    }

    return result;
}

void evaluateAndPrint(Model& model, std::vector<std::string>& parts, const std::vector<Insertion>& insertions, const int& numIn, Order& order) {
    try {
        Amplitude ampl = callWithTimeout(std::chrono::minutes(5),
                                    [&]() -> Amplitude {
                                        return model.computeAmplitude(order, insertions);
                                    });
        if (!ampl.empty()) {
            for (size_t n = 0; n != ampl.size(); n++) {
                Expr term = ampl.expression(n);
                Evaluate(term, csl::eval::abbreviation);

                std::cout << "Interaction: ";
                for (int i = 0; i < numIn; i++) {
                    std::cout << " " << getParticleString(insertions[i]) << " ";
                }
                
                std::cout << " to ";
                
                for (size_t j = numIn; j < parts.size(); j++) {
                    std::cout << " " << getParticleString(insertions[j]) << " ";
                }
                std::cout << ": " << term << " : ";

                Amplitude newAmpl = Amplitude(ampl.getOptions(), {ampl.getDiagrams()[n]}, ampl.getKinematics())
                Expr squaredAmpl = callWithTimeout(std::chrono::minutes(5),
                                                       [&]() -> Expr {
                                                            return model.computeSquaredAmplitude(newAmpl);
                                                       });
                Evaluate(squaredAmpl, csl::eval::abbreviation);
                std::cout << squaredAmpl << '\n';
            }
        }
    } catch (const std::exception& e) {
        // Log the error and continue with the next combination
        std::cout << "Error evaluating combination: ";
        for (int i = 0; i < numIn; i++) {
            std::cout << " " << getParticleString(insertions[i]) << " ";
        }
        
        std::cout << " to ";
        
        for (size_t j = numIn; j < parts.size(); j++) {
            std::cout << " " << getParticleString(insertions[j]) << " ";
        }
        std::cout << ": " << e.what() << '\n';
    }
}

void populateOptions(std::vector<Insertion>& options, const std::string& part, const bool& isIncoming) {
    options.clear(); // Clear the vector to avoid retaining previous elements
    if (isIncoming) {
        options.push_back(Incoming(part));
        options.push_back(Incoming(OffShell(part)));
        options.push_back(Incoming(AntiPart(part)));
        options.push_back(Incoming(AntiPart(OffShell(part))));
    } else {
        options.push_back(Outgoing(part));
        options.push_back(Outgoing(OffShell(part)));
        options.push_back(Outgoing(AntiPart(part)));
        options.push_back(Outgoing(AntiPart(OffShell(part))));
    }
}

void generateCombinations(Model& model, std::vector<std::string>& parts, std::vector<Insertion>& insertions, std::vector<Insertion>& options, const int& index, const int& numIn, const int& numOut, Order& order) {
    if (index == numIn + numOut) {
        evaluateAndPrint(model, parts, insertions, numIn, order);
        return;
    }

    populateOptions(options, parts[index], index < numIn);

    for (const auto& option : options) {
        insertions[index] = option;
        generateCombinations(model, parts, insertions, options, index + 1, numIn, numOut, order);
    }
}

int recursive_loop(const int& max_loops, const int& current_loop, const int& range, Model& model, const int& numIn, const int& numOut, Order& order, std::vector<std::string>& parts, std::vector<Insertion>& insertions, std::vector<Insertion>& options, const std::vector<std::string_view>& lis, const int& start_index = 0) {
    if (current_loop == max_loops) {
        try {
            generateCombinations(model, parts, insertions, options, 0, numIn, numOut, order);
        } catch (const std::exception& e) {
            std::cerr << "Error in main loop: " << e.what() << '\n';
        }
        return current_loop;
    } else {
        int loop_range = (current_loop == 0 || current_loop == numIn) ? 0 : start_index;
        std::vector<std::string> original_parts(parts.begin() + current_loop, parts.end());

        for (int i = loop_range; i < range; i++) {
            parts[current_loop].clear();
            parts[current_loop] = std::string(lis[i]);
            recursive_loop(max_loops, current_loop + 1, range, model, numIn, numOut, order, parts, insertions, options, lis, i);
        }

        std::copy(original_parts.begin(), original_parts.end(), parts.begin() + current_loop);
    }
    return current_loop;
}

int com_amp(Model& model, std::string type, const std::vector<std::string_view>& lis, const int& numParts, const int& numIn, const int& numOut, Order& order) {
    // Format the filename to include the number of incoming and outgoing particles
    std::stringstream filename;
    filename << type << "-" << numIn << "-to-" << numOut << ".txt";
    dtout.open(filename.str());

    std::vector<Insertion> options (4, Incoming(AntiPart(OffShell(lis[1]))));
    std::vector<Insertion> insertions(numIn + numOut, Incoming(AntiPart(OffShell(lis[1]))));
    std::vector<std::string> parts(numIn + numOut, "xyz");
    
    recursive_loop(numIn + numOut, 0, numParts, model, numIn, numOut, order, parts, insertions, options, lis);

    dtout.close();
    return 0;
}

Order parseOrder(const std::string& orderStr) {
    if (orderStr == "TreeLevel") {
        return Order::TreeLevel;
    } else if (orderStr == "OneLoop") {
        return Order::OneLoop;
    } else {
        throw std::invalid_argument("Invalid order: " + orderStr);
    }
}

int main(int argc, char *argv[]) {
    Model ElectroWeak;
    AddGaugedGroup(ElectroWeak, group::Type::SU, "SU2_L", 2, constant_s("g"));
    AddGaugedGroup(ElectroWeak, group::Type::U1, "U1_Y", constant_s("g'"));
    Init(ElectroWeak);

    Rename(ElectroWeak, "A_SU2_L", "W");
    Rename(ElectroWeak, "A_U1_Y", "B");
    Particle W       = GetParticle(ElectroWeak, "W");
    Particle B       = GetParticle(ElectroWeak, "B");
    Particle ghost_W = GetParticle(ElectroWeak, "c_W");

    Particle H = scalarboson_s("H", ElectroWeak);
    SetGroupRep(H, "SU2_L", 1);
    SetGroupRep(H, "U1_Y", {1, 2});
    AddParticle(ElectroWeak, H);

    Particle q_L = weylfermion_s("q_L", ElectroWeak, Chirality::Left);
    SetGroupRep(q_L, "SU2_L", 1);
    SetGroupRep(q_L, "U1_Y", {1, 6});
    AddParticle(ElectroWeak, q_L);

    Particle u_R = weylfermion_s("u_R", ElectroWeak, Chirality::Right);
    SetGroupRep(u_R, "U1_Y", {2, 3});
    AddParticle(ElectroWeak, u_R);

    Particle d_R = weylfermion_s("d_R", ElectroWeak, Chirality::Right);
    SetGroupRep(d_R, "U1_Y", {-1, 3});
    AddParticle(ElectroWeak, d_R);

    Particle l_L = weylfermion_s("l_L", ElectroWeak, Chirality::Left);
    SetGroupRep(l_L, "SU2_L", 1);
    SetGroupRep(l_L, "U1_Y", {-1, 2});
    AddParticle(ElectroWeak, l_L);

    Particle e_R = weylfermion_s("e_R", ElectroWeak, Chirality::Right);
    SetGroupRep(e_R, "U1_Y", {-1, 1});
    AddParticle(ElectroWeak, e_R);

    csl::Expr    v           = constant_s("v");
    csl::Expr    mH          = constant_s("m_h");
    csl::Expr    Yu          = sqrt_s(2) * constant_s("m_u") / v;
    csl::Expr    Yd          = sqrt_s(2) * constant_s("m_d") / v;
    csl::Expr    Ye          = sqrt_s(2) * constant_s("m_e") / v;
    Tensor       X           = MinkowskiVector("X");
    Index        alpha       = DiracIndex();
    Index        i           = GaugeIndex(ElectroWeak, "SU2_L", H);
    Index        j           = GaugeIndex(ElectroWeak, "SU2_L", H);
    const Space *SU2_F_space = VectorSpace(ElectroWeak, "SU2_L", H);
    Tensor       eps         = Epsilon(SU2_F_space);

    csl::Expr H_squared = GetComplexConjugate(H(i, X)) * H(i, X);
    csl::Expr HiggsPotential
        = -pow_s(mH, 2) / (2 * pow_s(v, 2)) * pow_s(H_squared - v * v / 2, 2);

    AddTerm(ElectroWeak, HiggsPotential);
    AddTerm(ElectroWeak,
            -Yu * eps({i, j}) * GetComplexConjugate(H(j, X))
                * GetComplexConjugate(q_L({i, alpha}, X)) * u_R(alpha, X),
            true);
    AddTerm(ElectroWeak,
            -Yd * H(i, X) * GetComplexConjugate(q_L({i, alpha}, X))
                * d_R(alpha, X),
            true);
    AddTerm(ElectroWeak,
            -Ye * H(i, X) * GetComplexConjugate(l_L({i, alpha}, X))
                * e_R(alpha, X),
            true);

    ///////////////////////////////////////////////////
    // SU(2)_L symmetry breaking
    ///////////////////////////////////////////////////

    BreakGaugeSymmetry(ElectroWeak,
                       "SU2_L",
                       {H, W, q_L, l_L, ghost_W},
                       {{"H0", "H1"},
                        {"W1", "W2", "W3"},
                        {"u_L", "d_L"},
                        {"nue_L", "e_L"},
                        {"c_W1", "c_W2", "c_W3"}});

    ///////////////////////////////////////////////////
    // Replacements to get SM particles W +-
    ///////////////////////////////////////////////////

    Particle W1   = GetParticle(ElectroWeak, "W1");
    Particle W2   = GetParticle(ElectroWeak, "W2");
    Particle W_SM = GenerateSimilarParticle("W", W1);
    SetSelfConjugate(W_SM, false);

    Index     mu    = MinkowskiIndex();
    Index     nu    = MinkowskiIndex();
    csl::Expr W_p   = W_SM(+mu, X);
    csl::Expr W_m   = GetComplexConjugate(W_SM(+mu, X));
    csl::Expr F_W_p = W_SM({+mu, +nu}, X);
    csl::Expr F_W_m = GetComplexConjugate(W_SM({+mu, +nu}, X));

    Replaced(ElectroWeak, W1, (W_p + W_m) / sqrt_s(2));
    Replaced(ElectroWeak, W2, CSL_I * (W_p - W_m) / sqrt_s(2));
    Replaced(ElectroWeak, GetFieldStrength(W1), (F_W_p + F_W_m) / sqrt_s(2));
    Replaced(ElectroWeak,
             GetFieldStrength(W2),
             CSL_I * (F_W_p - F_W_m) / sqrt_s(2));

    ///////////////////////////////////////////////////
    // Actual gauge (spontaneous) symmetry breaking
    ///////////////////////////////////////////////////

    Particle H0 = GetParticle(ElectroWeak, "H0");
    Particle H1 = GetParticle(ElectroWeak, "H1");

    Particle h = scalarboson_s("h", ElectroWeak);
    SetSelfConjugate(h, true);

    Replaced(ElectroWeak, H0, CSL_0);
    Replaced(ElectroWeak, H1, (h(X) + v) / sqrt_s(2));

    // std::cout << ElectroWeak << std::endl;

    ///////////////////////////////////////////////////
    // Gather masses of all particles,
    // get standard conventions for A and Z
    ///////////////////////////////////////////////////

    DiagonalizeMassMatrices(ElectroWeak);

    Rename(ElectroWeak, "B", "A");
    Rename(ElectroWeak, "W3", "Z");

    csl::Expr e      = constant_s("e");
    csl::Expr thetaW = constant_s("theta_W");
    csl::Expr g      = GetCoupling(ElectroWeak, "g");
    csl::Expr g_p    = GetCoupling(ElectroWeak, "g'");
    Replaced(ElectroWeak, pow_s(g, 2) + pow_s(g_p, 2), pow_s(g * g_p / e, 2));
    Replaced(ElectroWeak, g, e / sin_s(thetaW));
    Replaced(ElectroWeak, g_p, e / cos_s(thetaW));

    // std::cout << ElectroWeak << std::endl;
    // std::cout << "Computing feynman rules ... " << std::endl;
    // auto rules = ComputeFeynmanRules(ElectroWeak);
    // Display(rules);
    // // ExportPNG("EW_rules", rules);
    //
    // std::cout << ElectroWeak << std::endl;


    W          = W_SM;
    Particle Z = GetParticle(ElectroWeak, "Z");

    std::vector<std::string_view> lis = {"u_R","u_L", "d_L", "d_R", "e_R", "e_L", "nue_L", "W", "h", "A", "Z", "e", "u", "d"};

    int param1 = std::stoi(argv[1]);
    int param2 = std::stoi(argv[2]);
    Order order = parseOrder(argv[3]);
    
    com_amp(ElectroWeak, "EW", lis, 14, param1, param2, order);

    return 0;
}
