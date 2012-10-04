//# Nodes : 3

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

    double dOmega       = 0.0;
    double dLambda      = 6.0;
    
    int    iSystem      = QDOT2D;
    int    iInteraction = Q2D_NORMAL;

    //
    // OpenMPI Code
    //

    stringstream ssOut;
    ofstream     oOutput;
    double       dEnergy = 0.0;
    int          iProc, iRank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &iProc);
	MPI_Comm_rank(MPI_COMM_WORLD, &iRank);

    System *oSystem = new System();
    if(argc > 1 && iRank==0) oSystem->SetLogFile(argv[1]);

    if(iRank == 0) {
        oOutput.open("tempQueue/output.txt");

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
    oSystem->BuildBasis();
    
    Lanczos oLanczos(oSystem);

    int  iReady=0;
    int  iBasisDim = oSystem->GetBasis()->GetSize();
    int  iChunkSize = ceil(iBasisDim/(double)(iProc-1));
    int  iChunks = ceil(iBasisDim/(double)iChunkSize);
    int  iDone = 0;

    vector<int> vJobs(iChunks+1);

    // Master Node
    if(iRank == 0)  {

        MPI_Status mpiStatus;
        Row<int>   mReady;
        
        mReady.zeros(iProc);
        mReady(0) = 1;

        for(int i=1; i<iProc; i++) {
            MPI_Recv(&iReady, 1, MPI_INT, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD, &mpiStatus);
            if(iReady == 1) mReady(i) = 1;
        }

        if(sum(mReady) == iProc) {

            ssOut << endl;
            ssOut << iProc << " nodes are ready ..." << endl;
            oSystem->GetLog()->Output(&ssOut);

            for(int i=0; i<=iChunks; i++) vJobs[i] = iChunkSize*i;
            if(vJobs[iChunks+1] > iBasisDim) vJobs[iChunks+1] = iBasisDim;
            MPI_Bcast(&vJobs[0], iChunks+1, MPI_INT, 0, MPI_COMM_WORLD);

            oLanczos.RunInit();
            ssOut << "Master nodes initiated ..." << endl;
            ssOut << endl;
            oSystem->GetLog()->Output(&ssOut);
            
            Col<double>    *mLzV;
            Col<double>    *mLzW;
            Col<double>    *mEnergy;
            vector<double>  vLzW;
            vector<double>  vReturn(iBasisDim);

            mLzV    = oLanczos.GetLanczosVectorV();
            mLzW    = oLanczos.GetLanczosVectorW();
            mEnergy = oLanczos.GetEnergies();

            while(iDone == 0) {
                vLzW = conv_to< vector<double> >::from(*mLzW);
                MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);

                for(int i=1; i<iProc; i++) {
                    MPI_Recv(&vReturn[0], iBasisDim, MPI_DOUBLE, MPI_ANY_SOURCE, 501, MPI_COMM_WORLD, &mpiStatus);
                    for(int j=0; j<iBasisDim; j++) mLzV->at(j) += vReturn[j];
                }
                
                iDone = oLanczos.RunMaster();
                MPI_Bcast(&iDone, 1, MPI_INT, 0, MPI_COMM_WORLD);
            }
            
            dEnergy = mEnergy->at(0);

        } else {

            ssOut << endl;
            ssOut << "Not all nodes are answering, exiting ..." << endl;
            ssOut << endl;
            oSystem->GetLog()->Output(&ssOut);

        }

    // Slave Nodes
    } else {
        
        iReady = 1;
        MPI_Send(&iReady, 1, MPI_INT, 0, 500, MPI_COMM_WORLD);

        MPI_Bcast(&vJobs[0], iChunks+1, MPI_INT, 0, MPI_COMM_WORLD);

        Col<double>    mLzW;
        vector<double> vLzW(iBasisDim);
        vector<double> vLzV(iBasisDim);
        vector<double> vReturn(iBasisDim);

        while(iDone == 0) {
            MPI_Bcast(&vLzW[0], iBasisDim, MPI_DOUBLE, 0, MPI_COMM_WORLD);
            mLzW = conv_to< colvec >::from(vLzW);
            oLanczos.RunSlave(mLzW, vReturn, vJobs[iRank-1], vJobs[iRank]);
            MPI_Send(&vReturn[0], iBasisDim, MPI_DOUBLE, 0, 501, MPI_COMM_WORLD);
            MPI_Bcast(&iDone, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }

    }

    // Data Output
    if(iRank == 0) {
        cout << endl;
        cout << "Energy: " << setprecision(10) << setw(11) << dEnergy << endl;
        oOutput << "P 4, ";
        oOutput << "Sh 6, ";
        oOutput << "M 0, ";
        oOutput << "Ms 0, ";
        oOutput << "Om 0.0, ";
        oOutput << "Lm 6.0, ";
        oOutput << "NoECut, ";
        oOutput << "Vstd, ";
        oOutput << "Lz";
        oOutput << "\t | Energy: " << setprecision(10) << setw(11) << dEnergy << endl;

        oOutput.close();
    }

    MPI_Finalize();

    return 0;
}
