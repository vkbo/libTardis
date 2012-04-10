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
#include "omp.h"

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
    void fOutput(std::stringstream*);

};

} // End namespace tardis

#endif
