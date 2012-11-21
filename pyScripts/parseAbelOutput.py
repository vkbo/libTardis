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

aTemp  = [0,0,0,0,0]
aAll   = [0,0,0,0,0]

iPrev  = 0
iStart = 0
iStop  = 0
iNodes = 0
iWait  = 0
iMerge = 0
iCalc  = 0
iIt    = 0

for sLine in oInput:
    sLine = sLine.strip()

    if sLine[:18] == "Starting Lanczos: ":
        iStart = int(mktime(strptime(sLine[18:], "%a %b %d %H:%M:%S %Y")))

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
        iStop    = aTemp[3]
        aAll[3]  = 1

    if sLine[:7]  == "Times: ":
        aLoads = sLine[7:].split(",")
        iNodes = len(aLoads)
        for j in range(iNodes):
            aLoad     = aLoads[j].split(":")
            aLoads[j] = int(aLoad[1])
        iMax = max(aLoads)
        for j in range(iNodes):
            iWait += iMax - aLoads[j]
        iCalc += sum(aLoads)
        aAll[4] = 1

    if sum(aAll) == 5:
        iIt += 1
        if iPrev > 0:
            iMerge += aTemp[0] - iPrev
        iPrev  = aTemp[3]
        aTemp  = [0,0,0,0,0]
        aAll   = [0,0,0,0,0]
        #~ print iCorr

iTotal  = (iStop-iStart) * iNodes
#~ iMerge *= iNodes
iComm   = iTotal-iCalc-iWait-iMerge

print "Nodes:         %7.d" %(iNodes)
print "Iterations:    %7.d" %(iIt)
print "CPU Time:      %7.d seconds (%6.2f%%)" %(iTotal, 100.0)
print "Calculating:   %7.d seconds (%6.2f%%)" %(iCalc, 100.0*iCalc/iTotal)
print "Communicating: %7.d seconds (%6.2f%%)" %(iComm, 100.0*iComm/iTotal)
print "Waiting:       %7.d seconds (%6.2f%%)" %(iWait, 100.0*iWait/iTotal)
print "Merging:       %7.d seconds (%6.2f%%)" %(iMerge, 100.0*iMerge/iTotal)
print ""

oInput.close()

