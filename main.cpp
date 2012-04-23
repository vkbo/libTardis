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

int main(int iArgs, char **aArgs) {

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

    //if(iArgs > 1) iShell = atoi(aArgs[1]);

    System *oSys   = new System(iShell, iPartInt, QDOT2D);
    //Basis  *oBasis = new Basis(oSys);
    oSys->GenerateH(true);

    Diag   oDiag(oSys);
    cout << "Energy: " << oDiag.Run(iM, iMs, dOmega, dLambda) << endl;

    //oBasis->BuildBasis(iM, iMs);
    //oBasis->Output();

    //Lanczos oLanczos(oSys, oBasis);
    //cout << "Energy: " << oLanczos.Run(iM, iMs, dOmega, dLambda) << endl;

    oSys->~System();
    tFinish = clock();
    cout << endl << "Computation time: " << setprecision(5) << double(tFinish-tStart)/CLOCKS_PER_SEC << " seconds" << endl << endl;

    return 0;
}
