//# Nodes : 8

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../libTardis/libTardis.hpp"
#include "mpi.h"

using namespace std;
using namespace tardis;
using namespace arma;

int main(int argc, char* argv[]) {

    //
    // Job Configurastion
    //

    int    iShells      = 8;
    int    iParticles   = 4;
    int    iM           = 0;
    int    iMs          = 0;
    bool   bEnergyCut   = false;

    double dOmega       = 1.0;
    double dLambda      = 0.0;
    
    int    iSystem      = QDOT2D;
    int    iInteraction = Q2D_EFFECTIVE;

    //
    // OpenMPI Code
    //

    stringstream ssOut;
    ofstream     oOutput;
    time_t       tTime;
    double       dEnergy = 0.0;
    int          iProc, iRank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &iProc);
    MPI_Comm_rank(MPI_COMM_WORLD, &iRank);

    System *oSystem = new System();

    if(iRank == 0) {
        ssOut << endl;
        ssOut << "System Config:" << endl;
        ssOut << endl;
        ssOut << "Shells:     " << iShells << endl;
        ssOut << "Particles:  " << iParticles << endl;
        ssOut << "Total M:    " << iM << endl;
        ssOut << "Total Spin: " << iMs << endl;
        ssOut << "Omega:      " << dOmega << endl;
        ssOut << "Lambda:     " << dLambda << endl;
        ssOut << endl;
        oSystem->GetLog()->Output(&ssOut);
    } else {
        oSystem->GetLog()->SetSilent(true);
    }

    // Build System
    oSystem->SetPotential(iShells, iSystem, iInteraction);
    oSystem->SetParticles(iParticles);
    oSystem->SetQNumber(QN_M, iM);
    oSystem->SetQNumber(QN_MS, iMs);
    oSystem->SetVariable(VAR_LAMBDA, dLambda);
    oSystem->SetVariable(VAR_OMEGA, dOmega);
    oSystem->EnableEnergyCut(bEnergyCut);
    oSystem->BuildPotential();

    if(iRank == 0)  {
        time(&tTime);
        cout << "Starting building basis: " << ctime(&tTime);
    }
    oSystem->BuildBasis();
    
    if(iRank == 0)  {
        time(&tTime);
        cout << "Starting Lanczos: " << ctime(&tTime);
    }
    Lanczos oLanczos(oSystem);

    int    iReady=0;
    int    iNodes=0;
    int    iBasisDim = oSystem->GetBasis()->GetSize();
    int    iDone = 0;
    double dTStart, dTStop;

    vector<int>     vChunk(iProc+1);
    vector<double>  vTime(iProc);
    vector<double>  vReturn(iBasisDim);
    vector<double>  vSend(iBasisDim);

    for(int i=0; i<iProc; i++)  vTime[i]  = 1;

    // Master Node
    if(iRank == 0)  {

        iReady = 1;
        MPI_Reduce(&iReady, &iNodes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        
        if(iNodes == iProc) {

            ssOut << endl;
            ssOut << iProc << " nodes are ready ..." << endl;
            oSystem->GetLog()->Output(&ssOut);

            double dTAvg;
            
            Col<double>    *mLzV;
            Col<double>    *mLzW;
            Row<double>    *mLzA;
            Row<double>    *mLzB;
            Row<double>    *mLzC;
            Row<double>    *mLzE;
            Col<double>    *mEnergy;
            Col<int>        mLzI;
            Col<int>        mLzN;
            vector<double>  vLzW;
            vector<int>     vPrev(iProc);

            for(int i=0; i<=iProc; i++) vChunk[i] = ceil((iBasisDim/(double)iProc)*i);
            vChunk[iProc] = iBasisDim;

            mLzV    = oLanczos.GetLanczosVectorV();
            mLzW    = oLanczos.GetLanczosVectorW();
            mLzA    = oLanczos.GetLanczosVectorA();
            mLzB    = oLanczos.GetLanczosVectorB();
            mLzC    = oLanczos.GetLanczosVectorC();
            mLzE    = oLanczos.GetLanczosVectorE();
            mEnergy = oLanczos.GetEnergies();

            mLzI.quiet_load("LanczosI.arma");
            if(mLzI.n_rows == 0) {
                oLanczos.RunInit();
                ssOut << "Master node initialised ..." << endl;
                ssOut << endl;
                oSystem->GetLog()->Output(&ssOut);
                mLzI.zeros(1);
            } else {
                mLzV->quiet_load("LanczosV.arma");
                mLzW->quiet_load("LanczosW.arma");
                mLzA->quiet_load("LanczosA.arma");
                mLzB->quiet_load("LanczosB.arma");
                mLzC->quiet_load("LanczosC.arma");
                mLzE->quiet_load("LanczosE.arma");

                mLzN.quiet_load("LanczosN.arma");
                oLanczos.SetLanczosIt(mLzI(0));

                if(mLzN.n_elem == iProc+1) {
                    vChunk = conv_to< vector<int> >::from(mLzN);
                }
            }

            while(iDone == 0) {
                
                dTAvg = 0.0;
                for(int i=0; i<iProc; i++) {
                    dTAvg += vTime[i];
                    vPrev[i] = vChunk[i+1]-vChunk[i];
                }
                dTAvg /= iProc;
                vChunk[0] = 0;
                for(int i=0; i<iProc; i++) {
                    vChunk[i+1] = vChunk[i] + ceil(vPrev[i]*dTAvg/vTime[i]);
                    if(vChunk[i+1] > iBasisDim) vChunk[i+1] = iBasisDim;
                }
                vChunk[iProc] = iBasisDim;

                ssOut << "Loads: 0:" << vChunk[1]-vChunk[0];
                for(int i=1; i<iProc; i++) ssOut << ", " << i << ":" << vChunk[i+1]-vChunk[i];
                ssOut << endl;

                oSystem->GetLog()->Output(&ssOut);

                MPI_Bcast(&vChunk[0], iProc+1, MPI_INT, 0, MPI_COMM_WORLD);

                time(&tTime);
                cout << "Starting new iterations : " << ctime(&tTime);

                vLzW = conv_to< vector<double> >::from(*mLzW);
                MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);

                time(&tTime);
                cout << "Done broadcasting       : " << ctime(&tTime);
                
                dTStart = MPI_Wtime();
                oLanczos.RunWorker(*mLzW, vSend, vChunk[iRank], vChunk[iRank+1]);
                dTStop  = MPI_Wtime()-dTStart;
                MPI_Gather(&dTStop, 1, MPI_DOUBLE, &vTime[0], 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

                ssOut << "Times: 0:" << ceil(vTime[0]);
                for(int i=1; i<iProc; i++) ssOut << ", " << i << ":" << ceil(vTime[i]);
                ssOut << endl;

                time(&tTime);
                cout << "Done calculating        : " << ctime(&tTime);

                MPI_Reduce(&vSend[0], &vReturn[0], iBasisDim, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
                for(int j=0; j<iBasisDim; j++) mLzV->at(j) += vReturn[j];
                
                time(&tTime);
                cout << "Done receiving          : " << ctime(&tTime) << endl;

                iDone = oLanczos.RunMaster();

                mLzV->save("LanczosV.arma");
                mLzW->save("LanczosW.arma");
                mLzA->save("LanczosA.arma");
                mLzB->save("LanczosB.arma");
                mLzC->save("LanczosC.arma");
                mLzE->save("LanczosE.arma");

                mLzI(0) = oLanczos.GetLanczosIt();
                mLzI.save("LanczosI.arma");

                mLzN = conv_to< Col<int> >::from(vChunk);
                mLzN.save("LanczosN.arma");

                MPI_Bcast(&iDone, 1, MPI_INT, 0, MPI_COMM_WORLD);

                cout << endl;
            }
            
            dEnergy = mEnergy->at(0);

            ssOut << endl;
            ssOut << "Eigenvalues:" << endl;
            ssOut << *mEnergy << endl;
            ssOut << endl;
            oSystem->GetLog()->Output(&ssOut);
            oSystem->GetBasis()->Save("Coeff.arma", SAVE_COEFF_ARMA);

        } else {

            ssOut << endl;
            ssOut << "Not all nodes are answering, exiting ..." << endl;
            ssOut << endl;
            oSystem->GetLog()->Output(&ssOut);

            MPI_Finalize();
            return 0;

        }

    // Worker Nodes
    } else {
        
        iReady = 1;
        MPI_Reduce(&iReady, &iNodes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        Col<double>    mLzW;
        vector<double> vLzW(iBasisDim);
        vector<double> vLzV(iBasisDim);

        while(iDone == 0) {
            MPI_Bcast(&vChunk[0], iProc+1, MPI_INT, 0, MPI_COMM_WORLD);
            MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);
            mLzW = conv_to< Col<double> >::from(vLzW);
            dTStart = MPI_Wtime();
            oLanczos.RunWorker(mLzW, vSend, vChunk[iRank], vChunk[iRank+1]);
            dTStop  = MPI_Wtime()-dTStart;
            MPI_Gather(&dTStop, 1, MPI_DOUBLE, &vTime[0], 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
            MPI_Reduce(&vSend[0], &vReturn[0], iBasisDim, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
            MPI_Bcast(&iDone, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }

    }

    // Data Output
    if(iRank == 0) {
        cout << endl;
        cout << "Energy: " << setprecision(10) << setw(11) << dEnergy << endl;
    }

    MPI_Finalize();

    return 0;
}
