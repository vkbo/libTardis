/*
** Configuration file for libTardis
*/

// Armadillo Cache
#define ARMA_CACHE     true                         // Enable?
#define ARMA_CACHE_DIR "/scratch/Temp/arma_cache/"  // Path to cache, must end with "/"
#define ARMA_CACHE_MIN 40                           // Minimum size matrix to save

// QDot2D Lanczos
#define LANCZOS_ZERO     1e-9
#define LANCZOS_CONVERGE 1e-6
#define USE_RAND_SEED    true

// Size of Slater Determinant
#define SLATER_WORD 128

// Enable Progress Output if defined
#define PROGRESS

// Enable OpenMP
#define OPENMP

// Enable OpenMPI
//#define OPENMPI
