##
## o-------------------------o
## |     incFunctions.py     |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

import os
from math  import ceil

#
#  Function for reading job files
#

def fReadJobFile(sFile):

    aReturn = list()

    file = open(sFile, 'r')
    aLines = file.read().splitlines()
    file.close()

    for sLine in aLines:
        if sLine.startswith("//#") and sLine.strip() != "":
            aReturn.append(sLine[3:].strip())

    return aReturn

# End fReadJobFile


#
#  Function for extracting an option value
#

def fGetOption(sFind, aOptions, sDefault=""):
    for sOption in aOptions:
        aTemp = sOption.split(":")
        if len(aTemp) == 2:
            if aTemp[0].strip().lower() == sFind.lower():
                return aTemp[1].strip()
    return sDefault

# End fGetOption


#
#  Check if directory exist, if not make it
#

def fDirX(sDir):

    if not os.path.exists(sDir):
        try:
            os.makedirs(sDir)
            return True
        except:
            print "Failed to make directory: "+sDir
            return False
    else:
        return True

# End fDirX


#
#  Output to log and stdout
#

def fEcho(sOutput, sFile):

    file = open(sFile, 'a')
    file.write(sOutput+"\n")
    print sOutput
    file.close()
    return True

# End fEcho

#
#  Jobfile generator
#

def fJobFile(iShells, iParticles, iM, iMs, dOmega, dLambda, bEnergyCut, bEffective, iMethod, bCalcCoeff=False, sCoeffPath=""):
    sOutput  = "//# Threads : 1\n"
    sOutput += "//# Slater : "+str(int((1+ceil(iShells*(iShells+1)/64))*64))+"\n"
    sOutput += "\n"
    sOutput += "#include <cstdlib>\n"
    sOutput += "#include <iostream>\n"
    sOutput += "#include <fstream>\n"
    sOutput += "#include "+chr(34)+"../libTardis/libTardis.hpp"+chr(34)+"\n"
    sOutput += "\n"
    sOutput += "using namespace std;\n"
    sOutput += "using namespace tardis;\n"
    sOutput += "\n"
    sOutput += "int main(int argc, char* argv[]) {\n"
    sOutput += "\n"
    sOutput += "    stringstream ssOut;\n"
    sOutput += "\n"
    sOutput += "    int    iShells    = "+str(iShells)+";\n"
    sOutput += "    int    iParticles = "+str(iParticles)+";\n"
    sOutput += "    int    iM         = "+str(iM)+";\n"
    sOutput += "    int    iMs        = "+str(iMs)+";\n"
    if bEnergyCut:
        sOutput += "    bool   bEnergyCut = true;\n"
    else:
        sOutput += "    bool   bEnergyCut = false;\n"
    sOutput += "\n"
    sOutput += "    double dOmega     = "+str(dOmega)+";\n"
    sOutput += "    double dLambda    = "+str(dLambda)+";\n"
    sOutput += "\n"
    sOutput += "    System *oSystem = new System();\n"
    sOutput += "    if(argc > 1) oSystem->SetLogFile(argv[1]);\n"
    sOutput += "\n"
    sOutput += "    ofstream oOutput;\n"
    sOutput += "    oOutput.open("+chr(34)+"tempQueue/output.txt"+chr(34)+");\n"
    sOutput += "\n"
    sOutput += "    ssOut << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"System Config:"+chr(34)+" << endl;\n"
    sOutput += "    ssOut << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"Shells:     "+chr(34)+" << iShells << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"Particles:  "+chr(34)+" << iParticles << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"Total M:    "+chr(34)+" << iM << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"Total Spin: "+chr(34)+" << iMs << endl;\n"
    #~ sOutput += "    if(bEnergyCut) {\n"
    #~ sOutput += "        ssOut << "+chr(34)+"Energy Cut: "+chr(34)+" << iEMax << endl;\n"
    #~ sOutput += "    }\n"
    sOutput += "    ssOut << "+chr(34)+"Omega:      "+chr(34)+" << dOmega << endl;\n"
    sOutput += "    ssOut << "+chr(34)+"Lambda:     "+chr(34)+" << dLambda << endl;\n"
    sOutput += "    ssOut << endl;\n"
    sOutput += "    oSystem->GetLog()->Output(&ssOut);\n"
    sOutput += "\n"
    if bEffective:
        sOutput += "    oSystem->SetPotential(iShells, QDOT2D, Q2D_EFFECTIVE);\n"
    else:
        sOutput += "    oSystem->SetPotential(iShells, QDOT2D, Q2D_NORMAL);\n"
    sOutput += "    oSystem->SetParticles(iParticles);\n"
    sOutput += "    oSystem->SetQNumber(QN_M, iM);\n"
    sOutput += "    oSystem->SetQNumber(QN_MS, iMs);\n"
    #~ sOutput += "    oSystem->SetQNumber(QN_EMAX, iEMax);\n"
    sOutput += "    oSystem->SetVariable(VAR_LAMBDA, dLambda);\n"
    sOutput += "    oSystem->SetVariable(VAR_OMEGA, dOmega);\n"
    sOutput += "    oSystem->EnableEnergyCut(bEnergyCut);\n"

    if iMethod == 0:
        sOutput += "    oSystem->BuildPotential();\n"
        sOutput += "    oSystem->BuildBasis();\n"
        sOutput += "\n"
        sOutput += "    Lanczos oLanczos(oSystem);\n"
        if bCalcCoeff:
            sOutput += "    double dEnergy = oLanczos.Run(LZ_COEFF_CALC);\n"
            sOutput += "    oSystem->SortBasis(20);\n"
            sOutput += "    oSystem->SaveBasis("+chr(34)+sCoeffPath+chr(34)+", SAVE_COEFF_ASC);\n"
        else:
            sOutput += "    double dEnergy = oLanczos.Run();\n"
        sOutput += "\n"

    if iMethod == 1:
        sOutput += "    oSystem->BuildPotentialBlock();\n"
        sOutput += "\n"
        sOutput += "    Diag oDiag(oSystem);\n"
        sOutput += "    double dEnergy = oDiag.Run();\n"
        sOutput += "\n"

    sOutput += "    cout << "+chr(34)+"Energy: "+chr(34)+" << setprecision(10) << setw(11) << dEnergy << endl;\n"
    sOutput += "    oOutput << "+chr(34)+"P "+str(iParticles)+", "+chr(34)+";\n"
    sOutput += "    oOutput << "+chr(34)+"Sh "+str(iShells)+", "+chr(34)+";\n"
    sOutput += "    oOutput << "+chr(34)+"M "+str(iM)+", "+chr(34)+";\n"
    sOutput += "    oOutput << "+chr(34)+"Ms "+str(iMs)+", "+chr(34)+";\n"
    sOutput += "    oOutput << "+chr(34)+"Om "+str(dOmega)+", "+chr(34)+";\n"
    sOutput += "    oOutput << "+chr(34)+"Lm "+str(dLambda)+", "+chr(34)+";\n"

    if bEnergyCut:
        sOutput += "    oOutput << "+chr(34)+"ECut, "+chr(34)+";\n"
    else:
        sOutput += "    oOutput << "+chr(34)+"NoECut, "+chr(34)+";\n"

    if bEffective:
        sOutput += "    oOutput << "+chr(34)+"Veff, "+chr(34)+";\n"
    else:
        sOutput += "    oOutput << "+chr(34)+"Vstd, "+chr(34)+";\n"

    if iMethod == 0:
        sOutput += "    oOutput << "+chr(34)+"Lz"+chr(34)+";\n"
    if iMethod == 1:
        sOutput += "    oOutput << "+chr(34)+"Di"+chr(34)+";\n"

    sOutput += "    oOutput << "+chr(34)+"\\t | Energy: "+chr(34)+" << setprecision(10) << setw(11) << dEnergy << endl;\n"
    sOutput += "\n"
    sOutput += "    oOutput.close();\n"
    sOutput += "\n"
    sOutput += "    return 0;\n"
    sOutput += "}\n"
    return sOutput

# End fJobFile

#
#  Abel JobScript
#

def fJobScript(sJobName, sExecName, sTime):
    sOutput  = "#!/bin/bash\n"
    sOutput += "#SBATCH --job-name="+sJobName+"\n"
    sOutput += "#SBATCH --account=nn2977k\n"
    sOutput += "#SBATCH --time='"+sTime+"'\n"
    sOutput += "#SBATCH --mem-per-cpu=3900M\n"
    sOutput += "#SBATCH --nodes=1\n"
    sOutput += "#SBATCH --ntasks-per-node=1\n"
    sOutput += "#SBATCH --cpus-per-task=16\n"
    sOutput += "#SBATCH --exclude="+chr(34)+"c[10-13]-[1-36],c[15-18]-[1-36]"+chr(34)+"\n"
    sOutput += "source /cluster/bin/jobsetup\n"
    sOutput += "module load intel\n"
    sOutput += "module load openmpi.intel\n"
    sOutput += "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usit/abel/u1/frankol/usr/lib64\n"
    sOutput += "export OMP_NUM_THREADS=16\n"
    sOutput += "OUTFILE=Run-"+sJobName+".out\n"
    sOutput += "chkfile $OUTFILE\n"
    sOutput += "mpirun "+sExecName+" > $OUTFILE\n"
    return sOutput

# End fJobScript
