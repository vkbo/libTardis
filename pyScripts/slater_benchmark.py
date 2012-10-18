#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aTime = zeros(31,float)
aBit  = zeros(1025,float)

aTime[0]  = 0
aTime[1]  = 3.009
aTime[2]  = 2.625
aTime[3]  = 2.604
aTime[4]  = 2.594
aTime[5]  = 2.590
aTime[6]  = 2.590
aTime[7]  = 2.585
aTime[8]  = 5.272
aTime[9]  = 5.288
aTime[10] = 5.243
aTime[11] = 7.461
aTime[12] = 7.409
aTime[13] = 7.346
aTime[14] = 10.117
aTime[15] = 10.089
aTime[16] = 12.508
aTime[17] = 12.531
aTime[18] = 14.865
aTime[19] = 14.556
aTime[20] = 17.204
aTime[21] = 19.310
aTime[22] = 19.435
aTime[23] = 21.670
aTime[24] = 24.109
aTime[25] = 26.826
aTime[26] = 26.449
aTime[27] = 29.133
aTime[28] = 31.448
aTime[29] = 33.798
aTime[30] = 35.855

for i in range(0,65):     aBit[i] = 2.590
for i in range(65,129):   aBit[i] = 5.113
for i in range(129,193):  aBit[i] = 7.225
for i in range(193,257):  aBit[i] = 10.022
for i in range(257,321):  aBit[i] = 12.377
for i in range(321,385):  aBit[i] = 14.674
for i in range(385,449):  aBit[i] = 16.952
for i in range(449,513):  aBit[i] = 19.317
for i in range(513,577):  aBit[i] = 21.654
for i in range(577,641):  aBit[i] = 24.159
for i in range(641,705):  aBit[i] = 26.548
for i in range(705,769):  aBit[i] = 28.872
for i in range(769,833):  aBit[i] = 30.988
for i in range(833,897):  aBit[i] = 33.288
for i in range(897,961):  aBit[i] = 35.753
for i in range(961,1025): aBit[i] = 38.139

# Plots

fig0 = figure()
plot0 = fig0.add_subplot(1,2,1)

plot0.set_title("Slater/Bitset Benchmark")
plot0.set_xlabel("Shells")
plot0.set_ylabel("Time (s)")
plot0.plot(aTime, 'b')
plot0.set_xlim((1,30))

xax = plot0.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


plot1 = fig0.add_subplot(1,2,2)

plot1.set_title("Slater/Bitset Benchmark")
plot1.set_xlabel("Orbitals")
plot1.set_ylabel("Time (s)")
plot1.plot(aBit, 'b')
plot1.set_xlim((1,1024))

xax = plot1.xaxis
xax.set_ticks((64,128,192,256,320,384,448,512,576,640,704,768,832,896,960,1024))


show()
