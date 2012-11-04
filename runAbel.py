#!/usr/bin/env python

##
## o-------------------------o
## |       runAbel.py        |
## | ~~~~~~~~~~~~~~~~~~~~~~~ |
## |    Part of libTardis    |
## o-------------------------o
##

import subprocess
from   os           import listdir, path, rename
from   incFunctions import *


# General Settings
#------------------
sExec = "CISD" # Name of executable
sNode = "Abel" # Name of node


# Initialisation
#----------------
print ""
print "Running on node: "+sNode

# Creating Directories
if not fDirX("jobQueue"):    exit()
if not fDirX("jobBuild"):    exit()
if not fDirX("tempCompile"): exit()


iJobs = 0
aJobs = list()
for sObject in listdir("jobQueue"):
    if not path.isdir("jobQueue/"+sObject):
        aJobs.append(sObject)
        iJobs += 1

aJobs.sort()
print "Job Queue has "+str(iJobs)+" jobs"
print ""

iJob = 0

for sFile in aJobs:

    iJob += 1
    print "Building Job "+str(iJob)+" of "+str(iJobs)+" : "+sFile
    print ""
    

    # Compiler
    #----------

    sOldMain = "tempCompile/"+sNode+"/main.o"
    if os.path.exists(sOldMain):
        os.remove(sOldMain)

    sExecName = sExec+"-"+sNode+"-"+str(iJob).zfill(3)
    sJobName  = "Job-"+str(iJob).zfill(3)
    sCompileString = "make CC=icc NODE="+sNode+" MAIN=jobQueue/"+sFile+" EXEC=jobBuild/"+sExecName

    print "Calling: "+sCompileString
    subprocess.call(sCompileString, shell=True)
    print ""

    oFile = open("jobBuild/JobScript-"+sExecName+".sh", "w")
    oFile.write(fJobScript(sJobName, sExecName, "48:00:00"))
    oFile.close()
