#!/usr/bin/env python

##
## o-------------------------o
## |     parseOutput.py      |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

#~ import subprocess
#~ from   platform     import node
#~ from   time         import time
#~ from   datetime     import datetime
#~ from   math         import floor
#~ from   os           import listdir, path
from   sys          import exit, argv
#~ from   incFunctions import *


if len(argv) == 3:
    sInput  = argv[1]
    sOutput = argv[2]
else:
    print "Input or putput file missing ..."
    exit()

oInput  = open(sInput,  "r")
oOutput = open(sOutput, "w")

for sLine in oInput:
    if sLine[:2] == "20":
        sLine = sLine[sLine.find("|", 22):]
        
        # Find Particles
        iStart = sLine.find("P ")
        iStop  = sLine.find(",", iStart)
        sP = sLine[iStart+2:iStop]

        # Find Shells
        iStart = sLine.find("Sh ")
        iStop  = sLine.find(",", iStart)
        sSh = sLine[iStart+3:iStop]

        # Find M
        iStart = sLine.find("M ")
        iStop  = sLine.find(",", iStart)
        sM = sLine[iStart+2:iStop]

        # Find Ms
        iStart = sLine.find("Ms ")
        iStop  = sLine.find(",", iStart)
        sMs = sLine[iStart+3:iStop]

        # Find Omega
        iStart = sLine.find("Om ")
        iStop  = sLine.find(",", iStart)
        sOm = sLine[iStart+3:iStop]

        # Find Lambda
        iStart = sLine.find("Lm ")
        iStop  = sLine.find(",", iStart)
        sLm = sLine[iStart+3:iStop]

        # Find Energy
        iStart = sLine.find("Energy: ")
        iStop  = sLine.find(chr(9), iStart)
        sEn = sLine[iStart+8:iStop].strip()

        # Generate Output
        # Alter these lines to desired format
        sOutput = "aXSpin"+sMs+"["+sM+"] = "+sEn+"\n"

        oOutput.write(sOutput)





        
