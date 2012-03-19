/*
** ~ libTardis ~
**
** Class :: System
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

#include "modQDot2D.cpp"

/*
** Public :: Constructor and Destructor
*/

System::System(int iSh, int iP, int iSysType) {

	int iIndex;

	iShells     = iSh;
	iParticles  = iP;
	iSystemType = iSysType;
	//iNMTotal    = iParticles*(iShells-1);
	//iNLambda    = 0;

	bCache = false;

	switch(iSystemType) {
		case ATOM:
			iStates = 0;
			break;

		case QDOT2D:
			iStates = iShells*(iShells+1);
			mStates.set_size(iStates,3);
			iIndex = 0;
			for(int iR = 0; iR < iShells; iR++) {
				for(int iM = -iR; iM <= iR; iM += 2) {
					int iN = (iR - abs(iM))/2;
					mStates(2*iIndex,0)   = iN;
					mStates(2*iIndex,1)   = iM;
					mStates(2*iIndex,2)   = -1;  // 2*Ms
					mStates(2*iIndex+1,0) = iN;
					mStates(2*iIndex+1,1) = iM;
					mStates(2*iIndex+1,2) = 1;   // 2*Ms
					iIndex++;
				}
			}
			break;

		case QDOT3D:
			iStates = 0;
			break;

		case NUCLEUS:
			iStates = 0;
			break;

		case HNUCLEUS:
			iStates = 0;
			break;
	}

	// Generate array of log(n!)
	vLogFac.resize(MAX_FAC+1);
	vLogFac[0] = 0.0;
	vLogFac[1] = 0.0;
	for(int i = 2; i <= MAX_FAC; i++) {
		vLogFac[i] = vLogFac[i-1] + log(i);
	}

	// Generate array of LGamma
	vLGamma.resize(2*MAX_LGAMMA+1);
	for(double dX = 0.0; dX <= MAX_LGAMMA; dX += 0.5) {
		vLGamma[(int)(dX*2)] = fLGamma(dX);
	}

	return;
}

/*
** Public :: Functions
*/

void System::GenerateH(bool bLoad) {

	ostringstream sFileNameH, sFileNameM;
	//bool bLoad = ARMA_CACHE;
	bool bCalc = true;

	sFileNameH << ARMA_CACHE_DIR << "QDot2D_CoulombBlock_Sh" << iShells << ".dat"; 
	sFileNameM << ARMA_CACHE_DIR << "QDot2D_CoulombBlockMap_Sh" << iShells << ".dat"; 
	if(bLoad) {
		bCalc = !mHamiltonian.quiet_load(sFileNameH.str().c_str());
		bCalc = !mMap.quiet_load(sFileNameM.str().c_str());
	}

	if(bCalc) {
		int    iM, iMs, iLambda, iMu;
		int    iCount = 12*iShells-9;
		int    iDim;
		double dSize = 0.0;

		mMap.zeros(iStates*iStates,2);
		mHamiltonian.set_size(1,iCount+1);
		vector<vector<int> > vConfig(iCount);

		cout << "Hamiltonian not found in cache, building ..." << endl;
		cout << "Generating configurations ...";
		fflush(stdout);

		for(int i=0; i<iStates; i++) {
			for(int j=i; j<iStates; j++) {
				iM  = mStates(i,1)+mStates(j,1);
				iMs = mStates(i,2)+mStates(j,2);
				iLambda = (6*iM + 12*iShells + iMs - 10)/2;
				mMap(i*iStates+j,0) = iLambda+1;
				mMap(j*iStates+i,0) = iLambda+1;
				if(j>i) {
					vConfig[iLambda].push_back(i);
					vConfig[iLambda].push_back(j);
					iMu = vConfig[iLambda].size()/2-1;
					mMap(i*iStates+j,1) = iMu;
					mMap(j*iStates+i,1) = iMu;
				}
			}
		}

		for(int k=0; k<=iCount; k++) {
			iDim = vConfig[k-1].size()/2;
			dSize += iDim*iDim*sizeof(double);
		}

		cout << "\rEstimated size: " << setprecision(4) << dSize/MBYTE << " Mb       " << endl;
		cout << "Generating 1-particle Hamiltonian ...";
		fflush(stdout);

		mHamiltonian(0).zeros(iStates,iStates);
		for(int i=0; i<iStates; i++) {
			for(int j=0; j<iStates; j++) {
				mHamiltonian(0)(i,j) = (1+2*mStates(i,0)+abs(mStates(i,1))) + (1+2*mStates(j,0)+abs(mStates(j,1)));
			}
		}

		//cout << mHamiltonian(0) << endl;

		for(int k=1; k<=iCount; k++) {
			iDim = vConfig[k-1].size()/2;
			cout << "\r                                                                                   ";
			cout << "\rGenerating 2-particle Hamiltonian, block " << k << " of " << iCount << " (Dim: " << iDim << "x" << iDim << ")";
			fflush(stdout);
			if(iDim > 0) {
				mHamiltonian(k).zeros(iDim,iDim);
				for(int i=0; i<iDim; i++) {
					for(int j=i; j<iDim; j++) {
						mHamiltonian(k)(i,j) = fCalcElementQ2D(vConfig[k-1][2*i],vConfig[k-1][2*i+1],vConfig[k-1][2*j],vConfig[k-1][2*j+1]);
						mHamiltonian(k)(j,i) = mHamiltonian(k)(i,j);
					}
				}
			} else {
				mHamiltonian(k).zeros(1,1);
			}
		}

		cout << "\r                                                                                   ";
		if(bLoad) {
			mHamiltonian.save(sFileNameH.str().c_str());
			mMap.save(sFileNameM.str().c_str());
			cout << "\rDone and saved to cache";
		} else {
			cout << "\rDone";
		}
		fflush(stdout);
	} else {
		cout << "Hamiltonian found in cache and loaded into memory";
	}

	cout << endl << endl;
	bCache = true;

	return;
}

/*
** Public :: Getters, Setters and Output
*/

int System::GetParticles() {
	return iParticles;
}

int System::GetStates() {
	return iStates;
}

int System::GetState(int iState, int iQN) {
	return mStates(iState, iQN);
}

double System::Get1PElement(int p, int q) {

	if(iSystemType == QDOT2D) {
		if(bCache) {
			return 1.0/(iParticles-1)*mHamiltonian(0)(p,q);
		} else {
			return 1.0/(iParticles-1)*((1 + 2*mStates(p,0) + abs(mStates(p,1))) + (1 + 2*mStates(q,0) + abs(mStates(q,1))));
		}
	}
	return -1.0;
}

double System::Get2PElement(int p, int q, int r, int s) {

	if(iSystemType == QDOT2D) {
		if(bCache) {
			int iLambda1 = mMap(p*iStates+q,0);
			int iLambda2 = mMap(r*iStates+s,0);
			if(iLambda1 == iLambda2) {
				return mHamiltonian(iLambda1)(mMap(p*iStates+q,1),mMap(r*iStates+s,1));
			} else {
				return 0.0;
			}
		} else {
			return fCalcElementQ2D(p, q, r, s);
		}
	}
	return -1.0;
}
