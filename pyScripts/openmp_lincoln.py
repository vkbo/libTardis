#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aOne  = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
aLin  = [1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32]
aJob1 = zeros(33,float)
aJob2 = zeros(33,float)

aJob1[0]  = 60.475
aJob1[1]  = 60.475
aJob1[2]  = 30.361
aJob1[3]  = 20.286
aJob1[4]  = 15.318
aJob1[5]  = 12.205
aJob1[6]  = 10.206
aJob1[7]  =  8.775
aJob1[8]  =  7.682
aJob1[9]  =  6.852
aJob1[10] =  6.171
aJob1[11] =  5.607
aJob1[12] =  5.172
aJob1[13] =  4.783
aJob1[14] =  4.493
aJob1[15] =  4.132
aJob1[16] =  3.895
aJob1[17] =  3.888
aJob1[18] =  3.884
aJob1[19] =  3.874
aJob1[20] =  3.902
aJob1[21] =  3.827
aJob1[22] =  3.869
aJob1[23] =  3.796
aJob1[24] =  3.858
aJob1[25] =  3.817
aJob1[26] =  3.740
aJob1[27] =  3.738
aJob1[28] =  3.733
aJob1[29] =  3.689
aJob1[30] =  3.676
aJob1[31] =  3.675
aJob1[32] =  3.682

aJob2[0]  = 3600 + 17*60 + 15.823
aJob2[1]  = 3600 + 17*60 + 15.823
aJob2[2]  =        38*60 + 37.152
aJob2[3]  =        25*60 + 43.425
aJob2[4]  =        19*60 + 18.012
aJob2[5]  =        15*60 + 27.081
aJob2[6]  =        12*60 + 54.063
aJob2[7]  =        11*60 +  1.998
aJob2[8]  =         9*60 + 43.236
aJob2[9]  =         8*60 + 35.126
aJob2[10] =         7*60 + 43.728
aJob2[11] =         7*60 +  3.100
aJob2[12] =         6*60 + 26.089
aJob2[13] =         5*60 + 56.985
aJob2[14] =         5*60 + 31.266
aJob2[15] =         5*60 +  9.761
aJob2[16] =         4*60 + 51.243
aJob2[17] =         4*60 + 47.712
aJob2[18] =         4*60 + 46.913
aJob2[19] =         4*60 + 44.283
aJob2[20] =         4*60 + 42.485
aJob2[21] =         4*60 + 40.228
aJob2[22] =         4*60 + 39.796
aJob2[23] =         4*60 + 36.437
aJob2[24] =         4*60 + 35.341
aJob2[25] =         4*60 + 33.371
aJob2[26] =         4*60 + 31.020
aJob2[27] =         4*60 + 29.452
aJob2[28] =         4*60 + 27.650
aJob2[29] =         4*60 + 28.645
aJob2[30] =         4*60 + 31.982
aJob2[31] =         4*60 + 22.473
aJob2[32] =         4*60 + 21.024

# Plots

fig0 = figure(figsize=(16, 7), dpi=80)
fig0.suptitle('Multicore Scalability on Server "Lincoln" (32 Cores)')

plot0 = fig0.add_subplot(121)
plot0.set_title("6 shells, 5 electrons, $M=0$, $2s=5$, $\lambda=6$")
plot0.set_xlabel("Cores")
plot0.set_ylabel("$t(1)/t(x)$")
plot0.plot(aLin, 'r-')
plot0.plot(aJob1[1]/aJob1, 'ks', markersize=5, label='$t(1) = $'+str(int(round(aJob1[1])))+' sec')
plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((1,32))
plot0.set_ylim((1,32))

xax = plot0.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32))

plot1 = fig0.add_subplot(122)
plot1.set_title("8 shells, 5 electrons, $M=0$, $2s=5$, $\lambda=6$")
plot1.set_xlabel("Cores")
plot1.set_ylabel("$t(1)/t(x)$")
plot1.plot(aLin, 'r-')
plot1.plot(aJob2[1]/aJob2, 'ks', markersize=5, label='$t(1) = $'+str(int(round(aJob2[1])))+' sec')
plot1.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot1.set_xlim((1,32))
plot1.set_ylim((1,32))

xax = plot1.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32))


show()
