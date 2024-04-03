#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the value of Newton's forward interpolation
double newtonsForwardInterpolation(double x, double h, double *xValues, double *yValues, int n) {
    double result = yValues[0];
    double u = (x - xValues[0]) / h;

    for (int i = 1; i < n; i++) {
        double temp = u;
        for (int j = 1; j <= i; j++) {
            temp *= (u - j);
        }
        result += (temp / factorial(i)) * yValues[i];
    }

    return result;
}

// Function to calculate the value of the user-defined function
double calculateFunction(double x) {
    // Replace this with your own function
    return sin(x);
}

// Function to calculate the integral of the user-defined function
double calculateIntegral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = a + (i * h);
        sum += calculateFunction(x);
    }

    return h * sum;
}

int main() {
    // Input values
    double a, b;
    int n;

    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);

    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    // Calculate the integral of the user-defined function
    double integral = calculateIntegral(a, b, n);

    // Input polynomial
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coefficients[degree + 1];
    printf("Enter the coefficients of the polynomial (from highest degree to constant term): ");
    for (int i = degree; i >= 0; i--) {
        scanf("%lf", &coefficients[i]);
    }

    // Input value
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Calculate the value of the polynomial at x
    double polynomialValue = 0;
    for (int i = degree; i >= 0; i--) {
        polynomialValue += coefficients[i] * pow(x, i);
    }

    printf("Value of the polynomial at x = %.4f is %.4f\n", x, polynomialValue);

    // Interpolation
    // Assuming user has pre-defined data points for interpolation
    double xValues[] = {0, 1, 2, 3, 4}; // Example values, replace with your own
    double yValues[] = {0, 1, 4, 9, 16}; // Example values, replace with your own
    int m = sizeof(xValues) / sizeof(xValues[0]); // Example value, replace with your own

    // Calculate the value using Newton's forward interpolation
    double interpolatedValue = newtonsForwardInterpolation(x, xValues[1] - xValues[0], xValues, yValues, m);

    printf("Interpolated value at x = %.4f is %.4f\n", x, interpolatedValue);

    return 0;
}
