/*
** Configuration file for libTardis
*/

// Armadillo Cache
#define ARMA_CACHE_DIR "/scratch/Temp/arma_cache/"  // Path to cache, must end with "/"

// QDot2D Lanczos
#define LANCZOS_ZERO     1e-9
#define LANCZOS_CONVERGE 1e-6
#define USE_RAND_SEED    false

// Size of Slater Determinant
#define SLATER_WORD 512

// Enable Progress Output
#define PROGRESS

// Enable OpenMP
#define OPENMP

// Enable OpenMPI
//#define OPENMPI

// Use index-based basis search?
//  - Only useful for small basises.
//  - Uses a lot of memory but gives a good speedup.
//#define INDEX_BASIS
