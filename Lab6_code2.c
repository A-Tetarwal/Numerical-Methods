#include <stdio.h>
#include <math.h>

#define SIZE 100

double forward_difference(double *y, double h, int i) {
    return (y[i + 1] - y[i]) / h;
}

double backward_difference(double *y, double h, int i) {
    return (y[i] - y[i - 1]) / h;
}

double central_difference(double *y, double h, int i) {
    return (y[i + 1] - y[i - 1]) / (2 * h);
}

double second_derivative(double *y, double h, int i) {
    return (y[i + 1] - 2 * y[i] + y[i - 1]) / (h * h);
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
        double default_y[] = {2.7183, 3.3201, 4.0552, 4.9530, 6.0496, 7.3891, 9.0250};
        for (int i = 0; i < sizeof(default_x) / sizeof(default_x[0]); ++i) {
            x[i] = default_x[i];
            y[i] = default_y[i];
        }
        n = sizeof(default_x) / sizeof(default_x[0]);
    } else {
        // Custom function values
        printf("Enter the number of data points: ");
        scanf("%d", &n);
        printf("Enter the values of x and y: \n");
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &x[i], &y[i]);
        }
    }
    
    printf("Choose the difference formula (1: Forward, 2: Backward, 3: Central): ");
    int choice;
    scanf("%d", &choice);
    double h;
    printf("Enter the value of h: ");
    scanf("%lf", &h);
    
    double (*difference_function)(double *, double, int);
    
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
    for (int i = 1; i < n - 1; ++i) {
        printf("At x = %.2lf, ", x[i]);
        printf("First derivative: %.6lf, ", difference_function(y, h, i));
        printf("Second derivative: %.6lf\n", second_derivative(y, h, i));
    }
    
    return 0;
}
