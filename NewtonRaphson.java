import java.util.function.DoubleUnaryOperator;
import java.util.Scanner;

public class NewtonRaphson {
    static int[] array;
    static int num;

    // Step 1: Define f(x)
    public static double function(double x) {
        // Define your function here
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the order of the polynomial:");
        num = scanner.nextInt();
        // System.out.println("Enter the value of x:");
        // x = scanner.nextDouble(); // Changed to nextDouble() to match variable type
        
        // Read the coefficients into an array and build the expression
        StringBuilder expression = new StringBuilder();
        System.out.println("Enter " + (num + 1) + " coefficients:");
        for (int i = 0; i <= num; i++) {
            array[i] = scanner.nextInt();
            if (i == 0) {
                expression.append(array[i]);
            } else {
                expression.append((array[i] < 0) ? " - " : " + ");
                expression.append(Math.abs(array[i])).append("x^").append(i);
            }
        }
        
        // Compute the function value using the provided coefficients
        double result = 0;
        for (int i = 0; i <= num; i++) {
            result += array[i] * Math.pow(x, i);
        }
        return result;
    }
    // Step 2: Calculate f(x) for a given function
    public static double calculateFunction(double x) {
        return function(x);
    }

    // Step 3: Check the sign of consecutive f(x) values
    public static boolean checkSign(double x0, double x1) {
        return function(x0) * function(x1) < 0;
    }

    // Step 4: Calculate the derivative f'(x)
    public static double derivative(double x) {
        // Retrieve the coefficients of the polynomial from the function definition
        
        // Assume the coefficients are stored in a global variable or computed beforehand
        
        // Now, compute the derivative of the polynomial
        double derivativeResult = 0;
        for (int i = 1; i <= num; i++) {
            derivativeResult += i * array[i] * Math.pow(x, i - 1);
        }
        
        return derivativeResult;
    }
    

    // Step 5 and 6: Apply Newton-Raphson formula to find the root
    public static double newtonRaphson(double x0, double tolerance, int maxIterations) {
        double x = x0;
        int iterations = 0;
        while (iterations < maxIterations) {
            double fx = function(x);
            if (Math.abs(fx) < tolerance) {
                System.out.println("Converged after " + iterations + " iterations.");
                return x;
            }
            double dfx = derivative(x);
            if (dfx == 0) {
                throw new ArithmeticException("Derivative is zero. Cannot continue.");
            }
            x = x - fx / dfx;
            iterations++;
        }
        throw new ArithmeticException("Maximum number of iterations reached.");
    }

    public static void main(String[] args) {
        double x0 = 2; // Initial guess
        double tolerance = 1e-6; // Tolerance for convergence
        int maxIterations = 100; // Maximum number of iterations
        double root = newtonRaphson(x0, tolerance, maxIterations);
        System.out.println("Root: " + root);
    }
}
