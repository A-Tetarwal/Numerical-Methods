#include <stdio.h>
#include <math.h>

#define SIZE 100

double forward_difference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double backward_difference(double (*f)(double), double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double central_difference(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

double second_derivative(double (*f)(double), double x, double h) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double custom_function(double x) {
    // Example function, you can replace this with any function you want
    return exp(x); // Returns e^x
}

int main() {
    double x[SIZE], y[SIZE];
    int n;
    printf("Do you want to use default function? (1: Yes, 0: No): ");
    scanf("%d", &n);

    if (n == 1) {
        // Use default function values
        double default_x[] = {1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.8};
        for (int i = 0; i < sizeof(default_x) / sizeof(default_x[0]); ++i) {
            x[i] = default_x[i];
            y[i] = custom_function(x[i]);
        }
        n = sizeof(default_x) / sizeof(default_x[0]);
    } else {
        // Custom function values
        printf("Enter the number of data points: ");
        scanf("%d", &n);
        printf("Enter the values of x: \n");
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &x[i]);
        }
        printf("Enter the values of y: \n");
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &y[i]);
        }
    }

     printf("Choose the difference formula (1: Forward, 2: Backward, 3: Central): ");
    int choice;
    scanf("%d", &choice);
    double h;
    printf("Enter the value of h: ");
    scanf("%lf", &h);

    double (*difference_function)(double (*)(double), double, double);

    switch (choice) {
        case 1:
            difference_function = forward_difference;
            break;
        case 2:
            difference_function = backward_difference;
            break;
        case 3:
            difference_function = central_difference;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Derivative values:\n");
    for (int i = 0; i < n; ++i) {
        printf("At x = %.2lf, ", x[i]);
        printf("First derivative: %.6lf, ", difference_function(custom_function, x[i], h));
        printf("Second derivative: %.6lf\n", second_derivative(custom_function, x[i], h));
    }


    return 0;
}