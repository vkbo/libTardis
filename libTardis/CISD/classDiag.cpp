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

    iStates    = oSystem->GetStates();
    iParticles = oSystem->GetParticles();

    return;
}

/*
** Public :: Functions
*/

double Diag::Run(int iM, int iMs, double dOmega, double dLambda) {

    // Check for illegal values

    //if(iParticles != 2) {
    //    cout << "Error: Diag can only be used for systems of 2 particles ..." << endl;
    //    fOutput(&ssOut);
    //    return -1.0;
    //}

    // Lambda or Omega values
    double d1PFac, d2PFac;
    int    iDim;

    Mat<double>        mTemp;
    Mat<double>        mHDiag;
    Col<double>        mEnergy;
    Col<cx_double>     mHEigVal;
    Mat<cx_double>     mHEigVec;
    const Col<double>* m1PHam;
    const Mat<double>* m2PHam;

    if(dOmega != 0.0) {
        d1PFac = dOmega;
        d2PFac = sqrt(dOmega);
    } else {
        if(dLambda != 0.0) {
            d1PFac = 1.0;
            d2PFac = dLambda;
        } else {
            d1PFac = 1.0;
            d2PFac = 0.0;
        }
    }

    iM  = abs(iM);  // iM  = -iM
    iMs = abs(iMs); // iMs = -iMs

    m1PHam = oSystem->Get1PHam(iM,iMs);
    m2PHam = oSystem->Get2PHam(iM,iMs);
    iDim = m1PHam->n_cols;

    mTemp.zeros(iDim,iDim);
    mTemp = d2PFac*(*m2PHam);
    mTemp.diag() += *m1PHam*d1PFac;

    // Calculating eigenvalues
    eig_gen(mHEigVal, mHEigVec, mTemp);
    mHDiag  = real(inv(mHEigVec)*mTemp*mHEigVec);
    mEnergy = sort(mHDiag.diag());
 
    return mEnergy(0);
}
