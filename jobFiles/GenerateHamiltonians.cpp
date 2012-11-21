//# Threads : 1

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <armadillo>
#include "../libTardis/libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

int main(int argc, char* argv[]) {

    stringstream ssFile;

    System *oSystem = new System();
    Mat<double>        mHam;
    const Col<double>* m1PHam;
    const Mat<double>* m2PHam;
    int iDim;

    for(int i=2; i<=20; i++) {
        oSystem->SetPotential(i, QDOT2D, Q2D_EFFECTIVE);
        oSystem->SetParticles(2);
        oSystem->SetQNumber(QN_M, 0);
        oSystem->SetQNumber(QN_MS, 0);
        oSystem->SetVariable(VAR_LAMBDA, 1.0);
        oSystem->SetVariable(VAR_OMEGA, 1.0);
        oSystem->EnableEnergyCut(false);
        oSystem->BuildPotential();

        m1PHam = oSystem->GetPotential()->Get1PHam(0,0);
        m2PHam = oSystem->GetPotential()->Get2PHam(0,0);
        iDim   = m2PHam->n_cols;
        mHam = *m2PHam;
        mHam.diag() += *m1PHam;

        ssFile.str(string());
        ssFile << "Ham-2P-" << i << "R-" << "Dim" << iDim << "x" << iDim << ".arma";

        mHam.save(ssFile.str());
    }

    return 0;
}
