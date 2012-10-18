#!/usr/bin/env python

from numpy import array, zeros, linspace
from matplotlib.pyplot import *

# Data

aLzVStd = zeros((29,4),float)
aLzVEff = zeros((29,4),float)
aLzVCut = zeros((29,4),float)
aDiVStd = zeros((29,4),float)
aDiVEff = zeros((29,4),float)
aDiVCut = zeros((29,4),float)
aShells = linspace(2,30,29)

# Lanczos Runs
###############

# 2 Shells
aLzVCut[0,0]  = 0.4           # 2012-06-05 14:12:59	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy:         0.4	| Exec: 83ms
aLzVEff[0,0]  = 0.4716227724  # 2012-05-29 17:32:13	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4716227724	| Exec: 335ms
aLzVStd[0,0]  = 0.5125198414  # 2012-05-29 17:32:19	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.5125198414	| Exec: 14ms
aLzVCut[0,1]  = 1.021644014   # 2012-06-05 14:13:01	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644014	| Exec: 22ms
aLzVEff[0,1]  = 1.06693768    # 2012-05-31 17:59:33	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.06693768	| Exec: 47ms
aLzVStd[0,1]  = 1.127251038   # 2012-05-31 17:59:36	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.127251038	| Exec: 5ms
aLzVCut[0,2]  = 1.65977215    # 2012-06-05 14:13:02	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.65977215	| Exec: 59ms
aLzVEff[0,2]  = 1.71357741    # 2012-05-29 17:32:20	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy:  1.71357741	| Exec: 42ms
aLzVStd[0,2]  = 1.78691353    # 2012-05-29 17:32:21	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy:  1.78691353	| Exec: 15ms
aLzVCut[0,3]  = 3.0           # 2012-06-05 14:13:04	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:           3	| Exec: 43ms
aLzVEff[0,3]  = 3.063440415   # 2012-05-29 17:32:22	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.063440415	| Exec: 58ms
aLzVStd[0,3]  = 3.152328007   # 2012-05-29 17:32:24	| Node: TheBeast	| P 2, Sh 2, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.152328007	| Exec: 13ms

# 3 Shells
aLzVCut[1,0]  = 0.440791888   # 2012-06-05 14:13:05	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.440791888	| Exec: 43ms
aLzVEff[1,0]  = 0.4408842465  # 2012-05-29 17:32:25	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408842465	| Exec: 162ms
aLzVStd[1,0]  = 0.4421887603  # 2012-05-29 17:32:26	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4421887603	| Exec: 22ms
aLzVCut[1,1]  = 1.021644014   # 2012-06-05 14:13:07	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644014	| Exec: 128ms
aLzVEff[1,1]  = 1.023735252   # 2012-05-31 17:59:39	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.023735252	| Exec: 89ms
aLzVStd[1,1]  = 1.032681475   # 2012-05-31 17:59:42	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.032681475	| Exec: 6ms
aLzVCut[1,2]  = 1.65977215    # 2012-06-05 14:13:08	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.65977215	| Exec: 43ms
aLzVEff[1,2]  = 1.664345672   # 2012-05-29 17:32:28	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.664345672	| Exec: 104ms
aLzVStd[1,2]  = 1.681632649   # 2012-05-29 17:32:29	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.681632649	| Exec: 18ms
aLzVCut[1,3]  = 3.0           # 2012-06-05 14:13:10	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:           3	| Exec: 49ms
aLzVEff[1,3]  = 3.008602486   # 2012-05-29 17:32:30	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.008602486	| Exec: 115ms
aLzVStd[1,3]  = 3.038604721   # 2012-05-29 17:32:31	| Node: TheBeast	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.038604721	| Exec: 15ms

# 4 Shells
aLzVCut[2,0]  = 0.440791888   # 2012-06-05 14:13:11	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.440791888	| Exec: 85ms
aLzVEff[2,0]  = 0.4408949429  # 2012-05-29 17:32:33	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408949429	| Exec: 169ms
aLzVStd[2,0]  = 0.441869139   # 2012-05-29 17:32:34	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441869139	| Exec: 32ms
aLzVCut[2,1]  = 1.021644014   # 2012-06-05 14:13:13	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644014	| Exec: 91ms
aLzVEff[2,1]  = 1.022974723   # 2012-05-31 17:59:45	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022974723	| Exec: 192ms
aLzVStd[2,1]  = 1.02880398    # 2012-05-31 17:59:48	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy:  1.02880398	| Exec: 25ms
aLzVCut[2,2]  = 1.65977215    # 2012-06-05 14:13:14	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.65977215	| Exec: 148ms
aLzVEff[2,2]  = 1.662657983   # 2012-05-29 17:32:35	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.662657983	| Exec: 182ms
aLzVStd[2,2]  = 1.673872492   # 2012-05-29 17:32:37	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.673872492	| Exec: 39ms
aLzVCut[2,3]  = 3.0           # 2012-06-05 14:13:16	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:           3	| Exec: 172ms
aLzVEff[2,3]  = 3.005519052   # 2012-05-29 17:32:38	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.005519052	| Exec: 197ms
aLzVStd[2,3]  = 3.025230938   # 2012-05-29 17:32:39	| Node: TheBeast	| P 2, Sh 4, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.025230938	| Exec: 30ms

# 5 Shells
aLzVCut[3,0]  = 0.4407918916  # 2012-06-05 14:13:17	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407918916	| Exec: 129ms
aLzVEff[3,0]  = 0.4408708071  # 2012-05-29 17:32:40	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408708071	| Exec: 295ms
aLzVStd[3,0]  = 0.4416144253  # 2012-05-29 17:32:42	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4416144253	| Exec: 79ms
aLzVCut[3,1]  = 1.021644027   # 2012-06-05 14:13:19	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644027	| Exec: 196ms
aLzVEff[3,1]  = 1.022381355   # 2012-05-31 17:59:51	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022381355	| Exec: 325ms
aLzVStd[3,1]  = 1.026588201   # 2012-05-31 17:59:54	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.026588201	| Exec: 104ms
aLzVCut[3,2]  = 1.659772168   # 2012-06-05 14:13:20	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659772168	| Exec: 269ms
aLzVEff[3,2]  = 1.661390061   # 2012-05-29 17:32:43	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.661390061	| Exec: 312ms
aLzVStd[3,2]  = 1.669500949   # 2012-05-29 17:32:45	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.669500949	| Exec: 68ms
aLzVCut[3,3]  = 3.00000002    # 2012-06-05 14:13:22	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:  3.00000002	| Exec: 270ms
aLzVEff[3,3]  = 3.003199953   # 2012-05-29 17:32:46	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.003199953	| Exec: 302ms
aLzVStd[3,3]  = 3.017608018   # 2012-05-29 17:32:47	| Node: TheBeast	| P 2, Sh 5, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.017608018	| Exec: 62ms

# 6 Shells
aLzVCut[4,0]  = 0.4407919062  # 2012-06-05 14:13:24	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407919062	| Exec: 263ms
aLzVEff[4,0]  = 0.440852998   # 2012-05-29 17:32:49	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.440852998	| Exec: 532ms
aLzVStd[4,0]  = 0.4414467908  # 2012-05-29 17:32:50	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4414467908	| Exec: 193ms
aLzVCut[4,1]  = 1.021644086   # 2012-06-05 14:13:26	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644086	| Exec: 268ms
aLzVEff[4,1]  = 1.022163815   # 2012-05-31 17:59:57	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022163815	| Exec: 563ms
aLzVStd[4,1]  = 1.025449495   # 2012-05-31 18:00:01	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.025449495	| Exec: 241ms
aLzVCut[4,2]  = 1.65977229    # 2012-06-05 14:13:27	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.65977229	| Exec: 259ms
aLzVEff[4,2]  = 1.660916639   # 2012-05-29 17:32:52	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660916639	| Exec: 519ms
aLzVStd[4,2]  = 1.667258338   # 2012-05-29 17:32:53	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.667258338	| Exec: 186ms
aLzVCut[4,3]  = 3.000000176   # 2012-06-05 14:13:29	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000000176	| Exec: 263ms
aLzVEff[4,3]  = 3.002285098   # 2012-05-29 17:32:55	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.002285098	| Exec: 515ms
aLzVStd[4,3]  = 3.013634648   # 2012-05-29 17:32:56	| Node: TheBeast	| P 2, Sh 6, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.013634648	| Exec: 150ms

# 7 Shells
aLzVCut[5,0]  = 0.440791899   # 2012-06-05 14:13:31	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.440791899	| Exec: 524ms
aLzVEff[5,0]  = 0.4408396949  # 2012-05-29 17:32:58	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408396949	| Exec: 990ms
aLzVStd[5,0]  = 0.4413299429  # 2012-05-29 17:33:00	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4413299429	| Exec: 552ms
aLzVCut[5,1]  = 1.02164404    # 2012-06-05 14:13:32	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.02164404	| Exec: 488ms
aLzVEff[5,1]  = 1.022025565   # 2012-05-31 18:00:04	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022025565	| Exec: 1s 17ms
aLzVStd[5,1]  = 1.024706611   # 2012-05-31 18:00:08	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.024706611	| Exec: 544ms
aLzVCut[5,2]  = 1.65977218    # 2012-06-05 14:13:34	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy:  1.65977218	| Exec: 502ms
aLzVEff[5,2]  = 1.660611515   # 2012-05-29 17:33:02	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660611515	| Exec: 1s 12ms
aLzVStd[5,2]  = 1.665799928   # 2012-05-29 17:33:04	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.665799928	| Exec: 525ms
aLzVCut[5,3]  = 3.000000026   # 2012-06-05 14:13:36	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000000026	| Exec: 532ms
aLzVEff[5,3]  = 3.001694057   # 2012-05-29 17:33:06	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001694057	| Exec: 998ms
aLzVStd[5,3]  = 3.011025544   # 2012-05-29 17:33:08	| Node: TheBeast	| P 2, Sh 7, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.011025544	| Exec: 484ms

# 8 Shells
aLzVCut[6,0]  = 0.4407920511  # 2012-06-05 14:13:38	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407920511	| Exec: 870ms
aLzVEff[6,0]  = 0.4408306209  # 2012-05-29 17:33:09	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408306209	| Exec: 1s 981ms
aLzVStd[6,0]  = 0.4412463975  # 2012-05-29 17:33:13	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4412463975	| Exec: 1s 406ms
aLzVCut[6,1]  = 1.021644024   # 2012-06-05 14:13:41	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021644024	| Exec: 960ms
aLzVEff[6,1]  = 1.021942995   # 2012-05-31 18:00:12	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021942995	| Exec: 1s 634ms
aLzVStd[6,1]  = 1.024200183   # 2012-05-31 18:00:17	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.024200183	| Exec: 907ms
aLzVCut[6,2]  = 1.659772165   # 2012-06-05 14:13:43	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659772165	| Exec: 934ms
aLzVEff[6,2]  = 1.660428851   # 2012-05-29 17:33:15	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660428851	| Exec: 1s 923ms
aLzVStd[6,2]  = 1.664807378   # 2012-05-29 17:33:18	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.664807378	| Exec: 1s 327ms
aLzVCut[6,3]  = 3.000001217   # 2012-06-05 14:13:45	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000001217	| Exec: 905ms
aLzVEff[6,3]  = 3.001328913   # 2012-05-29 17:33:21	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001328913	| Exec: 1s 925ms
aLzVStd[6,3]  = 3.009238286   # 2012-05-29 17:33:24	| Node: TheBeast	| P 2, Sh 8, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.009238286	| Exec: 1s 261ms

# 9 Shells
aLzVCut[7,0]  = 0.4407926039  # 2012-06-05 14:13:48	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407926039	| Exec: 1s 732ms
aLzVEff[7,0]  = 0.4408246799  # 2012-05-29 17:33:26	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408246799	| Exec: 3s 801ms
aLzVStd[7,0]  = 0.4411842403  # 2012-05-29 17:33:31	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4411842403	| Exec: 3s 155ms
aLzVCut[7,1]  = 1.021645498   # 2012-06-05 14:13:51	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.021645498	| Exec: 1s 732ms
aLzVEff[7,1]  = 1.021885342   # 2012-05-31 18:00:22	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021885342	| Exec: 2s 858ms
aLzVStd[7,1]  = 1.023832091   # 2012-05-31 18:00:27	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023832091	| Exec: 1s 925ms
aLzVCut[7,2]  = 1.659774761   # 2012-06-05 14:13:54	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659774761	| Exec: 1s 750ms
aLzVEff[7,2]  = 1.660302967   # 2012-05-29 17:33:36	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660302967	| Exec: 3s 829ms
aLzVStd[7,2]  = 1.664085835   # 2012-05-29 17:33:41	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.664085835	| Exec: 2s 880ms
aLzVCut[7,3]  = 3.00000369    # 2012-06-05 14:13:57	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:  3.00000369	| Exec: 1s 856ms
aLzVEff[7,3]  = 3.001081738   # 2012-05-29 17:33:45	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001081738	| Exec: 3s 595ms
aLzVStd[7,3]  = 3.007932519   # 2012-05-29 17:33:49	| Node: TheBeast	| P 2, Sh 9, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.007932519	| Exec: 2s 931ms

# 10 Shells
aLzVCut[8,0]  = 0.4407919322  # 2012-06-05 14:14:00	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407919322	| Exec: 3s 798ms
aLzVEff[8,0]  = 0.4408193914  # 2012-05-29 17:33:54	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408193914	| Exec: 7s 820ms
aLzVStd[8,0]  = 0.441135621   # 2012-05-29 17:34:03	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441135621	| Exec: 7s 78ms
aLzVCut[8,1]  = 1.021645606   # 2012-06-05 14:14:06	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645606	| Exec: 3s 484ms
aLzVEff[8,1]  = 1.021845259   # 2012-05-31 18:00:33	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021845259	| Exec: 5s 239ms
aLzVStd[8,1]  = 1.023553869   # 2012-05-31 18:00:42	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023553869	| Exec: 3s 927ms
aLzVCut[8,2]  = 1.659774248   # 2012-06-05 14:14:10	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659774248	| Exec: 3s 571ms
aLzVEff[8,2]  = 1.660212772   # 2012-05-29 17:34:11	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660212772	| Exec: 7s 407ms
aLzVStd[8,2]  = 1.663538014   # 2012-05-29 17:34:19	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.663538014	| Exec: 6s 326ms
aLzVCut[8,3]  = 3.000002456   # 2012-06-05 14:14:15	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000002456	| Exec: 3s 514ms
aLzVEff[8,3]  = 3.000900173   # 2012-05-29 17:34:27	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000900173	| Exec: 7s 4ms
aLzVStd[8,3]  = 3.006944181   # 2012-05-29 17:34:35	| Node: TheBeast	| P 2, Sh 10, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.006944181	| Exec: 5s 850ms

# 11 Shells
aLzVCut[9,0]  = 0.4407927734  # 2012-06-05 16:10:05	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407927734	| Exec: 6s 529ms
aLzVEff[9,0]  = 0.4408153057  # 2012-05-29 17:34:42	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408153057	| Exec: 14s 953ms
aLzVStd[9,0]  = 0.4410981831  # 2012-05-29 17:34:58	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410981831	| Exec: 13s 670ms
aLzVCut[9,1]  = 1.021645564   # 2012-06-05 14:14:24	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645564	| Exec: 6s 774ms
aLzVEff[9,1]  = 1.021814071   # 2012-05-31 18:00:50	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021814071	| Exec: 9s 228ms
aLzVStd[9,1]  = 1.023334289   # 2012-05-31 18:01:03	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023334289	| Exec: 7s 597ms
aLzVCut[9,2]  = 1.659774026   # 2012-06-05 14:14:32	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659774026	| Exec: 6s 729ms
aLzVEff[9,2]  = 1.660145116   # 2012-05-29 17:35:13	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660145116	| Exec: 13s 963ms
aLzVStd[9,2]  = 1.663108651   # 2012-05-29 17:35:28	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.663108651	| Exec: 12s 661ms
aLzVCut[9,3]  = 3.000008434   # 2012-06-05 14:14:40	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000008434	| Exec: 6s 198ms
aLzVEff[9,3]  = 3.000777332   # 2012-05-29 17:35:42	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000777332	| Exec: 12s 492ms
aLzVStd[9,3]  = 3.006180869   # 2012-05-29 17:35:56	| Node: TheBeast	| P 2, Sh 11, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.006180869	| Exec: 11s 259ms

# 12 Shells
aLzVCut[10,0] = 0.4407920172  # 2012-06-05 14:14:48	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407920172	| Exec: 12s 153ms
aLzVEff[10,0] = 0.440813193   # 2012-05-29 17:36:08	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.440813193	| Exec: 24s 740ms
aLzVStd[10,0] = 0.4410662985  # 2012-05-29 17:36:34	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410662985	| Exec: 24s 497ms
aLzVCut[10,1] = 1.021645171   # 2012-06-05 14:15:01	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645171	| Exec: 11s 620ms
aLzVEff[10,1] = 1.021790139   # 2012-05-31 18:01:16	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021790139	| Exec: 15s 694ms
aLzVStd[10,1] = 1.023158159   # 2012-05-31 18:01:35	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023158159	| Exec: 13s 824ms
aLzVCut[10,2] = 1.659773569   # 2012-06-05 14:15:14	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659773569	| Exec: 11s 504ms
aLzVEff[10,2] = 1.660097721   # 2012-05-29 17:37:00	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660097721	| Exec: 22s 949ms
aLzVStd[10,2] = 1.662763541   # 2012-05-29 17:37:24	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662763541	| Exec: 23s 44ms
aLzVCut[10,3] = 3.000001604   # 2012-06-05 14:15:27	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000001604	| Exec: 11s 352ms
aLzVEff[10,3] = 3.000660636   # 2012-05-29 17:37:48	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000660636	| Exec: 23s 192ms
aLzVStd[10,3] = 3.005538493   # 2012-05-29 17:38:13	| Node: TheBeast	| P 2, Sh 12, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.005538493	| Exec: 21s 530ms

# 13 Shells
aLzVCut[11,0] = 0.4407924783  # 2012-06-05 14:15:40	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407924783	| Exec: 21s 749ms
aLzVEff[11,0] = 0.4408107773  # 2012-05-29 17:38:35	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408107773	| Exec: 47s 42ms
aLzVStd[11,0] = 0.441041082   # 2012-05-29 17:39:23	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441041082	| Exec: 47s 446ms
aLzVCut[11,1] = 1.021645193   # 2012-06-05 14:16:03	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645193	| Exec: 21s 528ms
aLzVEff[11,1] = 1.021772186   # 2012-05-31 18:01:55	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021772186	| Exec: 29s 439ms
aLzVStd[11,1] = 1.023014307   # 2012-05-31 18:02:28	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023014307	| Exec: 26s 36ms
aLzVCut[11,2] = 1.659773574   # 2012-06-05 14:16:26	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659773574	| Exec: 21s 699ms
aLzVEff[11,2] = 1.660052965   # 2012-05-29 17:40:12	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660052965	| Exec: 47s 111ms
aLzVStd[11,2] = 1.662481916   # 2012-05-29 17:41:00	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662481916	| Exec: 44s 835ms
aLzVCut[11,3] = 3.000001582   # 2012-06-05 14:16:49	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000001582	| Exec: 21s 890ms
aLzVEff[11,3] = 3.000575656   # 2012-05-29 17:41:46	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000575656	| Exec: 44s 530ms
aLzVStd[11,3] = 3.005019323   # 2012-05-29 17:42:32	| Node: TheBeast	| P 2, Sh 13, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.005019323	| Exec: 45s 240ms

# 14 Shells
aLzVCut[12,0] = 0.4407921639  # 2012-06-05 14:17:12	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407921639	| Exec: 37s 17ms
aLzVEff[12,0] = 0.4408085334  # 2012-05-29 17:43:19	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408085334	| Exec: 1m 21s 584ms
aLzVStd[12,0] = 0.4410193383  # 2012-05-29 17:44:41	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410193383	| Exec: 1m 22s 590ms
aLzVCut[12,1] = 1.02164449    # 2012-06-05 14:17:51	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy:  1.02164449	| Exec: 37s 887ms
aLzVEff[12,1] = 1.021756781   # 2012-05-31 18:03:02	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021756781	| Exec: 49s 756ms
aLzVStd[12,1] = 1.022893802   # 2012-05-31 18:03:57	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022893802	| Exec: 46s 576ms
aLzVCut[12,2] = 1.659772698   # 2012-06-05 14:18:30	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659772698	| Exec: 38s 150ms
aLzVEff[12,2] = 1.66001952    # 2012-05-29 17:46:05	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy:  1.66001952	| Exec: 1m 21s 670ms
aLzVStd[12,2] = 1.662245865   # 2012-05-29 17:47:28	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662245865	| Exec: 1m 18s 341ms
aLzVCut[12,3] = 3.000000568   # 2012-06-05 14:19:10	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000000568	| Exec: 38s 18ms
aLzVEff[12,3] = 3.000506251   # 2012-05-29 17:48:47	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000506251	| Exec: 1m 21s 714ms
aLzVStd[12,3] = 3.004588525   # 2012-05-29 17:50:10	| Node: TheBeast	| P 2, Sh 14, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.004588525	| Exec: 1m 19s 598ms

# 15 Shells
aLzVCut[13,0] = 0.4407928055  # 2012-06-05 14:19:49	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407928055	| Exec: 1m 1s 688ms
aLzVEff[13,0] = 0.4408066509  # 2012-05-29 17:51:31	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408066509	| Exec: 2m 23s 691ms
aLzVStd[13,0] = 0.4410019315  # 2012-05-29 17:53:56	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410019315	| Exec: 2m 19s 285ms
aLzVCut[13,1] = 1.02164524    # 2012-06-05 14:20:52	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy:  1.02164524	| Exec: 1m 2s 812ms
aLzVEff[13,1] = 1.021745869   # 2012-05-31 18:04:54	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021745869	| Exec: 1m 21s 174ms
aLzVStd[13,1] = 1.022793768   # 2012-05-31 18:06:22	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022793768	| Exec: 1m 17s 353ms
aLzVCut[13,2] = 1.659773407   # 2012-06-05 14:21:56	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659773407	| Exec: 1m 4s 20ms
aLzVEff[13,2] = 1.659994038   # 2012-05-29 17:56:17	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659994038	| Exec: 2m 17s 295ms
aLzVStd[13,2] = 1.662048307   # 2012-05-29 17:58:35	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662048307	| Exec: 2m 13s 816ms
aLzVCut[13,3] = 3.000001204   # 2012-06-05 14:23:02	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000001204	| Exec: 1m 1s 608ms
aLzVEff[13,3] = 3.000452873   # 2012-05-29 18:00:50	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000452873	| Exec: 2m 17s 352ms
aLzVStd[13,3] = 3.004226196   # 2012-05-29 18:03:09	| Node: TheBeast	| P 2, Sh 15, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.004226196	| Exec: 2m 13s 619ms

# 16 Shells
aLzVCut[14,0] = 0.4407939874  # 2012-06-05 14:24:05	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407939874	| Exec: 1m 32s 96ms
aLzVEff[14,0] = 0.4408062502  # 2012-05-29 18:05:23	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408062502	| Exec: 3m 23s 698ms
aLzVStd[14,0] = 0.4409871654  # 2012-05-29 18:08:48	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409871654	| Exec: 3m 16s 888ms
aLzVCut[14,1] = 1.02164964    # 2012-06-05 14:25:38	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy:  1.02164964	| Exec: 1m 34s 907ms
aLzVEff[14,1] = 1.021740349   # 2012-05-31 18:07:54	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021740349	| Exec: 1m 53s 241ms
aLzVStd[14,1] = 1.022708295   # 2012-05-31 18:09:57	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022708295	| Exec: 1m 55s 49ms
aLzVCut[14,2] = 1.659779658   # 2012-06-05 14:27:15	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659779658	| Exec: 1m 29s 927ms
aLzVEff[14,2] = 1.659977926   # 2012-05-29 18:12:06	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659977926	| Exec: 3m 13s 133ms
aLzVStd[14,2] = 1.661884545   # 2012-05-29 18:15:21	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661884545	| Exec: 3m 8s 779ms
aLzVCut[14,3] = 3.000008884   # 2012-06-05 14:28:46	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000008884	| Exec: 1m 29s 963ms
aLzVEff[14,3] = 3.000414612   # 2012-05-29 18:18:31	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000414612	| Exec: 3m 15s 379ms
aLzVStd[14,3] = 3.003921634   # 2012-05-29 18:21:47	| Node: TheBeast	| P 2, Sh 16, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003921634	| Exec: 3m 8s 496ms

# 17 Shells
aLzVCut[15,0] = 0.4407937987  # 2012-06-05 14:30:17	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407937987	| Exec: 2m 22s 697ms
aLzVEff[15,0] = 0.4408049143  # 2012-05-29 18:24:57	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408049143	| Exec: 5m 27s 996ms
aLzVStd[15,0] = 0.4409737481  # 2012-05-29 18:30:26	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409737481	| Exec: 5m 19s 597ms
aLzVCut[15,1] = 1.021645199   # 2012-06-05 14:32:42	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645199	| Exec: 2m 34s 801ms
aLzVEff[15,1] = 1.021734124   # 2012-05-31 18:12:14	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021734124	| Exec: 2m 58s 130ms
aLzVStd[15,1] = 1.022633487   # 2012-05-31 18:15:29	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022633487	| Exec: 3m 2s 320ms
aLzVCut[15,2] = 1.659782818   # 2012-06-05 14:35:18	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659782818	| Exec: 2m 31s 80ms
aLzVEff[15,2] = 1.659964017   # 2012-05-29 18:35:47	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659964017	| Exec: 5m 10s 65ms
aLzVStd[15,2] = 1.661742453   # 2012-05-29 18:40:58	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661742453	| Exec: 5m 160ms
aLzVCut[15,3] = 3.00001682    # 2012-06-05 14:37:50	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy:  3.00001682	| Exec: 2m 28s 92ms
aLzVEff[15,3] = 3.000385262   # 2012-05-29 18:46:00	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000385262	| Exec: 5m 9s 648ms
aLzVStd[15,3] = 3.003661506   # 2012-05-29 18:51:10	| Node: TheBeast	| P 2, Sh 17, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003661506	| Exec: 5m 133ms

# 18 Shells
aLzVCut[16,0] = 0.4407928897  # 2012-06-05 14:40:20	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407928897	| Exec: 4m 1s 477ms
aLzVEff[16,0] = 0.4408037325  # 2012-05-29 18:56:12	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408037325	| Exec: 8m 31s 187ms
aLzVStd[16,0] = 0.4409601286  # 2012-05-29 19:04:44	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409601286	| Exec: 9m 4s 919ms
aLzVCut[16,1] = 1.021645532   # 2012-06-05 14:44:23	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645532	| Exec: 4m 3s 387ms
aLzVEff[16,1] = 1.021719004   # 2012-05-31 18:19:05	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021719004	| Exec: 5m 9s 47ms
aLzVStd[16,1] = 1.022565916   # 2012-05-31 18:24:42	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022565916	| Exec: 4m 57s 957ms
aLzVCut[16,2] = 1.659773908   # 2012-06-05 14:48:27	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659773908	| Exec: 3m 59s 586ms
aLzVEff[16,2] = 1.659936114   # 2012-05-29 19:13:50	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659936114	| Exec: 8m 47s 531ms
aLzVStd[16,2] = 1.661601099   # 2012-05-29 19:22:39	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661601099	| Exec: 8m 33s 387ms
aLzVCut[16,3] = 3.000001997   # 2012-06-05 14:52:28	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000001997	| Exec: 4m 4s 512ms
aLzVEff[16,3] = 3.00034043    # 2012-05-29 19:31:14	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00034043	| Exec: 8m 25s 292ms
aLzVStd[16,3] = 3.003411079   # 2012-05-29 19:39:40	| Node: TheBeast	| P 2, Sh 18, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003411079	| Exec: 8m 10s 106ms

# 19 Shells
aLzVCut[17,0] = 0.4407938181  # 2012-06-05 14:56:34	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407938181	| Exec: 5m 33s 428ms
aLzVEff[17,0] = 0.4408043332  # 2012-05-30 15:01:19	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408043332	| Exec: 6m 54s 600ms
aLzVStd[17,0] = 0.4409508183  # 2012-05-30 15:08:37	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409508183	| Exec: 6m 55s 770ms
aLzVCut[17,1] = 1.021645932   # 2012-06-05 15:02:09	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021645932	| Exec: 5m 32s 789ms
aLzVEff[17,1] = 1.02171374    # 2012-05-31 18:30:31	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.02171374	| Exec: 6m 41s 618ms
aLzVStd[17,1] = 1.022508844   # 2012-05-31 18:37:57	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022508844	| Exec: 6m 28s 189ms
aLzVCut[17,2] = 1.659774618   # 2012-06-05 15:07:43	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659774618	| Exec: 5m 27s 905ms
aLzVEff[17,2] = 1.659923664   # 2012-05-30 15:15:34	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659923664	| Exec: 6m 52s 877ms
aLzVStd[17,2] = 1.661488638   # 2012-05-30 15:22:28	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661488638	| Exec: 6m 31s 650ms
aLzVCut[17,3] = 3.000004867   # 2012-06-05 15:13:13	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000004867	| Exec: 5m 29s 225ms
aLzVEff[17,3] = 3.000315342   # 2012-05-30 15:29:02	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000315342	| Exec: 6m 42s 443ms
aLzVStd[17,3] = 3.003206092   # 2012-05-30 15:35:45	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003206092	| Exec: 6m 5s 268ms

# 20 Shells
aLzVCut[18,0] = 0.4407925544  # 2012-06-05 15:18:43	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Lz	 | Energy: 0.4407925544	| Exec: 8m 45s 19ms
aLzVEff[18,0] = 0.4408025494  # 2012-05-30 15:41:52	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408025494	| Exec: 10m 55s 293ms
aLzVStd[18,0] = 0.4409407791  # 2012-05-30 15:52:49	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409407791	| Exec: 11m 14s 152ms
aLzVCut[18,1] = 1.021644913   # 2012-06-05 15:27:30	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Lz | Energy: 1.021644913	| Exec: 9m 8s 625ms
aLzVEff[18,1] = 1.021708017   # 2012-05-31 18:45:43	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021708017	| Exec: 11m 2s 877ms
aLzVStd[18,1] = 1.022458086   # 2012-05-31 18:57:53	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022458086	| Exec: 10m 43s 248ms
aLzVCut[18,2] = 1.659773054   # 2012-06-05 15:36:40	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Lz	 | Energy: 1.659773054	| Exec: 9m 3s 699ms
aLzVEff[18,2] = 1.659911076   # 2012-05-30 16:04:04	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659911076	| Exec: 10m 54s 538ms
aLzVStd[18,2] = 1.661387786   # 2012-05-30 16:15:00	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661387786	| Exec: 10m 47s 956ms
aLzVCut[18,3] = 3.000005185   # 2012-06-05 15:45:45	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Lz	 | Energy: 3.000005185	| Exec: 8m 27s 917ms
aLzVEff[18,3] = 3.000312309   # 2012-05-30 16:25:50	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000312309	| Exec: 10m 4s 626ms
aLzVStd[18,3] = 3.003044958   # 2012-05-30 16:35:56	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003044958	| Exec: 9m 52s 736ms


# Diag Runs
############

# 2 Shells
aDiVEff[0,0]  = 0.4716227724  # 2012-05-30 17:56:01	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4716227724	| Exec: 41ms
aDiVStd[0,0]  = 0.5125198414  # 2012-05-30 17:56:25	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.5125198414	| Exec: 4ms
aDiVEff[0,1]  = 1.06693768    # 2012-05-31 17:59:32	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.06693768	| Exec: 37ms
aDiVStd[0,1]  = 1.127251038   # 2012-05-31 17:59:35	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.127251038	| Exec: 4ms
aDiVEff[0,2]  = 1.71357741    # 2012-05-30 17:56:26	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy:  1.71357741	| Exec: 36ms
aDiVStd[0,2]  = 1.78691353    # 2012-05-30 17:56:28	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy:  1.78691353	| Exec: 4ms
aDiVEff[0,3]  = 3.063440415   # 2012-05-30 17:56:29	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.063440415	| Exec: 36ms
aDiVStd[0,3]  = 3.152328007   # 2012-05-30 17:56:30	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.152328007	| Exec: 4ms

# 3 Shells
aDiVEff[1,0]  = 0.4408841339  # 2012-05-30 17:56:32	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408841339	| Exec: 86ms
aDiVStd[1,0]  = 0.4421887603  # 2012-05-30 17:56:33	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4421887603	| Exec: 3ms
aDiVEff[1,1]  = 1.023735246   # 2012-05-31 17:59:37	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.023735246	| Exec: 86ms
aDiVStd[1,1]  = 1.032681412   # 2012-05-31 17:59:40	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.032681412	| Exec: 3ms
aDiVEff[1,2]  = 1.664345671   # 2012-05-30 17:56:35	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.664345671	| Exec: 87ms
aDiVStd[1,2]  = 1.681631996   # 2012-05-30 17:56:36	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.681631996	| Exec: 3ms
aDiVEff[1,3]  = 3.008602483   # 2012-05-30 17:56:37	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.008602483	| Exec: 87ms
aDiVStd[1,3]  = 3.038604576   # 2012-05-30 17:56:39	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.038604576	| Exec: 4ms

# 4 Shells
aDiVEff[2,0]  = 0.4408938347  # 2012-05-30 17:56:40	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408938347	| Exec: 165ms
aDiVStd[2,0]  = 0.4418679942  # 2012-05-30 17:56:42	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4418679942	| Exec: 4ms
aDiVEff[2,1]  = 1.022974149   # 2012-05-31 17:59:43	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022974149	| Exec: 162ms
aDiVStd[2,1]  = 1.028803672   # 2012-05-31 17:59:46	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.028803672	| Exec: 4ms
aDiVEff[2,2]  = 1.662657612   # 2012-05-30 17:56:43	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.662657612	| Exec: 161ms
aDiVStd[2,2]  = 1.673872389   # 2012-05-30 17:56:45	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.673872389	| Exec: 4ms
aDiVEff[2,3]  = 3.005518845   # 2012-05-30 17:56:46	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.005518845	| Exec: 161ms
aDiVStd[2,3]  = 3.025230582   # 2012-05-30 17:56:48	| Node: Sigma   	| P 2, Sh 4, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.025230582	| Exec: 4ms

# 5 Shells
aDiVEff[3,0]  = 0.4408701421  # 2012-05-30 17:56:49	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408701421	| Exec: 266ms
aDiVStd[3,0]  = 0.4416137068  # 2012-05-30 17:56:51	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4416137068	| Exec: 5ms
aDiVEff[3,1]  = 1.022380493   # 2012-05-31 17:59:49	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022380493	| Exec: 265ms
aDiVStd[3,1]  = 1.026588059   # 2012-05-31 17:59:53	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.026588059	| Exec: 5ms
aDiVEff[3,2]  = 1.661389243   # 2012-05-30 17:56:52	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.661389243	| Exec: 265ms
aDiVStd[3,2]  = 1.669498218   # 2012-05-30 17:56:54	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.669498218	| Exec: 5ms
aDiVEff[3,3]  = 3.00319931    # 2012-05-30 17:56:55	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00319931	| Exec: 275ms
aDiVStd[3,3]  = 3.01760623    # 2012-05-30 17:56:57	| Node: Sigma   	| P 2, Sh 5, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy:  3.01760623	| Exec: 5ms

# 6 Shells
aDiVEff[4,0]  = 0.4408528222  # 2012-05-30 17:56:58	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408528222	| Exec: 397ms
aDiVStd[4,0]  = 0.441446672   # 2012-05-30 17:57:00	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441446672	| Exec: 8ms
aDiVEff[4,1]  = 1.022163351   # 2012-05-31 17:59:56	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.022163351	| Exec: 396ms
aDiVStd[4,1]  = 1.025448813   # 2012-05-31 17:59:59	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.025448813	| Exec: 8ms
aDiVEff[4,2]  = 1.660912849   # 2012-05-30 17:57:01	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660912849	| Exec: 396ms
aDiVStd[4,2]  = 1.667257181   # 2012-05-30 17:57:03	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.667257181	| Exec: 7ms
aDiVEff[4,3]  = 3.002279268   # 2012-05-30 17:57:05	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.002279268	| Exec: 395ms
aDiVStd[4,3]  = 3.013626129   # 2012-05-30 17:57:06	| Node: Sigma   	| P 2, Sh 6, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.013626129	| Exec: 8ms

# 7 Shells
aDiVEff[5,0]  = 0.4408394169  # 2012-05-30 17:57:08	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408394169	| Exec: 563ms
aDiVStd[5,0]  = 0.4413297357  # 2012-05-30 17:57:10	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4413297357	| Exec: 14ms
aDiVEff[5,1]  = 1.02202522    # 2012-05-31 18:00:02	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.02202522	| Exec: 565ms
aDiVStd[5,1]  = 1.024705875   # 2012-05-31 18:00:07	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.024705875	| Exec: 14ms
aDiVEff[5,2]  = 1.660611185   # 2012-05-30 17:57:11	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660611185	| Exec: 565ms
aDiVStd[5,2]  = 1.665799351   # 2012-05-30 17:57:13	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.665799351	| Exec: 22ms
aDiVEff[5,3]  = 3.001691331   # 2012-05-30 17:57:14	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001691331	| Exec: 567ms
aDiVStd[5,3]  = 3.011019984   # 2012-05-30 17:57:16	| Node: Sigma   	| P 2, Sh 7, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.011019984	| Exec: 13ms

# 8 Shells
aDiVEff[6,0]  = 0.440830339   # 2012-05-30 17:57:18	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.440830339	| Exec: 767ms
aDiVStd[6,0]  = 0.4412461536  # 2012-05-30 17:57:20	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4412461536	| Exec: 30ms
aDiVEff[6,1]  = 1.021941517   # 2012-05-31 18:00:10	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021941517	| Exec: 774ms
aDiVStd[6,1]  = 1.024199606   # 2012-05-31 18:00:15	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.024199606	| Exec: 30ms
aDiVEff[6,2]  = 1.660427426   # 2012-05-30 17:57:21	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660427426	| Exec: 769ms
aDiVStd[6,2]  = 1.664806939   # 2012-05-30 17:57:23	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.664806939	| Exec: 32ms
aDiVEff[6,3]  = 3.001327589   # 2012-05-30 17:57:25	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001327589	| Exec: 771ms
aDiVStd[6,3]  = 3.009235721   # 2012-05-30 17:57:27	| Node: Sigma   	| P 2, Sh 8, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.009235721	| Exec: 31ms

# 9 Shells
aDiVEff[7,0]  = 0.4408236538  # 2012-05-30 17:57:28	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408236538	| Exec: 1s 30ms
aDiVStd[7,0]  = 0.441183487   # 2012-05-30 17:57:31	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441183487	| Exec: 65ms
aDiVEff[7,1]  = 1.021883856   # 2012-05-31 18:00:19	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021883856	| Exec: 1s 33ms
aDiVStd[7,1]  = 1.023830251   # 2012-05-31 18:00:26	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023830251	| Exec: 64ms
aDiVEff[7,2]  = 1.660300805   # 2012-05-30 17:57:32	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660300805	| Exec: 1s 31ms
aDiVStd[7,2]  = 1.664083215   # 2012-05-30 17:57:35	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.664083215	| Exec: 64ms
aDiVEff[7,3]  = 3.001075183   # 2012-05-30 17:57:36	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.001075183	| Exec: 1s 33ms
aDiVStd[7,3]  = 3.007929461   # 2012-05-30 17:57:39	| Node: Sigma   	| P 2, Sh 9, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.007929461	| Exec: 63ms

# 10 Shells
aDiVEff[8,0]  = 0.4408186851  # 2012-05-30 17:57:40	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408186851	| Exec: 1s 378ms
aDiVStd[8,0]  = 0.441135127   # 2012-05-30 17:57:43	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.441135127	| Exec: 156ms
aDiVEff[8,1]  = 1.021842866   # 2012-05-31 18:00:31	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021842866	| Exec: 1s 384ms
aDiVStd[8,1]  = 1.023550577   # 2012-05-31 18:00:40	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023550577	| Exec: 156ms
aDiVEff[8,2]  = 1.660210657   # 2012-05-30 17:57:44	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660210657	| Exec: 1s 380ms
aDiVStd[8,2]  = 1.663535219   # 2012-05-30 17:57:47	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.663535219	| Exec: 153ms
aDiVEff[8,3]  = 3.000894294   # 2012-05-30 17:57:49	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000894294	| Exec: 1s 380ms
aDiVStd[8,3]  = 3.006937178   # 2012-05-30 17:57:51	| Node: Sigma   	| P 2, Sh 10, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.006937178	| Exec: 153ms

# 11 Shells
aDiVEff[9,0]  = 0.4408148616  # 2012-05-30 17:57:53	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408148616	| Exec: 1s 845ms
aDiVStd[9,0]  = 0.4410967714  # 2012-05-30 17:57:56	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410967714	| Exec: 319ms
aDiVEff[9,1]  = 1.021812317   # 2012-05-31 18:00:47	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021812317	| Exec: 1s 829ms
aDiVStd[9,1]  = 1.023331672   # 2012-05-31 18:01:01	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023331672	| Exec: 316ms
aDiVEff[9,2]  = 1.660143425   # 2012-05-30 17:57:58	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660143425	| Exec: 1s 834ms
aDiVStd[9,2]  = 1.663106203   # 2012-05-30 17:58:01	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.663106203	| Exec: 311ms
aDiVEff[9,3]  = 3.00075878    # 2012-05-30 17:58:03	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00075878	| Exec: 1s 861ms
aDiVStd[9,3]  = 3.006158277   # 2012-05-30 17:58:06	| Node: Sigma   	| P 2, Sh 11, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.006158277	| Exec: 312ms

# 12 Shells
aDiVEff[10,0] = 0.4408118587  # 2012-05-30 17:58:08	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408118587	| Exec: 2s 490ms
aDiVStd[10,0] = 0.4410656959  # 2012-05-30 17:58:12	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410656959	| Exec: 601ms
aDiVEff[10,1] = 1.021788887   # 2012-05-31 18:01:12	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021788887	| Exec: 2s 505ms
aDiVStd[10,1] = 1.023156037   # 2012-05-31 18:01:33	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023156037	| Exec: 604ms
aDiVEff[10,2] = 1.660091823   # 2012-05-30 17:58:14	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660091823	| Exec: 2s 500ms
aDiVStd[10,2] = 1.662761861   # 2012-05-30 17:58:18	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662761861	| Exec: 601ms
aDiVEff[10,3] = 3.000654383   # 2012-05-30 17:58:20	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000654383	| Exec: 2s 493ms
aDiVStd[10,3] = 3.005531679   # 2012-05-30 17:58:23	| Node: Sigma   	| P 2, Sh 12, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.005531679	| Exec: 598ms

# 13 Shells
aDiVEff[11,0] = 0.4408094506  # 2012-05-30 17:58:25	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408094506	| Exec: 3s 502ms
aDiVStd[11,0] = 0.4410400544  # 2012-05-30 17:58:30	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410400544	| Exec: 1s 158ms
aDiVEff[11,1] = 1.021770438   # 2012-05-31 18:01:50	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021770438	| Exec: 3s 496ms
aDiVStd[11,1] = 1.023012173   # 2012-05-31 18:02:26	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.023012173	| Exec: 1s 149ms
aDiVEff[11,2] = 1.660051171   # 2012-05-30 17:58:33	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.660051171	| Exec: 3s 504ms
aDiVStd[11,2] = 1.662479681   # 2012-05-30 17:58:38	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662479681	| Exec: 1s 153ms
aDiVEff[11,3] = 3.000571897   # 2012-05-30 17:58:40	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000571897	| Exec: 3s 526ms
aDiVStd[11,3] = 3.005017173   # 2012-05-30 17:58:45	| Node: Sigma   	| P 2, Sh 13, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.005017173	| Exec: 1s 144ms

# 14 Shells
aDiVEff[12,0] = 0.4408074869  # 2012-05-30 17:58:48	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408074869	| Exec: 5s 193ms
aDiVStd[12,0] = 0.4410185706  # 2012-05-30 17:58:54	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410185706	| Exec: 2s 287ms
aDiVEff[12,1] = 1.02175561    # 2012-05-31 18:02:56	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.02175561	| Exec: 5s 205ms
aDiVStd[12,1] = 1.022892313   # 2012-05-31 18:03:53	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022892313	| Exec: 2s 288ms
aDiVEff[12,2] = 1.66001848    # 2012-05-30 17:58:58	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy:  1.66001848	| Exec: 5s 161ms
aDiVStd[12,2] = 1.662244466   # 2012-05-30 17:59:04	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662244466	| Exec: 2s 272ms
aDiVEff[12,3] = 3.000505406   # 2012-05-30 17:59:08	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000505406	| Exec: 5s 252ms
aDiVStd[12,3] = 3.004587539   # 2012-05-30 17:59:15	| Node: Sigma   	| P 2, Sh 14, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.004587539	| Exec: 2s 250ms

# 15 Shells
aDiVEff[13,0] = 0.4408058617  # 2012-05-30 17:59:18	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408058617	| Exec: 7s 584ms
aDiVStd[13,0] = 0.4410003318  # 2012-05-30 17:59:27	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4410003318	| Exec: 4s 174ms
aDiVEff[13,1] = 1.02174348    # 2012-05-31 18:04:45	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.02174348	| Exec: 7s 572ms
aDiVStd[13,1] = 1.022791004   # 2012-05-31 18:06:17	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022791004	| Exec: 3s 903ms
aDiVEff[13,2] = 1.659991725   # 2012-05-30 17:59:33	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659991725	| Exec: 7s 641ms
aDiVStd[13,2] = 1.662045551   # 2012-05-30 17:59:42	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.662045551	| Exec: 4s 150ms
aDiVEff[13,3] = 3.00045088    # 2012-05-30 17:59:48	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00045088	| Exec: 7s 701ms
aDiVStd[13,3] = 3.004223632   # 2012-05-30 17:59:57	| Node: Sigma   	| P 2, Sh 15, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.004223632	| Exec: 3s 956ms

# 16 Shells
aDiVEff[14,0] = 0.4408044992  # 2012-05-30 18:00:02	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408044992	| Exec: 12s 101ms
aDiVStd[14,0] = 0.4409846708  # 2012-05-30 18:00:16	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409846708	| Exec: 7s 879ms
aDiVEff[14,1] = 1.021733407   # 2012-05-31 18:07:41	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021733407	| Exec: 11s 753ms
aDiVStd[14,1] = 1.022704316   # 2012-05-31 18:09:49	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022704316	| Exec: 7s 417ms
aDiVEff[14,2] = 1.659969501   # 2012-05-30 18:00:25	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659969501	| Exec: 12s 191ms
aDiVStd[14,2] = 1.661875253   # 2012-05-30 18:00:39	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661875253	| Exec: 7s 718ms
aDiVEff[14,3] = 3.000405511   # 2012-05-30 18:00:48	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000405511	| Exec: 11s 796ms
aDiVStd[14,3] = 3.003911628   # 2012-05-30 18:01:01	| Node: Sigma   	| P 2, Sh 16, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003911628	| Exec: 7s 514ms

# 17 Shells
aDiVEff[15,0] = 0.440803344   # 2012-05-30 18:01:10	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.440803344	| Exec: 19s 431ms
aDiVStd[15,0] = 0.4409710892  # 2012-05-30 18:01:31	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409710892	| Exec: 14s 511ms
aDiVEff[15,1] = 1.021724934   # 2012-05-31 18:11:54	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021724934	| Exec: 19s 196ms
aDiVStd[15,1] = 1.022629348   # 2012-05-31 18:15:14	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022629348	| Exec: 13s 910ms
aDiVEff[15,2] = 1.659950801   # 2012-05-30 18:01:47	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659950801	| Exec: 19s 824ms
aDiVStd[15,2] = 1.661727896   # 2012-05-30 18:02:08	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661727896	| Exec: 14s 685ms
aDiVEff[15,3] = 3.000367282   # 2012-05-30 18:02:24	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000367282	| Exec: 19s 287ms
aDiVStd[15,3] = 3.003641299   # 2012-05-30 18:02:44	| Node: Sigma   	| P 2, Sh 17, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003641299	| Exec: 13s 682ms

# 18 Shells
aDiVEff[16,0] = 0.4408023547  # 2012-05-30 18:03:00	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408023547	| Exec: 30s 940ms
aDiVStd[16,0] = 0.4409592075  # 2012-05-30 18:03:32	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409592075	| Exec: 24s 482ms
aDiVEff[16,1] = 1.021717726   # 2012-05-31 18:18:33	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021717726	| Exec: 31s 102ms
aDiVStd[16,1] = 1.02256391    # 2012-05-31 18:24:16	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy:  1.02256391	| Exec: 24s 610ms
aDiVEff[16,2] = 1.65993489    # 2012-05-30 18:03:58	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy:  1.65993489	| Exec: 30s 792ms
aDiVStd[16,2] = 1.661599201   # 2012-05-30 18:04:30	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661599201	| Exec: 24s 392ms
aDiVEff[16,3] = 3.000334715   # 2012-05-30 18:04:56	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000334715	| Exec: 31s 8ms
aDiVStd[16,3] = 3.003404918   # 2012-05-30 18:05:28	| Node: Sigma   	| P 2, Sh 18, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003404918	| Exec: 24s 470ms

# 19 Shells
aDiVEff[17,0] = 0.4408015001  # 2012-05-30 18:05:54	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408015001	| Exec: 48s 697ms
aDiVStd[17,0] = 0.4409487322  # 2012-05-30 18:06:44	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409487322	| Exec: 40s 625ms
aDiVEff[17,1] = 1.021711535   # 2012-05-31 18:29:41	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021711535	| Exec: 48s 834ms
aDiVStd[17,1] = 1.022506321   # 2012-05-31 18:37:15	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022506321	| Exec: 40s 904ms
aDiVEff[17,2] = 1.659921217   # 2012-05-30 18:07:26	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659921217	| Exec: 49s 200ms
aDiVStd[17,2] = 1.661485883   # 2012-05-30 18:08:17	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661485883	| Exec: 40s 927ms
aDiVEff[17,3] = 3.000306701   # 2012-05-30 18:08:59	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000306701	| Exec: 49s 591ms
aDiVStd[17,3] = 3.003196547   # 2012-05-30 18:09:50	| Node: Sigma   	| P 2, Sh 19, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003196547	| Exec: 41s 186ms

# 20 Shells
aDiVEff[18,0] = 0.4408007558  # 2012-05-30 18:10:32	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408007558	| Exec: 1m 15s 56ms
aDiVStd[18,0] = 0.4409394326  # 2012-05-30 18:11:49	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409394326	| Exec: 1m 5s 641ms
aDiVEff[18,1] = 1.021706169   # 2012-05-31 18:44:26	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021706169	| Exec: 1m 14s 827ms
aDiVStd[18,1] = 1.022455271   # 2012-05-31 18:56:47	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022455271	| Exec: 1m 4s 827ms
aDiVEff[18,2] = 1.659909366   # 2012-05-30 18:12:56	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659909366	| Exec: 1m 14s 689ms
aDiVStd[18,2] = 1.661385379   # 2012-05-30 18:14:12	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661385379	| Exec: 1m 5s 36ms
aDiVEff[18,3] = 3.000282396   # 2012-05-30 18:15:18	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000282396	| Exec: 1m 14s 532ms
aDiVStd[18,3] = 3.003011545   # 2012-05-30 18:16:34	| Node: Sigma   	| P 2, Sh 20, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.003011545	| Exec: 1m 6s 226ms

# 21 Shells
aDiVEff[19,0] = 0.4408001031  # 2012-05-30 18:17:42	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4408001031	| Exec: 1m 52s 989ms
aDiVStd[19,0] = 0.4409311254  # 2012-05-30 18:19:36	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409311254	| Exec: 1m 41s 25ms
aDiVEff[19,1] = 1.021701482   # 2012-05-31 19:08:38	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021701482	| Exec: 1m 52s 415ms
aDiVStd[19,1] = 1.022409724   # 2012-05-31 19:10:32	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022409724	| Exec: 1m 40s 656ms
aDiVEff[19,2] = 1.659899014   # 2012-05-30 18:21:19	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659899014	| Exec: 1m 52s 575ms
aDiVStd[19,2] = 1.66129566    # 2012-05-30 18:23:13	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy:  1.66129566	| Exec: 1m 41s 98ms
aDiVEff[19,3] = 3.000261148   # 2012-05-30 18:24:55	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000261148	| Exec: 1m 52s 80ms
aDiVStd[19,3] = 3.002846237   # 2012-05-30 18:26:49	| Node: Sigma   	| P 2, Sh 21, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002846237	| Exec: 1m 40s 505ms

# 22 Shells
aDiVEff[20,0] = 0.4407995269  # 2012-05-30 18:28:31	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407995269	| Exec: 2m 52s 4ms
aDiVStd[20,0] = 0.4409236631  # 2012-05-30 18:31:24	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409236631	| Exec: 2m 33s 908ms
aDiVEff[20,1] = 1.02169736    # 2012-05-31 19:12:14	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy:  1.02169736	| Exec: 2m 47s 832ms
aDiVStd[20,1] = 1.022368849   # 2012-05-31 19:15:03	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022368849	| Exec: 2m 34s 867ms
aDiVEff[20,2] = 1.659889907   # 2012-05-30 18:33:59	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659889907	| Exec: 2m 48s 431ms
aDiVStd[20,2] = 1.661215104   # 2012-05-30 18:36:49	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661215104	| Exec: 2m 33s 846ms
aDiVEff[20,3] = 3.000242444   # 2012-05-30 18:39:24	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000242444	| Exec: 2m 50s 64ms
aDiVStd[20,3] = 3.002697673   # 2012-05-30 18:42:16	| Node: Sigma   	| P 2, Sh 22, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002697673	| Exec: 2m 32s 162ms

# 23 Shells
aDiVEff[21,0] = 0.4407990152  # 2012-05-30 18:44:49	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407990152	| Exec: 4m 2s 547ms
aDiVStd[21,0] = 0.4409169256  # 2012-05-30 18:48:53	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409169256	| Exec: 3m 45s 447ms
aDiVEff[21,1] = 1.021693712   # 2012-05-31 19:17:39	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021693712	| Exec: 4m 3s 844ms
aDiVStd[21,1] = 1.022331972   # 2012-05-31 19:21:44	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022331972	| Exec: 3m 45s 697ms
aDiVEff[21,2] = 1.659881845   # 2012-05-30 18:52:40	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659881845	| Exec: 4m 1s 797ms
aDiVStd[21,2] = 1.661142393   # 2012-05-30 18:56:43	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661142393	| Exec: 3m 46s 375ms
aDiVEff[21,3] = 3.000225877   # 2012-05-30 19:00:31	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000225877	| Exec: 4m 2s 326ms
aDiVStd[21,3] = 3.002563462   # 2012-05-30 19:04:35	| Node: Sigma   	| P 2, Sh 23, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002563462	| Exec: 3m 45s 160ms

# 24 Shells
aDiVEff[22,0] = 0.4407985585  # 2012-05-30 19:08:21	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407985585	| Exec: 5m 50s 939ms
aDiVStd[22,0] = 0.4409108143  # 2012-05-30 19:14:14	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409108143	| Exec: 5m 29s 926ms
aDiVEff[22,1] = 1.021690464   # 2012-05-31 19:25:32	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021690464	| Exec: 5m 51s 510ms
aDiVStd[22,1] = 1.022298543   # 2012-05-31 19:31:25	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022298543	| Exec: 5m 30s 591ms
aDiVEff[22,2] = 1.659874668   # 2012-05-30 19:19:45	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659874668	| Exec: 5m 48s 418ms
aDiVStd[22,2] = 1.661076449   # 2012-05-30 19:25:35	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661076449	| Exec: 5m 29s 102ms
aDiVEff[22,3] = 3.00021112    # 2012-05-30 19:31:05	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00021112	| Exec: 5m 49s 228ms
aDiVStd[22,3] = 3.002441644   # 2012-05-30 19:36:56	| Node: Sigma   	| P 2, Sh 24, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002441644	| Exec: 5m 28s 684ms

# 25 Shells
aDiVEff[23,0] = 0.4407981489  # 2012-05-30 19:42:26	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407981489	| Exec: 8m 21s 885ms
aDiVStd[23,0] = 0.4409052474  # 2012-05-30 19:50:49	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409052474	| Exec: 7m 58s 874ms
aDiVEff[23,1] = 1.021687558   # 2012-05-31 19:36:57	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021687558	| Exec: 8m 21s 643ms
aDiVStd[23,1] = 1.022268108   # 2012-05-31 19:45:20	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022268108	| Exec: 7m 56s 963ms
aDiVEff[23,2] = 1.659868246   # 2012-05-30 19:58:50	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659868246	| Exec: 8m 19s 711ms
aDiVStd[23,2] = 1.661016382   # 2012-05-30 20:07:11	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.661016382	| Exec: 7m 56s 695ms
aDiVEff[23,3] = 3.000197907   # 2012-05-30 20:15:09	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000197907	| Exec: 8m 20s 158ms
aDiVStd[23,3] = 3.002330597   # 2012-05-30 20:23:30	| Node: Sigma   	| P 2, Sh 25, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002330597	| Exec: 7m 56s 863ms

# 26 Shells
aDiVEff[24,0] = 0.4407977797  # 2012-05-30 20:31:29	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407977797	| Exec: 11m 26s 220ms
aDiVStd[24,0] = 0.4409001567  # 2012-05-30 20:42:56	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4409001567	| Exec: 10m 59s 320ms
aDiVEff[24,1] = 1.021684945   # 2012-05-31 19:53:18	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021684945	| Exec: 11m 31s 513ms
aDiVStd[24,1] = 1.022240288   # 2012-05-31 20:04:51	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022240288	| Exec: 11m 3s 65ms
aDiVEff[24,2] = 1.659862471   # 2012-05-30 20:53:57	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659862471	| Exec: 11m 27s 170ms
aDiVStd[24,2] = 1.660961451   # 2012-05-30 21:05:26	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.660961451	| Exec: 10m 57s 253ms
aDiVEff[24,3] = 3.000186022   # 2012-05-30 21:16:24	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000186022	| Exec: 11m 31s 387ms
aDiVStd[24,3] = 3.00222897    # 2012-05-30 21:27:57	| Node: Sigma   	| P 2, Sh 26, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy:  3.00222897	| Exec: 10m 59s 75ms

# 27 Shells
aDiVEff[25,0] = 0.4407974457  # 2012-05-30 21:38:57	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407974457	| Exec: 16m 10s 555ms
aDiVStd[25,0] = 0.4408954849  # 2012-05-30 21:55:09	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4408954849	| Exec: 15m 26s 536ms
aDiVEff[25,1] = 1.021682585   # 2012-05-31 20:15:55	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021682585	| Exec: 15m 53s 52ms
aDiVStd[25,1] = 1.022214764   # 2012-05-31 20:31:50	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022214764	| Exec: 15m 19s 314ms
aDiVEff[25,2] = 1.659857255   # 2012-05-30 22:10:37	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659857255	| Exec: 15m 51s 946ms
aDiVStd[25,2] = 1.660911031   # 2012-05-30 22:26:31	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.660911031	| Exec: 15m 22s 755ms
aDiVEff[25,3] = 3.000175285   # 2012-05-30 22:41:55	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000175285	| Exec: 15m 54s 805ms
aDiVStd[25,3] = 3.002135626   # 2012-05-30 22:57:51	| Node: Sigma   	| P 2, Sh 27, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002135626	| Exec: 15m 29s 954ms

# 28 Shells
aDiVEff[26,0] = 0.4407971423  # 2012-05-30 23:13:22	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407971423	| Exec: 21m 54s 650ms
aDiVStd[26,0] = 0.4408911832  # 2012-05-30 23:35:18	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4408911832	| Exec: 21m 16s 646ms
aDiVEff[26,1] = 1.021680446   # 2012-05-31 20:47:11	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021680446	| Exec: 21m 54s 245ms
aDiVStd[26,1] = 1.022191267   # 2012-05-31 21:09:06	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022191267	| Exec: 21m 13s 370ms
aDiVEff[26,2] = 1.659852526   # 2012-05-30 23:56:36	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659852526	| Exec: 21m 59s 282ms
aDiVStd[26,2] = 1.660864597   # 2012-05-31 00:18:37	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.660864597	| Exec: 21m 11s 496ms
aDiVEff[26,3] = 3.000165546   # 2012-05-31 00:39:50	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000165546	| Exec: 21m 51s 66ms
aDiVStd[26,3] = 3.002049603   # 2012-05-31 01:01:42	| Node: Sigma   	| P 2, Sh 28, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.002049603	| Exec: 21m 11s 914ms

# 29 Shells
aDiVEff[27,0] = 0.4407968657  # 2012-05-31 01:22:56	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407968657	| Exec: 30m 31s 467ms
aDiVStd[27,0] = 0.4408872101  # 2012-05-31 01:53:29	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4408872101	| Exec: 29m 24s 496ms
aDiVEff[27,1] = 1.021678499   # 2012-05-31 21:30:21	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021678499	| Exec: 30m 25s 881ms
aDiVStd[27,1] = 1.022169569   # 2012-05-31 22:00:48	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022169569	| Exec: 29m 49s 549ms
aDiVEff[27,2] = 1.659848222   # 2012-05-31 02:22:55	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659848222	| Exec: 30m 27s 147ms
aDiVStd[27,2] = 1.660821699   # 2012-05-31 02:53:23	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.660821699	| Exec: 29m 27s 567ms
aDiVEff[27,3] = 3.00015668    # 2012-05-31 03:22:52	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy:  3.00015668	| Exec: 30m 18s 389ms
aDiVStd[27,3] = 3.001970082   # 2012-05-31 03:53:12	| Node: Sigma   	| P 2, Sh 29, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.001970082	| Exec: 29m 29s 490ms

# 30 Shells
aDiVEff[28,0] = 0.4407966128  # 2012-05-31 04:22:43	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Veff	 | Energy: 0.4407966128	| Exec: 40m 48s 892ms
aDiVStd[28,0] = 0.4408835301  # 2012-05-31 05:03:33	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.1, Lm 0.0, NoECut, Vstd	 | Energy: 0.4408835301	| Exec: 39m 43s 149ms
aDiVEff[28,1] = 1.021676721   # 2012-05-31 22:30:39	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Veff	 | Energy: 1.021676721	| Exec: 40m 55s 676ms
aDiVStd[28,1] = 1.022149473   # 2012-05-31 23:11:36	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.28, Lm 0.0, NoECut, Vstd	 | Energy: 1.022149473	| Exec: 40m 4s 140ms
aDiVEff[28,2] = 1.659844292   # 2012-05-31 05:43:17	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Veff	 | Energy: 1.659844292	| Exec: 40m 34s 987ms
aDiVStd[28,2] = 1.660781953   # 2012-05-31 06:23:54	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 0.5, Lm 0.0, NoECut, Vstd	 | Energy: 1.660781953	| Exec: 39m 44s 462ms
aDiVEff[28,3] = 3.000148581   # 2012-05-31 07:03:40	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Veff	 | Energy: 3.000148581	| Exec: 40m 41s 864ms
aDiVStd[28,3] = 3.001896361   # 2012-05-31 07:44:23	| Node: Sigma   	| P 2, Sh 30, M 0, Ms 0, Om 1.0, Lm 0.0, NoECut, Vstd	 | Energy: 3.001896361	| Exec: 39m 36s 527ms

for i in range(len(aDiVCut[:,0])):
    aDiVCut[i,0] = 0.440791888  # 2012-06-05 15:56:12	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Di	 | Energy: 0.440791888	| Exec: 36ms
    aDiVCut[i,1] = 1.021644014  # 2012-06-05 15:56:13	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.28, Lm 0.0, ECut, Veff, Di	 | Energy: 1.021644014	| Exec: 36ms
    aDiVCut[i,2] = 1.65977215   # 2012-06-05 15:56:14	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 0.5, Lm 0.0, ECut, Veff, Di	 | Energy:  1.65977215	| Exec: 41ms
    aDiVCut[i,3] = 3.0          # 2012-06-05 15:56:16	| Node: Sigma   	| P 2, Sh 3, M 0, Ms 0, Om 1.0, Lm 0.0, ECut, Veff, Di	 | Energy:           3	| Exec: 36ms

aDiVCut[0,0] = 0.4            # 2012-06-05 15:56:06	| Node: Sigma   	| P 2, Sh 2, M 0, Ms 0, Om 0.1, Lm 0.0, ECut, Veff, Di	 | Energy:         0.4	| Exec: 20ms


# Plots

fig0 = figure()
plot0 = fig0.add_subplot(2,2,1)

plot0.set_title("QDot 2D, 2 Electrons, $\omega$ = 0.1")
plot0.set_xlabel("Number of Shells")
plot0.set_ylabel("Energy ($\hbar \omega$)")
plot0.plot(aShells, aLzVCut[:,0], 'go',  label='Lanczos, Eff. Int. + ECut')
plot0,plot(aShells, aDiVCut[:,0], 'g',   label='Diag, Eff. Int. + ECut')
plot0.plot(aShells, aLzVEff[:,0], 'ro',  label='Lanczos, Effective Int.')
plot0,plot(aShells, aDiVEff[:,0], 'r',   label='Diag, Effective Int.')
plot0.plot(aShells, aLzVStd[:,0], 'bo',  label='Lanczos, Standard Int.')
plot0.plot(aShells, aDiVStd[:,0], 'b',   label='Diag, Standard Int.')
plot0.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot0.set_xlim((2,30))
plot0.set_ylim((0.4406,0.4420001))

xax = plot0.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


plot1 = fig0.add_subplot(2,2,2)

plot1.set_title("QDot 2D, 2 Electrons, $\omega$ = 0.28")
plot1.set_xlabel("Number of Shells")
plot1.set_ylabel("Energy ($\hbar \omega$)")
plot1.plot(aShells, aLzVCut[:,1], 'go',  label='Lanczos, Eff. Int. + ECut')
plot1,plot(aShells, aDiVCut[:,1], 'g',   label='Diag, Eff. Int. + ECut')
plot1.plot(aShells, aLzVEff[:,1], 'ro',  label='Lanczos, Effective Int.')
plot1,plot(aShells, aDiVEff[:,1], 'r',   label='Diag, Effective Int.')
plot1.plot(aShells, aLzVStd[:,1], 'bo',  label='Lanczos, Standard Int.')
plot1.plot(aShells, aDiVStd[:,1], 'b',   label='Diag, Standard Int.')
plot1.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot1.set_xlim((2,30))
plot1.set_ylim((1.02,1.03))

xax = plot1.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


plot2 = fig0.add_subplot(2,2,3)

plot2.set_title("QDot 2D, 2 Electrons, $\omega$ = 0.5")
plot2.set_xlabel("Number of Shells")
plot2.set_ylabel("Energy ($\hbar \omega$)")
plot2.plot(aShells, aLzVCut[:,2], 'go',  label='Lanczos, Eff. Int. + ECut')
plot2,plot(aShells, aDiVCut[:,2], 'g',   label='Diag, Eff. Int. + ECut')
plot2.plot(aShells, aLzVEff[:,2], 'ro',  label='Lanczos, Effective Int.')
plot2,plot(aShells, aDiVEff[:,2], 'r',   label='Diag, Effective Int.')
plot2.plot(aShells, aLzVStd[:,2], 'bo',  label='Lanczos, Standard Int.')
plot2.plot(aShells, aDiVStd[:,2], 'b',   label='Diag, Standard Int.')
plot2.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot2.set_xlim((2,30))
plot2.set_ylim((1.655,1.675))

xax = plot2.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


plot3 = fig0.add_subplot(2,2,4)

plot3.set_title("QDot 2D, 2 Electrons, $\omega$ = 1.0")
plot3.set_xlabel("Number of Shells")
plot3.set_ylabel("Energy ($\hbar \omega$)")
plot3.plot(aShells, aLzVCut[:,3], 'go',  label='Lanczos, Eff. Int. + ECut')
plot3,plot(aShells, aDiVCut[:,3], 'g',   label='Diag, Eff. Int. + ECut')
plot3.plot(aShells, aLzVEff[:,3], 'ro',  label='Lanczos, Effective Int.')
plot3,plot(aShells, aDiVEff[:,3], 'r',   label='Diag, Effective Int.')
plot3.plot(aShells, aLzVStd[:,3], 'bo',  label='Lanczos, Standard Int.')
plot3.plot(aShells, aDiVStd[:,3], 'b',   label='Diag, Standard Int.')
plot3.legend(bbox_to_anchor=(0.95, 0.95), loc=1, ncol=1, borderaxespad=0.)
plot3.set_xlim((2,30))
plot3.set_ylim((2.99,3.04))

xax = plot3.xaxis
xax.set_ticks((2,4,6,8,10,12,14,16,18,20,22,24,26,28,30))


show()
