//# Threads : 1

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "libTardis/libTardis.hpp"

using namespace std;
using namespace tardis;

int main(int argc, char* argv[]) {

    stringstream ssOut;

    int    iShells    = 6;
    int    iParticles = 4;
    int    iM         = 0;
    int    iMs        = 0;
    bool   bEnergyCut = false;

    double dOmega     = 0.0;
    double dLambda    = 6.0;

    System *oSystem = new System();
    if(argc > 1) oSystem->SetLogFile(argv[1]);

    ofstream oOutput;
    oOutput.open("tempQueue/output.txt");

    ssOut << endl;
    ssOut << "System Config:" << endl;
    ssOut << endl;
    ssOut << "Shells:     " << iShells << endl;
    ssOut << "Particles:  " << iParticles << endl;
    ssOut << "Total M:    " << iM << endl;
    ssOut << "Total Spin: " << iMs << endl;
    ssOut << "Omega:      " << dOmega << endl;
    ssOut << "Lambda:     " << dLambda << endl;
    ssOut << endl;
    oSystem->GetLog()->Output(&ssOut);

    oSystem->SetPotential(iShells, QDOT2D, Q2D_NORMAL);
    oSystem->SetParticles(iParticles);
    oSystem->SetQNumber(QN_M, iM);
    oSystem->SetQNumber(QN_MS, iMs);
    oSystem->SetVariable(VAR_LAMBDA, dLambda);
    oSystem->SetVariable(VAR_OMEGA, dOmega);
    oSystem->EnableEnergyCut(bEnergyCut);
    oSystem->BuildPotential();
    oSystem->BuildBasis();

    Lanczos oLanczos(oSystem);
    double dEnergy = oLanczos.Run();

    cout << "Energy: " << setprecision(10) << setw(11) << dEnergy << endl;
    oOutput << "P 4, ";
    oOutput << "Sh 6, ";
    oOutput << "M 0, ";
    oOutput << "Ms 0, ";
    oOutput << "Om 0.0, ";
    oOutput << "Lm 6.0, ";
    oOutput << "NoECut, ";
    oOutput << "Vstd, ";
    oOutput << "Lz";
    oOutput << "\t | Energy: " << setprecision(10) << setw(11) << dEnergy << endl;

    oOutput.close();

    return 0;
}
