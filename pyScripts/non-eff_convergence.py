#!/usr/bin/env python

from numpy import array, zeros, ones, linspace
from matplotlib.pyplot import *

# Data

aShell = zeros(14,int)
aEff   = ones(14,float)
aStd   = zeros(14,float)

aEff *= 1

i = 0

aShell[i] = 2
aStd[i]   = 2.167961058
i += 1
aShell[i] = 3
aStd[i]   = 1.832656572
i += 1
aShell[i] = 4
aStd[i]   = 1.716042873
i += 1
aShell[i] = 5
aStd[i]   = 1.713442914
i += 1
aShell[i] = 6
aStd[i]   = 1.69166743
i += 1
aShell[i] = 7
aStd[i]   = 1.691088429
i += 1
aShell[i] = 8
aStd[i]   = 1.690771968
i += 1
aShell[i] = 9
aStd[i]   = 1.690560657
i += 1
aShell[i] = 10
aStd[i]   = 1.690411826
i += 1
aShell[i] = 12
aStd[i]   = 1.690217711
i += 1
aShell[i] = 14
aStd[i]   = 1.690093445
i += 1
#~ aShell[i] = 16
#~ aStd[i]   = 0
#~ i += 1
#~ aShell[i] = 18
#~ aStd[i]   = 0
#~ i += 1
#~ aShell[i] = 20
#~ aStd[i]   = 0

# Plots

fig0 = figure()
plot0 = fig0.add_subplot(1,1,1)

plot0.set_title("")
plot0.set_xlabel("Shells")
plot0.set_ylabel("$E_{0} (\hbar\omega)$")
plot0.plot(aShell, aStd, ' ', marker='s', markersize=8, mfc='black', mec='black', label='$V_{\mbox{std}}$')
#~ plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((3,20))
plot0.set_ylim((1.68,1.72))

xax = plot0.xaxis
xax.set_ticks(linspace(3, 20, 18))


show()
