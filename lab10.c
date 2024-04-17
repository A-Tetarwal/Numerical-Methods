#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the derivative dy/dx
double derivative(double x, double y, char *function) {
    // Parse and evaluate the function
    // For simplicity, we assume the function is of the form "x + y" or similar
    // You can enhance this to support more complex functions or use external libraries
    char expression[100]; // Adjust size as needed
    strcpy(expression, function);

    // Replace 'x' and 'y' with their respective values
    char *ptr;
    while ((ptr = strstr(expression, "x")) != NULL) {
        sprintf(ptr, "%f", x);
    }
    while ((ptr = strstr(expression, "y")) != NULL) {
        sprintf(ptr, "%f", y);
    }

    // Evaluate the expression
    return atof(expression); // Convert string to double
}

// RK4 method to solve the differential equation
void rungeKutta(double x0, double y0, double h, char *function) {
    double x = x0;
    double y = y0;

    // Calculate k values
    double k1 = h * derivative(x, y, function);
    double k2 = h * derivative(x + 0.5 * h, y + 0.5 * k1, function);
    double k3 = h * derivative(x + 0.5 * h, y + 0.5 * k2, function);
    double k4 = h * derivative(x + h, y + k3, function);

    // Calculate the next value of y using the weighted sum of k values
    double next_y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

    // Output the result
    printf("x = %.2f, y = %.4f\n", x, next_y);
}

int main() {
    // Get initial values of x and y
    double x0, y0;
    printf("Enter initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter initial value of y: ");
    scanf("%lf", &y0);

    // Get step size
    double h;
    printf("Enter step size (h): ");
    scanf("%lf", &h);

    // Get the function
    char function[100]; // Adjust size as needed
    printf("Enter the function (use 'x' and 'y' as variables, e.g., x + y): ");
    scanf("%s", function);

    // Perform 4th order Runge-Kutta method with the user-defined function
    rungeKutta(x0, y0, h, function);

    return 0;
}
