/*
** ~ libTardis ~
**
** Class :: Lanczos
*/

#ifndef CLASS_LANCZOS_HPP

#define CLASS_LANCZOS_HPP
#include "../libTardis.hpp"
#include <iostream>
#include <fstream>

#ifdef OPENMP
    #include "omp.h"
#endif

namespace tardis {

class Lanczos
{
    public:

    // Constructor and Destructor
    Lanczos(System*);
    ~Lanczos() {};

    // One-Node Lanczos Functions
    double Run(int iCoeffMode = 0);

    // Multi-Node Lanczos Functions
    int  RunInit();
    int  RunSlave(arma::Col<double>&, std::vector<double>&, int, int);
    int  RunMaster();

    // Getters, Setters and Output
    int  GetLanczosIt()        {return iLzIt;};
    void SetLanczosIt(int iIt) {iLzIt = iIt;};

    arma::Col<double> *GetLanczosVectorV() {return &mLzV;};
    arma::Col<double> *GetLanczosVectorW() {return &mLzW;};
    arma::Row<double> *GetLanczosVectorA() {return &mLzA;};
    arma::Row<double> *GetLanczosVectorB() {return &mLzB;};
    arma::Row<double> *GetLanczosVectorC() {return &mLzC;};
    arma::Row<double> *GetLanczosVectorE() {return &mLzE;};
    arma::Col<double> *GetEnergies()       {return &mEnergy;};


    private:

    // Variables
    int    iStates;
    int    iParticles;
    int    iBasisDim;
    double d1PFac;
    double d2PFac;

    // Lanczos Variables
    int               iLzIt;   // Lanczos iteration
    arma::Col<double> mLzV;    // Lanczos vector V
    arma::Col<double> mLzW;    // Lanczos vectoe W
    arma::Row<double> mLzA;    // Lanczos tridiagonal vector Alpha
    arma::Row<double> mLzB;    // Lanczos tridiagonal vector Beta
    arma::Row<double> mLzC;    // Lanczos first eigenvalue convergence
    arma::Row<double> mLzE;    // Lanczos eigenvalues
    arma::Col<double> mEnergy; // Energy eigenvalues
    arma::Mat<double> mFullLz; // Full matrix of Lanczos vectors

    // Other Variables
    std::stringstream ssOut;

    // Objects
    System    *oSystem;
    Potential *oPot;
    Basis     *oBasis;
    Log       *oOut;

    // Functions
    void fMatrixVector(arma::Col<double>&, std::vector<std::vector<double> >&, double, double, int, int);

};

} // End namespace tardis

#endif
