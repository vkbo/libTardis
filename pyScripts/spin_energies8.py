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

aASpin0[0]  = 1.266903986
aASpin2[0]  = 1.26688268
aASpin4[0]  = 1.266871791
aASpin6[0]  = 1.270947627
aASpin8[0]  = 1.279507117

aASpin0[1]  = 1.266923007
aASpin2[1]  = 1.266932324
aASpin4[1]  = 1.266936034
aASpin6[1]  = 1.266913759
aASpin8[1]  = 1.281156304

aASpin0[2]  = 1.26685638
aASpin2[2]  = 1.266857782
aASpin4[2]  = 1.266853643
aASpin6[2]  = 1.272026591
aASpin8[2]  = 1.281060641

aASpin0[3]  = 1.267158775
aASpin2[3]  = 1.267137214
aASpin4[3]  = 1.267135331
aASpin6[3]  = 1.268673031
aASpin8[3]  = 1.282327955

aASpin0[4]  = 1.268128094
aASpin2[4]  = 1.268127218
aASpin4[4]  = 1.269420991
aASpin6[4]  = 1.273081119
aASpin8[4]  = 1.274341099

aASpin0[5]  = 1.268086908
aASpin2[5]  = 1.268087124
aASpin4[5]  = 1.269816305
aASpin6[5]  = 1.271511794
aASpin8[5]  = 1.273354422

aASpin0[6]  = 1.269083692
aASpin2[6]  = 1.271402607
aASpin4[6]  = 1.271403355
aASpin6[6]  = 1.274140371
aASpin8[6]  = 1.287936707

aASpin0[7]  = 1.271281813
aASpin2[7]  = 1.271283138
aASpin4[7]  = 1.27216965
aASpin6[7]  = 1.274546551
aASpin8[7]  = 1.286867802

aASpin0[8]  = 1.272320762
aASpin2[8]  = 1.27223939
aASpin4[8]  = 1.275771791
aASpin6[8]  = 1.277037903
aASpin8[8]  = 1.295287056

aASpin0[9]  = 1.274282625
aASpin2[9]  = 1.274063608
aASpin4[9]  = 1.276126912
aASpin6[9]  = 1.277787104
aASpin8[9]  = 1.288057481

aASpin0[10] = 1.275668006
aASpin2[10] = 1.277618259
aASpin4[10] = 1.277640955
aASpin6[10] = 1.281382921
aASpin8[10] = 1.297871875

aASpin0[11] = 1.277481209
aASpin2[11] = 1.277479452
aASpin4[11] = 1.279819598
aASpin6[11] = 1.282547337
aASpin8[11] = 1.285724681

aASpin0[12] = 1.281136827
aASpin2[12] = 1.28112049
aASpin4[12] = 1.28217599
aASpin6[12] = 1.286526888
aASpin8[12] = 1.287863762

aASpin0[13] = 1.283319357
aASpin2[13] = 1.283318201
aASpin4[13] = 1.283311215
aASpin6[13] = 1.285646601
aASpin8[13] = 1.312916312

aASpin0[14] = 1.28534837
aASpin2[14] = 1.285346614
aASpin4[14] = 1.285340746
aASpin6[14] = 1.292332546
aASpin8[14] = 1.311102313

aASpin0[15] = 1.288673544
aASpin2[15] = 1.28867262
aASpin4[15] = 1.289519583
aASpin6[15] = 1.289510195
aASpin8[15] = 1.312132323

aASpin0[16] = 1.291646487
aASpin2[16] = 1.29164748
aASpin4[16] = 1.292014948
aASpin6[16] = 1.298740087
aASpin8[16] = 1.32503532

aASpin0[17] = 1.294657239
aASpin2[17] = 1.294672235
aASpin4[17] = 1.29523846
aASpin6[17] = 1.295283987
aASpin8[17] = 1.319276839

aASpin0[18] = 1.297973846
aASpin2[18] = 1.297997688
aASpin4[18] = 1.298012947
aASpin6[18] = 1.30802802
aASpin8[18] = 1.354832286

aASpin0[19] = 1.30141646
aASpin2[19] = 1.301473801
aASpin4[19] = 1.302528326
aASpin6[19] = 1.302542746
aASpin8[19] = 1.357018036

aASpin0[20] = 1.304462501
aASpin2[20] = 1.304465849
aASpin4[20] = 1.306709581
aASpin6[20] = 1.331633357
aASpin8[20] = 1.373123766

aASpin0[21] = 1.308879756
aASpin2[21] = 1.30887724
aASpin4[21] = 1.310050742
aASpin6[21] = 1.335374924
aASpin8[21] = 1.405126587

aASpin0[22] = 1.311437124
aASpin2[22] = 1.314535201
aASpin4[22] = 1.314512623
aASpin6[22] = 1.344666632
aASpin8[22] = -1

aASpin0[23] = 1.318261732
aASpin2[23] = 1.318266131
aASpin4[23] = 1.318259972
aASpin6[23] = 1.348708032
aASpin8[23] = -1

aASpin0[24] = 1.321100163
aASpin2[24] = 1.321099425
aASpin4[24] = 1.334090551
aASpin6[24] = 1.383299548
aASpin8[24] = -1

aASpin0[25] = 1.327390455
aASpin2[25] = 1.327394541
aASpin4[25] = 1.355653311
aASpin6[25] = 1.394980159
aASpin8[25] = -1

aASpin0[26] = 1.332623749
aASpin2[26] = 1.342889818
aASpin4[26] = 1.359192049
aASpin6[26] = -1
aASpin8[26] = -1

aASpin0[27] = 1.337780822
aASpin2[27] = 1.337780853
aASpin4[27] = 1.373296601
aASpin6[27] = -1
aASpin8[27] = -1

aASpin0[28] = 1.352192999
aASpin2[28] = 1.376399277
aASpin4[28] = 1.431911376
aASpin6[28] = -1
aASpin8[28] = -1

aASpin0[29] = 1.384067692
aASpin2[29] = 1.384067692
aASpin4[29] = -1
aASpin6[29] = -1
aASpin8[29] = -1

aASpin0[30] = 1.428693193
aASpin2[30] = -1
aASpin4[30] = -1
aASpin6[30] = -1
aASpin8[30] = -1

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

aBSpin0[2] =  6.079782864
aBSpin2[2] =  6.079771188
aBSpin4[2] =  6.102718093
aBSpin6[2] =  6.130976416
aBSpin8[2] =  6.19739919

aBSpin0[3]  = 6.100743334
aBSpin2[3]  = 6.100718184
aBSpin4[3]  = 6.123598515
aBSpin6[3]  = 6.123592284
aBSpin8[3]  = 6.26096219

aBSpin0[4]  = 6.090732399
aBSpin2[4]  = 6.113072737
aBSpin4[4]  = 6.113080425
aBSpin6[4]  = 6.14557743
aBSpin8[4]  = 6.195880527

aBSpin0[5]  = 6.10766414
aBSpin2[5]  = 6.107652445
aBSpin4[5]  = 6.143896235
aBSpin6[5]  = 6.18634635
aBSpin8[5]  = 6.298900368

aBSpin0[6]  = 6.135044862
aBSpin2[6]  = 6.140804531
aBSpin4[6]  = 6.1407693
aBSpin6[6]  = 6.209126426
aBSpin8[6]  = 6.32695564

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
aCSpin2[7]  = 35.04156541
aCSpin4[7]  = 35.04155881
aCSpin6[7]  = 36.06735405
aCSpin8[7]  = 36.96127165

aCSpin0[8]  = 34.6304214
aCSpin2[8]  = 34.6304253
aCSpin4[8]  = 35.59048774
aCSpin6[8]  = 36.62801322
aCSpin8[8]  = 37.76951361

aCSpin0[9]  = 35.21822004
aCSpin2[9]  = 35.21818283
aCSpin4[9]  = 36.19700762
aCSpin6[9]  = 36.24641858
aCSpin8[9]  = 38.57376569

aCSpin0[10] = 35.83421102
aCSpin2[10] = 35.8340835
aCSpin4[10] = 35.93992357
aCSpin6[10] = 36.83199133
aCSpin8[10] = 37.78497267

aCSpin0[11] = 36.49539739
aCSpin2[11] = 36.49538199
aCSpin4[11] = 36.53663775
aCSpin6[11] = 37.45260974
aCSpin8[11] = 38.69062017

aCSpin0[12] = 36.03196999
aCSpin2[12] = 37.15129466
aCSpin4[12] = 37.1514258
aCSpin6[12] = 38.06537997
aCSpin8[12] = 39.46005576

aCSpin0[13] = 36.83440998
aCSpin2[13] = 36.83439809
aCSpin4[13] = 37.81946526
aCSpin6[13] = 38.75757844
aCSpin8[13] = 40.25792524

aCSpin0[14] = 37.45904042
aCSpin2[14] = 37.45901316
aCSpin4[14] = 38.4663136
aCSpin6[14] = 38.52569626
aCSpin8[14] = 39.38519322

aCSpin0[15] = 38.1789573
aCSpin2[15] = 38.17894885
aCSpin4[15] = 39.17914405
aCSpin6[15] = 39.24512413
aCSpin8[15] = 40.25260952

aCSpin0[16] = 38.89798027
aCSpin2[16] = 38.89797518
aCSpin4[16] = 38.89620906
aCSpin6[16] = 39.88220376
aCSpin8[16] = 40.9579038

aCSpin0[17] = 39.60341135
aCSpin2[17] = 39.63061418
aCSpin4[17] = 39.69564654
aCSpin6[17] = 40.62939703
aCSpin8[17] = 42.01515813

aCSpin0[18] = 40.32377587
aCSpin2[18] = 40.32367459
aCSpin4[18] = 40.3577657
aCSpin6[18] = 41.40267233
aCSpin8[18] = 42.7375795

aCSpin0[19] = 41.11257136
aCSpin2[19] = 41.11241195
aCSpin4[19] = 41.17665108
aCSpin6[19] = 42.22006868
aCSpin8[19] = 43.72282173

aCSpin0[20] = 41.84768444
aCSpin2[20] = 41.86345441
aCSpin4[20] = 41.89508274
aCSpin6[20] = 43.05018908
aCSpin8[20] = 44.64518832

aCSpin0[21] = 42.71533213
aCSpin2[21] = 42.70879866
aCSpin4[21] = 42.78014797
aCSpin6[21] = 43.92463024
aCSpin8[21] = 46.98071726

aCSpin0[22] = 43.48440902
aCSpin2[22] = 43.4842941
aCSpin4[22] = 43.50895819
aCSpin6[22] = 44.89255511
aCSpin8[22] = -1

aCSpin0[23] = 44.34747308
aCSpin2[23] = 44.34745812
aCSpin4[23] = 44.36624848
aCSpin6[23] = 45.84793222
aCSpin8[23] = -1

aCSpin0[24] = 45.17957675
aCSpin2[24] = 45.17962322
aCSpin4[24] = 45.17953132
aCSpin6[24] = 48.28963144
aCSpin8[24] = -1

aCSpin0[25] = 46.09646468
aCSpin2[25] = 46.09644987
aCSpin4[25] = 47.65010365
aCSpin6[25] = 49.23812531
aCSpin8[25] = -1

aCSpin0[26] = 47.02772212
aCSpin2[26] = 47.05426118
aCSpin4[26] = 48.62811349
aCSpin6[26] = -1
aCSpin8[26] = -1

aCSpin0[27] = 48.02523632
aCSpin2[27] = 48.02523561
aCSpin4[27] = 49.62334582
aCSpin6[27] = -1
aCSpin8[27] = -1

aCSpin0[28] = 49.06140402
aCSpin2[28] = 50.6320279
aCSpin4[28] = 52.25405616
aCSpin6[28] = -1
aCSpin8[28] = -1

aCSpin0[29] = 51.62778758
aCSpin2[29] = 51.62778757
aCSpin4[29] = -1
aCSpin6[29] = -1
aCSpin8[29] = -1

aCSpin0[30] = 54.40077594
aCSpin2[30] = -1
aCSpin4[30] = -1
aCSpin6[30] = -1
aCSpin8[30] = -1

# Omega = 5.0 Values

aDSpin0[0]  = 122.3331528
aDSpin2[0]  = 122.3331174
aDSpin4[0]  = 129.1341361
aDSpin6[0]  = 136.3144177
aDSpin8[0]  = 142.9644415

aDSpin0[1]  = 125.6679462
aDSpin2[1]  = 125.6664351
aDSpin4[1]  = 125.6663936
aDSpin6[1]  = 133.0502751
aDSpin8[1]  = 147.5717856

aDSpin0[2]  = 122.5349138
aDSpin2[2]  = 122.5333866
aDSpin4[2]  = 129.1465989
aDSpin6[2]  = 136.1647725
aDSpin8[2]  = 143.256606

aDSpin0[3]  = 125.9831325
aDSpin2[3]  = 125.9833265
aDSpin4[3]  = 132.45849
aDSpin6[3]  = 132.4580536
aDSpin8[3]  = 147.75631

aDSpin0[4]  = 122.5599209
aDSpin2[4]  = 129.4387289
aDSpin4[4]  = 129.4376723
aDSpin6[4]  = 136.2531918
aDSpin8[4]  = 143.192713

aDSpin0[5]  = 126.1544322
aDSpin2[5]  = 126.1540719
aDSpin4[5]  = 133.1393691
aDSpin6[5]  = 140.0688807
aDSpin8[5]  = 147.8028079

aDSpin0[6]  = 129.7693116
aDSpin2[6]  = 129.7695298
aDSpin4[6]  = 129.769255
aDSpin6[6]  = 137.1671912
aDSpin8[6]  = 152.078177

aDSpin0[7]  = 133.5600093
aDSpin2[7]  = 133.5605602
aDSpin4[7]  = 133.5596967
aDSpin6[7]  = 140.7909835
aDSpin8[7]  = 147.4917196

aDSpin0[8]  = 130.2567073
aDSpin2[8]  = 130.2566913
aDSpin4[8]  = 137.3288969
aDSpin6[8]  = 144.5132025
aDSpin8[8]  = 151.9728933

aDSpin0[9]  = 134.0809832
aDSpin2[9]  = 134.0810009
aDSpin4[9]  = 141.1321429
aDSpin6[9]  = 141.129364
aDSpin8[9]  = 156.4552727

aDSpin0[10] = 137.9877784
aDSpin2[10] = 138.1001317
aDSpin4[10] = 138.1036517
aDSpin6[10] = 144.9949126
aDSpin8[10] = 152.0130251

aDSpin0[11] = 141.9895662
aDSpin2[11] = 141.9900458
aDSpin4[11] = 141.9877496
aDSpin6[11] = 148.9476452
aDSpin8[11] = 156.7072137

aDSpin0[12] = 138.5374703
aDSpin2[12] = 145.929429
aDSpin4[12] = 145.9290448
aDSpin6[12] = 152.8869702
aDSpin8[12] = 160.9966711

aDSpin0[13] = 142.7543858
aDSpin2[13] = 142.7543916
aDSpin4[13] = 150.0140337
aDSpin6[13] = 156.9454615
aDSpin8[13] = 165.5217086

aDSpin0[14] = 146.7734931
aDSpin2[14] = 146.7734814
aDSpin4[14] = 154.0322223
aDSpin6[14] = 154.0309143
aDSpin8[14] = 160.8580421

aDSpin0[15] = 150.9294454
aDSpin2[15] = 150.9293488
aDSpin4[15] = 158.160573
aDSpin6[15] = 158.2721355
aDSpin8[15] = 165.4901743

aDSpin0[16] = 155.0483319
aDSpin2[16] = 155.0478012
aDSpin4[16] = 155.0477404
aDSpin6[16] = 162.2724623
aDSpin8[16] = 169.7595621

aDSpin0[17] = 159.3250802
aDSpin2[17] = 159.3231807
aDSpin4[17] = 159.4972882
aDSpin6[17] = 166.5732644
aDSpin8[17] = 174.6785229

aDSpin0[18] = 163.4659138
aDSpin2[18] = 163.4660307
aDSpin4[18] = 163.5653591
aDSpin6[18] = 170.9584931
aDSpin8[18] = 178.9996357

aDSpin0[19] = 167.9121632
aDSpin2[19] = 167.911517
aDSpin4[19] = 168.0387678
aDSpin6[19] = 175.3988381
aDSpin8[19] = 183.9553077

aDSpin0[20] = 172.1319718
aDSpin2[20] = 172.2042057
aDSpin4[20] = 172.3140208
aDSpin6[20] = 179.9180028
aDSpin8[20] = 188.5600641

aDSpin0[21] = 176.7364004
aDSpin2[21] = 176.7217292
aDSpin4[21] = 176.886363
aDSpin6[21] = 184.5709072
aDSpin8[21] = 202.0919088

aDSpin0[22] = 181.0904542
aDSpin2[22] = 181.0911698
aDSpin4[22] = 181.1837193
aDSpin6[22] = 189.3507333
aDSpin8[22] = -1

aDSpin0[23] = 185.6870663
aDSpin2[23] = 185.6875357
aDSpin4[23] = 185.8462022
aDSpin6[23] = 194.2650901
aDSpin8[23] = -1

aDSpin0[24] = 190.1983866
aDSpin2[24] = 190.1983948
aDSpin4[24] = 190.1978691
aDSpin6[24] = 207.9558287
aDSpin8[24] = -1

aDSpin0[25] = 195.0726964
aDSpin2[25] = 195.0724264
aDSpin4[25] = 203.9945498
aDSpin6[25] = 212.8257539
aDSpin8[25] = -1

aDSpin0[26] = 200.0439117
aDSpin2[26] = 200.0456271
aDSpin4[26] = 208.9006572
aDSpin6[26] = -1
aDSpin8[26] = -1

aDSpin0[27] = 205.0186504
aDSpin2[27] = 205.0186608
aDSpin4[27] = 213.8698538
aDSpin6[27] = -1
aDSpin8[27] = -1

aDSpin0[28] = 210.173238
aDSpin2[28] = 219.0147032
aDSpin4[28] = 228.0595259
aDSpin6[28] = -1
aDSpin8[28] = -1

aDSpin0[29] = 224.0794444
aDSpin2[29] = 224.0794295
aDSpin4[29] = -1
aDSpin6[29] = -1
aDSpin8[29] = -1

aDSpin0[30] = 238.5650711
aDSpin2[30] = -1
aDSpin4[30] = -1
aDSpin6[30] = -1
aDSpin8[30] = -1

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
plot0.set_ylim((1.26, 1.44))
xax = plot0.xaxis
yax = plot0.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(1.27, 1.43, 9))

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
plot1.set_ylim((6.05, 6.95))
xax = plot1.xaxis
yax = plot1.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(6.1, 6.9, 9))


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
plot2.set_ylim((33, 55))
xax = plot2.xaxis
yax = plot2.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(34, 54, 11))

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
plot3.set_ylim((118, 242))
xax = plot3.xaxis
yax = plot3.yaxis
xax.set_ticks(linspace(0, 30, 16))
yax.set_ticks(linspace(120, 240, 13))

show()
