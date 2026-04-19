#include "solver.h"
#include <math.h>
#include <stdlib.h>

int gaussian_elimination(double** A, double* b, double* x, int n) {
    for (int col = 0; col < n; col++) {
        int maxRow = col;
        for (int row = col + 1; row < n; row++) {
            if (fabs(A[row][col]) > fabs(A[maxRow][col]))
                maxRow = row;
        }

        double* tempRow = A[col];
        A[col] = A[maxRow];
        A[maxRow] = tempRow;

        double tempB = b[col];
        b[col] = b[maxRow];
        b[maxRow] = tempB;

        if (fabs(A[col][col]) < 1e-12)
            return -1;

        for (int row = col + 1; row < n; row++) {
            double factor = A[row][col] / A[col][col];
            for (int k = col; k < n; k++)
                A[row][k] -= factor * A[col][k];
            b[row] -= factor * b[col];
        }
    }

    for (int row = n - 1; row >= 0; row--) {
        x[row] = b[row];
        for (int k = row + 1; k < n; k++)
            x[row] -= A[row][k] * x[k];
        x[row] /= A[row][row];
    }

    return 0;
}
