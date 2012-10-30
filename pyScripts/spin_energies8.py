#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aASpin0 = zeros(31,float)
aASpin2 = zeros(31,float)
aASpin4 = zeros(31,float)
aASpin6 = zeros(31,float)
aASpin8 = zeros(31,float)
aBSpin0 = zeros(31,float)
aBSpin2 = zeros(31,float)
aBSpin4 = zeros(31,float)
aBSpin6 = zeros(31,float)
aBSpin8 = zeros(31,float)
aCSpin0 = zeros(31,float)
aCSpin2 = zeros(31,float)
aCSpin4 = zeros(31,float)
aCSpin6 = zeros(31,float)
aCSpin8 = zeros(31,float)
aDSpin0 = zeros(31,float)
aDSpin2 = zeros(31,float)
aDSpin4 = zeros(31,float)
aDSpin6 = zeros(31,float)
aDSpin8 = zeros(31,float)

# Omega = 0.01 Values

aASpin0[0]  = 0
aASpin2[0]  = 0
aASpin4[0]  = 0
aASpin6[0]  = 0
aASpin8[0]  = 0

aASpin0[1]  = 0
aASpin2[1]  = 0
aASpin4[1]  = 0
aASpin6[1]  = 0
aASpin8[1]  = 0

aASpin0[2]  = 0
aASpin2[2]  = 0
aASpin4[2]  = 0
aASpin6[2]  = 0
aASpin8[2]  = 0

aASpin0[3]  = 0
aASpin2[3]  = 0
aASpin4[3]  = 0
aASpin6[3]  = 0
aASpin8[3]  = 0

aASpin0[4]  = 0
aASpin2[4]  = 0
aASpin4[4]  = 0
aASpin6[4]  = 0
aASpin8[4]  = 0

aASpin0[5]  = 0
aASpin2[5]  = 0
aASpin4[5]  = 0
aASpin6[5]  = 0
aASpin8[5]  = 0

aASpin0[6]  = 0
aASpin2[6]  = 0
aASpin4[6]  = 0
aASpin6[6]  = 0
aASpin8[6]  = 0

aASpin0[7]  = 0
aASpin2[7]  = 0
aASpin4[7]  = 0
aASpin6[7]  = 0
aASpin8[7]  = 0

aASpin0[8]  = 0
aASpin2[8]  = 0
aASpin4[8]  = 0
aASpin6[8]  = 0
aASpin8[8]  = 0

aASpin0[9]  = 0
aASpin2[9]  = 0
aASpin4[9]  = 0
aASpin6[9]  = 0
aASpin8[9]  = 0

aASpin0[10] = 0
aASpin2[10] = 0
aASpin4[10] = 0
aASpin6[10] = 0
aASpin8[10] = 0

aASpin0[11] = 0
aASpin2[11] = 0
aASpin4[11] = 0
aASpin6[11] = 0
aASpin8[11] = 0

aASpin0[12] = 0
aASpin2[12] = 0
aASpin4[12] = 0
aASpin6[12] = 0
aASpin8[12] = 0

aASpin0[13] = 0
aASpin2[13] = 0
aASpin4[13] = 0
aASpin6[13] = 0
aASpin8[13] = 0

aASpin0[14] = 0
aASpin2[14] = 0
aASpin4[14] = 0
aASpin6[14] = 0
aASpin8[14] = 0

aASpin0[15] = 0
aASpin2[15] = 0
aASpin4[15] = 0
aASpin6[15] = 0
aASpin8[15] = 0

aASpin0[16] = 0
aASpin2[16] = 0
aASpin4[16] = 0
aASpin6[16] = 0
aASpin8[16] = 0

aASpin0[17] = 0
aASpin2[17] = 0
aASpin4[17] = 0
aASpin6[17] = 0
aASpin8[17] = 0

aASpin0[18] = 0
aASpin2[18] = 0
aASpin4[18] = 0
aASpin6[18] = 0
aASpin8[18] = 0

aASpin0[19] = 0
aASpin2[19] = 0
aASpin4[19] = 0
aASpin6[19] = 0
aASpin8[19] = 0

aASpin0[20] = 0
aASpin2[20] = 0
aASpin4[20] = 0
aASpin6[20] = 0
aASpin8[20] = 0

aASpin0[21] = 0
aASpin2[21] = 0
aASpin4[21] = 0
aASpin6[21] = 0
aASpin8[21] = 0

aASpin0[22] = 0
aASpin2[22] = 0
aASpin4[22] = 0
aASpin6[22] = 0
aASpin8[22] = 0

aASpin0[23] = 0
aASpin2[23] = 0
aASpin4[23] = 0
aASpin6[23] = 0
aASpin8[23] = 0

aASpin0[24] = 0
aASpin2[24] = 0
aASpin4[24] = 0
aASpin6[24] = 0
aASpin8[24] = 0

aASpin0[25] = 0
aASpin2[25] = 0
aASpin4[25] = 0
aASpin6[25] = 0
aASpin8[25] = 0

aASpin0[26] = 0
aASpin2[26] = 0
aASpin4[26] = 0
aASpin6[26] = 0
aASpin8[26] = 0

aASpin0[27] = 0
aASpin2[27] = 0
aASpin4[27] = 0
aASpin6[27] = 0
aASpin8[27] = 0

aASpin0[28] = 0
aASpin2[28] = 0
aASpin4[28] = 0
aASpin6[28] = 0
aASpin8[28] = 0

aASpin0[29] = 0
aASpin2[29] = 0
aASpin4[29] = 0
aASpin6[29] = 0
aASpin8[29] = 0

aASpin0[30] = 0
aASpin2[30] = 0
aASpin4[30] = 0
aASpin6[30] = 0
aASpin8[30] = 0

# Omega = 0.1 Values

aBSpin0[0]  = 6.07021703
aBSpin2[0]  = 6.070215165
aBSpin4[0]  = 6.098501016
aBSpin6[0]  = 6.131079243
aBSpin8[0]  = 6.147338152

aBSpin0[1]  = 6.085100567
aBSpin2[1]  = 6.085098804
aBSpin4[1]  = 6.095533446
aBSpin6[1]  = 6.143403641
aBSpin8[1]  = 6.242196965

aBSpin0[2]  = 0
aBSpin2[2]  = 0
aBSpin4[2]  = 0
aBSpin6[2]  = 0
aBSpin8[2]  = 0

aBSpin0[3]  = 0
aBSpin2[3]  = 0
aBSpin4[3]  = 0
aBSpin6[3]  = 0
aBSpin8[3]  = 0

aBSpin0[4]  = 0
aBSpin2[4]  = 0
aBSpin4[4]  = 0
aBSpin6[4]  = 0
aBSpin8[4]  = 0

aBSpin0[5]  = 0
aBSpin2[5]  = 0
aBSpin4[5]  = 0
aBSpin6[5]  = 0
aBSpin8[5]  = 0

aBSpin0[6]  = 0
aBSpin2[6]  = 0
aBSpin4[6]  = 0
aBSpin6[6]  = 0
aBSpin8[6]  = 0

aBSpin0[7]  = 0
aBSpin2[7]  = 0
aBSpin4[7]  = 0
aBSpin6[7]  = 0
aBSpin8[7]  = 0

aBSpin0[8]  = 0
aBSpin2[8]  = 0
aBSpin4[8]  = 0
aBSpin6[8]  = 0
aBSpin8[8]  = 0

aBSpin0[9]  = 0
aBSpin2[9]  = 0
aBSpin4[9]  = 0
aBSpin6[9]  = 0
aBSpin8[9]  = 0

aBSpin0[10] = 0
aBSpin2[10] = 0
aBSpin4[10] = 0
aBSpin6[10] = 0
aBSpin8[10] = 0

aBSpin0[11] = 0
aBSpin2[11] = 0
aBSpin4[11] = 0
aBSpin6[11] = 0
aBSpin8[11] = 0

aBSpin0[12] = 0
aBSpin2[12] = 0
aBSpin4[12] = 0
aBSpin6[12] = 0
aBSpin8[12] = 0

aBSpin0[13] = 0
aBSpin2[13] = 0
aBSpin4[13] = 0
aBSpin6[13] = 0
aBSpin8[13] = 0

aBSpin0[14] = 0
aBSpin2[14] = 0
aBSpin4[14] = 0
aBSpin6[14] = 0
aBSpin8[14] = 0

aBSpin0[15] = 0
aBSpin2[15] = 0
aBSpin4[15] = 0
aBSpin6[15] = 0
aBSpin8[15] = 0

aBSpin0[16] = 0
aBSpin2[16] = 0
aBSpin4[16] = 0
aBSpin6[16] = 0
aBSpin8[16] = 0

aBSpin0[17] = 0
aBSpin2[17] = 0
aBSpin4[17] = 0
aBSpin6[17] = 0
aBSpin8[17] = 0

aBSpin0[18] = 0
aBSpin2[18] = 0
aBSpin4[18] = 0
aBSpin6[18] = 0
aBSpin8[18] = 0

aBSpin0[19] = 0
aBSpin2[19] = 0
aBSpin4[19] = 0
aBSpin6[19] = 0
aBSpin8[19] = 0

aBSpin0[20] = 0
aBSpin2[20] = 0
aBSpin4[20] = 0
aBSpin6[20] = 0
aBSpin8[20] = 0

aBSpin0[21] = 0
aBSpin2[21] = 0
aBSpin4[21] = 0
aBSpin6[21] = 0
aBSpin8[21] = 0

aBSpin0[22] = 0
aBSpin2[22] = 0
aBSpin4[22] = 0
aBSpin6[22] = 0
aBSpin8[22] = 0

aBSpin0[23] = 0
aBSpin2[23] = 0
aBSpin4[23] = 0
aBSpin6[23] = 0
aBSpin8[23] = 0

aBSpin0[24] = 0
aBSpin2[24] = 0
aBSpin4[24] = 0
aBSpin6[24] = 0
aBSpin8[24] = 0

aBSpin0[25] = 0
aBSpin2[25] = 0
aBSpin4[25] = 0
aBSpin6[25] = 0
aBSpin8[25] = 0

aBSpin0[26] = 0
aBSpin2[26] = 0
aBSpin4[26] = 0
aBSpin6[26] = 0
aBSpin8[26] = 0

aBSpin0[27] = 0
aBSpin2[27] = 0
aBSpin4[27] = 0
aBSpin6[27] = 0
aBSpin8[27] = 0

aBSpin0[28] = 0
aBSpin2[28] = 0
aBSpin4[28] = 0
aBSpin6[28] = 0
aBSpin8[28] = 0

aBSpin0[29] = 0
aBSpin2[29] = 0
aBSpin4[29] = 0
aBSpin6[29] = 0
aBSpin8[29] = 0

aBSpin0[30] = 0
aBSpin2[30] = 0
aBSpin4[30] = 0
aBSpin6[30] = 0
aBSpin8[30] = 0

# Omega = 1.0 Values

aCSpin0[0]  = 33.33816518
aCSpin2[0]  = 33.33815067
aCSpin4[0]  = 34.23188617
aCSpin6[0]  = 35.25781309
aCSpin8[0]  = 36.07832883

aCSpin0[1]  = 33.77857214
aCSpin2[1]  = 33.7785457
aCSpin4[1]  = 33.77849001
aCSpin6[1]  = 34.88371209
aCSpin8[1]  = 36.95458198

aCSpin0[2]  = 33.40811869
aCSpin2[2]  = 33.40811364
aCSpin4[2]  = 34.23857969
aCSpin6[2]  = 35.19733701
aCSpin8[2]  = 36.19527576

aCSpin0[3]  = 33.87501243
aCSpin2[3]  = 33.87504223
aCSpin4[3]  = 34.66531926
aCSpin6[3]  = 34.6652642
aCSpin8[3]  = 37.00780194

aCSpin0[4]  = 33.42391034
aCSpin2[4]  = 34.33446153
aCSpin4[4]  = 34.33439985
aCSpin6[4]  = 35.23239829
aCSpin8[4]  = 36.17250839

aCSpin0[5]  = 33.93167755
aCSpin2[5]  = 33.93161203
aCSpin4[5]  = 34.87753405
aCSpin6[5]  = 35.81995638
aCSpin8[5]  = 37.04104369

aCSpin0[6]  = 34.45895104
aCSpin2[6]  = 34.45895053
aCSpin4[6]  = 34.45892692
aCSpin6[6]  = 35.55787016
aCSpin8[6]  = 37.80792648

aCSpin0[7]  = 35.0415908
aCSpin2[7]  = 0
aCSpin4[7]  = 0
aCSpin6[7]  = 0
aCSpin8[7]  = 0

aCSpin0[8]  = 0
aCSpin2[8]  = 0
aCSpin4[8]  = 0
aCSpin6[8]  = 0
aCSpin8[8]  = 0

aCSpin0[9]  = 0
aCSpin2[9]  = 0
aCSpin4[9]  = 0
aCSpin6[9]  = 0
aCSpin8[9]  = 0

aCSpin0[10] = 0
aCSpin2[10] = 0
aCSpin4[10] = 0
aCSpin6[10] = 0
aCSpin8[10] = 0

aCSpin0[11] = 0
aCSpin2[11] = 0
aCSpin4[11] = 0
aCSpin6[11] = 0
aCSpin8[11] = 0

aCSpin0[12] = 0
aCSpin2[12] = 0
aCSpin4[12] = 0
aCSpin6[12] = 0
aCSpin8[12] = 0

aCSpin0[13] = 0
aCSpin2[13] = 0
aCSpin4[13] = 0
aCSpin6[13] = 0
aCSpin8[13] = 0

aCSpin0[14] = 0
aCSpin2[14] = 0
aCSpin4[14] = 0
aCSpin6[14] = 0
aCSpin8[14] = 0

aCSpin0[15] = 0
aCSpin2[15] = 0
aCSpin4[15] = 0
aCSpin6[15] = 0
aCSpin8[15] = 0

aCSpin0[16] = 0
aCSpin2[16] = 0
aCSpin4[16] = 0
aCSpin6[16] = 0
aCSpin8[16] = 0

aCSpin0[17] = 0
aCSpin2[17] = 0
aCSpin4[17] = 0
aCSpin6[17] = 0
aCSpin8[17] = 0

aCSpin0[18] = 0
aCSpin2[18] = 0
aCSpin4[18] = 0
aCSpin6[18] = 0
aCSpin8[18] = 0

aCSpin0[19] = 0
aCSpin2[19] = 0
aCSpin4[19] = 0
aCSpin6[19] = 0
aCSpin8[19] = 0

aCSpin0[20] = 0
aCSpin2[20] = 0
aCSpin4[20] = 0
aCSpin6[20] = 0
aCSpin8[20] = 0

aCSpin0[21] = 0
aCSpin2[21] = 0
aCSpin4[21] = 0
aCSpin6[21] = 0
aCSpin8[21] = 0

aCSpin0[22] = 0
aCSpin2[22] = 0
aCSpin4[22] = 0
aCSpin6[22] = 0
aCSpin8[22] = 0

aCSpin0[23] = 0
aCSpin2[23] = 0
aCSpin4[23] = 0
aCSpin6[23] = 0
aCSpin8[23] = 0

aCSpin0[24] = 0
aCSpin2[24] = 0
aCSpin4[24] = 0
aCSpin6[24] = 0
aCSpin8[24] = 0

aCSpin0[25] = 0
aCSpin2[25] = 0
aCSpin4[25] = 0
aCSpin6[25] = 0
aCSpin8[25] = 0

aCSpin0[26] = 0
aCSpin2[26] = 0
aCSpin4[26] = 0
aCSpin6[26] = 0
aCSpin8[26] = 0

aCSpin0[27] = 0
aCSpin2[27] = 0
aCSpin4[27] = 0
aCSpin6[27] = 0
aCSpin8[27] = 0

aCSpin0[28] = 0
aCSpin2[28] = 0
aCSpin4[28] = 0
aCSpin6[28] = 0
aCSpin8[28] = 0

aCSpin0[29] = 0
aCSpin2[29] = 0
aCSpin4[29] = 0
aCSpin6[29] = 0
aCSpin8[29] = 0

aCSpin0[30] = 0
aCSpin2[30] = 0
aCSpin4[30] = 0
aCSpin6[30] = 0
aCSpin8[30] = 0

# Omega = 5.0 Values

aDSpin0[0]  = 0
aDSpin2[0]  = 0
aDSpin4[0]  = 0
aDSpin6[0]  = 0
aDSpin8[0]  = 0

aDSpin0[1]  = 0
aDSpin2[1]  = 0
aDSpin4[1]  = 0
aDSpin6[1]  = 0
aDSpin8[1]  = 0

aDSpin0[2]  = 0
aDSpin2[2]  = 0
aDSpin4[2]  = 0
aDSpin6[2]  = 0
aDSpin8[2]  = 0

aDSpin0[3]  = 0
aDSpin2[3]  = 0
aDSpin4[3]  = 0
aDSpin6[3]  = 0
aDSpin8[3]  = 0

aDSpin0[4]  = 0
aDSpin2[4]  = 0
aDSpin4[4]  = 0
aDSpin6[4]  = 0
aDSpin8[4]  = 0

aDSpin0[5]  = 0
aDSpin2[5]  = 0
aDSpin4[5]  = 0
aDSpin6[5]  = 0
aDSpin8[5]  = 0

aDSpin0[6]  = 0
aDSpin2[6]  = 0
aDSpin4[6]  = 0
aDSpin6[6]  = 0
aDSpin8[6]  = 0

aDSpin0[7]  = 0
aDSpin2[7]  = 0
aDSpin4[7]  = 0
aDSpin6[7]  = 0
aDSpin8[7]  = 0

aDSpin0[8]  = 0
aDSpin2[8]  = 0
aDSpin4[8]  = 0
aDSpin6[8]  = 0
aDSpin8[8]  = 0

aDSpin0[9]  = 0
aDSpin2[9]  = 0
aDSpin4[9]  = 0
aDSpin6[9]  = 0
aDSpin8[9]  = 0

aDSpin0[10] = 0
aDSpin2[10] = 0
aDSpin4[10] = 0
aDSpin6[10] = 0
aDSpin8[10] = 0

aDSpin0[11] = 0
aDSpin2[11] = 0
aDSpin4[11] = 0
aDSpin6[11] = 0
aDSpin8[11] = 0

aDSpin0[12] = 0
aDSpin2[12] = 0
aDSpin4[12] = 0
aDSpin6[12] = 0
aDSpin8[12] = 0

aDSpin0[13] = 0
aDSpin2[13] = 0
aDSpin4[13] = 0
aDSpin6[13] = 0
aDSpin8[13] = 0

aDSpin0[14] = 0
aDSpin2[14] = 0
aDSpin4[14] = 0
aDSpin6[14] = 0
aDSpin8[14] = 0

aDSpin0[15] = 0
aDSpin2[15] = 0
aDSpin4[15] = 0
aDSpin6[15] = 0
aDSpin8[15] = 0

aDSpin0[16] = 0
aDSpin2[16] = 0
aDSpin4[16] = 0
aDSpin6[16] = 0
aDSpin8[16] = 0

aDSpin0[17] = 0
aDSpin2[17] = 0
aDSpin4[17] = 0
aDSpin6[17] = 0
aDSpin8[17] = 0

aDSpin0[18] = 0
aDSpin2[18] = 0
aDSpin4[18] = 0
aDSpin6[18] = 0
aDSpin8[18] = 0

aDSpin0[19] = 0
aDSpin2[19] = 0
aDSpin4[19] = 0
aDSpin6[19] = 0
aDSpin8[19] = 0

aDSpin0[20] = 0
aDSpin2[20] = 0
aDSpin4[20] = 0
aDSpin6[20] = 0
aDSpin8[20] = 0

aDSpin0[21] = 0
aDSpin2[21] = 0
aDSpin4[21] = 0
aDSpin6[21] = 0
aDSpin8[21] = 0

aDSpin0[22] = 0
aDSpin2[22] = 0
aDSpin4[22] = 0
aDSpin6[22] = 0
aDSpin8[22] = 0

aDSpin0[23] = 0
aDSpin2[23] = 0
aDSpin4[23] = 0
aDSpin6[23] = 0
aDSpin8[23] = 0

aDSpin0[24] = 0
aDSpin2[24] = 0
aDSpin4[24] = 0
aDSpin6[24] = 0
aDSpin8[24] = 0

aDSpin0[25] = 0
aDSpin2[25] = 0
aDSpin4[25] = 0
aDSpin6[25] = 0
aDSpin8[25] = 0

aDSpin0[26] = 0
aDSpin2[26] = 0
aDSpin4[26] = 0
aDSpin6[26] = 0
aDSpin8[26] = 0

aDSpin0[27] = 0
aDSpin2[27] = 0
aDSpin4[27] = 0
aDSpin6[27] = 0
aDSpin8[27] = 0

aDSpin0[28] = 0
aDSpin2[28] = 0
aDSpin4[28] = 0
aDSpin6[28] = 0
aDSpin8[28] = 0

aDSpin0[29] = 0
aDSpin2[29] = 0
aDSpin4[29] = 0
aDSpin6[29] = 0
aDSpin8[29] = 0

aDSpin0[30] = 0
aDSpin2[30] = 0
aDSpin4[30] = 0
aDSpin6[30] = 0
aDSpin8[30] = 0

# Plots

fig0 = figure(figsize=(16, 7), dpi=80)
fig0.suptitle('Ground State Energy as a Function of Total M and Total Spin')

plot0 = fig0.add_subplot(121)
plot0.set_title("8 electrons, $\omega = 0.01$")
plot0.set_xlabel("Total M")
plot0.set_ylabel("$E_0 (\hbar\omega)$")
plot0.plot(aASpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot0.plot(aASpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot0.plot(aASpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot0.plot(aASpin6, ' ', marker='x', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot0.plot(aASpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 8/2')
plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((-1, 31))
plot0.set_ylim((4.7, 6.4))
xax = plot0.xaxis
yax = plot0.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(4.7, 6.3, 9))

plot1 = fig0.add_subplot(122)
plot1.set_title("8 electrons, $\omega = 0.1$")
plot1.set_xlabel("Total M")
plot1.set_ylabel("$E_0 (\hbar\omega)$")
plot1.plot(aBSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot1.plot(aBSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot1.plot(aBSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot1.plot(aBSpin6, ' ', marker='x', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot1.plot(aBSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 8/2')
plot1.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot1.set_xlim((-1, 31))
plot1.set_ylim((4.7, 6.4))
xax = plot1.xaxis
yax = plot1.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(4.7, 6.3, 9))


fig1 = figure(figsize=(16, 7), dpi=80)
fig1.suptitle('Ground State Energy as a Function of Total M and Total Spin')

plot2 = fig1.add_subplot(121)
plot2.set_title("8 electrons, $\omega = 1.0$")
plot2.set_xlabel("Total M")
plot2.set_ylabel("$E_0 (\hbar\omega)$")
plot2.plot(aCSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot2.plot(aCSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot2.plot(aCSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot2.plot(aCSpin6, ' ', marker='x', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot2.plot(aCSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 8/2')
plot2.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot2.set_xlim((-1, 31))
plot2.set_ylim((33, 51))
xax = plot2.xaxis
yax = plot2.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(34, 50, 9))

plot3 = fig1.add_subplot(122)
plot3.set_title("8 electrons, $\omega = 5.0$")
plot3.set_xlabel("Total M")
plot3.set_ylabel("$E_0 (\hbar\omega)$")
plot3.plot(aDSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot3.plot(aDSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot3.plot(aDSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot3.plot(aDSpin6, ' ', marker='x', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot3.plot(aDSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 8/2')
plot3.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot3.set_xlim((-1, 31))
plot3.set_ylim((25, 47))
xax = plot3.xaxis
yax = plot3.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(25, 47, 12))

show()
