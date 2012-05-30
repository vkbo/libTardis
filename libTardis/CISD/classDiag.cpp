/*
** ~ libTardis ~
**
** Class :: Diag
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
** Public :: Constructor and Destructor
*/

Diag::Diag(System *oSys) {

    oSystem = oSys;
    oPot    = oSys->GetPotential();

    iStates    = oSystem->GetStates();
    iParticles = oSystem->GetParticles();
    iM         = oSystem->GetQNumber(QN_M);
    iMs        = oSystem->GetQNumber(QN_MS);
    d1PFac     = oSystem->GetVariable(VAR_1PFAC);
    d2PFac     = oSystem->GetVariable(VAR_2PFAC);

    return;
}

/*
** Public :: Functions
*/

double Diag::Run() {

    // Check for illegal values
    if(iParticles != 2) {
        cout << "Error: Diag can only be used for systems of 2 particles ..." << endl;
        return -1.0;
    }

    int                iDim;
    Mat<double>        mTemp;
    Mat<double>        mHDiag;
    Col<double>        mEnergy;
    Col<cx_double>     mHEigVal;
    Mat<cx_double>     mHEigVec;
    const Col<double>* m1PHam;
    const Mat<double>* m2PHam;

    iM  = abs(iM);  // iM  = -iM
    iMs = abs(iMs); // iMs = -iMs

    // Building Hamiltonian
    m1PHam = oPot->Get1PHam(iM,iMs);
    m2PHam = oPot->Get2PHam(iM,iMs);
    iDim = m1PHam->n_cols;

    mTemp.zeros(iDim,iDim);
    mTemp = *m2PHam*d2PFac;
    mTemp.diag() += *m1PHam*d1PFac;

    // Calculating eigenvalues
    eig_gen(mHEigVal, mHEigVec, mTemp);
    mHDiag  = real(inv(mHEigVec)*mTemp*mHEigVec);
    mEnergy = sort(mHDiag.diag());

    return mEnergy(0);
}
