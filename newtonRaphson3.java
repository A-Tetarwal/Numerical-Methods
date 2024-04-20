import java.util.Scanner;

public class newtonRaphson3 {
    static int[] coefficients;
    static int degree;

    // Step 1: Define f(x)
    public static double function(double x) {
        double result = 0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * Math.pow(x, i);
        }
        return result;
    }

    // Step 4: Calculate the derivative f'(x)
    public static double derivative(double x) {
        double result = 0;
        for (int i = 1; i <= degree; i++) {
            result += i * coefficients[i] * Math.pow(x, i - 1);
        }
        return result;
    }

    // Step 3: Check the sign of consecutive f(x) values
    public static double[] findInitialGuess() {
        double x0 = -1.0; // Start with a reasonable initial guess
        double x1 = 1.0; // Another initial guess
        double fx0 = function(x0);
        double fx1 = function(x1);

        // Check if the function changes sign between x0 and x1
        if (fx0 * fx1 < 0) {
            // If the function changes sign, return x0 and x1
            return new double[]{x0, x1};
        }

        // If the function does not change sign between x0 and x1, continue searching
        double step = 2.0; // Increment for the next guess
        while (true) {
            x0 = x1;
            x1 += step;
            fx0 = fx1;
            fx1 = function(x1);

            if (fx0 * fx1 < 0) {
                // If the function changes sign, return x0 and x1
                return new double[]{x0, x1};
            }

            // Increase the step size if the function does not change sign
            step *= 2;
        }
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
        Scanner scanner = new Scanner(System.in);

        // Step 1: Get the polynomial degree and coefficients from the user
        System.out.print("Enter the degree of the polynomial: ");
        degree = scanner.nextInt();
        coefficients = new int[degree + 1];
        System.out.println("Enter " + (degree + 1) + " coefficients:");
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = scanner.nextInt();
        }

        // Step 3: Find the initial guess x0
        double[] initialGuess = findInitialGuess();
        double x0 = initialGuess[0];
        double x1 = initialGuess[1];
        double fx0 = function(x0);
        double fx1 = function(x1);

        // Choose the value of x0 closer to zero as the initial guess
        x0 = Math.abs(fx0) < Math.abs(fx1) ? x0 : x1;

        double tolerance = 1e-6; // Tolerance for convergence
        int maxIterations = 100; // Maximum number of iterations
        double root = newtonRaphson(x0, tolerance, maxIterations);
        System.out.println("Root: " + root);
    }
}