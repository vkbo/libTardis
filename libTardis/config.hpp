/*
** Configuration file for libTardis
*/

// QDot2D Lanczos
#define LANCZOS_ZERO     1e-9
#define LANCZOS_CONVERGE 1e-5
#define LANCZOS_MAX_IT   50
#define USE_RAND_SEED    false

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
