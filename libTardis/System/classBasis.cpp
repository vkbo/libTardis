/*
** ~ libTardis ~
**
** Class :: Basis
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
** Basis Constructor
*/

Basis::Basis(Potential *oPotential, Log *oLog, int iNumParticles, int iNumShells) {

    oPot          = oPotential;
    oOut          = oLog;
    iParticles    = iNumParticles;
    iShells       = iNumShells;
    iStates       = iShells*(iShells+1);
    bEnergyCut    = false;
    bEnergyCutSet = false;
    iEnergyCuts   = 0;
    iEMax         = iShells;

    // Qunatum Numbers
    iM  = 0;
    iMs = 0;

    if(iStates > SLATER_WORD) {
        ssOut << "Warning: SLATER_WORD not large enough for this configuration." << endl;
        ssOut << "         SLATER_WORD must be at least " << (floor(iStates/64)+1)*64 << " bit" << endl;
        oOut->Output(&ssOut);
    }

    // Using binary search and simple index
    #ifndef INDEX_BASIS
        mIndex.set_size(iStates+1,2);
        mIndex.fill(-1);
    #endif
    
    mConfigMap.zeros((iShells-1)*iParticles+1,iParticles+1);

    return;
}


/*
**  Building the Basis
** ====================
**
**  If INDEX_BASIS is defined:
**   - Builds a full index after the basis itself has been built
**   - The size of the index should scale like Np(Np+1)/2 * Dim_Basis * sizeof(short)
**   - Not recommended for large systems where both Np and Dim_Basis blows up
**
**  If INDEX_BASIS is not defined:
**   - Builds a simple index of the first particle (vTemp[0])
**   - Index is built in the basis loop tself
**   - Scales as 2*N_States * sizeof(int)
**   - Defines the initial interval for the binary search
*/

int Basis::BuildBasis(bool bOutputConfigs) {

    Slater sdTest;
    int    iBasisDim = 0;
    int    i,j,iExp;
    long   lConfMax;
    double d, dX = 1.0;
    #ifndef INDEX_BASIS
        int iPrev = -1;
    #endif

    // Calculate energy cut-off is bEnergyCut=true
    if(bEnergyCut && !bEnergyCutSet) {
        int iNMax = floor((iStates - iParticles)/2);
        iEMax = iNMax + 2;
        ssOut << "Energy Cut-off: 2·max(N) + max(|M|) <= " << iEMax << endl;
    }

    // Calculating number of possible configurations
    for(d=0.0; d<iParticles; d++) dX *= (iStates-d)/(iParticles-d);
    lConfMax = (long)dX;
    iExp     = floor(log10(lConfMax));
    ssOut << "Possible configurations: " << lConfMax;
    if(lConfMax > 0) ssOut << " (~" << round(lConfMax/pow(10,iExp)) << "e" << iExp << ")";
    ssOut << endl;

    #ifdef PROGRESS
        long lCount = 0;
        int  iOut = 0;

        cout << showpoint;
        cout << setw(5);
        cout << setprecision(3);
    #else
        ssOut << "Building Basis ... " << endl;
    #endif
    oOut->Output(&ssOut);

    /*
    **  Building Basis
    ** ================
    **  Example: Np = 4 particles, States = 12 (3 shells)
    **   - Initial config: (|0>,|1>,|2>,|3>)
    **   - Next step:      (|0>,|1>,|2>,|4>)
    **     ...
    **   - Then:           (|0>,|1>,|2>,|11>)
    **   - Next step:      (|0>,|1>,|3>,|4>)
    **     ...
    **   - Then:           (|0>,|1>,|10>,|11>)
    **   - Next step:      (|0>,|2>,|3>,|4>)
    **
    **   ! Did not achieve significant improvement with OpenMP
    **     Implementation is complicated due to outer while-loop
    */

    vector<int> vTemp(iParticles,0); // Vector of particles
    vBasis.clear();                  // Clearing old basis

    // Setting and checking lowest particle states (|0>, |1>, ... , |Np>)
    for(int i=0; i<iParticles; i++) vTemp[i] = i;

    if(fCheckQDot2D(vTemp, bOutputConfigs)) {
        sdTest.Zero();
        for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
        vBasis.push_back(sdTest);
        #ifndef INDEX_BASIS
            if(vTemp[0] != iPrev) {
                if(iPrev >= 0) mIndex(iPrev,1)  = vBasis.size()-2;
                mIndex(vTemp[0],0) = vBasis.size()-1;
                iPrev = vTemp[0];
            }
            mIndex(vTemp[0],1) = vBasis.size()-1;
        #endif
    }

    // Looping over the rest of the possible configurations
    while(vTemp[0] < iStates-iParticles) {           // Stop if first particle is in highest state allowed
        for(i=iParticles-1; i>=0; i--) {             // Loop through particles from last to first
            if(vTemp[i] < iStates-iParticles+i) {    // If there are any higher state available for given particle
                vTemp[i]++;                          // Move particle up one state
                if(i < iParticles-1) {               // If this is not the last particle
                    for(j=i+1; j<iParticles; j++) {  // Reset the following particles to lowest states available
                        vTemp[j] = vTemp[j-1] + 1;
                    }
                }
                break;
            }
        }
        if(fCheckQDot2D(vTemp, bOutputConfigs)) {
            sdTest.Zero();
            for(i=0; i<iParticles; i++) sdTest.Create(vTemp[i]);
            vBasis.push_back(sdTest);
            #ifndef INDEX_BASIS
                if(vTemp[0] != iPrev) {
                    if(iPrev >= 0) mIndex(iPrev,1) = vBasis.size()-2;
                    mIndex(vTemp[0],0) = vBasis.size()-1;
                    iPrev = vTemp[0];
                }
                mIndex(vTemp[0],1) = vBasis.size()-1;
            #endif
        }

        #ifdef PROGRESS
            if(lConfMax > 100000) {
                lCount++;
                iOut++;
                if(iOut >= lConfMax/1000) {
                    cout << "\rBuilding Basis: " << OUTPUTF(3) << (lCount/double(lConfMax)*100) << "% " << flush;
                    iOut = 0;
                }
            }
        #endif
    }

    iBasisDim = vBasis.size();

    #ifdef PROGRESS
        cout << "\rBuilding Basis: 100.0%" << endl;
    #endif

    iExp = floor(log10(iBasisDim));
    ssOut << "Dimension of Basis: " << iBasisDim;
    if(iBasisDim > 0) ssOut << " (~" << round(iBasisDim/pow(10,iExp)) << "e" << iExp << ")";
    ssOut << endl;
    if(bEnergyCut) {
        iExp = floor(log10(iEnergyCuts));
        ssOut << "Energy Cuts: " << iEnergyCuts;
        if(iEnergyCuts > 0) ssOut << " (~" << setprecision(3) << (iEnergyCuts*100.0/(iEnergyCuts + iBasisDim)) << "%)";
        ssOut << endl;
    }

    /*
    **  Building Index (Only if INDEX_BASIS is defined)
    ** =================================================
    **  - Builds a vector for indices p*iStates+q (N = States^2)
    **  - For each index, builds a vector of all slater determinants that contains
    **    particles in state p and q
    **  ! Can probably be optimised. For instance by only running q>p
    **  ! Is fairly slow, but uses OpenMP relatively efficiently
    */

    #ifdef INDEX_BASIS

        int p,q;
        int iDim = iStates*iStates;
        vIndex.resize(iDim);

        #ifdef PROGRESS
            cout << "Indexing Basis ... " << flush;
            lCount = 0;
        #endif

        iOut = 0;
        #ifdef OPENMP
            #pragma omp parallel for private(i,q,sdTest) schedule(dynamic,1)
        #endif
        for(p=0; p<iStates; p++) {
            for(q=0; q<iStates; q++) {
                for(i=0; i<iBasisDim; i++) {
                    sdTest = vBasis[i];
                    if(sdTest.Annihilate(p) != 0) {
                        if(sdTest.Annihilate(q) != 0) {
                            #ifdef OPENMP
                                #pragma omp critical
                            #endif
                            vIndex[p*iStates+q].push_back(i);
                        }
                    }
                }

                #ifdef PROGRESS
                    #ifdef OPENMP
                    if(omp_get_thread_num() == 0) {
                    #endif
                        if(iDim > 1000) {
                            lCount = p*iStates+q;
                            iOut++;
                            if(iOut >= iDim/1000) {
                                cout << "\rIndexing Basis: " << OUTPUTF(3) << (lCount/double(iDim)*100) << "% " << flush;
                                iOut = 0;
                            }
                        }
                    #ifdef OPENMP
                    }
                    #endif
                #endif
            }
        }
        #ifdef PROGRESS
            cout << "\rIndexing Basis: 100.0%" << endl;
        #endif

    #endif

    ssOut << endl;
    oOut->Output(&ssOut);

    if(bOutputConfigs) {
        ssOut << "Configurations" << endl;
        for(unsigned int m=0; m<mConfigMap.n_rows; m++) {
            for(unsigned int n=0; n<mConfigMap.n_cols; n++) {
                if(mConfigMap(m,n) > 0) {
                    ssOut << "M=" << m << ", ";
                    ssOut << "2s=" << n << " : ";
                    ssOut << mConfigMap(m,n) << endl;
                }
            }
        }
        ssOut << endl;
        oOut->Output(&ssOut);
    }

    return iBasisDim;
}

/*
**  Load the Basis
** ================
**
**  Loads a basis saved with Save("filename", 1)
**   - Checks that number of particles is correct
**   - Otherwise assumes the basis is the correct one for the running system
*/

bool Basis::LoadBasis(const char *cPath) {
    
    Mat<int> mBasis;
    Slater   sdTemp;
    int      iPrev = -1;
    int      iExp, iBasisDim;
    
    ssOut << "Loading basis from file." << endl;
    oOut->Output(&ssOut);

    #ifdef INDEX_BASIS
        ssOut << "Cannot load indexed basises." << endl;
        oOut->Output(&ssOut);
        return false;
    #endif

    mBasis.load(cPath);
    iBasisDim = mBasis.n_rows;
    
    iExp = floor(log10(iBasisDim));
    ssOut << "Dimension of Basis: " << iBasisDim;
    if(iBasisDim > 0) ssOut << " (~" << round(iBasisDim/pow(10,iExp)) << "e" << iExp << ")";
    ssOut << endl;

    if(mBasis.n_cols != (unsigned int)iParticles) {
        ssOut << "Basis contains the wrong number of particles." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    vBasis.clear();
    for(int i=0; i<iBasisDim; i++) {
        sdTemp.Zero();
        for(int j=0; j<iParticles; j++) sdTemp.Create(mBasis(i,j));
        vBasis.push_back(sdTemp);
        if(mBasis(i,0) != iPrev) {
            if(iPrev >= 0) mIndex(iPrev,1) = vBasis.size()-2;
            mIndex(mBasis(i,0),0) = vBasis.size()-1;
            iPrev = mBasis(i,0);
        }
        mIndex(mBasis(i,0),1) = vBasis.size()-1;
    }
    
    return true;
}

/*
**  Basis Search
** ==============
**
**  If INDEX_BASIS is defined:
**   - Uses simple straight forward search for slater determinants that have state p and q occupied
**   ! Can probably be improved by implementing binary search
**
**  If INDEX_BASIS is not defined
**   - Uses binary search. Should scale with ln(Dim_Basis)
*    - Is more efficient than full index for large systems
*/

int Basis::FindSlater(Slater sdFind, int p, int q) {

    #ifdef INDEX_BASIS
        // Index-based search
        for(unsigned int i=0; i<vIndex[p*iStates+q].size(); i++) {
            if(vBasis[vIndex[p*iStates+q][i]].Equal(sdFind)) {
                return vIndex[p*iStates+q][i];
            }
        }
    #else
        // Binary search
        int iCheck;
        int iP   = sdFind.GetFirst();  // Find lowest occupied state
        int iMin = mIndex(iP,0);       // Set search range based on lowest occupied state
        int iMax = mIndex(iP,1);

        if(iMin == -1) return -1;      // Returns "not found" if stae is never occupied in basis

        while(iMax!=iMin) {            // Otherwise do binary searchy until search interval is 1
            iCheck = iMin+(iMax-iMin)/2;
            switch(vBasis[iCheck].Compare(sdFind)) {
                case  0: return iCheck;
                case -1: iMax = iCheck;   break;
                case  1: iMin = iCheck+1; break;
            }
        }

        if(iMax == iMin) return iMin;  // If only one state exists, return index value
    #endif

    return -1;
}

/*
**  Setting Coefficients
** ======================
**  After calculating the coefficients with Lanczos, these can be returned to the basis
*/

bool Basis::SetCoefficients(Col<double> &mInput) {

    if(vBasis.size() == 0) {
        ssOut << "Error: Basis is of dimension 0. Nothing to do." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(mInput.n_elem != vBasis.size()) {
        ssOut << "Error: Coefficient Vector is not of same dimension as basis." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    mCoefficients = mInput;
    return true;
}

/*
**  Saving Basis
** ==============
*/

bool Basis::Save(const char *cPath, int iMode) {

    // Save Basis in ASCII mode with all coefficients
    if(iMode == 0) {

        ofstream oOutput;
        oOutput.open(cPath);

        oOutput << "#  States:" << endl;
        oOutput << "# ---------" << endl;
        oOutput << "# State   N   M  2*Spin" << endl;
        for(int i=0; i<iStates; i++) {
            oOutput << "|" << setw(3) << i << ">  ";
            oOutput << setw(4) << oPot->GetState(i,0);
            oOutput << setw(4) << oPot->GetState(i,1);
            oOutput << setw(4) << oPot->GetState(i,2);
            oOutput << endl;
        }

        oOutput << endl;
        oOutput << "#  Basis:" << endl;
        oOutput << "# --------" << endl;

        for(unsigned int i=0; i<vBasis.size(); i++) {
            oOutput << setprecision(12) << setw(18) << mCoefficients[i] << " |";
            for(int j=0; j<iStates; j++) {
                oOutput << vBasis[i].Word[j];
            }
            oOutput << ">" << endl;
        }

        oOutput.close();
    }

    // Save Basis as binary files for later reloading
    if(iMode == 1) {

        int      iP;
        Mat<int> mBasis;

        mBasis.zeros(vBasis.size(),iParticles);
        for(unsigned int i=0; i<vBasis.size(); i++) {
            iP = 0;
            for(int j=0; j<iStates; j++) {
                if(vBasis[i].IsSet(j)) {
                    mBasis(i,iP)=j;
                    iP++;
                }
            }
        }
        mBasis.save(cPath);
    }

    return true;
}

/*
** Private :: Basis selction functions
*/

bool Basis::fCheckQDot2D(const vector<int> &vTemp, bool bOutputConfigs) {

    int iTotM   = 0;
    int iTotMs  = 0;
    int iNCurr  = 0;
    int iMCurr  = 0;
    int iNMax   = 0;
    int iMMax   = 0;
    int iEnergy = 0;

    for(int i=0; i<iParticles; i++) {
        iTotM  += oPot->GetState(vTemp[i],1);
        iTotMs += 2*(vTemp[i]%2)-1;
        if(bEnergyCut) {
            iNCurr = oPot->GetState(vTemp[i],0);
            iMCurr = abs(oPot->GetState(vTemp[i],1));
            if(iNCurr > iNMax) iNMax = iNCurr;
            if(iMCurr > iMMax) iMMax = iMCurr;
            iEnergy = 2*iNMax + iMMax;
        }
    }

    if(bOutputConfigs) {
        if(iTotM >= 0 && iTotMs >= 0) {
            mConfigMap(iTotM,iTotMs)++;
        }
    }

    if(iTotMs == iMs && iTotM == iM) {
        if(bEnergyCut && iEnergy > iEMax) {
            iEnergyCuts++;
            return false;
        }
        return true;
    }

    return false;
}

/*
** Public :: Getters, Setters and Output
*/

void Basis::Output() {

    int iWidth = ceil(log10(iStates))+1;

    for(unsigned int i=0; i<vBasis.size(); i++) {
        cout << "|" << setw(iWidth) << i << "> : ";
        vBasis[i].Output(iStates);
    }

    return;
}

bool Basis::SetQNumber(int iVar, int iValue) {

    switch(iVar) {
        case QN_M:    iM    = iValue; break;
        case QN_MS:   iMs   = iValue; break;
        case QN_EMAX: iEMax = iValue; bEnergyCutSet = true; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return false;
    }

    return true;
}

int Basis::GetQNumber(int iVar) {

    switch(iVar) {
        case QN_M:    return iM;    break;
        case QN_MS:   return iMs;   break;
        case QN_EMAX: return iEMax; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return -1000;
    }
}

bool Basis::EnableEnergyCut(bool bValue) {
    bEnergyCut = bValue;
    return true;
}
