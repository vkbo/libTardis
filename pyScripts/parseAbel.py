#!/usr/bin/env python

##
## o-------------------------o
## |      parseAbel.py       |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

from   sys  import exit, argv
from   os   import listdir
from   math import floor
import re

if len(argv) == 2:
    sInput = argv[1]
else:
    print "Input folder missing ..."
    exit()

aRun   = []
aSlurm = []
for sObject in listdir(sInput):
    if sObject[:4] == "Run-":
        aRun.append(sObject)
    if sObject[:6] == "slurm-":
        aSlurm.append(sObject)

aRun.sort()
aSlurm.sort()

sPlot  = ""
sLaTeX = ""

for sRun in aRun:
    oFile = open(sInput+"/"+sRun)
    sFile = oFile.read()
    oFile.close()
    sM = ""
    sS = ""
    sE = "-1"
    aTemp = re.findall(r"Total M\:\s+([0-9]+)", sFile)
    if len(aTemp) > 0: sM = aTemp[0]
    aTemp = re.findall(r"Total Spin\:\s+([0-9]+)", sFile)
    if len(aTemp) > 0: sS = aTemp[0]
    aTemp = re.findall(r"Energy\:\s+([0-9]+\.+[0-9]+)", sFile)
    if len(aTemp) > 0: sE = aTemp[0]
    if int(sM) < 10:
        sPlot += "aXSpin"+sS+"["+sM+"]  = "+sE+"\n"
        sM = " "+sM
    else:
        sPlot += "aXSpin"+sS+"["+sM+"] = "+sE+"\n"
    if sS == "8":
        sPlot += "\n"

    if sE == "-1":
        sE = "--       "
    else:
        sE = str(round(float(sE),5)).ljust(9,"0")

    if sS == "0":
        sLaTeX += sM+" & "+sE
    elif sS == "8":
        sLaTeX += " & "+sE+" \\\\\n"
    else:
        sLaTeX += " & "+sE


print ""
print sPlot
print sLaTeX

dTime = 0.0
for sSlurm in aSlurm:
    oFile = open(sInput+"/"+sSlurm)
    sFile = oFile.read()
    oFile.close()
    aTemp = re.findall(r"\s{2}([0-9]{2}\:[0-9]{2}\:[0-9]{2})", sFile)
    if len(aTemp) > 0: sT = aTemp[0]
    dTime += int(sT[:2])*3600 + int(sT[3:5])*60 + int(sT[6:8])

print "Total time:"
print "Seconds:  "+str(round(dTime,0))
print "Hours:    "+str(round(dTime/3600,2))
print "4  Cores: "+str(int(round(dTime/3600,0)*4))
print "6  Cores: "+str(int(round(dTime/3600,0)*6))
print "8  Cores: "+str(int(round(dTime/3600,0)*8))
print "16 Cores: "+str(int(round(dTime/3600,0)*16))

dTime  = round(dTime,0)
iDays  = int(floor(dTime/86400))
dTime -= iDays*86400
iHours = int(floor(dTime/3600))
dTime -= iHours*3600
iMin   = int(floor(dTime/60))
dTime -= iMin*60
iSec   = int(dTime)
dTime -= iSec

print "Time:     "+str(iDays)+":"+("0"+str(iHours))[-2:]+":"+("0"+str(iMin))[-2:]+":"+("0"+str(iSec))[-2:]
print ""
