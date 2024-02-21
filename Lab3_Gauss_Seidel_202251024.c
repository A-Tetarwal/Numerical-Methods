#include <stdio.h>

int main(void) {
    float a[3][3], b[3], x[3], y[3];
    int m, i, j;

    printf("Enter coefficients for the 3x3 matrix A:\n");
    for (i = 0; i < 3; i++) {
        printf("Enter coefficients for row %d: ", i + 1);
        for (j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nEnter the right-hand side values for the equations (Vector B):\n");
    for (i = 0; i < 3; i++) {
        printf("Enter value for B[%d]: ", i + 1);
        scanf("%f", &b[i]);
    }

    printf("Enter initial values of x:\n");
    for (i = 0; i < 3; i++) {
        printf("Enter value for x[%d]: ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("\nEnter the number of iterations: ");
    scanf("%d", &m);

    while (m > 0) {
        for (i = 0; i < 3; i++) {
            y[i] = (b[i] / a[i][i]);

            for (j = 0; j < 3; j++) {
                if (j == i)
                    continue;

                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }

            printf("x[%d] = %f    ", i + 1, y[i]);
        }

        printf("\n");
        m--;
    }

    return 0;
}
