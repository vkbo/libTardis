/*
** ~ libTardis ~
**
** Class :: Lanczos
*/

#ifndef CLASS_LANCZOS_HPP

#define CLASS_LANCZOS_HPP
#include "../libTardis.hpp"
#include "../System/classSystem.hpp"
//#include "../System/classBasis.hpp"
//#include "../System/classLog.hpp"
#include <iostream>
#include <fstream>

#ifdef OPENMP
    #include "omp.h"
#endif

#ifdef OPENMPI
    #include "mpi.h"
#endif

namespace tardis {

class Lanczos
{
    public:

    // Constructor and Destructor
    Lanczos(System*);
    ~Lanczos() {};

    // Public Functions
    double Run(int, int, double dOmega = 1.0, double dLambda = 0.0);

    // Getters, Setters and Output


    private:

    // Variables
    int iStates;
    int iParticles;
    int iBasisDim;

    // Other Variables
    std::stringstream ssOut;

    // Objects
    System    *oSystem;
    Potential *oPot;
    Basis     *oBasis;
    Log       *oOut;

    // Functions
    void fMatrixVector(arma::Col<double>&, arma::Col<double>&, double, double);

};

} // End namespace tardis

#endif
