/*
** ~ libTardis ~
**
** Class :: System
*/

#ifndef CLASS_SYSTEM_HPP

#define CLASS_SYSTEM_HPP
#include "../libTardis.hpp"
#ifdef OPENMP
    #include "omp.h"
#endif

namespace tardis {

class System
{
    public:

    // Constructor and Destructor
    System(int, int, int);
    ~System() {};

    // Public Functions
    void GenerateH(bool bLoad=false);

    // Getters, Setters and Output
    int GetParticles();
    int GetStates();
    int GetState(int, int);

    // QDot2D functions in modQDot2D.cpp
    double                   Get1PElement(int, int);
    double                   Get2PElement(int, int, int, int);
    const arma::Col<double> *Get1PHam(int, int);
    const arma::Mat<double> *Get2PHam(int, int);
    int                      GetDim(int, int);


    private:

    // Variables
    int  iSystemType; // Type of system
    int  iShells;     // Number of shells
    int  iParticles;  // Number of particles
    int  iStates;     // Number of quantum states |0> |1> ... |n>
    int  iNMTotal;    // Number of M-totals
    int  iNLambda;    // Number of blocks + H(1)
    bool bCache;      // Is the Hamiltonian in memory?

    // Initial Objects
    arma::Mat<int>      mStates; // All possible states
    std::vector<double> vLogFac;
    std::vector<double> vLGamma;

    // Hamiltonian
    arma::field<arma::Mat<double> > mHamiltonian; // Blockdiagonal Hamiltonian Matrix
    arma::field<arma::Mat<int> >    mConfig;      // Configurations
    arma::Mat<int>                  mMap;         // Mapping between mStates and mHamiltonian
    arma::Col<double>               m1PHam;       // Array to hold 1P elements

    // Private functions
    int fMapLambda(int, int);

    // QDot2D functions in modQDot2D.cpp
    double fCalcElementQ2D(int, int, int, int);
    double fCoulomb2D(int, int, int, int, int, int, int, int);
    double fLGamma(double);
};

} // End namespace tardis

#endif
