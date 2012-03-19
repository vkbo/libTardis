/*
** ~ libTardis ~
**
** Class :: QDot2D
*/
#include <sstream>

#ifndef CLASS_QDOT2D_HPP

#define CLASS_QDOT2D_HPP
#include "../libTardis.hpp"

#define MAX_FAC    170
#define MAX_LGAMMA 170

#define DELTA(a,b)   (((a)*(b) > 0) ? true : false)
#define MINUS_POW(a) ((abs(a)%2)*-2+1)

namespace tardis {

/*
**  Class init for main class Generator
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
class QDot2D
{
	public:

	int Shells;  // Number of shells
	int PartInt; // Number of particle interactions
	int States;  // Number of states
	int Cores;   // Number of CPU cores to split the job across
	int Core;    // Current CPU core

	arma::Mat<int>    QN;          // List of Quantum Numbers
	arma::Mat<double> Hamiltonian; // Hamiltonian

	QDot2D(int, int);
	~QDot2D() {};
	void   GenerateAll();
	double GetEnergyLanczos(int, int, double dOmega = 1.0, double dLambda = 0.0);
	double GetEnergyMMS(int, int, double);
	void   ListEnergiesMMS(double);

	private:

	int   iConfigDim; // Size of configuration matrix mConfig
	int   iBasisDim;  // Size of Basis

	//arma::Col<double> mLogFac;
	//arma::Col<double> mLGamma;
	std::vector<double> vLogFac;
	std::vector<double> vLGamma;
	arma::Mat<int>      mConfig; // Table of configurations. Even cols = a, odd cols = b
	arma::Row<int>      mStates; // List of states (basis)

	std::vector<tardis::Slater> sdBasis;     // Slater determinant basis
	std::vector<int>            sdTemp;      // Temp vector for building slater determinants
	arma::Cube<int>             mBasisIndex; // Lookup index of sdBasis

	bool              bCoulomb;
	arma::Mat<int>    mBraKet;
	arma::Mat<double> mCoulomb;
	
	void   fGenMPConfig(int, int, int iP=0);
	void   fIndexMPConfig();
	void   fGen2PConfig();

	double fCalcElement(int, int, int, int);
	double fCoulomb2D(int, int, int, int, int, int, int, int);
	double fLGamma(double);

	int    fGetMMsIndex(int, int);
	double fHOscEnergy(int, int, int, int);

};

} // End namespace tardis

#endif
