/*
  Test libTardis
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>
#include "libTardis/libTardis.hpp"

using namespace std;
using namespace tardis;

int main() {

    clock_t tStart, tFinish;
    tStart = clock();

    string sTemp;
    int    iShell, iPartInt, iM, iMs;
    double dOmega, dLambda;

    cout << endl;
    cout << "Input" << endl;
    cout << "*****" << endl;

    cout << "Shells [2]: ";
    getline(cin, sTemp);
    if(sTemp == "") {iShell = 2;} else {iShell = atoi(sTemp.c_str());}

    cout << "Particles [2]: ";
    getline(cin, sTemp);
    if(sTemp == "") {iPartInt = 2;} else {iPartInt = atoi(sTemp.c_str());}

    cout << "Total M [0]: ";
    getline(cin, sTemp);
    if(sTemp == "") {iM = 0;} else {iM = atoi(sTemp.c_str());}

    cout << "Total Ms [0]: ";
    getline(cin, sTemp);
    if(sTemp == "") {iMs = 0;} else {iMs = atoi(sTemp.c_str());}

    cout << "Omega [1.0]: ";
    getline(cin, sTemp);
    if(sTemp == "") {dOmega = 1.0;} else {dOmega = atof(sTemp.c_str());}

    cout << "Lambda [0.0]: ";
    getline(cin, sTemp);
    if(sTemp == "") {dLambda = 0.0;} else {dLambda = atof(sTemp.c_str());}

    cout << endl;

    System *oSystem = new System();
    oSystem->SetPotential(iShell, QDOT2D, Q2D_EFFECTIVE);
    oSystem->SetParticles(iPartInt);
    oSystem->SetQNumber(QN_M, iM);
    oSystem->SetQNumber(QN_MS, iMs);
    //oSystem->SetCache("/scratch/Temp/arma_cache/");
    oSystem->BuildPotential();
    oSystem->BuildBasis();

    Lanczos oLanczos(oSystem);
    cout << "Energy: " << setprecision(8) << oLanczos.Run(iM, iMs, dOmega, dLambda) << endl;

    //Diag oDiag(oSystem);
    //cout << "Energy: " << oDiag.Run(iM, iMs, dOmega, dLambda) << endl;

    tFinish = clock();
    cout << endl << "Computation time: " << setprecision(5) << double(tFinish-tStart)/CLOCKS_PER_SEC << " seconds" << endl << endl;

    return 0;
}
