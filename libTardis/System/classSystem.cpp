/*
** ~ libTardis ~
**
** Class :: System
*/

#include "../libTardis.hpp"

using namespace std;
using namespace arma;
using namespace tardis;

/*
** Public :: Constructor and Destructor
*/

System::System() {

    // Init variables
    iPotType   = QDOT2D;
    iGenType   = Q2D_ANALYTIC;
    iShells    = 4;
    iParticles = 2;
    iStates    = iShells*(iShells+1);

    // Init switches
    bPotType    = false;
    bPotBuilt   = false;
    bBasisBuilt = false;

    // Qunatum Numbers
    iM  = 0;
    iMs = 0;

    // System Variables
    dLambda = 0.0;
    dOmega  = 0.0;

    oOut = new Log();

    return;
}

System::~System() {
    oPot->~Potential();
    oBasis->~Basis();
    oOut->~Log();
}

/*
** Build Functions
*/

bool System::BuildPotential() {

    if(bPotBuilt) {
        ssOut << "Potential already built. Nothing to do." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(!bPotType) {
        ssOut << "Error: Potential not set." << endl;
        ssOut << "       Please run System->SetPotential(...) first." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(ssCache.str().length() > 0) {
        oPot->SetCache(ssCache.str().c_str());
    }

    oPot->LoadOrGenerate(iGenType);
    bPotBuilt = true;

    return true;
}

bool System::BuildBasis() {

    if(bBasisBuilt) {
        ssOut << "Basis already built. Nothing to do." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(!bPotBuilt) {
        ssOut << "Error: Potential missing." << endl;
        ssOut << "       Run System->BuildPotential() first." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(iParticles < 1) {
        ssOut << "Error: Too few particles in system." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    oBasis = new Basis(oPot, oOut, iParticles, iStates);
    oBasis->SetQNumber(QN_M, iM);
    oBasis->SetQNumber(QN_MS, iMs);
    oBasis->BuildBasis();

    return true;
}

/*
** Potential Configuration
*/

bool System::SetPotential(int iNumShells, int iPotential, int iGenerator) {

    bool bOK = false;

    iPotType = iPotential;
    iGenType = iGenerator;
    iShells  = iNumShells;

    if(iPotType == QDOT2D)   bOK = true;
    //if(iPotType == QDOT3D)   bOK = true;
    //if(iPotType == ATOM)     bOK = true;
    //if(iPotType == NUCLEUS)  bOK = true;
    //if(iPotType == HNUCLEUS) bOK = true;

    if(!bOK) {
        ssOut << "Error: Potential type unknown." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(floor(iGenType/10) != iPotType) {
        ssOut << "Error: Generator not compatible with potential." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    if(iNumShells < 1) {
        ssOut << "Error: Too few shells in system." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    switch(iPotType) {
        case QDOT2D:
            oPot = new QDot2D(iShells, oOut);
            iStates = oPot->GetStates();
            bPotType = true;
            break;
    }

    return true;
}

/*
** Basis Configuration
*/

bool System::SetParticles(int iValue) {

    if(iValue < 1) {
        ssOut << "Error: Too few particles in system." << endl;
        oOut->Output(&ssOut);
        return false;
    }

    iParticles = iValue;

    return true;
}

void System::SetCache(const char *cCache) {
    ssCache << cCache;
    return;
}

void System::SetLogFile(const char *cCache) {
    oOut->SetFile(cCache);
    return;
}

/*
** System Configuration
*/

bool System::SetQNumber(int iVar, int iValue) {

    switch(iVar) {
        case QN_M:  iM  = iValue; break;
        case QN_MS: iMs = iValue; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return false;
    }

    return true;
}

bool System::SetVariable(int iVar, double dValue) {

    switch(iVar) {
        case VAR_LAMBDA: dLambda = dValue; break;
        case VAR_OMEGA:  dOmega  = dValue; break;
        default:
            ssOut << "Error: Not a valid System Variable." << endl;
            oOut->Output(&ssOut);
            return false;
    }

    return true;
}

int System::GetQNumber(int iVar) {

    switch(iVar) {
        case QN_M:  return iM;  break;
        case QN_MS: return iMs; break;
        default:
            ssOut << "Error: Not a valid Quantum Number." << endl;
            oOut->Output(&ssOut);
            return -1000;
    }
}

double System::GetVariable(int iVar) {

    switch(iVar) {
        case VAR_LAMBDA: return dLambda; break;
        case VAR_OMEGA:  return dOmega;  break;
        default:
            ssOut << "Error: Not a valid System Variable." << endl;
            oOut->Output(&ssOut);
            return -1.0;
    }
}
