/*
** ~ libTardis ~
**
** Class :: Lanczos
*/

#ifndef CLASS_LANCZOS_HPP

#define CLASS_LANCZOS_HPP
#include "../libTardis.hpp"

namespace tardis {

class Lanczos
{
    public:

    // Constructor and Destructor
    Lanczos(tardis::System*, tardis::Basis*);
    ~Lanczos() {};

    // Public Functions
    double Run(int, int, double dOmega = 1.0, double dLambda = 0.0);
    double RunPar(int, int, double dOmega = 1.0, double dLambda = 0.0);

    // Getters, Setters and Output


    private:

    // Variables
    int iStates;
    int iParticles;
    int iBasisDim;

    // Objects
    tardis::System *oSystem;
    tardis::Basis  *oBasis;

    // Functions

};

} // End namespace tardis

#endif
