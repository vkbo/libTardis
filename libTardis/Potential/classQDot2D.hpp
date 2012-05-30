/*
** ~ libTardis ~
**
** Class :: QDot2D
*/

#ifndef CLASS_QDOT2D_HPP

#define CLASS_QDOT2D_HPP
#include "../libTardis.hpp"
#include "classPotential.hpp"

// openFCI
#include "../OpenFCI/classQDotInteraction.hpp"

#ifdef OPENMP
    #include "omp.h"
#endif

#define MAX_FAC    170
#define MAX_LGAMMA 170

#define DELTA(a,b)   (((a)*(b) > 0) ? true : false)
#define MINUS_POW(a) ((abs(a)%2)*-2+1)

namespace tardis {

class QDot2D : public Potential
{
    public:

    // Constructor and Destructor
    QDot2D(int, Log*);
    ~QDot2D() {};

    // Public Functions
    void Load(int);
    void Generate(int, bool);
    void LoadOrGenerate(int, bool);

    // Setters
    void SetCache(const char *cCache) {ssCache << cCache;};
    void SetLambda(double dValue)     {dLambda = dValue;};
    void SetEnergyCut(bool bValue)    {bEnergyCut = bValue;};
    void SetBlock(int iQa, int iQb)   {iFM = iQa; iFMs = iQb;};

    // Getters
    int  GetShells()                   {return iShells;};
    int  GetStates()                   {return iStates;};
    int  GetState(int iState, int iQN) {return mStates(iState, iQN);};
    bool GetEnergyCut()                {return bEnergyCut;};

    double Get1PElement(int, int);
    double Get2PElement(int, int, int, int);

    const arma::Mat<int>    *GetConfig(int, int);
    const arma::Col<double> *Get1PHam(int, int);
    const arma::Mat<double> *Get2PHam(int, int);


    private:

    // Variables
    int                             iShells;    // Number of shells
    int                             iStates;    // Number of quantum states |0> |1> ... |n>
    int                             iFM;        // One block only M total
    int                             iFMs;       // One block only Spinn total
    bool                            bEnergyCut; // Use Energy Cut?
    double                          dLambda;    // Lambda value for QDot2D VEff
    bool                            bCache;     // Is the Hamiltonian in memory?

    // Other Variables
    std::stringstream               ssOut;      // stdout and log string
    std::stringstream               ssCache;    // Cache directory for quick loading

    // Objects
    Log                            *oOut;       // Logfile
    quantumdot::QdotInteraction    *oOFCI;      // OpenFCI Object

    // Initial Objects
    arma::Mat<int>                  mStates;    // Holds qunatum numbers for all states   :: 3xN Matrix
    std::vector<double>             vLogFac;    // Temp vector for log(n!)
    std::vector<double>             vLGamma;    // Temp vector for analytic gamma values

    // Hamiltonian
    arma::Col<double>               m1PHam;     // 1-Particle Hamiltonian (not cached)    :: Column (Diagonal)
    arma::field<arma::Mat<double> > mBlHam;     // Blockdiagonal 1+2-Particle Hamiltonian :: Field of Matrices
    arma::field<arma::Mat<int> >    mConfig;    // Allowed Configurations                 :: Field of 2xN Matrices
    arma::Mat<int>                  mMap;       // Mapping between mStates and m2PHam     :: 2xN Matrix

    /*
    ** Private functions
    */

    // Returns the Lambda value from M and Ms
    int fMapLambda(int iM, int iMs) {return (6*iM + 12*iShells + iMs - 10)/2;};

    // Functions in modQDot2D.cpp
    double fCalcElementQ2DOpenFCI(int, int, int, int);
    double fCalcElementQ2D(int, int, int, int);
    double fCoulomb2D(int, int, int, int, int, int, int, int);
    double fLGamma(double);

};

} // End namespace tardis

#endif
