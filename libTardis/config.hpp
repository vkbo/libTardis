/*
** Configuration file for libTardis
*/

// Lanczos
#define LANCZOS_ZERO     1e-9   // Zero-ondition for Beta value
#define LANCZOS_CONVERGE 1e-5   // Covergence condition for Lanczos iterations
#define LANCZOS_MAX_IT   50     // Max number of iterations
#define LANCZOS_SEED     false  // If true, seeds random generator with time(NULL)
#define LANCZOS_STRICT          // If defined, will break the Lanczos if convergence increase

// Size of Slater Determinant
#define SLATER_WORD 512

// Enable Progress Output
#define PROGRESS
//#define MINIMAL

// Enable OpenMP
#define OPENMP

// Enable OpenMPI
//#define OPENMPI

// Use index-based basis search?
//  - Only useful for small basises.
//  - Uses a lot of memory but gives a good speedup for small systems.
//#define INDEX_BASIS
