/*
** ~ libTardis ~
**
** Class :: Diag
*/

#ifndef CLASS_DIAG_HPP

#define CLASS_DIAG_HPP
#include "../libTardis.hpp"
#include "../System/classSystem.hpp"

namespace tardis {

class Diag
{
    public:

    // Constructor and Destructor
    Diag(System*);
    ~Diag() {};

    // Public Functions
    double Run(int, int, double dOmega = 1.0, double dLambda = 0.0);
 

    private:

    // Variables
    int iStates;
    int iParticles;

    // Objects
    System    *oSystem;
    Potential *oPot;

};

} // End namespace tardis

#endif
