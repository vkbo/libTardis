#!/usr/bin/env python

##
## o--------------------------o
## |       makeJobs.py        |
## | ~~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis     |
## o--------------------------o
##

from   incFunctions import *

aShells    = [2,3,4,5,6,7,8,9,10]
aParticles = [2]
aM         = [0]
aMs        = [0]
aOmega     = [0.1]
aLambda    = [0.0]
aEnergyCut = [False]
aEffective = [True]
aMethod    = [0]

for bEffective in aEffective:
    for bEnergyCut in aEnergyCut:
        for dLambda in aLambda:
            for dOmega in aOmega:
                for iMs in aMs:
                    for iM in aM:
                        for iParticles in aParticles:
                            for iShells in aShells:
                                for iMethod in aMethod:

                                    sFile  = str(iParticles).zfill(2)+"P"
                                    sFile += "_"+str(iShells).zfill(2)+"Sh"

                                    if dLambda > 0:
                                        sFile += "_"+str(dLambda).zfill(4)+"L"

                                    if dOmega > 0:
                                        sFile += "_"+str(dOmega).zfill(4)+"O"

                                    sFile += "_"+str(iM).zfill(2)+"M"
                                    sFile += "_"+str(iMs).zfill(2)+"Ms"

                                    if bEnergyCut:
                                        sFile += "_ECut"
                                    else:
                                        sFile += "_NoECut"

                                    if bEffective:
                                        sFile += "_Veff"
                                    else:
                                        sFile += "_Vstd"

                                    if iMethod == 0:
                                        sFile += "_Lz"
                                    else:
                                        sFile += "_Di"

                                    sFile += ".cpp"

                                    print "Making file: jobQueue/"+sFile
                                    oFile = open("jobQueue/"+sFile, 'w')
                                    oFile.write(fJobFile(iShells, iParticles, iM, iMs, dOmega, dLambda, bEnergyCut, bEffective, iMethod))
                                    oFile.close()
