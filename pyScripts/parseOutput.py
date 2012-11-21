#!/usr/bin/env python

##
## o-------------------------o
## |     parseOutput.py      |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

from sys  import exit, argv
from math import floor


if len(argv) == 2:
    sInput = argv[1]
else:
    print "Input file missing ..."
    exit()

oInput = open(sInput, "r")
dTime  = 0.0
print ""

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

        # Find Time
        iStart = sLine.find("Exec: ")
        iStop  = len(sLine)
        sTm = sLine[iStart+6:iStop].strip()
        sTm = sTm.replace("ms", "*0.001")
        sTm = sTm.replace("s", " +")
        sTm = sTm.replace("m", "*60 +")
        sTm = sTm.replace("h", "*3600 +")
        sTm = sTm.replace("d", "*86400 +")
        dTm = eval(sTm)
        dTime += dTm

        # Generate Output
        # Alter these lines to desired format
        print "aXSpin"+sMs+"["+sM+"] = "+sEn

print ""
print "Total time:"
print "Seconds: "+str(round(dTime,0))
print "Hours:   "+str(round(dTime/3600,2))
print "4 Cores: "+str(int(round(dTime/3600,0)*4))
print "6 Cores: "+str(int(round(dTime/3600,0)*6))
print "8 Cores: "+str(int(round(dTime/3600,0)*8))

dTime  = round(dTime,0)
iDays  = int(floor(dTime/86400))
dTime -= iDays*86400
iHours = int(floor(dTime/3600))
dTime -= iHours*3600
iMin   = int(floor(dTime/60))
dTime -= iMin*60
iSec   = int(dTime)
dTime -= iSec

print "Time:    "+str(iDays)+":"+("0"+str(iHours))[-2:]+":"+("0"+str(iMin))[-2:]+":"+("0"+str(iSec))[-2:]
print ""

oInput.close()
       
