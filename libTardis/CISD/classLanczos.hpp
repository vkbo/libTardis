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
#ifdef OPENMPI
    #include "mpi.h"
#endif

namespace tardis {

class Lanczos
{
    public:

    // Constructor and Destructor
    Lanczos(tardis::System*, tardis::Basis*, const char* = "");
    ~Lanczos() {};

    // Public Functions
    double Run(int, int, double dOmega = 1.0, double dLambda = 0.0);
    //double RunMaster(int, int, double dOmega = 1.0, double dLambda = 0.0, const char* = "");

    // Getters, Setters and Output


    private:

    // Variables
    int           iStates;
    int           iParticles;
    int           iBasisDim;
    const char*   sOutput;
    bool          bLog;


    // Objects
    tardis::System *oSystem;
    tardis::Basis  *oBasis;

    // Functions
    void fMatrixVector(arma::Col<double>&, arma::Col<double>&, double, double);
    void fOutput(std::stringstream*);

};

} // End namespace tardis

#endif
