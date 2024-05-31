#include "marty.h"
#include <fstream>
#include <string_view>
#include <string>
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
    Model QED_Model;

    Expr psi = constant_s("e");
    QED_Model.addGaugedGroup(group::Type::U1, "em", psi);

    QED_Model.init();

    Particle e = diracfermion_s("e", QED_Model);
    Particle mu = diracfermion_s("mu", QED_Model);
    Particle t = diracfermion_s("t", QED_Model);
    Particle u = diracfermion_s("u", QED_Model);
    Particle d = diracfermion_s("d", QED_Model);
    Particle s = diracfermion_s("s", QED_Model);
    Particle tt = diracfermion_s("tt", QED_Model);
    Particle c = diracfermion_s("c", QED_Model);
    Particle b = diracfermion_s("b", QED_Model);



    auto m_e = constant_s("m_e");
    auto m_mu = constant_s("m_mu");
    auto m_t = constant_s("m_t");
    auto m_u = constant_s("m_u");
    auto m_d = constant_s("m_d");
    auto m_s = constant_s("m_s");
    auto m_tt = constant_s("m_tt");
    auto m_c = constant_s("m_c");
    auto m_b = constant_s("m_b");


    e->setGroupRep("em", -1);
    mu->setGroupRep("em", -1);
    t->setGroupRep("em", -1);
    u->setGroupRep("em", {2,3});
    d->setGroupRep("em", {-1,3});
    s->setGroupRep("em", {-1,3});
    tt->setGroupRep("em", {2,3});
    c->setGroupRep("em", {2,3});
    b->setGroupRep("em", {-1,3});



    e->setMass(m_e);
    mu->setMass(m_mu);
    t->setMass(m_t);
    u->setMass(m_u);
    d->setMass(m_d);
    s->setMass(m_s);
    tt->setMass(m_tt);
    c->setMass(m_c);
    b->setMass(m_b);


    QED_Model.addParticle(e);
    QED_Model.addParticle(mu);
    QED_Model.addParticle(t);
    QED_Model.addParticle(u);
    QED_Model.addParticle(d);
    QED_Model.addParticle(s);
    QED_Model.addParticle(tt);
    QED_Model.addParticle(c);
    QED_Model.addParticle(b);



    QED_Model.renameParticle("A_em", "A");

    QED_Model.refresh();

    std::vector<std::string_view> lis = {"e", "mu","t" ,"u" ,"d" ,"s" ,"tt" ,"c" ,"b", "A"};
    
    int param1 = std::stoi(argv[1]);
    int param2 = std::stoi(argv[2]);
    Order order = parseOrder(argv[3]);
    
    com_amp(QED_Model, "QED", lis, 10, param1, param2, order);

}
