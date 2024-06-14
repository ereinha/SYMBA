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
    std::optional<decltype(func())> result;

    std::function<decltype(func())()> task = func;
    std::thread t([&cv, &result, &completed, task]() {
        result.emplace(task());
        completed = true;
        cv.notify_one();
    });

    std::unique_lock<std::mutex> l(m);
    if (!cv.wait_for(l, timeout_duration, [&completed]{ return completed; })) {
        t.detach(); // Detach if still running and timeout occurred
        throw std::runtime_error("Timeout");
    } else {
        t.join(); // Ensure the thread finishes before returning
    }

    return *result;
}

void evaluateAndPrint(Model& model, std::vector<std::string>& parts, const std::vector<Insertion>& insertions, const int& numIn, Order& order) {
    try {
        auto ampl = callWithTimeout(std::chrono::minutes(5),
                                    [&]() -> auto {
                                        return model.computeAmplitude(order, insertions);
                                    });
        if (!ampl.empty()) {
            for (size_t n = 0; n != ampl.size(); n++) {
                Expr term = ampl.expression(n);
                Evaluate(term, csl::eval::abbreviation);

                dtout << "Interaction: ";
                for (int i = 0; i < numIn; i++) {
                    dtout << " " << getParticleString(insertions[i]) << " ";
                }
                
                dtout << " to ";
                
                for (size_t j = numIn; j < parts.size(); j++) {
                    dtout << " " << getParticleString(insertions[j]) << " ";
                }
                dtout << ": " << term << " : ";

                Amplitude newAmpl = Amplitude(ampl.getOptions(), {ampl.getDiagrams()[n]}, ampl.getKinematics());
                Expr squaredAmpl = callWithTimeout(std::chrono::minutes(5),
                                                       [&]() -> Expr {
                                                            return model.computeSquaredAmplitude(newAmpl);
                                                       });
                Evaluate(squaredAmpl, csl::eval::abbreviation);
                dtout << squaredAmpl << '\n';
            }
        }
    } catch (const std::exception& e) {
        // Log the error and continue with the next combination
        dtout << "Error evaluating combination: ";
        for (int i = 0; i < numIn; i++) {
            dtout << " " << getParticleString(insertions[i]) << " ";
        }
        
        dtout << " to ";
        
        for (size_t j = numIn; j < parts.size(); j++) {
            dtout << " " << getParticleString(insertions[j]) << " ";
        }
        dtout << ": " << e.what() << '\n';
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

//        for (int i = loop_range; i < range; i++) {
//            parts[current_loop].clear();
//            parts[current_loop] = std::string(lis[i]);
//            recursive_loop(max_loops, current_loop + 1, range, model, numIn, numOut, order, parts, insertions, options, lis, i);
//        }
//
//        std::copy(original_parts.begin(), original_parts.end(), parts.begin() + current_loop);
        for (int i = loop_range; i < range; i++) {
            std::string original_part = std::move(parts[current_loop]);
            parts[current_loop] = std::string(lis[i]);
            recursive_loop(max_loops, current_loop + 1, range, model, numIn, numOut, order, parts, insertions, options, lis, i);
            parts[current_loop] = std::move(original_part);
        }
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
    Model QCD_Model;

    QCD_Model.addGaugedGroup(group::Type::SU, "C", 3, csl::constant_s("g"));
    QCD_Model.init();


    Particle u = diracfermion_s("u", QCD_Model);
    Particle d = diracfermion_s("d", QCD_Model);
    Particle s = diracfermion_s("s", QCD_Model);
    Particle t = diracfermion_s("t", QCD_Model);
    Particle c = diracfermion_s("c", QCD_Model);
    Particle b = diracfermion_s("b", QCD_Model);
    SetMass(u, "m_u");
    SetMass(d, "m_d");
    SetMass(s, "m_s");
    SetMass(t, "m_t");
    SetMass(c, "m_c");
    SetMass(b, "m_b");

    SetGroupRep(u, "C", {1, 0});
    SetGroupRep(d, "C", {1, 0});
    SetGroupRep(s, "C", {1, 0});
    SetGroupRep(t, "C", {1, 0});
    SetGroupRep(c, "C", {1, 0});
    SetGroupRep(b, "C", {1, 0});

    QCD_Model.addParticle(u);
    QCD_Model.addParticle(d);
    QCD_Model.addParticle(s);
    QCD_Model.addParticle(t);
    QCD_Model.addParticle(c);
    QCD_Model.addParticle(b);


    QCD_Model.renameParticle("A_C", "G");
    //Particle gluon = getParticle("G");

    QCD_Model.refresh();

    std::vector<std::string_view> lis ={"u", "d", "s", "t", "c" , "b" ,  "G"};

    int param1 = std::stoi(argv[1]);
    int param2 = std::stoi(argv[2]);
    Order order = parseOrder(argv[3]);

    
    com_amp(QCD_Model, "QCD", lis, 7, param1, param2, order);

    return 0;
}
