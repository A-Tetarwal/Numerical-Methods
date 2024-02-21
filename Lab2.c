#include <stdio.h>
#include <math.h>

#define SIZE 10

void printMatrix(float a[SIZE][SIZE], int n);
void qrDecomposition(float a[SIZE][SIZE], int n, float q[SIZE][SIZE], float r[SIZE][SIZE]);
void matrixMultiplication(float a[SIZE][SIZE], float b[SIZE][SIZE], float result[SIZE][SIZE], int n);
void findEigenvalues(float a[SIZE][SIZE], int n, float epsilon);

int main() {
    float a[SIZE][SIZE];
    int n;

    /* Inputs */
    printf("Enter Order of Matrix: ");
    scanf("%d", &n);

    /* Reading Matrix */
    printf("Enter Coefficient of Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]=", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    /* Eigenvalues */
    findEigenvalues(a, n, 0.001);

    return 0;
}

void printMatrix(float a[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
}

void qrDecomposition(float a[SIZE][SIZE], int n, float q[SIZE][SIZE], float r[SIZE][SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            q[i][j] = a[i][j];
        }
    }

    for (int k = 0; k < n - 1; k++) {
        float norm = 0.0;
        for (int m = k; m < n; m++) {
            norm += q[m][k] * q[m][k];
        }
        norm = sqrt(norm);

        if (q[k][k] > 0) {
            norm = -norm;
        }

        float alpha = norm * (norm - q[k][k]);
        for (int m = 0; m < k; m++) {
            r[m][k] = 0.0;
        }
        for (int m = k; m < n; m++) {
            r[m][k] = q[m][k] - alpha * q[m][k];
        }

        float beta = 0.0;
        for (int m = k; m < n; m++) {
            beta += r[m][k] * r[m][k];
        }
        beta = sqrt(beta);

        for (int m = 0; m < k; m++) {
            q[m][k] = 0.0;
        }
        for (int m = k; m < n; m++) {
            q[m][k] = r[m][k] / beta;
        }

        for (int j = k + 1; j < n; j++) {
            float gamma = 0.0;
            for (int m = k; m < n; m++) {
                gamma += q[m][k] * a[m][j];
            }

            for (int i = 0; i < n; i++) {
                a[i][j] -= 2.0 * gamma * q[i][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            r[i][j] = q[i][j];
        }
    }
}

void matrixMultiplication(float a[SIZE][SIZE], float b[SIZE][SIZE], float result[SIZE][SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void findEigenvalues(float a[SIZE][SIZE], int n, float epsilon) {
    float q[SIZE][SIZE], r[SIZE][SIZE];

    /* QR Algorithm iterations */
    for (int iter = 0; iter < 1000; iter++) {
        qrDecomposition(a, n, q, r);
        matrixMultiplication(r, q, a, n);

        /* Check for convergence */
        float offDiagonalSum = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    offDiagonalSum += fabs(a[i][j]);
                }
            }
        }

        if (offDiagonalSum < epsilon) {
            break;
        }
    }

    /* Display Eigenvalues */
    printf("\nEigenvalues:\n");
    for (int i = 0; i < n; i++) {
        printf("%f\n", a[i][i]);
    }
}
