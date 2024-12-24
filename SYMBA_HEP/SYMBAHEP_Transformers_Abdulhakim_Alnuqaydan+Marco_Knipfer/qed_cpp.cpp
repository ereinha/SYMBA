#include "marty.h"
#include <fstream>
using namespace std;
using namespace csl;
using namespace mty;
using namespace std::chrono;

ofstream dtout;


int com_amp(Model &model, string_view lis[], int) {

  dtout.open("QED_2to3.txt");
  for (int i=0; i<10; i++){
    for (int j=0; j<10; j++){
      for (int k=0; k<10; k++){
        for (int l=0; l<10; l++){
          for (int m=0; m<10; m++){
            
auto ampl0 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl0.empty()) {
               for (size_t n = 0; n != ampl0.size(); n++) {
                    Expr term = ampl0.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl0.getOptions(), {ampl0.getDiagrams()[n]}, ampl0.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl1 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl1.empty()) {
               for (size_t n = 0; n != ampl1.size(); n++) {
                    Expr term = ampl1.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl1.getOptions(), {ampl1.getDiagrams()[n]}, ampl1.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl2 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl2.empty()) {
               for (size_t n = 0; n != ampl2.size(); n++) {
                    Expr term = ampl2.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl2.getOptions(), {ampl2.getDiagrams()[n]}, ampl2.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl3 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl3.empty()) {
               for (size_t n = 0; n != ampl3.size(); n++) {
                    Expr term = ampl3.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl3.getOptions(), {ampl3.getDiagrams()[n]}, ampl3.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl4 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl4.empty()) {
               for (size_t n = 0; n != ampl4.size(); n++) {
                    Expr term = ampl4.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl4.getOptions(), {ampl4.getDiagrams()[n]}, ampl4.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl5 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl5.empty()) {
               for (size_t n = 0; n != ampl5.size(); n++) {
                    Expr term = ampl5.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl5.getOptions(), {ampl5.getDiagrams()[n]}, ampl5.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl6 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl6.empty()) {
               for (size_t n = 0; n != ampl6.size(); n++) {
                    Expr term = ampl6.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl6.getOptions(), {ampl6.getDiagrams()[n]}, ampl6.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl7 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl7.empty()) {
               for (size_t n = 0; n != ampl7.size(); n++) {
                    Expr term = ampl7.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl7.getOptions(), {ampl7.getDiagrams()[n]}, ampl7.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl8 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl8.empty()) {
               for (size_t n = 0; n != ampl8.size(); n++) {
                    Expr term = ampl8.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl8.getOptions(), {ampl8.getDiagrams()[n]}, ampl8.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl9 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl9.empty()) {
               for (size_t n = 0; n != ampl9.size(); n++) {
                    Expr term = ampl9.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl9.getOptions(), {ampl9.getDiagrams()[n]}, ampl9.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl10 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl10.empty()) {
               for (size_t n = 0; n != ampl10.size(); n++) {
                    Expr term = ampl10.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl10.getOptions(), {ampl10.getDiagrams()[n]}, ampl10.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl11 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl11.empty()) {
               for (size_t n = 0; n != ampl11.size(); n++) {
                    Expr term = ampl11.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl11.getOptions(), {ampl11.getDiagrams()[n]}, ampl11.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl12 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl12.empty()) {
               for (size_t n = 0; n != ampl12.size(); n++) {
                    Expr term = ampl12.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl12.getOptions(), {ampl12.getDiagrams()[n]}, ampl12.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl13 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl13.empty()) {
               for (size_t n = 0; n != ampl13.size(); n++) {
                    Expr term = ampl13.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl13.getOptions(), {ampl13.getDiagrams()[n]}, ampl13.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl14 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl14.empty()) {
               for (size_t n = 0; n != ampl14.size(); n++) {
                    Expr term = ampl14.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl14.getOptions(), {ampl14.getDiagrams()[n]}, ampl14.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl15 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl15.empty()) {
               for (size_t n = 0; n != ampl15.size(); n++) {
                    Expr term = ampl15.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl15.getOptions(), {ampl15.getDiagrams()[n]}, ampl15.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl16 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl16.empty()) {
               for (size_t n = 0; n != ampl16.size(); n++) {
                    Expr term = ampl16.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl16.getOptions(), {ampl16.getDiagrams()[n]}, ampl16.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl17 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl17.empty()) {
               for (size_t n = 0; n != ampl17.size(); n++) {
                    Expr term = ampl17.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl17.getOptions(), {ampl17.getDiagrams()[n]}, ampl17.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl18 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl18.empty()) {
               for (size_t n = 0; n != ampl18.size(); n++) {
                    Expr term = ampl18.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl18.getOptions(), {ampl18.getDiagrams()[n]}, ampl18.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl19 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(lis[j]),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl19.empty()) {
               for (size_t n = 0; n != ampl19.size(); n++) {
                    Expr term = ampl19.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<" " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl19.getOptions(), {ampl19.getDiagrams()[n]}, ampl19.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl20 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl20.empty()) {
               for (size_t n = 0; n != ampl20.size(); n++) {
                    Expr term = ampl20.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl20.getOptions(), {ampl20.getDiagrams()[n]}, ampl20.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl21 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl21.empty()) {
               for (size_t n = 0; n != ampl21.size(); n++) {
                    Expr term = ampl21.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl21.getOptions(), {ampl21.getDiagrams()[n]}, ampl21.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl22 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl22.empty()) {
               for (size_t n = 0; n != ampl22.size(); n++) {
                    Expr term = ampl22.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl22.getOptions(), {ampl22.getDiagrams()[n]}, ampl22.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl23 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl23.empty()) {
               for (size_t n = 0; n != ampl23.size(); n++) {
                    Expr term = ampl23.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl23.getOptions(), {ampl23.getDiagrams()[n]}, ampl23.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl24 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl24.empty()) {
               for (size_t n = 0; n != ampl24.size(); n++) {
                    Expr term = ampl24.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl24.getOptions(), {ampl24.getDiagrams()[n]}, ampl24.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl25 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl25.empty()) {
               for (size_t n = 0; n != ampl25.size(); n++) {
                    Expr term = ampl25.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl25.getOptions(), {ampl25.getDiagrams()[n]}, ampl25.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl26 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl26.empty()) {
               for (size_t n = 0; n != ampl26.size(); n++) {
                    Expr term = ampl26.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl26.getOptions(), {ampl26.getDiagrams()[n]}, ampl26.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl27 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl27.empty()) {
               for (size_t n = 0; n != ampl27.size(); n++) {
                    Expr term = ampl27.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl27.getOptions(), {ampl27.getDiagrams()[n]}, ampl27.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl28 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl28.empty()) {
               for (size_t n = 0; n != ampl28.size(); n++) {
                    Expr term = ampl28.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl28.getOptions(), {ampl28.getDiagrams()[n]}, ampl28.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl29 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl29.empty()) {
               for (size_t n = 0; n != ampl29.size(); n++) {
                    Expr term = ampl29.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl29.getOptions(), {ampl29.getDiagrams()[n]}, ampl29.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl30 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl30.empty()) {
               for (size_t n = 0; n != ampl30.size(); n++) {
                    Expr term = ampl30.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl30.getOptions(), {ampl30.getDiagrams()[n]}, ampl30.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl31 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl31.empty()) {
               for (size_t n = 0; n != ampl31.size(); n++) {
                    Expr term = ampl31.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl31.getOptions(), {ampl31.getDiagrams()[n]}, ampl31.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl32 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl32.empty()) {
               for (size_t n = 0; n != ampl32.size(); n++) {
                    Expr term = ampl32.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl32.getOptions(), {ampl32.getDiagrams()[n]}, ampl32.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl33 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl33.empty()) {
               for (size_t n = 0; n != ampl33.size(); n++) {
                    Expr term = ampl33.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl33.getOptions(), {ampl33.getDiagrams()[n]}, ampl33.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl34 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl34.empty()) {
               for (size_t n = 0; n != ampl34.size(); n++) {
                    Expr term = ampl34.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl34.getOptions(), {ampl34.getDiagrams()[n]}, ampl34.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl35 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl35.empty()) {
               for (size_t n = 0; n != ampl35.size(); n++) {
                    Expr term = ampl35.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl35.getOptions(), {ampl35.getDiagrams()[n]}, ampl35.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl36 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl36.empty()) {
               for (size_t n = 0; n != ampl36.size(); n++) {
                    Expr term = ampl36.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl36.getOptions(), {ampl36.getDiagrams()[n]}, ampl36.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl37 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl37.empty()) {
               for (size_t n = 0; n != ampl37.size(); n++) {
                    Expr term = ampl37.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl37.getOptions(), {ampl37.getDiagrams()[n]}, ampl37.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl38 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl38.empty()) {
               for (size_t n = 0; n != ampl38.size(); n++) {
                    Expr term = ampl38.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl38.getOptions(), {ampl38.getDiagrams()[n]}, ampl38.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl39 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl39.empty()) {
               for (size_t n = 0; n != ampl39.size(); n++) {
                    Expr term = ampl39.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl39.getOptions(), {ampl39.getDiagrams()[n]}, ampl39.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl40 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl40.empty()) {
               for (size_t n = 0; n != ampl40.size(); n++) {
                    Expr term = ampl40.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl40.getOptions(), {ampl40.getDiagrams()[n]}, ampl40.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl41 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl41.empty()) {
               for (size_t n = 0; n != ampl41.size(); n++) {
                    Expr term = ampl41.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl41.getOptions(), {ampl41.getDiagrams()[n]}, ampl41.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl42 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl42.empty()) {
               for (size_t n = 0; n != ampl42.size(); n++) {
                    Expr term = ampl42.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl42.getOptions(), {ampl42.getDiagrams()[n]}, ampl42.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl43 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl43.empty()) {
               for (size_t n = 0; n != ampl43.size(); n++) {
                    Expr term = ampl43.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl43.getOptions(), {ampl43.getDiagrams()[n]}, ampl43.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl44 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl44.empty()) {
               for (size_t n = 0; n != ampl44.size(); n++) {
                    Expr term = ampl44.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl44.getOptions(), {ampl44.getDiagrams()[n]}, ampl44.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl45 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl45.empty()) {
               for (size_t n = 0; n != ampl45.size(); n++) {
                    Expr term = ampl45.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl45.getOptions(), {ampl45.getDiagrams()[n]}, ampl45.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl46 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl46.empty()) {
               for (size_t n = 0; n != ampl46.size(); n++) {
                    Expr term = ampl46.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl46.getOptions(), {ampl46.getDiagrams()[n]}, ampl46.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl47 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl47.empty()) {
               for (size_t n = 0; n != ampl47.size(); n++) {
                    Expr term = ampl47.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl47.getOptions(), {ampl47.getDiagrams()[n]}, ampl47.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl48 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl48.empty()) {
               for (size_t n = 0; n != ampl48.size(); n++) {
                    Expr term = ampl48.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl48.getOptions(), {ampl48.getDiagrams()[n]}, ampl48.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl49 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl49.empty()) {
               for (size_t n = 0; n != ampl49.size(); n++) {
                    Expr term = ampl49.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl49.getOptions(), {ampl49.getDiagrams()[n]}, ampl49.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl50 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl50.empty()) {
               for (size_t n = 0; n != ampl50.size(); n++) {
                    Expr term = ampl50.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl50.getOptions(), {ampl50.getDiagrams()[n]}, ampl50.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl51 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl51.empty()) {
               for (size_t n = 0; n != ampl51.size(); n++) {
                    Expr term = ampl51.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl51.getOptions(), {ampl51.getDiagrams()[n]}, ampl51.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl52 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl52.empty()) {
               for (size_t n = 0; n != ampl52.size(); n++) {
                    Expr term = ampl52.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl52.getOptions(), {ampl52.getDiagrams()[n]}, ampl52.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl53 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl53.empty()) {
               for (size_t n = 0; n != ampl53.size(); n++) {
                    Expr term = ampl53.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl53.getOptions(), {ampl53.getDiagrams()[n]}, ampl53.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl54 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl54.empty()) {
               for (size_t n = 0; n != ampl54.size(); n++) {
                    Expr term = ampl54.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl54.getOptions(), {ampl54.getDiagrams()[n]}, ampl54.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl55 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl55.empty()) {
               for (size_t n = 0; n != ampl55.size(); n++) {
                    Expr term = ampl55.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl55.getOptions(), {ampl55.getDiagrams()[n]}, ampl55.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl56 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl56.empty()) {
               for (size_t n = 0; n != ampl56.size(); n++) {
                    Expr term = ampl56.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl56.getOptions(), {ampl56.getDiagrams()[n]}, ampl56.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl57 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl57.empty()) {
               for (size_t n = 0; n != ampl57.size(); n++) {
                    Expr term = ampl57.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl57.getOptions(), {ampl57.getDiagrams()[n]}, ampl57.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl58 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl58.empty()) {
               for (size_t n = 0; n != ampl58.size(); n++) {
                    Expr term = ampl58.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl58.getOptions(), {ampl58.getDiagrams()[n]}, ampl58.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl59 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl59.empty()) {
               for (size_t n = 0; n != ampl59.size(); n++) {
                    Expr term = ampl59.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl59.getOptions(), {ampl59.getDiagrams()[n]}, ampl59.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl60 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl60.empty()) {
               for (size_t n = 0; n != ampl60.size(); n++) {
                    Expr term = ampl60.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl60.getOptions(), {ampl60.getDiagrams()[n]}, ampl60.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl61 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl61.empty()) {
               for (size_t n = 0; n != ampl61.size(); n++) {
                    Expr term = ampl61.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl61.getOptions(), {ampl61.getDiagrams()[n]}, ampl61.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl62 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl62.empty()) {
               for (size_t n = 0; n != ampl62.size(); n++) {
                    Expr term = ampl62.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl62.getOptions(), {ampl62.getDiagrams()[n]}, ampl62.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl63 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl63.empty()) {
               for (size_t n = 0; n != ampl63.size(); n++) {
                    Expr term = ampl63.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl63.getOptions(), {ampl63.getDiagrams()[n]}, ampl63.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl64 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl64.empty()) {
               for (size_t n = 0; n != ampl64.size(); n++) {
                    Expr term = ampl64.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl64.getOptions(), {ampl64.getDiagrams()[n]}, ampl64.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl65 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl65.empty()) {
               for (size_t n = 0; n != ampl65.size(); n++) {
                    Expr term = ampl65.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl65.getOptions(), {ampl65.getDiagrams()[n]}, ampl65.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl66 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl66.empty()) {
               for (size_t n = 0; n != ampl66.size(); n++) {
                    Expr term = ampl66.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl66.getOptions(), {ampl66.getDiagrams()[n]}, ampl66.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl67 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl67.empty()) {
               for (size_t n = 0; n != ampl67.size(); n++) {
                    Expr term = ampl67.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl67.getOptions(), {ampl67.getDiagrams()[n]}, ampl67.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl68 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl68.empty()) {
               for (size_t n = 0; n != ampl68.size(); n++) {
                    Expr term = ampl68.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl68.getOptions(), {ampl68.getDiagrams()[n]}, ampl68.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl69 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl69.empty()) {
               for (size_t n = 0; n != ampl69.size(); n++) {
                    Expr term = ampl69.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl69.getOptions(), {ampl69.getDiagrams()[n]}, ampl69.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl70 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl70.empty()) {
               for (size_t n = 0; n != ampl70.size(); n++) {
                    Expr term = ampl70.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl70.getOptions(), {ampl70.getDiagrams()[n]}, ampl70.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl71 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl71.empty()) {
               for (size_t n = 0; n != ampl71.size(); n++) {
                    Expr term = ampl71.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl71.getOptions(), {ampl71.getDiagrams()[n]}, ampl71.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl72 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl72.empty()) {
               for (size_t n = 0; n != ampl72.size(); n++) {
                    Expr term = ampl72.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl72.getOptions(), {ampl72.getDiagrams()[n]}, ampl72.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl73 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl73.empty()) {
               for (size_t n = 0; n != ampl73.size(); n++) {
                    Expr term = ampl73.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl73.getOptions(), {ampl73.getDiagrams()[n]}, ampl73.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl74 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl74.empty()) {
               for (size_t n = 0; n != ampl74.size(); n++) {
                    Expr term = ampl74.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl74.getOptions(), {ampl74.getDiagrams()[n]}, ampl74.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl75 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl75.empty()) {
               for (size_t n = 0; n != ampl75.size(); n++) {
                    Expr term = ampl75.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl75.getOptions(), {ampl75.getDiagrams()[n]}, ampl75.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl76 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl76.empty()) {
               for (size_t n = 0; n != ampl76.size(); n++) {
                    Expr term = ampl76.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl76.getOptions(), {ampl76.getDiagrams()[n]}, ampl76.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl77 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl77.empty()) {
               for (size_t n = 0; n != ampl77.size(); n++) {
                    Expr term = ampl77.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl77.getOptions(), {ampl77.getDiagrams()[n]}, ampl77.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl78 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl78.empty()) {
               for (size_t n = 0; n != ampl78.size(); n++) {
                    Expr term = ampl78.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl78.getOptions(), {ampl78.getDiagrams()[n]}, ampl78.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl79 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(lis[i]), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl79.empty()) {
               for (size_t n = 0; n != ampl79.size(); n++) {
                    Expr term = ampl79.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << " " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl79.getOptions(), {ampl79.getDiagrams()[n]}, ampl79.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl80 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl80.empty()) {
               for (size_t n = 0; n != ampl80.size(); n++) {
                    Expr term = ampl80.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl80.getOptions(), {ampl80.getDiagrams()[n]}, ampl80.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl81 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl81.empty()) {
               for (size_t n = 0; n != ampl81.size(); n++) {
                    Expr term = ampl81.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl81.getOptions(), {ampl81.getDiagrams()[n]}, ampl81.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl82 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl82.empty()) {
               for (size_t n = 0; n != ampl82.size(); n++) {
                    Expr term = ampl82.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl82.getOptions(), {ampl82.getDiagrams()[n]}, ampl82.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl83 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl83.empty()) {
               for (size_t n = 0; n != ampl83.size(); n++) {
                    Expr term = ampl83.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl83.getOptions(), {ampl83.getDiagrams()[n]}, ampl83.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl84 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl84.empty()) {
               for (size_t n = 0; n != ampl84.size(); n++) {
                    Expr term = ampl84.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl84.getOptions(), {ampl84.getDiagrams()[n]}, ampl84.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl85 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl85.empty()) {
               for (size_t n = 0; n != ampl85.size(); n++) {
                    Expr term = ampl85.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl85.getOptions(), {ampl85.getDiagrams()[n]}, ampl85.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl86 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl86.empty()) {
               for (size_t n = 0; n != ampl86.size(); n++) {
                    Expr term = ampl86.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl86.getOptions(), {ampl86.getDiagrams()[n]}, ampl86.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl87 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl87.empty()) {
               for (size_t n = 0; n != ampl87.size(); n++) {
                    Expr term = ampl87.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl87.getOptions(), {ampl87.getDiagrams()[n]}, ampl87.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl88 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl88.empty()) {
               for (size_t n = 0; n != ampl88.size(); n++) {
                    Expr term = ampl88.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl88.getOptions(), {ampl88.getDiagrams()[n]}, ampl88.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl89 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl89.empty()) {
               for (size_t n = 0; n != ampl89.size(); n++) {
                    Expr term = ampl89.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl89.getOptions(), {ampl89.getDiagrams()[n]}, ampl89.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl90 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl90.empty()) {
               for (size_t n = 0; n != ampl90.size(); n++) {
                    Expr term = ampl90.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl90.getOptions(), {ampl90.getDiagrams()[n]}, ampl90.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl91 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl91.empty()) {
               for (size_t n = 0; n != ampl91.size(); n++) {
                    Expr term = ampl91.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl91.getOptions(), {ampl91.getDiagrams()[n]}, ampl91.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl92 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl92.empty()) {
               for (size_t n = 0; n != ampl92.size(); n++) {
                    Expr term = ampl92.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl92.getOptions(), {ampl92.getDiagrams()[n]}, ampl92.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl93 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl93.empty()) {
               for (size_t n = 0; n != ampl93.size(); n++) {
                    Expr term = ampl93.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl93.getOptions(), {ampl93.getDiagrams()[n]}, ampl93.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl94 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl94.empty()) {
               for (size_t n = 0; n != ampl94.size(); n++) {
                    Expr term = ampl94.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl94.getOptions(), {ampl94.getDiagrams()[n]}, ampl94.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl95 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl95.empty()) {
               for (size_t n = 0; n != ampl95.size(); n++) {
                    Expr term = ampl95.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl95.getOptions(), {ampl95.getDiagrams()[n]}, ampl95.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl96 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl96.empty()) {
               for (size_t n = 0; n != ampl96.size(); n++) {
                    Expr term = ampl96.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl96.getOptions(), {ampl96.getDiagrams()[n]}, ampl96.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl97 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl97.empty()) {
               for (size_t n = 0; n != ampl97.size(); n++) {
                    Expr term = ampl97.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl97.getOptions(), {ampl97.getDiagrams()[n]}, ampl97.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl98 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl98.empty()) {
               for (size_t n = 0; n != ampl98.size(); n++) {
                    Expr term = ampl98.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl98.getOptions(), {ampl98.getDiagrams()[n]}, ampl98.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl99 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(OffShell(lis[j])),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl99.empty()) {
               for (size_t n = 0; n != ampl99.size(); n++) {
                    Expr term = ampl99.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"OffShell " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl99.getOptions(), {ampl99.getDiagrams()[n]}, ampl99.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl100 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl100.empty()) {
               for (size_t n = 0; n != ampl100.size(); n++) {
                    Expr term = ampl100.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl100.getOptions(), {ampl100.getDiagrams()[n]}, ampl100.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl101 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl101.empty()) {
               for (size_t n = 0; n != ampl101.size(); n++) {
                    Expr term = ampl101.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl101.getOptions(), {ampl101.getDiagrams()[n]}, ampl101.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl102 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl102.empty()) {
               for (size_t n = 0; n != ampl102.size(); n++) {
                    Expr term = ampl102.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl102.getOptions(), {ampl102.getDiagrams()[n]}, ampl102.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl103 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl103.empty()) {
               for (size_t n = 0; n != ampl103.size(); n++) {
                    Expr term = ampl103.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl103.getOptions(), {ampl103.getDiagrams()[n]}, ampl103.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl104 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl104.empty()) {
               for (size_t n = 0; n != ampl104.size(); n++) {
                    Expr term = ampl104.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl104.getOptions(), {ampl104.getDiagrams()[n]}, ampl104.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl105 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl105.empty()) {
               for (size_t n = 0; n != ampl105.size(); n++) {
                    Expr term = ampl105.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl105.getOptions(), {ampl105.getDiagrams()[n]}, ampl105.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl106 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl106.empty()) {
               for (size_t n = 0; n != ampl106.size(); n++) {
                    Expr term = ampl106.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl106.getOptions(), {ampl106.getDiagrams()[n]}, ampl106.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl107 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl107.empty()) {
               for (size_t n = 0; n != ampl107.size(); n++) {
                    Expr term = ampl107.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl107.getOptions(), {ampl107.getDiagrams()[n]}, ampl107.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl108 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl108.empty()) {
               for (size_t n = 0; n != ampl108.size(); n++) {
                    Expr term = ampl108.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl108.getOptions(), {ampl108.getDiagrams()[n]}, ampl108.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl109 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl109.empty()) {
               for (size_t n = 0; n != ampl109.size(); n++) {
                    Expr term = ampl109.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl109.getOptions(), {ampl109.getDiagrams()[n]}, ampl109.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl110 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl110.empty()) {
               for (size_t n = 0; n != ampl110.size(); n++) {
                    Expr term = ampl110.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl110.getOptions(), {ampl110.getDiagrams()[n]}, ampl110.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl111 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl111.empty()) {
               for (size_t n = 0; n != ampl111.size(); n++) {
                    Expr term = ampl111.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl111.getOptions(), {ampl111.getDiagrams()[n]}, ampl111.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl112 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl112.empty()) {
               for (size_t n = 0; n != ampl112.size(); n++) {
                    Expr term = ampl112.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl112.getOptions(), {ampl112.getDiagrams()[n]}, ampl112.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl113 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl113.empty()) {
               for (size_t n = 0; n != ampl113.size(); n++) {
                    Expr term = ampl113.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl113.getOptions(), {ampl113.getDiagrams()[n]}, ampl113.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl114 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl114.empty()) {
               for (size_t n = 0; n != ampl114.size(); n++) {
                    Expr term = ampl114.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl114.getOptions(), {ampl114.getDiagrams()[n]}, ampl114.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl115 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl115.empty()) {
               for (size_t n = 0; n != ampl115.size(); n++) {
                    Expr term = ampl115.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl115.getOptions(), {ampl115.getDiagrams()[n]}, ampl115.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl116 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl116.empty()) {
               for (size_t n = 0; n != ampl116.size(); n++) {
                    Expr term = ampl116.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl116.getOptions(), {ampl116.getDiagrams()[n]}, ampl116.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl117 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl117.empty()) {
               for (size_t n = 0; n != ampl117.size(); n++) {
                    Expr term = ampl117.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl117.getOptions(), {ampl117.getDiagrams()[n]}, ampl117.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl118 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl118.empty()) {
               for (size_t n = 0; n != ampl118.size(); n++) {
                    Expr term = ampl118.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl118.getOptions(), {ampl118.getDiagrams()[n]}, ampl118.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl119 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl119.empty()) {
               for (size_t n = 0; n != ampl119.size(); n++) {
                    Expr term = ampl119.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl119.getOptions(), {ampl119.getDiagrams()[n]}, ampl119.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl120 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl120.empty()) {
               for (size_t n = 0; n != ampl120.size(); n++) {
                    Expr term = ampl120.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl120.getOptions(), {ampl120.getDiagrams()[n]}, ampl120.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl121 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl121.empty()) {
               for (size_t n = 0; n != ampl121.size(); n++) {
                    Expr term = ampl121.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl121.getOptions(), {ampl121.getDiagrams()[n]}, ampl121.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl122 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl122.empty()) {
               for (size_t n = 0; n != ampl122.size(); n++) {
                    Expr term = ampl122.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl122.getOptions(), {ampl122.getDiagrams()[n]}, ampl122.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl123 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl123.empty()) {
               for (size_t n = 0; n != ampl123.size(); n++) {
                    Expr term = ampl123.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl123.getOptions(), {ampl123.getDiagrams()[n]}, ampl123.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl124 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl124.empty()) {
               for (size_t n = 0; n != ampl124.size(); n++) {
                    Expr term = ampl124.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl124.getOptions(), {ampl124.getDiagrams()[n]}, ampl124.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl125 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl125.empty()) {
               for (size_t n = 0; n != ampl125.size(); n++) {
                    Expr term = ampl125.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl125.getOptions(), {ampl125.getDiagrams()[n]}, ampl125.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl126 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl126.empty()) {
               for (size_t n = 0; n != ampl126.size(); n++) {
                    Expr term = ampl126.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl126.getOptions(), {ampl126.getDiagrams()[n]}, ampl126.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl127 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl127.empty()) {
               for (size_t n = 0; n != ampl127.size(); n++) {
                    Expr term = ampl127.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl127.getOptions(), {ampl127.getDiagrams()[n]}, ampl127.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl128 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl128.empty()) {
               for (size_t n = 0; n != ampl128.size(); n++) {
                    Expr term = ampl128.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl128.getOptions(), {ampl128.getDiagrams()[n]}, ampl128.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl129 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl129.empty()) {
               for (size_t n = 0; n != ampl129.size(); n++) {
                    Expr term = ampl129.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl129.getOptions(), {ampl129.getDiagrams()[n]}, ampl129.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl130 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl130.empty()) {
               for (size_t n = 0; n != ampl130.size(); n++) {
                    Expr term = ampl130.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl130.getOptions(), {ampl130.getDiagrams()[n]}, ampl130.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl131 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl131.empty()) {
               for (size_t n = 0; n != ampl131.size(); n++) {
                    Expr term = ampl131.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl131.getOptions(), {ampl131.getDiagrams()[n]}, ampl131.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl132 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl132.empty()) {
               for (size_t n = 0; n != ampl132.size(); n++) {
                    Expr term = ampl132.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl132.getOptions(), {ampl132.getDiagrams()[n]}, ampl132.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl133 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl133.empty()) {
               for (size_t n = 0; n != ampl133.size(); n++) {
                    Expr term = ampl133.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl133.getOptions(), {ampl133.getDiagrams()[n]}, ampl133.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl134 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl134.empty()) {
               for (size_t n = 0; n != ampl134.size(); n++) {
                    Expr term = ampl134.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl134.getOptions(), {ampl134.getDiagrams()[n]}, ampl134.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl135 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl135.empty()) {
               for (size_t n = 0; n != ampl135.size(); n++) {
                    Expr term = ampl135.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl135.getOptions(), {ampl135.getDiagrams()[n]}, ampl135.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl136 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl136.empty()) {
               for (size_t n = 0; n != ampl136.size(); n++) {
                    Expr term = ampl136.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl136.getOptions(), {ampl136.getDiagrams()[n]}, ampl136.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl137 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl137.empty()) {
               for (size_t n = 0; n != ampl137.size(); n++) {
                    Expr term = ampl137.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl137.getOptions(), {ampl137.getDiagrams()[n]}, ampl137.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl138 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl138.empty()) {
               for (size_t n = 0; n != ampl138.size(); n++) {
                    Expr term = ampl138.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl138.getOptions(), {ampl138.getDiagrams()[n]}, ampl138.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl139 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(OffShell(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl139.empty()) {
               for (size_t n = 0; n != ampl139.size(); n++) {
                    Expr term = ampl139.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl139.getOptions(), {ampl139.getDiagrams()[n]}, ampl139.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl140 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl140.empty()) {
               for (size_t n = 0; n != ampl140.size(); n++) {
                    Expr term = ampl140.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl140.getOptions(), {ampl140.getDiagrams()[n]}, ampl140.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl141 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl141.empty()) {
               for (size_t n = 0; n != ampl141.size(); n++) {
                    Expr term = ampl141.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl141.getOptions(), {ampl141.getDiagrams()[n]}, ampl141.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl142 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl142.empty()) {
               for (size_t n = 0; n != ampl142.size(); n++) {
                    Expr term = ampl142.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl142.getOptions(), {ampl142.getDiagrams()[n]}, ampl142.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl143 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl143.empty()) {
               for (size_t n = 0; n != ampl143.size(); n++) {
                    Expr term = ampl143.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl143.getOptions(), {ampl143.getDiagrams()[n]}, ampl143.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl144 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl144.empty()) {
               for (size_t n = 0; n != ampl144.size(); n++) {
                    Expr term = ampl144.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl144.getOptions(), {ampl144.getDiagrams()[n]}, ampl144.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl145 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl145.empty()) {
               for (size_t n = 0; n != ampl145.size(); n++) {
                    Expr term = ampl145.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl145.getOptions(), {ampl145.getDiagrams()[n]}, ampl145.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl146 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl146.empty()) {
               for (size_t n = 0; n != ampl146.size(); n++) {
                    Expr term = ampl146.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl146.getOptions(), {ampl146.getDiagrams()[n]}, ampl146.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl147 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl147.empty()) {
               for (size_t n = 0; n != ampl147.size(); n++) {
                    Expr term = ampl147.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl147.getOptions(), {ampl147.getDiagrams()[n]}, ampl147.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl148 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl148.empty()) {
               for (size_t n = 0; n != ampl148.size(); n++) {
                    Expr term = ampl148.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl148.getOptions(), {ampl148.getDiagrams()[n]}, ampl148.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl149 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl149.empty()) {
               for (size_t n = 0; n != ampl149.size(); n++) {
                    Expr term = ampl149.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl149.getOptions(), {ampl149.getDiagrams()[n]}, ampl149.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl150 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl150.empty()) {
               for (size_t n = 0; n != ampl150.size(); n++) {
                    Expr term = ampl150.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl150.getOptions(), {ampl150.getDiagrams()[n]}, ampl150.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl151 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl151.empty()) {
               for (size_t n = 0; n != ampl151.size(); n++) {
                    Expr term = ampl151.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl151.getOptions(), {ampl151.getDiagrams()[n]}, ampl151.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl152 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl152.empty()) {
               for (size_t n = 0; n != ampl152.size(); n++) {
                    Expr term = ampl152.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl152.getOptions(), {ampl152.getDiagrams()[n]}, ampl152.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl153 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl153.empty()) {
               for (size_t n = 0; n != ampl153.size(); n++) {
                    Expr term = ampl153.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl153.getOptions(), {ampl153.getDiagrams()[n]}, ampl153.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl154 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl154.empty()) {
               for (size_t n = 0; n != ampl154.size(); n++) {
                    Expr term = ampl154.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl154.getOptions(), {ampl154.getDiagrams()[n]}, ampl154.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl155 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl155.empty()) {
               for (size_t n = 0; n != ampl155.size(); n++) {
                    Expr term = ampl155.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl155.getOptions(), {ampl155.getDiagrams()[n]}, ampl155.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl156 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl156.empty()) {
               for (size_t n = 0; n != ampl156.size(); n++) {
                    Expr term = ampl156.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl156.getOptions(), {ampl156.getDiagrams()[n]}, ampl156.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl157 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl157.empty()) {
               for (size_t n = 0; n != ampl157.size(); n++) {
                    Expr term = ampl157.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl157.getOptions(), {ampl157.getDiagrams()[n]}, ampl157.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl158 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl158.empty()) {
               for (size_t n = 0; n != ampl158.size(); n++) {
                    Expr term = ampl158.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl158.getOptions(), {ampl158.getDiagrams()[n]}, ampl158.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl159 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(lis[j])),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl159.empty()) {
               for (size_t n = 0; n != ampl159.size(); n++) {
                    Expr term = ampl159.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl159.getOptions(), {ampl159.getDiagrams()[n]}, ampl159.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl160 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl160.empty()) {
               for (size_t n = 0; n != ampl160.size(); n++) {
                    Expr term = ampl160.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl160.getOptions(), {ampl160.getDiagrams()[n]}, ampl160.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl161 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl161.empty()) {
               for (size_t n = 0; n != ampl161.size(); n++) {
                    Expr term = ampl161.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl161.getOptions(), {ampl161.getDiagrams()[n]}, ampl161.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl162 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl162.empty()) {
               for (size_t n = 0; n != ampl162.size(); n++) {
                    Expr term = ampl162.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl162.getOptions(), {ampl162.getDiagrams()[n]}, ampl162.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl163 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl163.empty()) {
               for (size_t n = 0; n != ampl163.size(); n++) {
                    Expr term = ampl163.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl163.getOptions(), {ampl163.getDiagrams()[n]}, ampl163.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl164 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl164.empty()) {
               for (size_t n = 0; n != ampl164.size(); n++) {
                    Expr term = ampl164.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl164.getOptions(), {ampl164.getDiagrams()[n]}, ampl164.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl165 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl165.empty()) {
               for (size_t n = 0; n != ampl165.size(); n++) {
                    Expr term = ampl165.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl165.getOptions(), {ampl165.getDiagrams()[n]}, ampl165.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl166 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl166.empty()) {
               for (size_t n = 0; n != ampl166.size(); n++) {
                    Expr term = ampl166.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl166.getOptions(), {ampl166.getDiagrams()[n]}, ampl166.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl167 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl167.empty()) {
               for (size_t n = 0; n != ampl167.size(); n++) {
                    Expr term = ampl167.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl167.getOptions(), {ampl167.getDiagrams()[n]}, ampl167.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl168 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl168.empty()) {
               for (size_t n = 0; n != ampl168.size(); n++) {
                    Expr term = ampl168.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl168.getOptions(), {ampl168.getDiagrams()[n]}, ampl168.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl169 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl169.empty()) {
               for (size_t n = 0; n != ampl169.size(); n++) {
                    Expr term = ampl169.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl169.getOptions(), {ampl169.getDiagrams()[n]}, ampl169.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl170 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl170.empty()) {
               for (size_t n = 0; n != ampl170.size(); n++) {
                    Expr term = ampl170.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl170.getOptions(), {ampl170.getDiagrams()[n]}, ampl170.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl171 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl171.empty()) {
               for (size_t n = 0; n != ampl171.size(); n++) {
                    Expr term = ampl171.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl171.getOptions(), {ampl171.getDiagrams()[n]}, ampl171.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl172 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl172.empty()) {
               for (size_t n = 0; n != ampl172.size(); n++) {
                    Expr term = ampl172.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl172.getOptions(), {ampl172.getDiagrams()[n]}, ampl172.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl173 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl173.empty()) {
               for (size_t n = 0; n != ampl173.size(); n++) {
                    Expr term = ampl173.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl173.getOptions(), {ampl173.getDiagrams()[n]}, ampl173.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl174 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl174.empty()) {
               for (size_t n = 0; n != ampl174.size(); n++) {
                    Expr term = ampl174.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl174.getOptions(), {ampl174.getDiagrams()[n]}, ampl174.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl175 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl175.empty()) {
               for (size_t n = 0; n != ampl175.size(); n++) {
                    Expr term = ampl175.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl175.getOptions(), {ampl175.getDiagrams()[n]}, ampl175.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl176 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl176.empty()) {
               for (size_t n = 0; n != ampl176.size(); n++) {
                    Expr term = ampl176.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl176.getOptions(), {ampl176.getDiagrams()[n]}, ampl176.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl177 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl177.empty()) {
               for (size_t n = 0; n != ampl177.size(); n++) {
                    Expr term = ampl177.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl177.getOptions(), {ampl177.getDiagrams()[n]}, ampl177.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl178 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl178.empty()) {
               for (size_t n = 0; n != ampl178.size(); n++) {
                    Expr term = ampl178.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl178.getOptions(), {ampl178.getDiagrams()[n]}, ampl178.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl179 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(lis[i])), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl179.empty()) {
               for (size_t n = 0; n != ampl179.size(); n++) {
                    Expr term = ampl179.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl179.getOptions(), {ampl179.getDiagrams()[n]}, ampl179.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl180 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(lis[m])}
                  );
             if (!ampl180.empty()) {
               for (size_t n = 0; n != ampl180.size(); n++) {
                    Expr term = ampl180.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << " " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl180.getOptions(), {ampl180.getDiagrams()[n]}, ampl180.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl181 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl181.empty()) {
               for (size_t n = 0; n != ampl181.size(); n++) {
                    Expr term = ampl181.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl181.getOptions(), {ampl181.getDiagrams()[n]}, ampl181.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl182 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl182.empty()) {
               for (size_t n = 0; n != ampl182.size(); n++) {
                    Expr term = ampl182.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl182.getOptions(), {ampl182.getDiagrams()[n]}, ampl182.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl183 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(lis[l]), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl183.empty()) {
               for (size_t n = 0; n != ampl183.size(); n++) {
                    Expr term = ampl183.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << " " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl183.getOptions(), {ampl183.getDiagrams()[n]}, ampl183.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl184 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl184.empty()) {
               for (size_t n = 0; n != ampl184.size(); n++) {
                    Expr term = ampl184.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl184.getOptions(), {ampl184.getDiagrams()[n]}, ampl184.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl185 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl185.empty()) {
               for (size_t n = 0; n != ampl185.size(); n++) {
                    Expr term = ampl185.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl185.getOptions(), {ampl185.getDiagrams()[n]}, ampl185.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl186 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl186.empty()) {
               for (size_t n = 0; n != ampl186.size(); n++) {
                    Expr term = ampl186.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl186.getOptions(), {ampl186.getDiagrams()[n]}, ampl186.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl187 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl187.empty()) {
               for (size_t n = 0; n != ampl187.size(); n++) {
                    Expr term = ampl187.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl187.getOptions(), {ampl187.getDiagrams()[n]}, ampl187.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl188 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl188.empty()) {
               for (size_t n = 0; n != ampl188.size(); n++) {
                    Expr term = ampl188.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl188.getOptions(), {ampl188.getDiagrams()[n]}, ampl188.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl189 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(lis[k]), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl189.empty()) {
               for (size_t n = 0; n != ampl189.size(); n++) {
                    Expr term = ampl189.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << "   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl189.getOptions(), {ampl189.getDiagrams()[n]}, ampl189.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl190 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(OffShell(lis[m]))}
                  );
             if (!ampl190.empty()) {
               for (size_t n = 0; n != ampl190.size(); n++) {
                    Expr term = ampl190.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "OffShell " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl190.getOptions(), {ampl190.getDiagrams()[n]}, ampl190.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl191 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl191.empty()) {
               for (size_t n = 0; n != ampl191.size(); n++) {
                    Expr term = ampl191.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl191.getOptions(), {ampl191.getDiagrams()[n]}, ampl191.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl192 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(OffShell(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl192.empty()) {
               for (size_t n = 0; n != ampl192.size(); n++) {
                    Expr term = ampl192.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "OffShell " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl192.getOptions(), {ampl192.getDiagrams()[n]}, ampl192.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl193 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl193.empty()) {
               for (size_t n = 0; n != ampl193.size(); n++) {
                    Expr term = ampl193.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl193.getOptions(), {ampl193.getDiagrams()[n]}, ampl193.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl194 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl194.empty()) {
               for (size_t n = 0; n != ampl194.size(); n++) {
                    Expr term = ampl194.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl194.getOptions(), {ampl194.getDiagrams()[n]}, ampl194.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl195 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(OffShell(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl195.empty()) {
               for (size_t n = 0; n != ampl195.size(); n++) {
                    Expr term = ampl195.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " OffShell  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl195.getOptions(), {ampl195.getDiagrams()[n]}, ampl195.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl196 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(lis[m]))}
                  );
             if (!ampl196.empty()) {
               for (size_t n = 0; n != ampl196.size(); n++) {
                    Expr term = ampl196.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl196.getOptions(), {ampl196.getDiagrams()[n]}, ampl196.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl197 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(lis[l])), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl197.empty()) {
               for (size_t n = 0; n != ampl197.size(); n++) {
                    Expr term = ampl197.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl197.getOptions(), {ampl197.getDiagrams()[n]}, ampl197.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl198 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(lis[k])), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl198.empty()) {
               for (size_t n = 0; n != ampl198.size(); n++) {
                    Expr term = ampl198.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart  " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl198.getOptions(), {ampl198.getDiagrams()[n]}, ampl198.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 auto ampl199 = model.computeAmplitude(
                    Order::TreeLevel,
                    {Incoming(AntiPart(OffShell(lis[i]))), Incoming(AntiPart(OffShell(lis[j]))),
                    Outgoing(AntiPart(OffShell(lis[k]))), Outgoing(AntiPart(OffShell(lis[l]))), Outgoing(AntiPart(OffShell(lis[m])))}
                  );
             if (!ampl199.empty()) {
               for (size_t n = 0; n != ampl199.size(); n++) {
                    Expr term = ampl199.expression(n);
                   Evaluate(term, csl::eval::abbreviation);
                    csl::option::printIndexIds = false;
         dtout << "AntiPart OffShell " << lis[i] << " " <<"AntiPart OffShell  " << lis[j] << "  to  "
              << " AntiPart OffShell   " << lis[k] << " "  << "AntiPart OffShell  " << lis[l] << " " << "AntiPart OffShell  " << lis[m] << " :  " << term <<" : ";
              
            Expr  squaredAmpl = model.computeSquaredAmplitude(
                       Amplitude(ampl199.getOptions(), {ampl199.getDiagrams()[n]}, ampl199.getKinematics())
    );


    Evaluate(squaredAmpl, csl::eval::abbreviation);
          dtout <<squaredAmpl << '\n';
                   }} 
 
 }
        }
      }
    }
  }
  dtout.close();


  return 0;
}


int main() {

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




 string_view lis[10]={"e", "mu","t" ,"u" ,"d" ,"s" ,"tt" ,"c" ,"b", "A"};


 com_amp(QED_Model, lis, 10);

 return 0;
}

