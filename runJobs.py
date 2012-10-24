#!/usr/bin/env python

##
## o-------------------------o
## |       runJobs.py        |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

import subprocess
from   platform     import node
from   time         import time
from   datetime     import datetime
from   math         import floor
from   os           import listdir, path, rename
from   sys          import exit, argv
from   incFunctions import *


# General Settings
#------------------
sExec       = "CISD"                 # Name of executable
sResultFile = "tempQueue/output.txt" # Exec result file


# Automatic Settings
#--------------------
sNode = node().strip()

if len(argv) > 1:
    sComment = argv[1]
else:
    sComment = "No comment"


# Initialisation
#----------------
print ""
print "Running on node: "+sNode

# Creating Directories
sMainLog = "jobLogs/"+sNode+"_"+datetime.today().strftime("%Y-%m-%d")+".log"
sLogSep  = chr(9)+"| "

if not fDirX("jobFiles"):      exit()
if not fDirX("jobQueue"):      exit()
if not fDirX("jobQueue/Done"): exit()
if not fDirX("jobLogs"):       exit()
if not fDirX("tempCompile"):   exit()
if not fDirX("tempQueue"):     exit()


iJobs = 0
aJobs = list()
for sObject in listdir("jobQueue"):
    if not path.isdir("jobQueue/"+sObject):
        aJobs.append(sObject)
        iJobs += 1

aJobs.sort()
print "Job Queue has "+str(iJobs)+" jobs"
print ""

oFile = open(sMainLog, 'a')
oFile.write("\n")
oFile.write(" Jobs started at "+datetime.today().strftime("%Y-%m-%d %H:%M:%S")+"\n")
oFile.write(("*"*37)+"\n")
oFile.write(" Comment: "+sComment+"\n")
oFile.write("\n")
oFile.close()


iJob = 0

for sFile in aJobs:

    dNow       = datetime.today()
    sLogDir    = "jobLogs/"+dNow.strftime("%Y/%m/%d")
    if not fDirX(sLogDir): exit()
    sOutFile   = sLogDir+"/"+sNode+"-"+dNow.strftime("%H%M%S")+".out"
    sLogEntry  = dNow.strftime("%Y-%m-%d %H:%M:%S")+sLogSep
    sLogEntry += "Node: "+sNode+sLogSep

    iJob += 1
    sPrint = "Running Job "+str(iJob)+" of "+str(iJobs)+" : "+sFile
    fEcho("o"+("-"*(len(sPrint)+2))+"o",sOutFile)
    fEcho("| "+sPrint+" |",sOutFile)
    fEcho("o"+("-"*(len(sPrint)+2))+"o",sOutFile)
    fEcho("",sOutFile)
    fEcho("TimeStamp: "+datetime.today().strftime("%Y-%m-%d %H:%M:%S"),sOutFile)
    fEcho("",sOutFile)


    # Reading Options
    #-----------------

    fEcho("Reading Settings ...",sOutFile)
    aOptions = fReadJobFile("jobQueue/"+sFile)
    fEcho("",sOutFile)

    iSlater = fGetOption("Slater", aOptions, "64")
    oFile = open("libTardis/slaterword.hpp", 'w')
    oFile.write("#define SLATER_WORD "+iSlater+"\n")
    oFile.close()


    # Compiler
    #----------

    sOldMain = "tempCompile/"+sNode+"/main.o"
    if os.path.exists(sOldMain):
        os.remove(sOldMain)

    sExecName = sExec+"-"+sNode
    iNodes    = fGetOption("Nodes", aOptions, "1")
    if int(iNodes) > 1:
        sCompileString = "make CC=mpic++ LIBADD='-lmpi' NODE="+sNode+" MAIN=jobQueue/"+sFile
    else:
        sCompileString = "make NODE="+sNode+" MAIN=jobQueue/"+sFile

    fEcho(" Calling: "+sCompileString,sOutFile)
    fEcho("*"*(len(sCompileString)+11),sOutFile)
    subprocess.call(sCompileString+" 2>&1 | tee -a "+sOutFile, shell=True)

    sLastLine = open(sOutFile, 'r').readlines()[-1].strip()
    if sLastLine[-7:] == "Error 1" or sLastLine[-5:] == "Stop.":
        fEcho("",sOutFile)
        fEcho("!!! Compiler error !!!",sOutFile)
        fEcho("!!! Aborting !!!",sOutFile)
        fEcho("",sOutFile)
        continue

    fEcho("",sOutFile)
    fEcho("TimeStamp: "+datetime.today().strftime("%Y-%m-%d %H:%M:%S"),sOutFile)
    fEcho("",sOutFile)


    # Execution
    #-----------

    fEcho(" Running Program: "+sExecName,sOutFile)
    fEcho("*"*(len(sExecName)+19),sOutFile)

    if os.path.exists(sResultFile):
        os.remove(sResultFile)

    tExecStart = time()
    if int(iNodes) > 1:
        subprocess.call("mpirun -np "+iNodes+" ./"+sExecName+" "+chr(34)+sOutFile+chr(34), shell=True)
    else:
        subprocess.call("./"+sExecName+" "+chr(34)+sOutFile+chr(34), shell=True)

    tExecStop = time()
    tExecTime = tExecStop-tExecStart

    fEcho("",sOutFile)
    if os.path.exists(sResultFile):
        oFile = open(sResultFile, 'r')
        sResult = oFile.readline().strip()
        oFile.close()
        fEcho(" Result:",sOutFile)
        fEcho("*********",sOutFile)
        fEcho(sResult,sOutFile)
        sResult.replace("\n", " :: ")
        sResult.replace("\r", "")
        sLogEntry += sResult+sLogSep
        
    os.rename("jobQueue/"+sFile, "jobQueue/Done/"+sFile)


    # Timer Output
    #--------------

    sExecTime = ""

    if tExecTime > 86400:
        sExecTime += str(int(floor(tExecTime/86400)))+"d "
        tExecTime %= 86400

    if tExecTime > 3600:
        sExecTime += str(int(floor(tExecTime/3600)))+"h "
        tExecTime %= 3600

    if tExecTime > 60:
        sExecTime += str(int(floor(tExecTime/60)))+"m "
        tExecTime %= 60

    if tExecTime > 1:
        sExecTime += str(int(floor(tExecTime)))+"s "
        tExecTime %= 1

    sExecTime += str(int(floor(tExecTime*1000)))+"ms"
    sLogEntry += "Exec: "+sExecTime

    fEcho("",sOutFile)
    fEcho("TimeStamp: "+datetime.today().strftime("%Y-%m-%d %H:%M:%S"),sOutFile)
    fEcho("",sOutFile)
    fEcho("Execution time: "+sExecTime,sOutFile)
    fEcho("",sOutFile)


    # Job Log
    #---------

    oFile = open(sMainLog, 'a')
    oFile.write(sLogEntry+"\n")
    oFile.close()

    if iJob < iJobs:
        print "*"*100
        print ""
