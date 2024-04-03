#include <stdio.h>

#define N 3

void gauss_jordan(double matrix[N][N+1]) {
    int i, j, k;
    double pivot, factor;

    for (i = 0; i < N; i++) {
        pivot = matrix[i][i];

        for (j = 0; j < N+1; j++) {
            matrix[i][j] /= pivot;
        }

        for (k = 0; k < N; k++) {
            if (k != i) {
                factor = matrix[k][i];

                for (j = 0; j < N+1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    double matrix[N][N+1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    gauss_jordan(matrix);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, matrix[i][N]);
    }

    return 0;
}