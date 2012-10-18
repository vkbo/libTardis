#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aASpin1 = zeros(28,float)
aASpin3 = zeros(28,float)
aASpin5 = zeros(28,float)
aASpin7 = zeros(28,float)
aBSpin1 = zeros(28,float)
aBSpin3 = zeros(28,float)
aBSpin5 = zeros(28,float)
aBSpin7 = zeros(28,float)
aCSpin1 = zeros(28,float)
aCSpin3 = zeros(28,float)
aCSpin5 = zeros(28,float)
aCSpin7 = zeros(28,float)
aDSpin1 = zeros(28,float)
aDSpin3 = zeros(28,float)
aDSpin5 = zeros(28,float)
aDSpin7 = zeros(28,float)

# Omega = 0.01 Values

aASpin1[0]  = 0
aASpin3[0]  = 0
aASpin5[0]  = 0
aASpin7[0]  = 0

aASpin1[1]  = 0
aASpin3[1]  = 0
aASpin5[1]  = 0
aASpin7[1]  = 0

aASpin1[2]  = 0
aASpin3[2]  = 0
aASpin5[2]  = 0
aASpin7[2]  = 0

aASpin1[3]  = 0
aASpin3[3]  = 0
aASpin5[3]  = 0
aASpin7[3]  = 0

aASpin1[4]  = 0
aASpin3[4]  = 0
aASpin5[4]  = 0
aASpin7[4]  = 0

aASpin1[5]  = 0
aASpin3[5]  = 0
aASpin5[5]  = 0
aASpin7[5]  = 0

aASpin1[6]  = 0
aASpin3[6]  = 0
aASpin5[6]  = 0
aASpin7[6]  = 0

aASpin1[7]  = 0
aASpin3[7]  = 0
aASpin5[7]  = 0
aASpin7[7]  = 0

aASpin1[8]  = 0
aASpin3[8]  = 0
aASpin5[8]  = 0
aASpin7[8]  = 0

aASpin1[9]  = 0
aASpin3[9]  = 0
aASpin5[9]  = 0
aASpin7[9]  = 0

aASpin1[10] = 0
aASpin3[10] = 0
aASpin5[10] = 0
aASpin7[10] = 0

aASpin1[11] = 0
aASpin3[11] = 0
aASpin5[11] = 0
aASpin7[11] = 0

aASpin1[12] = 0
aASpin3[12] = 0
aASpin5[12] = 0
aASpin7[12] = 0

aASpin1[13] = 0
aASpin3[13] = 0
aASpin5[13] = 0
aASpin7[13] = 0

aASpin1[14] = 0
aASpin3[14] = 0
aASpin5[14] = 0
aASpin7[14] = 0

aASpin1[15] = 0
aASpin3[15] = 0
aASpin5[15] = 0
aASpin7[15] = 0

aASpin1[16] = 0
aASpin3[16] = 0
aASpin5[16] = 0
aASpin7[16] = 0

aASpin1[17] = 0
aASpin3[17] = 0
aASpin5[17] = 0
aASpin7[17] = 0

aASpin1[18] = 0
aASpin3[18] = 0
aASpin5[18] = 0
aASpin7[18] = 0

aASpin1[19] = 0
aASpin3[19] = 0
aASpin5[19] = 0
aASpin7[19] = 0

aASpin1[20] = 0
aASpin3[20] = 0
aASpin5[20] = 0
aASpin7[20] = 0

aASpin1[21] = 0
aASpin3[21] = 0
aASpin5[21] = 0
aASpin7[21] = 0

aASpin1[22] = 0
aASpin3[22] = 0
aASpin5[22] = 0
aASpin7[22] = 0

aASpin1[23] = 0
aASpin3[23] = 0
aASpin5[23] = 0
aASpin7[23] = 0

aASpin1[24] = 0
aASpin3[24] = 0
aASpin5[24] = 0
aASpin7[24] = 0

aASpin1[25] = 0
aASpin3[25] = 0
aASpin5[25] = 0
aASpin7[25] = 0

aASpin1[26] = 0
aASpin3[26] = 0
aASpin5[26] = 0
aASpin7[26] = 0

aASpin1[27] = 0
aASpin3[27] = 0
aASpin5[27] = 0
aASpin7[27] = 0

# Omega = 0.1 Values

aBSpin1[0]  = 4.751330275
aBSpin3[0]  = 4.781961366
aBSpin5[0]  = 4.781854503
aBSpin7[0]  = 4.890905842

aBSpin1[1]  = 4.76124787
aBSpin3[1]  = 4.76124299
aBSpin5[1]  = 4.791449563
aBSpin7[1]  = 4.87503092

aBSpin1[2]  = 4.745737771
aBSpin3[2]  = 4.783457359
aBSpin5[2]  = 4.807446031
aBSpin7[2]  = 4.897027254

aBSpin1[3]  = 4.768610982
aBSpin3[3]  = 4.781017646
aBSpin5[3]  = 4.800923112
aBSpin7[3]  = 4.822281483

aBSpin1[4]  = 4.795779566
aBSpin3[4]  = 4.795781826
aBSpin5[4]  = 4.823426658
aBSpin7[4]  = 4.909553971

aBSpin1[5]  = 4.796851631
aBSpin3[5]  = 4.824611483
aBSpin5[5]  = 4.826895414
aBSpin7[5]  = 4.990754735

aBSpin1[6]  = 4.81495302
aBSpin3[6]  = 4.814951125
aBSpin5[6]  = 4.850829235
aBSpin7[6]  = 4.91988652

aBSpin1[7]  = 4.857506586
aBSpin3[7]  = 4.85753404
aBSpin5[7]  = 4.892629441
aBSpin7[7]  = 4.989452677

aBSpin1[8]  = 4.896787117
aBSpin3[8]  = 4.898413967
aBSpin5[8]  = 4.926769994
aBSpin7[8]  = 5.047941457

aBSpin1[9]  = 4.894828152
aBSpin3[9]  = 4.933619542
aBSpin5[9]  = 4.950910896
aBSpin7[9]  = 4.975090215

aBSpin1[10] = 4.943127762
aBSpin3[10] = 4.976133934
aBSpin5[10] = 4.995624338
aBSpin7[10] = 5.054037021

aBSpin1[11] = 4.98679894
aBSpin3[11] = 5.007416749
aBSpin5[11] = 5.037380632
aBSpin7[11] = 5.120043728

aBSpin1[12] = 5.032201911
aBSpin3[12] = 5.049849276
aBSpin5[12] = 5.079336721
aBSpin7[12] = 5.207532233

aBSpin1[13] = 5.094474528
aBSpin3[13] = 5.094470574
aBSpin5[13] = 5.13190425
aBSpin7[13] = 5.292390741

aBSpin1[14] = 5.147570313
aBSpin3[14] = 5.152160067
aBSpin5[14] = 5.189434708
aBSpin7[14] = 5.19816022

aBSpin1[15] = 5.206577348
aBSpin3[15] = 5.206550336
aBSpin5[15] = 5.206554786
aBSpin7[15] = 5.24333027

aBSpin1[16] = 5.265344597
aBSpin3[16] = 5.265316648
aBSpin5[16] = 5.277675925
aBSpin7[16] = 5.329605041

aBSpin1[17] = 5.330051368
aBSpin3[17] = 5.333133504
aBSpin5[17] = 5.345206115
aBSpin7[17] = 5.460964577

aBSpin1[18] = 5.398454292
aBSpin3[18] = 5.398451427
aBSpin5[18] = 5.398449616
aBSpin7[18] = 5.533320389

aBSpin1[19] = 5.471496975
aBSpin3[19] = 5.471495248
aBSpin5[19] = 5.498520828
aBSpin7[19] = 5.714021164

aBSpin1[20] = 5.548596625
aBSpin3[20] = 5.548593182
aBSpin5[20] = 5.548590343
aBSpin7[20] = 5.809435882

aBSpin1[21] = 5.629939726
aBSpin3[21] = 5.629910213
aBSpin5[21] = 5.736912833
aBSpin7[21] = -1

aBSpin1[22] = 5.707700113
aBSpin3[22] = 5.70768443
aBSpin5[22] = 5.84248862
aBSpin7[22] = -1

aBSpin1[23] = 5.795231508
aBSpin3[23] = 5.795218875
aBSpin5[23] = 5.93578438
aBSpin7[23] = -1

aBSpin1[24] = 5.8776798
aBSpin3[24] = 5.892766797
aBSpin5[24] = 6.156782824
aBSpin7[24] = -1

aBSpin1[25] = 5.97110648
aBSpin3[25] = 6.100081511
aBSpin5[25] = -1
aBSpin7[25] = -1

aBSpin1[26] = 6.053125117
aBSpin3[26] = 6.200209516
aBSpin5[26] = -1
aBSpin7[26] = -1

aBSpin1[27] = 6.292192084
aBSpin3[27] = -1
aBSpin5[27] = -1
aBSpin7[27] = -1

# Omega = 1.0 Values

aCSpin1[0]  = 26.60525631
aCSpin3[0]  = 27.3532558
aCSpin5[0]  = 27.35321547
aCSpin7[0]  = 29.62173854

aCSpin1[1]  = 26.93736911
aCSpin3[1]  = 26.93735036
aCSpin5[1]  = 27.86367515
aCSpin7[1]  = 28.94790992

aCSpin1[2]  = 26.51511657
aCSpin3[2]  = 27.47653588
aCSpin5[2]  = 28.36816333
aCSpin7[2]  = 29.65367909

aCSpin1[3]  = 27.02616677
aCSpin3[3]  = 27.07338101
aCSpin5[3]  = 27.97690504
aCSpin7[3]  = 28.80060465

aCSpin1[4]  = 27.54618971
aCSpin3[4]  = 27.54620057
aCSpin5[4]  = 28.49978949
aCSpin7[4]  = 29.66521372

aCSpin1[5]  = 27.14736372
aCSpin3[5]  = 28.06972308
aCSpin5[5]  = 28.06969314
aCSpin7[5]  = 30.48628402

aCSpin1[6]  = 27.67185948
aCSpin3[6]  = 27.67182423
aCSpin5[6]  = 28.6235774
aCSpin7[6]  = 29.68518325

aCSpin1[7]  = 28.2734851
aCSpin3[7]  = 28.27344248
aCSpin5[7]  = 29.22730244
aCSpin7[7]  = 30.48794923

aCSpin1[8]  = 28.89700393
aCSpin3[8]  = 28.89666067
aCSpin5[8]  = 29.82671638
aCSpin7[8]  = 31.26361158

aCSpin1[9]  = 28.49186432
aCSpin3[9]  = 29.55982702
aCSpin5[9]  = 29.55982444
aCSpin7[9]  = 30.44609412

aCSpin1[10] = 29.17084113
aCSpin3[10] = 30.15475812
aCSpin5[10] = 30.2480432
aCSpin7[10] = 31.28534685

aCSpin1[11] = 29.81487214
aCSpin3[11] = 29.88987543
aCSpin5[11] = 30.86117144
aCSpin7[11] = 32.04833113

aCSpin1[12] = 30.51320822
aCSpin3[12] = 30.54912931
aCSpin5[12] = 31.50831464
aCSpin7[12] = 32.97233671

aCSpin1[13] = 31.21278363
aCSpin3[13] = 31.21276421
aCSpin5[13] = 32.22886299
aCSpin7[13] = 33.82750257

aCSpin1[14] = 31.92184881
aCSpin3[14] = 31.9347167
aCSpin5[14] = 32.92289061
aCSpin7[14] = 32.92274837

aCSpin1[15] = 32.63870283
aCSpin3[15] = 32.63861617
aCSpin5[15] = 32.63860506
aCSpin7[15] = 33.70680318

aCSpin1[16] = 33.37370831
aCSpin3[16] = 33.37392634
aCSpin5[16] = 33.46774333
aCSpin7[16] = 34.56229003

aCSpin1[17] = 34.15809742
aCSpin3[17] = 34.18661001
aCSpin5[17] = 34.26430947
aCSpin7[17] = 35.557323

aCSpin1[18] = 34.97787435
aCSpin3[18] = 35.00564154
aCSpin5[18] = 35.03597717
aCSpin7[18] = 36.45134729

aCSpin1[19] = 35.82361243
aCSpin3[19] = 35.82358639
aCSpin5[19] = 35.91867399
aCSpin7[19] = 38.98011064

aCSpin1[20] = 36.68464118
aCSpin3[20] = 36.68456005
aCSpin5[20] = 36.68454908
aCSpin7[20] = 39.86371215

aCSpin1[21] = 37.63331728
aCSpin3[21] = 37.63329357
aCSpin5[21] = 39.23767214
aCSpin7[21] = -1

aCSpin1[22] = 38.59279044
aCSpin3[22] = 38.59291715
aCSpin5[22] = 40.1831948
aCSpin7[22] = -1

aCSpin1[23] = 39.56371487
aCSpin3[23] = 39.5648945
aCSpin5[23] = 41.18081569
aCSpin7[23] = -1

aCSpin1[24] = 40.53493073
aCSpin3[24] = 40.53510993
aCSpin5[24] = 43.86665058
aCSpin7[24] = -1

aCSpin1[25] = 41.5307982
aCSpin3[25] = 43.18228205
aCSpin5[25] = -1
aCSpin7[25] = -1

aCSpin1[26] = 42.5417262
aCSpin3[26] = 44.20201691
aCSpin5[26] = -1
aCSpin7[26] = -1

aCSpin1[27] = 45.28823657
aCSpin3[27] = -1
aCSpin5[27] = -1
aCSpin7[27] = -1

# Omega = 5.0 Values

aDSpin1[0]  = 98.34052154
aDSpin3[0]  = 104.6386309
aDSpin5[0]  = 104.6385773
aDSpin7[0]  = 119.7750189

aDSpin1[1]  = 101.3694815
aDSpin3[1]  = 101.3694698
aDSpin5[1]  = 108.2971365
aDSpin7[1]  = 115.6271541

aDSpin1[2]  = 98.05256066
aDSpin3[2]  = 105.073848
aDSpin5[2]  = 111.922099
aDSpin7[2]  = 119.8728439

aDSpin1[3]  = 101.6576028
aDSpin3[3]  = 101.7627422
aDSpin5[3]  = 108.636872
aDSpin7[3]  = 115.2624764

aDSpin1[4]  = 105.2694775
aDSpin3[4]  = 105.269138
aDSpin5[4]  = 112.3156862
aDSpin7[4]  = 119.8657198

aDSpin1[5]  = 101.9754661
aDSpin3[5]  = 108.8768239
aDSpin5[5]  = 108.876296
aDSpin7[5]  = 124.383617

aDSpin1[6]  = 105.6338627
aDSpin3[6]  = 105.6338708
aDSpin5[6]  = 112.6452598
aDSpin7[6]  = 119.942779

aDSpin1[7]  = 109.4963673
aDSpin3[7]  = 109.4937044
aDSpin5[7]  = 116.5230845
aDSpin7[7]  = 124.2961193

aDSpin1[8]  = 113.4104225
aDSpin3[8]  = 113.4098829
aDSpin5[8]  = 120.3868789
aDSpin7[8]  = 128.7326793

aDSpin1[9]  = 110.1283631
aDSpin3[9]  = 117.3501557
aDSpin5[9]  = 117.3495229
aDSpin7[9]  = 124.2173181

aDSpin1[10] = 114.1836667
aDSpin3[10] = 121.3778771
aDSpin5[10] = 121.5047492
aDSpin7[10] = 128.7811095

aDSpin1[11] = 118.2321616
aDSpin3[11] = 118.2914975
aDSpin5[11] = 125.4476212
aDSpin7[11] = 133.1805123

aDSpin1[12] = 122.3996498
aDSpin3[12] = 122.4032644
aDSpin5[12] = 129.487611
aDSpin7[12] = 137.916457

aDSpin1[13] = 126.4767257
aDSpin3[13] = 126.4696528
aDSpin5[13] = 133.6515041
aDSpin7[13] = 142.4636213

aDSpin1[14] = 130.6310356
aDSpin3[14] = 130.6297155
aDSpin5[14] = 137.7491964
aDSpin7[14] = 137.7486849

aDSpin1[15] = 134.7992709
aDSpin3[15] = 134.7985666
aDSpin5[15] = 134.798511
aDSpin7[15] = 142.2452652

aDSpin1[16] = 139.0777186
aDSpin3[16] = 139.0776045
aDSpin5[16] = 139.3132673
aDSpin7[16] = 146.8659139

aDSpin1[17] = 143.4792724
aDSpin3[17] = 143.5563815
aDSpin5[17] = 143.7611798
aDSpin7[17] = 151.6885833

aDSpin1[18] = 147.974477
aDSpin3[18] = 148.041144
aDSpin5[18] = 148.1735469
aDSpin7[18] = 156.4230401

aDSpin1[19] = 152.5385976
aDSpin3[19] = 152.5384002
aDSpin5[19] = 152.7231238
aDSpin7[19] = 170.3393794

aDSpin1[20] = 157.1471573
aDSpin3[20] = 157.1469511
aDSpin5[20] = 157.1468606
aDSpin7[20] = 174.9778277

aDSpin1[21] = 162.0411906
aDSpin3[21] = 162.0409616
aDSpin5[21] = 171.1615068
aDSpin7[21] = -1

aDSpin1[22] = 166.9912176
aDSpin3[22] = 166.9954755
aDSpin5[22] = 175.9005043
aDSpin7[22] = -1

aDSpin1[23] = 171.8740739
aDSpin3[23] = 171.9561758
aDSpin5[23] = 180.9200095
aDSpin7[23] = -1

aDSpin1[24] = 176.8650904
aDSpin3[24] = 176.8650949
aDSpin5[24] = 195.2273712
aDSpin7[24] = -1

aDSpin1[25] = 181.9310239
aDSpin3[25] = 191.0640948
aDSpin5[25] = -1
aDSpin7[25] = -1

aDSpin1[26] = 187.0279847
aDSpin3[26] = 196.1380442
aDSpin5[26] = -1
aDSpin7[26] = -1

aDSpin1[27] = 201.4346323
aDSpin3[27] = -1
aDSpin5[27] = -1
aDSpin7[27] = -1

# Plots

fig0 = figure(figsize=(16, 7), dpi=80)
fig0.suptitle('Energy as a Function of Total M and Total Spin')

plot0 = fig0.add_subplot(121)
plot0.set_title("7 electrons, $\omega = 0.01$")
plot0.set_xlabel("Total M")
plot0.set_ylabel("$E_0 (\hbar\omega)$")
plot0.plot(aASpin1, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 1/2')
plot0.plot(aASpin3, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 3/2')
plot0.plot(aASpin5, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 5/2')
plot0.plot(aASpin7, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 7/2')
plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((-1, 28))
plot0.set_ylim((4.7, 6.4))
xax = plot0.xaxis
yax = plot0.yaxis
xax.set_ticks(linspace(0, 26, 14))
yax.set_ticks(linspace(4.7, 6.3, 9))

plot1 = fig0.add_subplot(122)
plot1.set_title("7 electrons, $\omega = 0.1$")
plot1.set_xlabel("Total M")
plot1.set_ylabel("$E_0 (\hbar\omega)$")
plot1.plot(aBSpin1, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 1/2')
plot1.plot(aBSpin3, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 3/2')
plot1.plot(aBSpin5, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 5/2')
plot1.plot(aBSpin7, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 7/2')
plot1.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot1.set_xlim((-1, 28))
plot1.set_ylim((4.7, 6.4))
xax = plot1.xaxis
yax = plot1.yaxis
xax.set_ticks(linspace(0, 26, 14))
yax.set_ticks(linspace(4.7, 6.3, 9))


fig1 = figure(figsize=(16, 7), dpi=80)
fig1.suptitle('Energy as a Function of Total M and Total Spin')

plot2 = fig1.add_subplot(121)
plot2.set_title("7 electrons, $\omega = 1.0$")
plot2.set_xlabel("Total M")
plot2.set_ylabel("$E_0 (\hbar\omega)$")
plot2.plot(aCSpin1, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 1/2')
plot2.plot(aCSpin3, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 3/2')
plot2.plot(aCSpin5, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 5/2')
plot2.plot(aCSpin7, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 7/2')
plot2.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot2.set_xlim((-1, 28))
plot2.set_ylim((26, 46))
xax = plot2.xaxis
yax = plot2.yaxis
xax.set_ticks(linspace(0, 26, 14))
yax.set_ticks(linspace(26, 46, 11))

plot3 = fig1.add_subplot(122)
plot3.set_title("7 electrons, $\omega = 5.0$")
plot3.set_xlabel("Total M")
plot3.set_ylabel("$E_0 (\hbar\omega)$")
plot3.plot(aDSpin1, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 1/2')
plot3.plot(aDSpin3, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 3/2')
plot3.plot(aDSpin5, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 5/2')
plot3.plot(aDSpin7, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 7/2')
plot3.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot3.set_xlim((-1, 28))
plot3.set_ylim((95, 205))
xax = plot3.xaxis
yax = plot3.yaxis
xax.set_ticks(linspace(0, 26, 14))
yax.set_ticks(linspace(100, 200, 11))

show()
