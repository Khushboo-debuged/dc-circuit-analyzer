#ifndef SOLVER_H
#define SOLVER_H

#ifdef __cplusplus
extern "C" {
#endif

int gaussian_elimination(double** A, double* b, double* x, int n);

#ifdef __cplusplus
}
#endif

#endif
