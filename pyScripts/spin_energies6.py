#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aASpin0 = zeros(25,float)
aASpin2 = zeros(25,float)
aASpin4 = zeros(25,float)
aASpin6 = zeros(25,float)
aBSpin0 = zeros(25,float)
aBSpin2 = zeros(25,float)
aBSpin4 = zeros(25,float)
aBSpin6 = zeros(25,float)
aCSpin0 = zeros(25,float)
aCSpin2 = zeros(25,float)
aCSpin4 = zeros(25,float)
aCSpin6 = zeros(25,float)
aDSpin0 = zeros(25,float)
aDSpin2 = zeros(25,float)
aDSpin4 = zeros(25,float)
aDSpin6 = zeros(25,float)

# Omega = 0.01 Values

aASpin0[0]  = 0.71973483
aASpin2[0]  = 0.7215439276
aASpin4[0]  = 0.7215407724
aASpin6[0]  = 0.7296923569

aASpin0[1]  = 0.7211934095
aASpin2[1]  = 0.721204045
aASpin4[1]  = 0.7215383505
aASpin6[1]  = 0.7343009309

aASpin0[2]  = 0.7214422731
aASpin2[2]  = 0.7214462274
aASpin4[2]  = 0.7223763248
aASpin6[2]  = 0.7322555797

aASpin0[3]  = 0.7224398038
aASpin2[3]  = 0.7224001607
aASpin4[3]  = 0.7231703713
aASpin6[3]  = 0.7231702596

aASpin0[4]  = 0.7239712814
aASpin2[4]  = 0.7239988323
aASpin4[4]  = 0.7240064479
aASpin6[4]  = 0.7373338782

aASpin0[5]  = 0.7255717475
aASpin2[5]  = 0.7255667474
aASpin4[5]  = 0.7255734804
aASpin6[5]  = 0.7318574585

aASpin0[6]  = 0.7273037395
aASpin2[6]  = 0.7272839338
aASpin4[6]  = 0.7272839265
aASpin6[6]  = 0.7396398514

aASpin0[7]  = 0.7300345695
aASpin2[7]  = 0.7297125552
aASpin4[7]  = 0.730701367
aASpin6[7]  = 0.748152014

aASpin0[8]  = 0.7324714809
aASpin2[8]  = 0.7330323634
aASpin4[8]  = 0.7330320796
aASpin6[8]  = 0.7485384988

aASpin0[9]  = 0.736016896
aASpin2[9]  = 0.7360012955
aASpin4[9]  = 0.7370404085
aASpin6[9]  = 0.7370399054

aASpin0[10] = 0.7391690264
aASpin2[10] = 0.740377116
aASpin4[10] = 0.7403767059
aASpin6[10] = 0.7459269048

aASpin0[11] = 0.7431799164
aASpin2[11] = 0.7431799152
aASpin4[11] = 0.7439852836
aASpin6[11] = 0.7582608915

aASpin0[12] = 0.7465397991
aASpin2[12] = 0.7478422752
aASpin4[12] = 0.7481493833
aASpin6[12] = 0.7642963068

aASpin0[13] = 0.7517989762
aASpin2[13] = 0.7517991393
aASpin4[13] = 0.7517988232
aASpin6[13] = 0.7701706562

aASpin0[14] = 0.7561446979
aASpin2[14] = 0.7564498867
aASpin4[14] = 0.7564493828
aASpin6[14] = 0.7675080003

aASpin0[15] = 0.7609927089
aASpin2[15] = 0.7611791319
aASpin4[15] = 0.7611786951
aASpin6[15] = 0.7611787532

aASpin0[16] = 0.7659666284
aASpin2[16] = 0.7659602169
aASpin4[16] = 0.7659588747
aASpin6[16] = 0.7839986931

aASpin0[17] = 0.7710988927
aASpin2[17] = 0.7710988036
aASpin4[17] = 0.7724160994
aASpin6[17] = 0.7942405419

aASpin0[18] = 0.7764091979
aASpin2[18] = 0.7764045289
aASpin4[18] = 0.776404409
aASpin6[18] = 0.7944146636

aASpin0[19] = 0.7822239091
aASpin2[19] = 0.7822241522
aASpin4[19] = 0.7857749095
aASpin6[19] = 0.8336081148

aASpin0[20] = 0.7887217123
aASpin2[20] = 0.7881764963
aASpin4[20] = 0.7881763429
aASpin6[20] = -1

aASpin0[21] = 0.7947539209
aASpin2[21] = 0.7947524875
aASpin4[21] = 0.818943634
aASpin6[21] = -1

aASpin0[22] = 0.8004144333
aASpin2[22] = 0.8004143334
aASpin4[22] = 0.8231247092
aASpin6[22] = -1

aASpin0[23] = 0.8120274226
aASpin2[23] = 0.8120274133
aASpin4[23] = -1
aASpin6[23] = -1

aASpin0[24] = 0.8142008419
aASpin2[24] = 0.8417579519
aASpin4[24] = -1
aASpin6[24] = -1

# Omega = 0.1 Values

aBSpin0[0]  = 3.560682934
aBSpin2[0]  = 3.598379561
aBSpin4[0]  = 3.598379067
aBSpin6[0]  = 3.628415997

aBSpin0[1]  = 3.586357168
aBSpin2[1]  = 3.586369195
aBSpin4[1]  = 3.617585575
aBSpin6[1]  = 3.703066787

aBSpin0[2]  = 3.605932343
aBSpin2[2]  = 3.60773825
aBSpin4[2]  = 3.62034009
aBSpin6[2]  = 3.765877682

aBSpin0[3]  = 3.594215321
aBSpin2[3]  = 3.594217686
aBSpin4[3]  = 3.634422515
aBSpin6[3]  = 3.683067062

aBSpin0[4]  = 3.623603227
aBSpin2[4]  = 3.62359875
aBSpin4[4]  = 3.656178908
aBSpin6[4]  = 3.757302655

aBSpin0[5]  = 3.649545874
aBSpin2[5]  = 3.64954175
aBSpin4[5]  = 3.649536225
aBSpin6[5]  = 3.682965183

aBSpin0[6]  = 3.655388839
aBSpin2[6]  = 3.690057721
aBSpin4[6]  = 3.690009169
aBSpin6[6]  = 3.767247367

aBSpin0[7]  = 3.688450713
aBSpin2[7]  = 3.688448958
aBSpin4[7]  = 3.728720026
aBSpin6[7]  = 3.8368932

aBSpin0[8]  = 3.733282021
aBSpin2[8]  = 3.740447319
aBSpin4[8]  = 3.772667405
aBSpin6[8]  = 3.926373006

aBSpin0[9]  = 3.771480481
aBSpin2[9]  = 3.775131693
aBSpin4[9]  = 3.829922423
aBSpin6[9]  = 3.832261611

aBSpin0[10] = 3.823603994
aBSpin2[10] = 3.830176713
aBSpin4[10] = 3.842583691
aBSpin6[10] = 3.885257121

aBSpin0[11] = 3.871254467
aBSpin2[11] = 3.871260528
aBSpin4[11] = 3.890677484
aBSpin6[11] = 3.96613574

aBSpin0[12] = 3.935461196
aBSpin2[12] = 3.938640619
aBSpin4[12] = 3.938637374
aBSpin6[12] = 4.057583704

aBSpin0[13] = 3.98505209
aBSpin2[13] = 3.985050659
aBSpin4[13] = 3.98505024
aBSpin6[13] = 4.147562517

aBSpin0[14] = 4.046441575
aBSpin2[14] = 4.046441636
aBSpin4[14] = 4.046440224
aBSpin6[14] = 4.198596276

aBSpin0[15] = 4.103862423
aBSpin2[15] = 4.103865654
aBSpin4[15] = 4.10386452
aBSpin6[15] = 4.103859896

aBSpin0[16] = 4.190112183
aBSpin2[16] = 4.190108696
aBSpin4[16] = 4.190107398
aBSpin6[16] = 4.311065697

aBSpin0[17] = 4.277101439
aBSpin2[17] = 4.277099405
aBSpin4[17] = 4.278683958
aBSpin6[17] = 4.415521345

aBSpin0[18] = 4.365926859
aBSpin2[18] = 4.36586845
aBSpin4[18] = 4.365854778
aBSpin6[18] = 4.502482452

aBSpin0[19] = 4.452413048
aBSpin2[19] = 4.452430306
aBSpin4[19] = 4.459000925
aBSpin6[19] = 4.744130727

aBSpin0[20] = 4.542560926
aBSpin2[20] = 4.542546921
aBSpin4[20] = 4.542546831
aBSpin6[20] = -1

aBSpin0[21] = 4.63453892
aBSpin2[21] = 4.634538457
aBSpin4[21] = 4.777484333
aBSpin6[21] = -1

aBSpin0[22] = 4.726421794
aBSpin2[22] = 4.726421767
aBSpin4[22] = 4.872789865
aBSpin6[22] = -1

aBSpin0[23] = 4.824755962
aBSpin2[23] = 4.824755954
aBSpin4[23] = -1
aBSpin6[23] = -1

aBSpin0[24] = 4.914603624
aBSpin2[24] = 5.075988514
aBSpin4[24] = -1
aBSpin6[24] = -1

# Omega = 1.0 Values

aCSpin0[0]  = 20.17391283
aCSpin2[0]  = 21.10149287
aCSpin4[0]  = 21.10141357
aCSpin6[0]  = 21.99164275

aCSpin0[1]  = 20.69150095
aCSpin2[1]  = 20.69151035
aCSpin4[1]  = 21.61986908
aCSpin6[1]  = 22.85356414

aCSpin0[2]  = 21.22837438
aCSpin2[2]  = 21.22829514
aCSpin4[2]  = 21.22877101
aCSpin6[2]  = 23.64104077

aCSpin0[3]  = 20.73029828
aCSpin2[3]  = 20.73030456
aCSpin4[3]  = 21.73142672
aCSpin6[3]  = 22.7742871

aCSpin0[4]  = 21.29902709
aCSpin2[4]  = 21.29897078
aCSpin4[4]  = 22.24936335
aCSpin6[4]  = 23.6086876

aCSpin0[5]  = 21.83885826
aCSpin2[5]  = 21.83878492
aCSpin4[5]  = 21.83877746
aCSpin6[5]  = 22.77728757

aCSpin0[6]  = 21.48533876
aCSpin2[6]  = 22.49336649
aCSpin4[6]  = 22.4920532
aCSpin6[6]  = 23.65071261

aCSpin0[7]  = 22.1120515
aCSpin2[7]  = 22.11204968
aCSpin4[7]  = 23.09405804
aCSpin6[7]  = 24.44703116

aCSpin0[8]  = 22.7805311
aCSpin2[8]  = 22.78080868
aCSpin4[8]  = 23.74295096
aCSpin6[8]  = 25.33255898

aCSpin0[9]  = 23.42228314
aCSpin2[9]  = 23.42287236
aCSpin4[9]  = 24.4228023
aCSpin6[9]  = 24.42275896

aCSpin0[10] = 24.08744437
aCSpin2[10] = 24.14370761
aCSpin4[10] = 24.14405603
aCSpin6[10] = 25.20135721

aCSpin0[11] = 24.79889515
aCSpin2[11] = 24.79888785
aCSpin4[11] = 24.87228478
aCSpin6[11] = 26.06917784

aCSpin0[12] = 25.52366735
aCSpin2[12] = 25.52379432
aCSpin4[12] = 25.56430224
aCSpin6[12] = 26.9977417

aCSpin0[13] = 26.25238785
aCSpin2[13] = 26.25232741
aCSpin4[13] = 26.25294836
aCSpin6[13] = 27.89604382

aCSpin0[14] = 26.98867771
aCSpin2[14] = 26.98866602
aCSpin4[14] = 26.98866265
aCSpin6[14] = 28.72791907

aCSpin0[15] = 27.73663615
aCSpin2[15] = 27.73665001
aCSpin4[15] = 27.73665369
aCSpin6[15] = 27.73662278

aCSpin0[16] = 28.69234333
aCSpin2[16] = 28.6923401
aCSpin4[16] = 28.6923255
aCSpin6[16] = 30.36349982

aCSpin0[17] = 29.65035972
aCSpin2[17] = 29.6503584
aCSpin4[17] = 29.67441041
aCSpin6[17] = 31.29815812

aCSpin0[18] = 30.60778104
aCSpin2[18] = 30.62504766
aCSpin4[18] = 30.65396255
aCSpin6[18] = 32.26007866

aCSpin0[19] = 31.5832471
aCSpin2[19] = 31.58325973
aCSpin4[19] = 31.62629305
aCSpin6[19] = 34.99436195

aCSpin0[20] = 32.56256675
aCSpin2[20] = 32.56257403
aCSpin4[20] = 32.56255566
aCSpin6[20] = -1

aCSpin0[21] = 33.57532989
aCSpin2[21] = 33.575309
aCSpin4[21] = 35.28671992
aCSpin6[21] = -1

aCSpin0[22] = 34.59511013
aCSpin2[22] = 34.59626347
aCSpin4[22] = 36.3161026
aCSpin6[22] = -1

aCSpin0[23] = 35.61360875
aCSpin2[23] = 35.61360859
aCSpin4[23] = -1
aCSpin6[23] = -1

aCSpin0[24] = 36.6506954
aCSpin2[24] = 38.44267265
aCSpin4[24] = -1
aCSpin6[24] = -1

# Omega = 5.0 Values

aDSpin0[0]  = 74.94350103
aDSpin2[0]  = 81.85547717
aDSpin4[0]  = 81.85520331
aDSpin6[0]  = 88.68032974

aDSpin0[1]  = 78.56037783
aDSpin2[1]  = 78.56038084
aDSpin4[1]  = 85.52317316
aDSpin6[1]  = 93.32118968

aDSpin0[2]  = 82.19788695
aDSpin2[2]  = 82.20501949
aDSpin4[2]  = 82.19784513
aDSpin6[2]  = 97.75210001

aDSpin0[3]  = 78.66854776
aDSpin2[3]  = 78.66855971
aDSpin4[3]  = 85.83719206
aDSpin6[3]  = 93.11486427

aDSpin0[4]  = 82.45377408
aDSpin2[4]  = 82.45374377
aDSpin4[4]  = 89.4937919
aDSpin6[4]  = 97.66208206

aDSpin0[5]  = 86.14198541
aDSpin2[5]  = 86.14181432
aDSpin4[5]  = 86.1416343
aDSpin6[5]  = 93.12699382

aDSpin0[6]  = 83.00079285
aDSpin2[6]  = 90.1887176
aDSpin4[6]  = 90.18849542
aDSpin6[6]  = 97.77453056

aDSpin0[7]  = 86.96323634
aDSpin2[7]  = 86.96323917
aDSpin4[7]  = 94.08872525
aDSpin6[7]  = 102.2446266

aDSpin0[8]  = 91.02429124
aDSpin2[8]  = 91.02481701
aDSpin4[8]  = 98.09941351
aDSpin6[8]  = 106.8629721

aDSpin0[9]  = 95.04278442
aDSpin2[9]  = 95.04278337
aDSpin4[9]  = 102.1205582
aDSpin6[9]  = 102.1202237

aDSpin0[10] = 99.1303005
aDSpin2[10] = 99.18499089
aDSpin4[10] = 99.18492657
aDSpin6[10] = 106.5759939

aDSpin0[11] = 103.2926296
aDSpin2[11] = 103.2928382
aDSpin4[11] = 103.4722041
aDSpin6[11] = 111.2236468

aDSpin0[12] = 107.5233985
aDSpin2[12] = 107.5266802
aDSpin4[12] = 107.6569383
aDSpin6[12] = 115.9943327

aDSpin0[13] = 111.7580728
aDSpin2[13] = 111.7579433
aDSpin4[13] = 111.8128682
aDSpin6[13] = 120.7014697

aDSpin0[14] = 116.0419147
aDSpin2[14] = 116.0418273
aDSpin4[14] = 116.0419753
aDSpin6[14] = 125.3325422

aDSpin0[15] = 120.3413094
aDSpin2[15] = 120.3413322
aDSpin4[15] = 120.3414752
aDSpin6[15] = 120.3411845

aDSpin0[16] = 125.2488086
aDSpin2[16] = 125.2487719
aDSpin4[16] = 125.2487141
aDSpin6[16] = 134.4556679

aDSpin0[17] = 130.1597005
aDSpin2[17] = 130.1597112
aDSpin4[17] = 130.233651
aDSpin6[17] = 139.2353333

aDSpin0[18] = 135.1103527
aDSpin2[18] = 135.1133529
aDSpin4[18] = 135.2146321
aDSpin6[18] = 144.1378035

aDSpin0[19] = 140.028541
aDSpin2[19] = 140.0268583
aDSpin4[19] = 140.1504712
aDSpin6[19] = 158.5062416

aDSpin0[20] = 144.9968464
aDSpin2[20] = 144.9968406
aDSpin4[20] = 144.9967619
aDSpin6[20] = -1

aDSpin0[21] = 150.0614947
aDSpin2[21] = 150.0612478
aDSpin4[21] = 159.3347018
aDSpin6[21] = -1

aDSpin0[22] = 155.1606758
aDSpin2[22] = 155.1670294
aDSpin4[22] = 164.4510243
aDSpin6[22] = -1

aDSpin0[23] = 160.2333465
aDSpin2[23] = 160.2333468
aDSpin4[23] = -1
aDSpin6[23] = -1

aDSpin0[24] = 165.3907984
aDSpin2[24] = 174.8803522
aDSpin4[24] = -1
aDSpin6[24] = -1

# Plots

fig0 = figure(figsize=(16, 7), dpi=80)
fig0.suptitle('Energy as a Function of Total M and Total Spin')

plot0 = fig0.add_subplot(121)
plot0.set_title("6 electrons, $\omega = 0.01$")
plot0.set_xlabel("Total M")
plot0.set_ylabel("$E_0 (\hbar\omega)$")
plot0.plot(aASpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot0.plot(aASpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot0.plot(aASpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot0.plot(aASpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot0.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot0.set_xlim((-1, 25))
plot0.set_ylim((0.715, 0.845))
xax = plot0.xaxis
yax = plot0.yaxis
xax.set_ticks(linspace(0, 24, 13))
yax.set_ticks(linspace(0.72, 0.84, 13))

plot1 = fig0.add_subplot(122)
plot1.set_title("6 electrons, $\omega = 0.1$")
plot1.set_xlabel("Total M")
plot1.set_ylabel("$E_0 (\hbar\omega)$")
plot1.plot(aBSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot1.plot(aBSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot1.plot(aBSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot1.plot(aBSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot1.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot1.set_xlim((-1, 25))
plot1.set_ylim((3.55, 5.1))
xax = plot1.xaxis
yax = plot1.yaxis
xax.set_ticks(linspace(0, 24, 13))
yax.set_ticks(linspace(3.5, 5.0, 16))


fig1 = figure(figsize=(16, 7), dpi=80)
fig1.suptitle('Energy as a Function of Total M and Total Spin')

plot2 = fig1.add_subplot(121)
plot2.set_title("6 electrons, $\omega = 1.0$")
plot2.set_xlabel("Total M")
plot2.set_ylabel("$E_0 (\hbar\omega)$")
plot2.plot(aCSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot2.plot(aCSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot2.plot(aCSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot2.plot(aCSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot2.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot2.set_xlim((-1, 25))
plot2.set_ylim((19.5, 39))
xax = plot2.xaxis
yax = plot2.yaxis
xax.set_ticks(linspace(0, 24, 13))
yax.set_ticks(linspace(20, 38, 10))

plot3 = fig1.add_subplot(122)
plot3.set_title("6 electrons, $\omega = 5.0$")
plot3.set_xlabel("Total M")
plot3.set_ylabel("$E_0 (\hbar\omega)$")
plot3.plot(aDSpin0, ' ', marker='s', markersize=8, mfc='white', mec='black', label='Total Spin 0/2')
plot3.plot(aDSpin2, ' ', marker='^', markersize=8, mfc='white', mec='black', label='Total Spin 2/2')
plot3.plot(aDSpin4, ' ', marker='+', markersize=8, mfc='white', mec='black', label='Total Spin 4/2')
plot3.plot(aDSpin6, ' ', marker='o', markersize=8, mfc='white', mec='black', label='Total Spin 6/2')
plot3.legend(bbox_to_anchor=(0.05, 0.95), loc=2, ncol=1, borderaxespad=0.)
plot3.set_xlim((-1, 25))
plot3.set_ylim((72, 178))
xax = plot3.xaxis
yax = plot3.yaxis
xax.set_ticks(linspace(0, 24, 13))
yax.set_ticks(linspace(80, 170, 10))

show()
