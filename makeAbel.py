#!/usr/bin/env python

##
## o---------------------------o
## |        makeAbel.py        |
## | ~~~~~~~~~~~~~~~~~~~~~~~~~ |
## |  Compile script for Abel  |
## |     Part of libTardis     |
## o---------------------------o
##

import subprocess
from   os           import listdir, path
from   incFunctions import *


# General Settings
#------------------
sExec = "CISD"         # Name of executable
sNode = "Abel"         # Name of node
sFile = "mainAbel.cpp" # Abel CPP file

# Initialisation
#----------------
print ""
print "Running on node: "+sNode

# Creating Directories
if not fDirX("tempCompile"): exit()

print "Reading Settings ...\n"
aOptions = fReadJobFile(sFile)

# Compiler
#----------

sOldMain = "tempCompile/"+sNode+"/main.o"
if os.path.exists(sOldMain):
    os.remove(sOldMain)

sExecName = sExec+"-"+sNode
iNodes    = fGetOption("Nodes", aOptions, "1")
if int(iNodes) > 1:
    sCompileString = "make CC=mpicc NODE="+sNode+" MAIN="+sFile+" EXEC="+sExecName
else:
    sCompileString = "make CC=icc NODE="+sNode+" MAIN="+sFile+" EXEC="+sExecName
        
print " Calling: "+sCompileString
print "*"*(len(sCompileString)+11)
subprocess.call(sCompileString, shell=True)
