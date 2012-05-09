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
    //~ oSystem->SetPotential(iShell, QDOT2D, Q2D_ANALYTIC);
    //~ oSystem->SetPotential(iShell, QDOT2D, Q2D_NORMAL);
    oSystem->SetPotential(iShell, QDOT2D, Q2D_EFFECTIVE);
    oSystem->SetParticles(iPartInt);
    oSystem->SetQNumber(QN_M, iM);
    oSystem->SetQNumber(QN_MS, iMs);
    oSystem->SetQNumber(QN_EMAX, iShell);
    oSystem->SetVariable(VAR_LAMBDA, dLambda);
    oSystem->SetVariable(VAR_OMEGA,  dOmega);
    oSystem->EnableEnergyCut(true);
    //oSystem->SetCache("/scratch/Temp/arma_cache/");
    oSystem->BuildPotential();
    oSystem->BuildBasis();
    //oSystem->GetBasis()->Output();

    Lanczos oLanczos(oSystem);
    double dEnergy = oLanczos.Run();
    cout << "Energy: " << setprecision(8) << dEnergy << endl;
/*
    Potential *oPot;
    const arma::Mat<int>    *mConf;
    const arma::Mat<double> *mHam1;
    const arma::Mat<double> *mHam2;

    // Test Matrix-elements
    oSystem->SetPotential(iShell, QDOT2D, Q2D_ANALYTIC);
    oSystem->BuildPotential();
    oPot = oSystem->GetPotential();
    mHam1 = oPot->Get2PHam(0,0);
    mConf = oPot->GetConfig(0,0);

    oSystem->SetPotential(iShell, QDOT2D, Q2D_NORMAL);
    oSystem->BuildPotential();
    oPot = oSystem->GetPotential();
    mHam2 = oPot->Get2PHam(0,0);

    //cout << *mConf << endl;
    for(int i=0; i<mConf->n_cols; i++) {
        cout << "|" << mConf->at(0,i) << " " << mConf->at(1,i) << ">\t    ";
        cout << "|";
        cout << oPot->GetState(mConf->at(0,i),0) << " ";
        cout << oPot->GetState(mConf->at(0,i),1) << " ";
        cout << oPot->GetState(mConf->at(0,i),2) << ">\t";
        cout << "|";
        cout << oPot->GetState(mConf->at(1,i),0) << " ";
        cout << oPot->GetState(mConf->at(1,i),1) << " ";
        cout << oPot->GetState(mConf->at(1,i),2) << ">" << endl;
    }
    cout << endl;
    cout << *mHam1 << endl;
    cout << *mHam2 << endl;
    cout << (*mHam2-*mHam1) << endl;

    //oSystem->SetPotential(iShell, QDOT2D, Q2D_EFFECTIVE);
    //oSystem->BuildPotential();
    //oPot = oSystem->GetPotential();
    //mHam = oPot->Get2PHam(0,0);
    //cout << *mHam << endl;
*/

    //Diag oDiag(oSystem);
    //cout << "Energy: " << oDiag.Run(iM, iMs, dOmega, dLambda) << endl;

    tFinish = clock();
    cout << endl << "Computation time: " << setprecision(5) << double(tFinish-tStart)/CLOCKS_PER_SEC << " seconds" << endl << endl;

    return 0;
}
