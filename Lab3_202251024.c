#include <stdio.h>

void jacobi(float a[3][3], float b[3], float x[3], int iterations, float epsilon) {
    float x_new[3];
    int i, j, k;

    for (k = 0; k < iterations; k++) {
        int converged = 1; // Flag to check convergence

        for (i = 0; i < 3; i++) {
            x_new[i] = b[i];
            for (j = 0; j < 3; j++) {
                if (i != j) {
                    x_new[i] -= a[i][j] * x[j];
                }
            }
            x_new[i] /= a[i][i];
            // Check convergence criterion
            if (x_new[i] - x[i] > epsilon || x[i] - x_new[i] > epsilon) {
                converged = 0;
            }
        }

        if (converged) {
            printf("Jacobi's method converged after %d iterations.\n", k + 1);
            break;
        }

        for (i = 0; i < 3; i++) {
            x[i] = x_new[i];
        }

        printf("Jacobi's method - Iteration %d:\n", k + 1);
        for (i = 0; i < 3; i++) {
            printf("x[%d]=%f ", i, x[i]);
        }
        printf("\n\n");
    }

    if (k == iterations) {
        printf("Jacobi's method did not converge within the maximum number of iterations.\n");
    }
}

void gauss_seidel(float a[3][3], float b[3], float x[3], int iterations, float epsilon) {
    float x_new[3];
    int i, j, k;

    for (k = 0; k < iterations; k++) {
        int converged = 1; // Flag to check convergence

        for (i = 0; i < 3; i++) {
            x_new[i] = b[i];
            for (j = 0; j < 3; j++) {
                if (i != j) {
                    x_new[i] -= a[i][j] * x_new[j]; // Use x_new instead of x for Gauss-Seidel
                }
            }
            x_new[i] /= a[i][i];
            // Check convergence criterion
            if (x_new[i] - x[i] > epsilon || x[i] - x_new[i] > epsilon) {
                converged = 0;
            }
        }

        if (converged) {
            printf("Gauss-Seidel method converged after %d iterations.\n", k + 1);
            break;
        }

        for (i = 0; i < 3; i++) {
            x[i] = x_new[i];
        }

        printf("Gauss-Seidel method - Iteration %d:\n", k + 1);
        for (i = 0; i < 3; i++) {
            printf("x[%d]=%f ", i, x[i]);
        }
        printf("\n\n");
    }

    if (k == iterations) {
        printf("Gauss-Seidel method did not converge within the maximum number of iterations.\n");
    }
}

int main(void) {
    float a[3][3], b[3], x[3];
    int i, j, iterations;
    float epsilon;

    printf("Enter the coefficients of the 3x3 matrix A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("a[%d][%d]=", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the constants of the equations (b vector):\n");
    for (i = 0; i < 3; i++) {
        printf("b[%d]=", i);
        scanf("%f", &b[i]);
    }

    printf("Enter the initial values of x:\n");
    for (i = 0; i < 3; i++) {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &iterations);

    printf("Enter the convergence criterion (epsilon): ");
    scanf("%f", &epsilon);

    jacobi(a, b, x, iterations, epsilon);

    printf("\n\n");

    gauss_seidel(a, b, x, iterations, epsilon);

    return 0;
}
