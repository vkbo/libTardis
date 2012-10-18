#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aOne  = [1, 1, 1, 1, 1, 1, 1, 1, 1]
aLin  = [1, 1, 2, 3, 4, 5, 6, 7, 8]
aJob1 = zeros(9,float)
aJob2 = zeros(9,float)
aJob3 = zeros(9,float)
aJob4 = zeros(9,float)

aJob1[0] = 70.348
aJob1[1] = 70.348
aJob1[2] = 45.785
aJob1[3] = 34.992
aJob1[4] = 36.548
aJob1[5] = 49.209
aJob1[6] = 70.781
aJob1[7] = 79.923
aJob1[8] = 89.684

aJob2[0] = 1*3600 + 26*60 + 39.967
aJob2[1] = 1*3600 + 26*60 + 39.967
aJob2[2] =          53*60 +  9.515
aJob2[3] =          38*60 + 19.104
aJob2[4] =          24*60 + 14.848
aJob2[5] =          41*60 + 18.375
aJob2[6] = 1*3600 +  8*60 +  6.961
aJob2[7] = 1*3600 + 22*60 + 13.896
aJob2[8] = 1*3600 + 32*60 + 19.137

aJob3[0] = 66.748
aJob3[1] = 66.748
aJob3[2] = 33.982
aJob3[3] = 22.509
aJob3[4] = 16.925
aJob3[5] = 13.934
aJob3[6] = 11.832
aJob3[7] = 10.187
aJob3[8] =  8.932

aJob4[0] = 1*3600 + 23*60 + 54.696
aJob4[1] = 1*3600 + 23*60 + 54.696
aJob4[2] =          42*60 + 24.614
aJob4[3] =          28*60 +  6.481
aJob4[4] =          21*60 +  6.135
aJob4[5] =          17*60 + 23.285
aJob4[6] =          14*60 + 45.565
aJob4[7] =          12*60 + 45.847
aJob4[8] =          11*60 +  8.552

# Plots

fig0 = figure(figsize=(16, 7), dpi=80)
fig0.suptitle('Multicore Scalability on Server "Gizmo" (8 Cores)')

plot0 = fig0.add_subplot(121)
plot0.set_title("6 shells, 5 electrons, $M=0$, $2s=5$, $\lambda=6$")
plot0.set_xlabel("Cores")
plot0.set_ylabel("$t(1)/t(x)$")
plot0.plot(aOne, 'r-')
plot0.plot(aLin, 'r-')
plot0.plot(aJob1[1]/aJob1, 'k--', marker='s', markersize=8, mfc='white', mec='black', label='Before - $t(1) = $'+str(int(round(aJob1[1])))+' sec')
plot0.plot(aJob3[1]/aJob3, 'k--', marker='s', markersize=8, mfc='black', mec='black', label='After - $t(1) = $'+str(int(round(aJob3[1])))+' sec')
plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((1,8))
plot0.set_ylim((0,8))

plot1 = fig0.add_subplot(122)
plot1.set_title("8 shells, 5 electrons, $M=0$, $2s=5$, $\lambda=6$")
plot1.set_xlabel("Cores")
plot1.set_ylabel("$t(1)/t(x)$")
plot1.plot(aOne, 'r-')
plot1.plot(aLin, 'r-')
plot1.plot(aJob2[1]/aJob2, 'k--', marker='s', markersize=8, mfc='white', mec='black', label='Before - $t(1) = $'+str(int(round(aJob2[1])))+' sec')
plot1.plot(aJob4[1]/aJob4, 'k--', marker='s', markersize=8, mfc='black', mec='black', label='After - $t(1) = $'+str(int(round(aJob4[1])))+' sec')
plot1.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot1.set_xlim((1,8))
plot1.set_ylim((0,8))


show()
