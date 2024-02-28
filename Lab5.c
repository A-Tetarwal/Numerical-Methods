#include <stdio.h>
#include <math.h>

// Function to compute the value of the polynomial equation
float f(float x, float coeff[], int n) {
    float result = 0;
    for (int i = 0; i <= n; i++) {
        result += coeff[i] * pow(x, i);
    }
    return result;
}

// Function to compute the derivative of the polynomial equation
float df(float x, float coeff[], int n) {
    float result = 0;
    for (int i = 1; i <= n; i++) {
        result += i * coeff[i] * pow(x, i - 1);
    }
    return result;
}

int main() {
    int n, maxmitr;
    float h, x0, x1, allerr;

    // Prompt the user to input the order of the equation
    printf("Enter the order of the equation: ");
    scanf("%d", &n);

    // Array to store coefficients
    float coeff[n + 1];

    // Prompt the user to input coefficients
    printf("Enter the coefficients of the equation (from highest order to constant term):\n");
    for (int i = n; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%f", &coeff[i]);
    }

    // Prompt the user to input the initial guess, allowed error, and maximum iterations
    printf("\nEnter initial guess, allowed error, and maximum iterations:\n");
    scanf("%f %f %d", &x0, &allerr, &maxmitr);

    // Print header for the table
    printf("\n Iteration |    x(n)   |    f(x(n))   |    f'(x(n))   |    x(n+1)    |  |x(n+1) - x(n)|\n");
    printf("---------------------------------------------------------------------------------------\n");

    // Iteration loop
    int itr;
    for (itr = 1; itr <= maxmitr; itr++) {
        h = f(x0, coeff, n) / df(x0, coeff, n);
        x1 = x0 - h;
        printf("    %3d    | %9.6f | %12.6f | %14.6f | %12.6f | %14.6f |\n", itr, x0, f(x0, coeff, n), df(x0, coeff, n), x1, fabs(x1 - x0));
        if (fabs(x1 - x0) < allerr) {
            printf("\nRoot approximation after %d iterations: %8.6f\n", itr, x1);
            return 0;
        }
        x0 = x1;
    }

    // Check if the loop terminated due to maximum iterations
    if (itr > maxmitr) {
        printf("\nThe maximum number of iterations (%d) reached. The solution may not have converged.\n", maxmitr);
        return 1;
    }

    return 0;
}
