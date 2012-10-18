#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aEnergy   = zeros(62,float)
aConverge = zeros(62,float)

aEnergy[0]    = 36.11494532
aConverge[0]  = 1.00
aEnergy[1]    = 33.06052494
aConverge[1]  = 0.0924
aEnergy[2]    = 30.97090760
aConverge[2]  = 0.0675
aEnergy[3]    = 29.46998986
aConverge[3]  = 0.0509
aEnergy[4]    = 28.25429218
aConverge[4]  = 0.0430
aEnergy[5]    = 27.16717338
aConverge[5]  = 0.0400
aEnergy[6]    = 26.39168385
aConverge[6]  = 0.0294
aEnergy[7]    = 25.78017594
aConverge[7]  = 0.0237
aEnergy[8]    = 25.22878744
aConverge[8]  = 0.0219
aEnergy[9]    = 24.78250483
aConverge[9]  = 0.0180
aEnergy[10]   = 24.39865542
aConverge[10] = 0.0157
aEnergy[11]   = 24.10029409
aConverge[11] = 0.0124
aEnergy[12]   = 23.91554036
aConverge[12] = 0.00773
aEnergy[13]   = 23.81397201
aConverge[13] = 0.00427
aEnergy[14]   = 23.75641254
aConverge[14] = 0.00242
aEnergy[15]   = 23.72419559
aConverge[15] = 0.00136
aEnergy[16]   = 23.70558331
aConverge[16] = 0.000785
aEnergy[17]   = 23.69525401
aConverge[17] = 0.000436
aEnergy[18]   = 23.69009712
aConverge[18] = 0.000218
aEnergy[19]   = 23.68709268
aConverge[19] = 0.000127
aEnergy[20]   = 23.68530500
aConverge[20] = 7.55e-05
aEnergy[21]   = 23.68417467
aConverge[21] = 4.77e-05
aEnergy[22]   = 23.68340038
aConverge[22] = 3.27e-05
aEnergy[23]   = 23.68292383
aConverge[23] = 2.01e-05
aEnergy[24]   = 23.68259947
aConverge[24] = 1.37e-05
aEnergy[25]   = 23.68235539
aConverge[25] = 1.03e-05
aEnergy[26]   = 23.68214481
aConverge[26] = 8.89e-06
aEnergy[27]   = 23.68191390
aConverge[27] = 9.75e-06
aEnergy[28]   = 23.68159029
aConverge[28] = 1.37e-05
aEnergy[29]   = 23.68104645
aConverge[29] = 2.30e-05
aEnergy[30]   = 23.68006489
aConverge[30] = 4.15e-05
aEnergy[31]   = 23.67799052
aConverge[31] = 8.76e-05
aEnergy[32]   = 23.67352359
aConverge[32] = 0.000189
aEnergy[33]   = 23.66542899
aConverge[33] = 0.000342
aEnergy[34]   = 23.65690875
aConverge[34] = 0.000360
aEnergy[35]   = 23.65054904
aConverge[35] = 0.000269
aEnergy[36]   = 23.64570931
aConverge[36] = 0.000205
aEnergy[37]   = 23.64243819
aConverge[37] = 0.000138
aEnergy[38]   = 23.64057535
aConverge[38] = 7.88e-05
aEnergy[39]   = 23.63960129
aConverge[39] = 4.12e-05
aEnergy[40]   = 23.63916863
aConverge[40] = 1.83e-05
aEnergy[41]   = 23.63896580
aConverge[41] = 8.58e-06
aEnergy[42]   = 23.63885951
aConverge[42] = 4.50e-06
aEnergy[43]   = 23.63879814
aConverge[43] = 2.60e-06
aEnergy[44]   = 23.63876246
aConverge[44] = 1.51e-06
aEnergy[45]   = 23.63874064
aConverge[45] = 9.23e-07
aEnergy[46]   = 23.63872906
aConverge[46] = 4.90e-07
aEnergy[47]   = 23.63872325
aConverge[47] = 2.46e-07
aEnergy[48]   = 23.63872040
aConverge[48] = 1.21e-07
aEnergy[49]   = 23.63871894
aConverge[49] = 6.18e-08
aEnergy[50]   = 23.63871823
aConverge[50] = 2.99e-08
aEnergy[51]   = 23.63871785
aConverge[51] = 1.60e-08
aEnergy[52]   = 23.63871759
aConverge[52] = 1.13e-08
aEnergy[53]   = 23.63871743
aConverge[53] = 6.69e-09
aEnergy[54]   = 23.63871734
aConverge[54] = 3.77e-09
aEnergy[55]   = 23.63871729
aConverge[55] = 2.20e-09
aEnergy[56]   = 23.63871725
aConverge[56] = 1.43e-09
aEnergy[57]   = 23.63871723
aConverge[57] = 9.54e-10
aEnergy[58]   = 23.63871722
aConverge[58] = 6.37e-10
aEnergy[59]   = 23.63871721
aConverge[59] = 3.64e-10
aEnergy[60]   = 23.63871720
aConverge[60] = 1.92e-10
aEnergy[61]   = 23.63871720
aConverge[61] = 9.88e-11

# Plots

fig0 = figure()
plot0 = fig0.add_subplot(1,2,1)

plot0.set_title("Energy Convergence")
plot0.set_xlabel("Iteration")
plot0.set_ylabel("Energy ($\hbar \omega$)")
plot0.plot(aEnergy, 'b')
#plot0.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot0.set_xlim((0,61))
#plot0.set_ylim((0.4406,0.4420001))

xax = plot0.xaxis
#xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


plot1 = fig0.add_subplot(1,2,2)

plot1.set_title("Energy Convergence - Zoomed")
plot1.set_xlabel("Iteration")
plot1.set_ylabel("Energy ($\hbar \omega$)")
plot1.plot(aEnergy, 'r')
#plot1.plot(aConverge, 'b',  label='Lanczos, Eff. Int. + ECut')
#plot1.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot1.set_xlim((10,61))
plot1.set_ylim((23.6,24.0))

xax = plot1.xaxis
#xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


show()
