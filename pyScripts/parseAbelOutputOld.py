#!/usr/bin/env python

##
## o-------------------------o
## |   parseAbelOutput.py    |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

from sys  import exit, argv
from math import floor
from time import strptime, mktime

if len(argv) == 2:
    sInput = argv[1]
else:
    print "Input file missing ..."
    exit()

oInput = open(sInput, "r")
dTime  = 0.0
print ""

aTimes = [0,0,0,0]
aTemp  = [0,0,0,0]
aAll   = [0,0,0,0]

for sLine in oInput:
    sLine = sLine.strip()
    if sLine[:26] == "Starting new iterations : ":
        aTemp[0] = int(mktime(strptime(sLine[26:], "%a %b %d %H:%M:%S %Y")))
        aAll[0]  = 1
    if sLine[:26] == "Done broadcasting       : ":
        aTemp[1] = int(mktime(strptime(sLine[26:], "%a %b %d %H:%M:%S %Y")))
        aAll[1]  = 1
    if sLine[:26] == "Done calculating        : ":
        aTemp[2] = int(mktime(strptime(sLine[26:], "%a %b %d %H:%M:%S %Y")))
        aAll[2]  = 1
    if sLine[:26] == "Done receiving          : ":
        aTemp[3] = int(mktime(strptime(sLine[26:], "%a %b %d %H:%M:%S %Y")))
        aAll[3]  = 1
    if sum(aAll) == 4:
        aTimes[0] += 1
        aTimes[1] += aTemp[1] - aTemp[0]
        aTimes[2] += aTemp[2] - aTemp[1]
        aTimes[3] += aTemp[3] - aTemp[2]
        aTemp  = [0,0,0,0]
        aAll   = [0,0,0,0]

iTotal = aTimes[1]+aTimes[2]+aTimes[3]
print "Iterations:    %7.d" %(aTimes[0])
print "Total:         %7.d seconds (%6.2f%%)" %(iTotal, 100.0)
print "Calculating:   %7.d seconds (%6.2f%%)" %(aTimes[2], 100.0*aTimes[2]/iTotal)
print "Communicating: %7.d seconds (%6.2f%%)" %(aTimes[1]+aTimes[3], 100.0*(aTimes[1]+aTimes[3])/iTotal)
print ""

oInput.close()

