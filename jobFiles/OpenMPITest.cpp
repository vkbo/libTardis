//# Nodes : 4

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

    int    iShells      = 6;
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
    double dChunkSize = iBasisDim/(double)iProc;
    int    iDone = 0;

    vector<int>     vJobs(iProc+1);
    vector<double>  vReturn(iBasisDim);
    vector<double>  vSend(iBasisDim);

    // Master Node
    if(iRank == 0)  {

        iReady = 1;
        MPI_Reduce(&iReady, &iNodes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        
        if(iNodes == iProc) {

            ssOut << endl;
            ssOut << iProc << " nodes are ready ..." << endl;
            oSystem->GetLog()->Output(&ssOut);

            for(int i=0; i<=iProc; i++) vJobs[i] = ceil(dChunkSize*i);
            if(vJobs[iProc] > iBasisDim) vJobs[iProc] = iBasisDim;
            MPI_Bcast(&vJobs[0], iProc+1, MPI_INT, 0, MPI_COMM_WORLD);
            for(int i=0; i<=iProc-1; i++) {
                ssOut << "Node " << i << " running interval " << vJobs[i] << " - " << vJobs[i+1] << endl;
            }
            ssOut << endl;
            oSystem->GetLog()->Output(&ssOut);

            Col<double>    *mLzV;
            Col<double>    *mLzW;
            Row<double>    *mLzA;
            Row<double>    *mLzB;
            Row<double>    *mLzC;
            Row<double>    *mLzE;
            Col<double>    *mEnergy;
            Col<int>        mItt;
            vector<double>  vLzW;

            mLzV    = oLanczos.GetLanczosVectorV();
            mLzW    = oLanczos.GetLanczosVectorW();
            mLzA    = oLanczos.GetLanczosVectorA();
            mLzB    = oLanczos.GetLanczosVectorB();
            mLzC    = oLanczos.GetLanczosVectorC();
            mLzE    = oLanczos.GetLanczosVectorE();
            mEnergy = oLanczos.GetEnergies();

            mItt.quiet_load("LanczosItt.arma");
            if(mItt.n_rows == 0) {
                oLanczos.RunInit();
                ssOut << "Master node initialised ..." << endl;
                ssOut << endl;
                oSystem->GetLog()->Output(&ssOut);
                mItt.zeros(1);
            } else {
                mLzV->quiet_load("LanczosV.arma");
                mLzW->quiet_load("LanczosW.arma");
                mLzA->quiet_load("LanczosA.arma");
                mLzB->quiet_load("LanczosB.arma");
                mLzC->quiet_load("LanczosC.arma");
                mLzE->quiet_load("LanczosE.arma");
                oLanczos.SetLanczosItt(mItt(0));
            }

            while(iDone == 0) {
                time(&tTime);
                cout << "Starting new iterations : " << ctime(&tTime);

                vLzW = conv_to< vector<double> >::from(*mLzW);
                MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);

                time(&tTime);
                cout << "Done broadcasting       : " << ctime(&tTime);

                oLanczos.RunSlave(*mLzW, vSend, vJobs[iRank], vJobs[iRank+1]);

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

                mItt(0) = oLanczos.GetLanczosItt();
                mItt.save("LanczosItt.arma");

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

    // Slave Nodes
    } else {
        
        iReady = 1;
        MPI_Reduce(&iReady, &iNodes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        MPI_Bcast(&vJobs[0], iProc+1, MPI_INT, 0, MPI_COMM_WORLD);

        Col<double>    mLzW;
        vector<double> vLzW(iBasisDim);
        vector<double> vLzV(iBasisDim);

        while(iDone == 0) {
            MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);
            mLzW = conv_to< colvec >::from(vLzW);
            oLanczos.RunSlave(mLzW, vSend, vJobs[iRank], vJobs[iRank+1]);
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