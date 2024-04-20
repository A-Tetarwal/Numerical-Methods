#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// function to calculate the derivative of the polynomial
void derivative_(int n, float coeff[n])
{
    printf("The derivative of the polynomial is: ");
    for(int i = 0; i < n; i++)
    {
        printf("%fX^%d", coeff[i]*(n-i), n-i-1);
        if(coeff[i+1] >= 0 && i < n-1)
        {
            printf("+");
        }
    }
    printf("\n");
}

// print the polynomial in X^2-X^1+X^0 format
void print_polynomial(int n, float coeff[n])
{
    printf("The polynomial is: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%fX^%d", coeff[i], n-i);
        if(coeff[i+1] >= 0 && i < n)
        {
            printf("+");
        }
    }
    printf("\n");
}

// function to calculate the value of the polynomial at a given value of X
float F_x_(int n, float coeff[n], float x)
{
    float result = 0;
    for (int i = 0; i <= n; i++)
    {
        result += coeff[i]*pow(x, n-i);
    }
    return result;
}

// function to calculate the value of the derivative polynomial at a given value of X
float F_x_derivative(int n, float coeff[n], float x)
{
    float result = 0;
    for (int i = 0; i < n; i++)
    {
        result += coeff[i]*(n-i)*pow(x, n-i-1);
    }
    return result;
}

// function to calculate the roots of the polynomial using Newton-Raphson method
float newton_raphson(int n, float coeff[n])
{
    float x_0;
    printf("Enter the initial value of X: ");
    scanf("%f", &x_0);
    float elipson = 0.0001;

    float x_1 = x_0 - F_x_(n, coeff, x_0)/F_x_derivative(n, coeff, x_0);
    int iterations = 1; // Initialize iteration count to 1 (we already did 1 iteration above)
    while(fabs(x_1 - x_0) > elipson)
    {
        x_0 = x_1;
        x_1 = x_0 - F_x_(n, coeff, x_0)/F_x_derivative(n, coeff, x_0);
        iterations++; // Increment iteration count
    }
    printf("The root of the polynomial is: %f\n", x_1);
    printf("Number of iterations: %d\n", iterations);
    return x_1;
}



// main function
int main()
{
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    float coeff[n];
    for (int i = 0; i <= n; i++)
    {
        printf("Enter the coefficient of X^%d: ", n-i);
        scanf("%f", &coeff[i]);
    }
    print_polynomial(n, coeff);
    derivative_(n, coeff);
    newton_raphson(n, coeff);
    return 0;
}