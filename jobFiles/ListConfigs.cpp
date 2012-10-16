//# Threads : 1

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../libTardis/libTardis.hpp"

using namespace std;
using namespace tardis;

int main(int argc, char* argv[]) {

    stringstream ssOut;

    int iShells    = 6;
    int iParticles = 7;

    System *oSystem = new System();
    if(argc > 1) oSystem->SetLogFile(argv[1]);

    ssOut << endl;
    ssOut << "System Config:" << endl;
    ssOut << endl;
    ssOut << "Shells:     " << iShells << endl;
    ssOut << "Particles:  " << iParticles << endl;
    ssOut << endl;
    oSystem->GetLog()->Output(&ssOut);

    oSystem->SetPotential(iShells, QDOT2D, Q2D_NORMAL);
    oSystem->SetParticles(iParticles);
    oSystem->SetQNumber(QN_M, 0);
    oSystem->SetQNumber(QN_MS, 0);
    oSystem->EnableEnergyCut(false);
    oSystem->BuildPotential();
    oSystem->BuildBasis(true);

    return 0;
}
