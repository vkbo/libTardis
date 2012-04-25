/*
** ~ libTardis ~
**
** Class :: Potential
*/

#ifndef CLASS_POTENTIAL_HPP

#define CLASS_POTENTIAL_HPP
#include "../libTardis.hpp"
#include "../System/classLog.hpp"

namespace tardis {

class Potential
{
    public:

    // Constructor and Destructor
    Potential(int, Log*) {};
    virtual ~Potential() {};

    // Public Functions
    virtual void Load(int)           {return;};
    virtual void Generate(int)       {return;};
    virtual void LoadOrGenerate(int) {return;};

    // Setters
    virtual void SetCache(const char*) {return;};

    // Getters, Setters and Output
    virtual int  GetShells()        {return -1;};
    virtual int  GetStates()        {return -1;};
    virtual int  GetState(int, int) {return -1;};

    virtual double Get1PElement(int, int)           {return -1.0;};
    virtual double Get2PElement(int, int, int, int) {return -1.0;};

    virtual const arma::Col<double> *Get1PHam(int, int) {return NULL;};
    virtual const arma::Mat<double> *Get2PHam(int, int) {return NULL;};
};

} // End namespace tardis

#endif
