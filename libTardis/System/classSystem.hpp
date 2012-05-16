/*
** ~ libTardis ~
**
** Class :: System
*/

#ifndef CLASS_SYSTEM_HPP

#define CLASS_SYSTEM_HPP
#include "../libTardis.hpp"
#include "classBasis.hpp"
#include "classLog.hpp"
#include "../Potential/classPotential.hpp"
//#include "../Potential/classQDot2D.hpp"
#include <iostream>

namespace tardis {

class System
{
    public:

    // Constructor and Destructor
    System();
    ~System();

    // Potential Configuration
    bool SetPotential(int, int iPotential = QDOT2D, int iGenerator = Q2D_ANALYTIC);
    int  GetPotentialType()   {return iPotType;};
    int  GetShells()          {return iShells;};
    int  GetStates()          {return iStates;};

    // Basis Configuration
    bool SetParticles(int);
    int  GetParticles()       {return iParticles;};
    bool EnableEnergyCut(bool);

    // System Configuration
    bool   SetQNumber(int, int);
    bool   SetVariable(int, double);
    int    GetQNumber(int);
    double GetVariable(int);

    // Cache Directory
    void SetCache(const char*);
    void SetLogFile(const char*);

    // Pointers
    Potential *GetPotential() {return oPot;};
    Basis     *GetBasis()     {return oBasis;};
    Log       *GetLog()       {return oOut;};

    // System Functions
    bool BuildPotential();
    bool BuildBasis();


    private:

    // System Variables
    int iPotType;   // Type of potential
    int iGenType;   // Potential generator
    int iShells;    // Number of shells
    int iParticles; // Number of particles
    int iStates;    // Number of quantum states |0> |1> ... |n>

    // Switches
    bool bPotType;      // Potential type set
    bool bPotBuilt;     // Potential built
    bool bBasisBuilt;   // Basis built
    bool bEnergyCut;    // Use energy cut for basis
    bool bEnergyCutSet; // Is Energy Cut set manually?

    // System Configuration
    int    iM;      // Total M
    int    iMs;     // Total Spin
    int    iEMax;   // Energy cut value
    double dLambda; // Interaction strength
    double dOmega;  // Harmonic oscillator frequency
    double d1PFac;  // 1-Particle hamiltonian factor (derived from dOmega or dLambda)
    double d2PFac;  // 2-Particle hamiltonian factor (derived from dOmega or dLambda)

    // Other Variables
    std::stringstream ssOut;
    std::stringstream ssCache;

    // Objects
    Potential *oPot;    // Potential object
    Basis     *oBasis;  // Basis object
    Log       *oOut;    // Logfile

    // Private Functions
    void fUpdateFac();
};

} // End namespace tardis

#endif
