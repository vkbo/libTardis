/*
** ~ libTardis ~
**
** Class :: QDot2D
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
**  Constructor
** ~~~~~~~~~~~~~
*/
QDot2D::QDot2D(int iShells, int iPartInt) {

	int iIndex;

	Shells   = iShells;
	PartInt  = iPartInt;
	States   = Shells*(Shells + 1); // Number of possible quantum states
	bCoulomb = false;

	sdTemp.resize(PartInt,0);      // Set size of temp SD vector
	iBasisDim = 0;

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

	// Generate array of Quantum Numbers
	QN.set_size(States,3);
	iIndex = 0;
	for(int iN = 0; iN <= floor(Shells/2); iN++) {
		for(int iMl = -(Shells-2*iN-1); iMl <= Shells-2*iN-1; iMl++) {
			QN(2*iIndex,0)   = iN;
			QN(2*iIndex,1)   = iMl;
			QN(2*iIndex,2)   = -1;  // 2*Ms
			QN(2*iIndex+1,0) = iN;
			QN(2*iIndex+1,1) = iMl;
			QN(2*iIndex+1,2) = 1;   // 2*Ms
			iIndex++;
		}
	}

	// Generate 2-particle configuration table if PartInt = 2
	if(PartInt == 2) fGen2PConfig();

}

void QDot2D::GenerateAll() {

	double dMem;
	int i, j;
	int iIndex = 0;
	int iElements = pow(States*(States-1)/2,2);

	dMem = sizeof(int)*pow(States,2) + sizeof(double)*pow(States,4);
	
	cout << "Generating table of Coulomb elements ..." << endl;
	cout << "Size in memory: " << int(dMem/MBYTE) << "Mb" << endl;

	mBraKet.zeros(States,States);
	for(int p=0; p<States; p++) {
		for(int q=0; q<States; q++) {
			mBraKet(p,q) = iIndex;
			iIndex++;
		}
	}

	ostringstream sFileName;
	bool bLoad = ARMA_CACHE;
	bool bCalc = true;

	sFileName << ARMA_CACHE_DIR << "QDot2D_CoulombFull_Sh" << Shells << ".dat"; 
	if(bLoad) bCalc = !mCoulomb.quiet_load(sFileName.str().c_str());

	if(bCalc) {
		iIndex = 0;
		mCoulomb.zeros(States*States,States*States);
		for(int p=0; p<States; p++) {
			for(int q=p+1; q<States; q++) {
				for(int r=0; r<States; r++) {
					for(int s=r+1; s<States; s++) {
						i = mBraKet(p,q);
						j = mBraKet(r,s);
						mCoulomb(i,j) = fCalcElement(p,q,r,s);
						mCoulomb(j,i) = mCoulomb(i,j);
						iIndex++;
					}
				}
				fflush(stdout);
				cout << "\r                         ";
				cout << "\rProgress: " << ceil(iIndex*100.0/iElements) << "%";
			}
		}
		if(bLoad) mCoulomb.save(sFileName.str().c_str());
	} else {
		cout << "Coulomb file found in cache and loaded into memory";
	}
	cout << endl << endl;

	bCoulomb = true;

	return;
}

// Outputs a list of all configurations and energies
void QDot2D::ListEnergiesMMS(double dOmega) {

	double dE;
	int    iSW = floor(log10(PartInt*(Shells-1)))+1;
	bool   bFound;

	Mat<double> mEnergies;
	mEnergies.zeros(1,2);

	cout << endl;
	cout << "Energies for " << PartInt << " electrons in " << Shells << " shells:" << endl;
	cout << "=========================================" << endl;

	for(int iM=0; iM<=PartInt*(Shells-1); iM++) {
		for(int iMs=0; iMs<=PartInt; iMs+=2) {
			dE = GetEnergyMMS(iM,iMs,dOmega);
			if(dE > 0) {
				bFound = false;
				for(unsigned int i=0; i<mEnergies.n_rows; i++) {
					if(abs(mEnergies(i,1) - dE) < 1e-6) {
						mEnergies(i,0)++;
						bFound = true;
						break;
					}
				}
				if(!bFound) {
					mEnergies.insert_rows(0,1);
					mEnergies(0,0) = 1;
					mEnergies(0,1) = dE;
				}
			}
			fflush(stdout);
			cout << "M = ±" << setw(iSW) << iM << ", Ms = ±" << iMs << "/2 : ";
			if(dE > 0) {
				cout << "Energy = " << setprecision(8) << dE << endl;
			} else {
				cout << "Not allowed" << endl;
			}
		}
	}

	cout << endl;

	bool   bAgain = true;
	while(bAgain) {
		bAgain = false;
		for(unsigned int i=1; i<mEnergies.n_rows; i++) {
			if(mEnergies(i,1) < mEnergies(i-1,1)) {
				mEnergies.swap_rows(i,i-1);
				bAgain = true;
			}
		}
	}

	cout << "Energies sorted:" << endl;
	cout << "=========================================" << endl;
	
	iSW = floor(log10(mEnergies.n_rows-2))+1;
	for(unsigned int i=1; i<mEnergies.n_rows; i++) {
		cout << "E(" << right << setw(iSW) << (i-1) << ") = " << left << setw(12) << setprecision(8) << mEnergies(i,1) << " : Degeneracy = " << int(mEnergies(i,0)) << endl;
	}
	cout << endl;

	return;
}

double QDot2D::GetEnergyLanczos(int iM, int iMs, double dOmega, double dLambda) {

	double d1PFac, d2PFac;

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

	fGenMPConfig(iM, iMs);
	fIndexMPConfig();

	if(iBasisDim == 0) {
		cout << "Basis has dimension 0 ..." << endl;
		return -1.0;
	}

	if(States > SLATER_WORD) {
		cout << "Error: SLATER_WORD in libTardis.hpp too small, must be at least " << (ceil(States/64.0)*64) << " ..." << endl;
		return -1.0;
	}

	//if(iBasisDim <= 100) for(int i=0; i<iBasisDim; i++) sdBasis[i].Output(States);
	cout << "Dimension of basis: " << iBasisDim << endl << endl;

	/*
	** Initializing
	*/

	// Lanczos vectors
	Col<double> mV;
	Col<double> mW;
	mV.zeros(iBasisDim);
	mW.randu(iBasisDim);
	mW = mW/norm(mW,2);

	// Runtime variables
	int    i, j, k, p, q, r, s;
	int    iS1, iS2, iS3, iS4, iL=0;
	long   lCCount = 0;
	double dTemp, dV, dO;
	Slater sdPhiPQRS, sdPhiQRS, sdPhiSR, sdPhiR;
	Row<double> mA;
	Row<double> mB;
	Row<double> mE;
	mA.ones(1);
	mB.ones(1);
	mE.zeros(1);
	k = 0;

	// Eigenvector variables
	Mat<double>    mTemp;
	Mat<double>    mHDiag;
	Col<double>    mEnergy;
	Col<cx_double> mHEigVal;
	Mat<cx_double> mHEigVec;

	/*
	** The Lanczos algorithm
	** Source: Golub/Van Loan - Matrix Computations Third Edition, Page 480
	*/

	while(abs(mB(k)) > 1e-9 && k < iBasisDim && k < 200) {
		if(k > 0) {
			for(i=0; i<iBasisDim; i++) {
				dTemp = mW(i);
				mW(i) = mV(i)/mB(k);
				mV(i) = -mB(k)*dTemp;
			}
		}

		// Applying the Hamiltonian
		for(i=0; i<iBasisDim; i++) {
			for(r=0; r<States; r++) {
				sdPhiR = sdBasis[i];
				iS1 = sdPhiR.Annihilate(r);
				if(iS1 == 0) continue;
				for(s=r+1; s<States; s++) {
					sdPhiSR = sdPhiR;
					iS2 = sdPhiSR.Annihilate(s);
					if(iS2 == 0) continue;
					for(q=0; q<States; q++) {
						sdPhiQRS = sdPhiSR;
						iS3 = sdPhiQRS.Create(q);
						if(iS3 == 0) continue;
						for(p=0; p<q; p++) {
							sdPhiPQRS = sdPhiQRS;
							iS4 = sdPhiPQRS.Create(p);
							if(iS4 == 0) continue;
							iL = -1;
							//for(j=0; j<iBasisDim; j++) {
							//	if(sdBasis[j].Compare(sdPhiPQRS)) {iL = j; break;}
							//}
							for(j=1; j<=mBasisIndex(p,q,0); j++) {
								if(sdBasis[mBasisIndex(p,q,j)].Compare(sdPhiPQRS)) {iL = mBasisIndex(p,q,j); break;}
							}
							if(iL > -1) {
								dV = 0.0;
								if(p == r && q == s) dV += fHOscEnergy(QN(p,0),QN(p,1),QN(s,0),QN(s,1))*d1PFac; // 1-particle interaction
								dV += fCalcElement(p,q,r,s)*d2PFac;                                             // 2-particle interaction
								mV(iL) += iS1*iS2*iS3*iS4*dV*mW(i);
								lCCount++;
							}
						}
					}
				}
			}
			if(iBasisDim > 100 && i%10 == 9) {
				fflush(stdout);
				cout << "\r                                ";
				cout << "\rCalculating SD: " << i+1;
			}
		}

		// Prepere next iteration
		k++;
		mA.insert_cols(k,1);
		mB.insert_cols(k,1);
		mE.insert_cols(k,1);
		mA(k) = dot(mW,mV);
		mV   -= mA(k)*mW;
		mB(k) = norm(mV,2);

		// Ortonomalization of Lanczos vectors
		dO = dot(mV,mW);
		if(abs(dO) > 1e-12) {
			mV -= (dO/dot(mW,mW))*mW;
			mV/norm(mV,2);
			mW/norm(mW,2);
		}

		// Building the tri-diagonal matrix
		mTemp.zeros(k,k);
		for(i=0; i<k; i++) {
			mTemp(i,i) = mA(i+1);
			if(i<k-1) {
				mTemp(i,i+1) = mB(i+1);
				mTemp(i+1,i) = mB(i+1);
			}
		}

		// Calculating eigenvalues
		eig_gen(mHEigVal, mHEigVec, mTemp);
		mHDiag  = real(inv(mHEigVec)*mTemp*mHEigVec);
		mEnergy = sort(mHDiag.diag());
		mE(k) = mEnergy(0);

		// Checking for energy convergence
		if(abs(mE(k-1) - mE(k)) < LANCZOS_CONVERGE) break;

		fflush(stdout);
		cout << "\r                         ";
		cout << "\rLanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl;;
	}
	cout << "\r                         ";
	cout << "\rLanczos Iteration " << setw(2) << k << " : Energy = " << setprecision(10) << mE(k) << endl;;

	cout << endl;

	cout << "Coulomb calculations: " << lCCount << endl;
	cout << endl;
	cout << "Eigenvalues:" << endl;
	cout << mEnergy << endl;
	//cout << "CPS: " << CLOCKS_PER_SEC << endl;

	return mEnergy(0);
}

double QDot2D::GetEnergyMMS(int iM, int iMs, double dOmega) {

	if(PartInt != 2) {
		cout << "Error: GetEnergyMMS() can only be run for 2-particle interactions" << endl;
		return -1.0;
	}

	iM  = abs(iM);  // iM  = -iM
	iMs = abs(iMs); // iMs = -iMs
	int iConfIndex = fGetMMsIndex(iM,iMs);
	if(iConfIndex < 0 || iConfIndex >= iConfigDim) return -1.0;

	mStates = mConfig.row(iConfIndex);

	if(mStates(0) == 0) return -1.0; // Exit if there are no allowed configurations

	// Build (or load from disk) 2-Particle Hamiltonian Matrix
	cout << "Building Hamiltonian of dimension " << mStates(0) << "x" << mStates(0) << " ...";
	fflush(stdout);

	ostringstream sFileName;
	bool bLoad = ARMA_CACHE;
	bool bCalc = true;

	sFileName << ARMA_CACHE_DIR << "QDot2D_2PHam_Sh" << Shells << "_M" << iM << "_Ms" << iMs << ".dat"; 

	if(mStates(0) < ARMA_CACHE_MIN) bLoad = false;                      // Ignore cache for small matrices
	if(bLoad) bCalc = !Hamiltonian.quiet_load(sFileName.str().c_str()); // Check if Hamiltonian exists in cache

	if(bCalc) {
		Hamiltonian.reset();
		Hamiltonian.set_size(mStates(0),mStates(0));
		for(int i=0; i<mStates(0); i++) {
			for(int j=i; j<mStates(0); j++) {
				Hamiltonian(i,j) = fCalcElement(mStates(i*2+1),mStates(i*2+2),mStates(j*2+1),mStates(j*2+2))*sqrt(dOmega);
				Hamiltonian(j,i) = Hamiltonian(i,j);
			}
			Hamiltonian(i,i) += fHOscEnergy(QN(mStates(i*2+1),0),QN(mStates(i*2+1),1),QN(mStates(i*2+2),0),QN(mStates(i*2+2),1))*dOmega;
		}
		if(bLoad) Hamiltonian.save(sFileName.str().c_str(), arma_ascii);
	}

	Col<cx_double> mHEigVal;
	Mat<cx_double> mHEigVec;

	cout << "\r                                                   ";
	cout << "\rCalculating eigenvectors ...";
	fflush(stdout);
	eig_gen(mHEigVal, mHEigVec, Hamiltonian);

	cout << "\r                            ";
	cout << "\rDiagonalizing ...";
	fflush(stdout);
	Mat<double> mHDiag  = real(inv(mHEigVec)*Hamiltonian*mHEigVec);
	Col<double> mEnergy = sort(mHDiag.diag());

	cout << "\r                 \r";
	fflush(stdout);

	Hamiltonian.reset();
	return mEnergy(0);
}


/*
** +-------------------+
** | Private Functions |
** +-------------------+
*/

/*
**  Generates configuration for a given M and Ms for a many-particle system
** =========================================================================
*/
void QDot2D::fGenMPConfig(int iM, int iMs, int iP) {

	int iStart = 0;
	if(iP < PartInt) {
		if(iP > 0) iStart = sdTemp[iP-1]+1;
		for(int iS=iStart; iS<States; iS++) {
			sdTemp[iP] = iS;
			fGenMPConfig(iM, iMs, iP+1);
		}
	} else {
		Slater sdNew;
		int    iTM = 0;
		for(int i=0; i<PartInt; i++) {
			sdNew.Create(sdTemp[i]);
			iTM += QN(sdTemp[i],1);
		}
		if(sdNew.CountOdd()-sdNew.CountEven() == iMs && iTM == iM) {
			sdBasis.push_back(sdNew);
			iBasisDim++;
		}
	}

	return;
}

/*
**  Build an index for the generated many-particle system configuration
** =====================================================================
*/
void QDot2D::fIndexMPConfig() {

	Slater sdTest;
	int    iMax=0;

	mBasisIndex.zeros(States,States,1);
	
	for(int p=0; p<States; p++) {
		for(int q=0; q<States; q++) {
			for(int i=0; i<iBasisDim; i++) {
				sdTest = sdBasis[i];
				if(sdTest.Annihilate(p) != 0) {
					if(sdTest.Annihilate(q) != 0) {
						iMax = max(max(mBasisIndex.slice(0)));
						mBasisIndex(p,q,0)++;
						if(mBasisIndex(p,q,0) > iMax) {
							mBasisIndex.insert_slices(iMax+1,1);
							mBasisIndex.slice(iMax+1).fill(-1);
						}
						//cout << p << ", " << q << ", " << mBasisIndex(p,q,0) << endl;
						mBasisIndex(p,q,mBasisIndex(p,q,0)) = i;
					}
				}
			}
		}
	}
	//cout << mBasisIndex << endl;
	
	return;
}

/*
**  Generate configuration table for 2-particle systems
** =====================================================
*/
void QDot2D::fGen2PConfig() {

	if(PartInt != 2) {
		cout << "Error: Can only generate configuration table for 2-particle interactions." << endl;
		return;
	}

	int iMaxCol = 0;
	int iM, iMs, iConfIndex;

	iConfigDim = (PartInt+1)*(PartInt*2*(Shells-1)+1);

	mConfig.set_size(iConfigDim,1);
	for(int i=0; i<States; i++) {
		for(int j=i+1; j<States; j++) {
			iM  = QN(i,1)+QN(j,1);                // Total M
			iMs = QN(i,2)+QN(j,2);                // Total Ms
			iConfIndex = fGetMMsIndex(iM,iMs);    // Get configuration |n> = |M,Ms>
			iMaxCol = max(mConfig.col(0));        // Find largest set
			mConfig(iConfIndex,0)++;              // Increase size of current set
			if(mConfig(iConfIndex,0) > iMaxCol) { // Add new columns if needed
				mConfig.insert_cols(2*iMaxCol+1,2);
				for(int k=0; k<iConfigDim; k++) {   // Fill new columns with -1
					mConfig(k,2*iMaxCol+1) = -1;
					mConfig(k,2*iMaxCol+2) = -1;
				}
			}
			mConfig(iConfIndex,2*mConfig(iConfIndex,0)-1) = i; // Save |a> value
			mConfig(iConfIndex,2*mConfig(iConfIndex,0))   = j; // Save |b> value
		}
	}

	return;
}

/*
**  Calculates the Coulomb interaction element <pq|V|rs>
** ======================================================
**  - Accounts for spin
**  - Is antisymmetric
*/
double QDot2D::fCalcElement(int p, int q, int r, int s) {

	if(bCoulomb) return mCoulomb(mBraKet(p,q),mBraKet(r,s));

	double dDirect = 0.0, dExchange = 0.0;

	if(DELTA(QN(p,2),QN(s,2)) && DELTA(QN(q,2),QN(r,2))) {
		dExchange = fCoulomb2D(QN(p,0),QN(p,1),QN(q,0),QN(q,1),QN(r,0),QN(r,1),QN(s,0),QN(s,1));
	}

	if(DELTA(QN(p,2),QN(r,2)) && DELTA(QN(q,2),QN(s,2))) {
		dDirect = fCoulomb2D(QN(p,0),QN(p,1),QN(q,0),QN(q,1),QN(s,0),QN(s,1),QN(r,0),QN(r,1));
	}

	return dDirect - dExchange;
}

/*
**  Calculates Coulomb interactions in 2 dimensions
** =================================================
**  Code adapted from Morten Hjorth-Jensen
**  See Anisimovas and Matulis (1997) for analytical expression
**
**  - Computes <12|V|34>
**  - Does not check spin
**  - Does not antisymmertise
**  - Calculate: d(Ms1,Ms3)*d(Ms2,Ms4)*<12|V|43> - d(Ms1,Ms4)*d(Ms2,Ms3)*<12|V|34>
**      Where d(i,j) is the delta function
*/
double QDot2D::fCoulomb2D(int iN1, int iM1, int iN2, int iM2, int iN3, int iM3, int iN4, int iM4) {

	double dCoulombInt = 0.0;

	if(iM1 + iM2 == iM3 + iM4) {
		double dTemp;
		int    iLambda;
		int    iGamma1 = 0;
		int    iGamma2 = 0;
		int    iGamma3 = 0;
		int    iGamma4 = 0;
		int    iG = 0;
		for(int iJ1 = 0; iJ1 <= iN1; iJ1++) {
			for(int iJ2 = 0; iJ2 <= iN2; iJ2++) {
				for(int iJ3 = 0; iJ3 <= iN3; iJ3++) {
					for(int iJ4 = 0; iJ4 <= iN4; iJ4++) {
						iGamma1 = (int)(iJ1 + iJ4 + 0.5*(abs(iM1) + iM1) + 0.5*(abs(iM4) - iM4));
						iGamma2 = (int)(iJ2 + iJ3 + 0.5*(abs(iM2) + iM2) + 0.5*(abs(iM3) - iM3));
						iGamma3 = (int)(iJ2 + iJ3 + 0.5*(abs(iM3) + iM3) + 0.5*(abs(iM2) - iM2));
						iGamma4 = (int)(iJ1 + iJ4 + 0.5*(abs(iM4) + iM4) + 0.5*(abs(iM1) - iM1));
						iG = iGamma1 + iGamma2 + iGamma3 + iGamma4;

						double dLogRatio1   = - vLogFac[iJ1] - vLogFac[iJ2] - vLogFac[iJ3] - vLogFac[iJ4];
						double dLogProduct2 = vLogFac[iN1 + abs(iM1)] + vLogFac[iN2 + abs(iM2)]
                                + vLogFac[iN3 + abs(iM3)] + vLogFac[iN4 + abs(iM4)]
                                - vLogFac[iN1 - iJ1] - vLogFac[iN2 - iJ2]
                                - vLogFac[iN3 - iJ3] - vLogFac[iN4 - iJ4]
                                - vLogFac[iJ1 + abs(iM1)] - vLogFac[iJ2 + abs(iM2)]
                                - vLogFac[iJ3 + abs(iM3)] - vLogFac[iJ4 + abs(iM4)];
						double dLogRatio2   = -1*(iG + 1)*0.5*log(2);

						dTemp   = 0.0;
						iLambda = 0;

						for(int iL1 = 0; iL1 <= iGamma1; iL1++) {
							for(int iL2 = 0; iL2 <= iGamma2; iL2++) {
								for(int iL3 = 0; iL3 <= iGamma3; iL3++) {
									for(int iL4 = 0; iL4 <= iGamma4; iL4++) {
										iLambda = iL1 + iL2 + iL3 + iL4;
										if((iL1 + iL2) == (iL3 + iL4)) {
											dTemp += MINUS_POW(iGamma2 + iGamma3 - iL2 - iL3)
											       * exp(vLogFac[iGamma1] + vLogFac[iGamma2] + vLogFac[iGamma3] + vLogFac[iGamma4]
											              - vLogFac[iL1] - vLogFac[iL2] - vLogFac[iL3] - vLogFac[iL4]
											              - vLogFac[iGamma1 - iL1] - vLogFac[iGamma2 - iL2]
											              - vLogFac[iGamma3 - iL3] - vLogFac[iGamma4 - iL4]
											              + vLGamma[2 + iLambda] + vLGamma[iG - iLambda + 1]);
										}
									}
								}
							}
						}

						dCoulombInt += MINUS_POW(iJ1 + iJ2 + iJ3 + iJ4)
						             * exp(dLogRatio1 + dLogProduct2 + dLogRatio2)*dTemp;

					}
				}
			}
		}
		dCoulombInt *= exp((vLogFac[iN1] + vLogFac[iN2] + vLogFac[iN3] + vLogFac[iN4]
	                    - vLogFac[iN1 + abs(iM1)] - vLogFac[iN2 + abs(iM2)]
	                    - vLogFac[iN3 + abs(iM3)] - vLogFac[iN4 + abs(iM4)])*0.5);
	}

	return dCoulombInt;
}

/*
**  Calculates log(Gamma) of a real argument
** ==========================================
**  Code adapted from Morten Hjorth-Jensen
**      Algorithms and coefficient values from "Computation of Special
**      Functions", Zhang and Jin, John Wiley and Sons, 1996.
**
**  (C) 2003, C. Bond. All rights reserved.
**
**  NOTE: Returns 1e308 if argument is 0 or negative.
**  Taken from the web at http://www.crbond.com/math.htm
*/
double QDot2D::fLGamma(double dX) {

	if(dX > MAX_LGAMMA) {
		cout << "Error in fLGamma: Too big integer in lgamma(x) to give accurate result" << endl;
		return 0.0;
	}

	double dX0, dX2, dXp, dGL, dGL0;
	int    iN = 0, iK;
	static double aA[] = { 8.333333333333333e-02,
	                      -2.777777777777778e-03,
	                       7.936507936507937e-04,
	                      -5.952380952380952e-04,
	                       8.417508417508418e-04,
	                      -1.917526917526918e-03,
	                       6.410256410256410e-03,
	                      -2.955065359477124e-02,
	                       1.796443723688307e-01,
	                      -1.39243221690590};

	dX0 = dX;
	if     (dX <= 0.0) return 1e308;
	else if((dX == 1.0) || (dX == 2.0)) return 0.0;
	else if(dX <= 7.0) {
		iN = (int)(7-dX);
		dX0 = dX + iN;
	}
	dX2 = 1.0/(dX0*dX0);
	dXp = 2.0*M_PI;
	dGL0 = aA[9];
	for(iK = 8; iK >= 0; iK--) dGL0 = dGL0*dX2 + aA[iK];
	dGL = dGL0/dX0 + 0.5*log(dXp) + (dX0 - 0.5)*log(dX0) - dX0;
	if(dX <= 7.0) {
		for(iK = 1; iK <= iN; iK++) {
			dGL -= log(dX0-1.0);
			dX0 -= 1.0;
		}
	}
	return dGL;
}

/*
**  Other Private Functions
** =========================
**  fGetMMsIndex :: Returns configuration index for given M and Ms for 2-particle systems
**  fHOscEnergy  :: Calculates 1-particle energy contribution for 2D harmonic oscillator
**                  E = 1/N-1 * [(1 + 2n_1 + |m_1|) + (1 + 2n_2 + |m_2|)] * Omega
*/

int QDot2D::fGetMMsIndex(int iM, int iMs) {
	return (PartInt+1)*(iM+PartInt*(Shells-1))+(iMs+PartInt)/2;
}

double QDot2D::fHOscEnergy(int iN1, int iM1, int iN2, int iM2) {
	return 1.0/(PartInt-1) * ((1 + 2*iN1 + abs(iM1)) + (1 + 2*iN2 + abs(iM2)));
}

