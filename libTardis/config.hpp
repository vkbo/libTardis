/*
** Configuration file for libTardis
*/

// Lanczos Settings
#define LANCZOS_ZERO     1e-12  // Zero-condition for Beta value
#define LANCZOS_CONVERGE 1e-10  // Covergence condition for Lanczos iterations
#define LANCZOS_MAX_IT   100    // Max number of iterations
#define LANCZOS_SEED     false  // If true, seeds random generator with time(NULL)
#define LANCZOS_STRICT   false  // If true, will break the Lanczos if convergence increase
#define LANCZOS_DIVERGE  2.0    // How much divergence to allow if LANCZOS_STRICT is set

// Enable Progress Output
#define PROGRESS
//~ #define MINIMAL

// Enable OpenMP
#define OPENMP
//~ #define OPENMPLOWMEM

// Use index-based basis search?
//  - Only useful for small basises.
//  - Uses a lot of memory but gives a good speedup for small systems.
//~ #define INDEX_BASIS
