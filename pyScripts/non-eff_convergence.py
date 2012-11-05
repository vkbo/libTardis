#!/usr/bin/env python

from numpy import array, zeros, ones, linspace
from matplotlib.pyplot import *

# Data

aShell = zeros(15,int)
aEff   = ones(15,float)
aStd   = zeros(15,float)

aEff *= 1.689602226

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
aShell[i] = 16
aStd[i]   = 1.690008427
i += 1
aShell[i] = 18
aStd[i]   = 1.689947229
i += 1
aShell[i] = 20
aStd[i]   = 1.689899631
i += 1
aShell[i] = 22

# Plots

fig0 = figure()
plot0 = fig0.add_subplot(1,1,1)

plot0.set_title("Convergence of Standard Interactions")
plot0.set_xlabel("Shells")
plot0.set_ylabel("$E_{0} (\hbar\omega)$")
plot0.plot(aShell, aStd, ' ', marker='s', markersize=8, mfc='white', mec='black', label='$V_{std}$')
plot0.plot(aShell, aEff, 'r--', label='$V_{eff}$')
plot0.legend(bbox_to_anchor=(0.80, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((3,21))
plot0.set_ylim((1.685,1.72))

xax = plot0.xaxis
xax.set_ticks(linspace(3, 20, 18))


show()
