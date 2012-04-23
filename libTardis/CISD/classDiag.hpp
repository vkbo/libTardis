/*
** ~ libTardis ~
**
** Class :: Diag
*/

#ifndef CLASS_DIAG_HPP

#define CLASS_DIAG_HPP
#include "../libTardis.hpp"

namespace tardis {

class Diag
{
    public:

    // Constructor and Destructor
    Diag(tardis::System*);
    ~Diag() {};

    // Public Functions
    double Run(int, int, double dOmega = 1.0, double dLambda = 0.0);
 
    // Getters, Setters and Output


    private:

    // Variables
    int           iStates;
    int           iParticles;
    //const char*   sOutput;
    //bool          bLog;


    // Objects
    tardis::System *oSystem;

};

} // End namespace tardis

#endif
