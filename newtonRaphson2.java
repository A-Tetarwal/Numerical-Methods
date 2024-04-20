import java.util.Scanner;

public class newtonRaphson2 {
    static int[] coefficients;
    static int degree;
    static double x0;
    static double x1;
    static boolean foundPair;

    // Step 1: Define f(x)
    public static double function(double x0) {
        double result = 0;
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * Math.pow(x0, i);
        }
        return result;
    }

    // Step 4: Calculate the derivative f'(x)
    // public static double derivative(double x0) {
    //     double result = 0;
    //     for (int i = 1; i <= degree; i++) {
    //         result += i * coefficients[i] * Math.pow(x0, i - 1);
    //     }
    //     return result;
    // }

    public static double derivative(double x0) {
        if (degree < 1) {
            throw new ArithmeticException("Degree of polynomial must be at least 1 for derivative calculation.");
        }
        double result = 0;
        for (int i = 1; i <= degree; i++) {
            result += i * coefficients[i] * Math.pow(x0, i - 1);
        }
        return result;
    }

    // Step 3: Check the sign of consecutive f(x) values
    public static void checkSign(double x01, double x02){
        double result1 = function(x01);
        // for (int i = 0; i <= degree; i++) {
        //     result1 += coefficients[i] * Math.pow(x01, i);
        // }
        // System.out.println(result1);

        double result2 = function(x02);
        // for (int i = 0; i <= degree; i++) {
        //     result2 += coefficients[i] * Math.pow(x02, i);
        // }
        // System.out.println(result2);

        if (result1*result2<0) {
            if (result1<0 && result2>0) {
                if ((result1-0)>(0-result2)) {
                    x0 = x01;
                }
                else{
                    x0 = x02;
                }
            }
            else if (result1>0 && result2<0){
                if ((result1-0)<(0-result2)) {
                    x0 = x01;
                }
                else{
                    x0 = x02;
                }
            }
            foundPair = true;
        }
    }

    // Step 5 and 6: Apply Newton-Raphson formula to find the root
    // public static double newtonRaphson(double x0, double tolerance, int maxIterations) {
    //     double x = x0;
    //     int iterations = 0;
    //     while (iterations < maxIterations) {
    //         double fx0 = function(x0);
    //         if (Math.abs(fx0) < tolerance) {
    //             System.out.println("Converged after " + iterations + " iterations.");
    //             return x;
    //         }
    //         double dfx0 = derivative(x0);
    //         if (dfx0 == 0) {
    //             throw new ArithmeticException("Derivative is zero. Cannot continue.");
    //         }
    //         x1 = x0 - fx0 / dfx0;
    //         iterations++;
    //     }
    //     throw new ArithmeticException("Maximum number of iterations reached.");
    // }

    public static double newtonRaphson(double x0, double tolerance, int maxIterations) {
        double x = x0;
        int iterations = 0;
        while (iterations < maxIterations) {
            double fx0 = function(x0);
            if (Math.abs(fx0) < tolerance) {
                System.out.println("Converged after " + iterations + " iterations.");
                return x;
            }
            double dfx0 = derivative(x0);
            if (dfx0 == 0) {
                // Choose a different initial point
                x0 += 1; // You can adjust this value as needed
                iterations = 0; // Reset iterations
                continue; // Restart the loop with the new initial point
            }
            x1 = x0 - fx0 / dfx0;
            iterations++;
        }
        throw new ArithmeticException("Maximum number of iterations reached.");
    }
    

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // Step 1: Get the polynomial degree and coefficients from the user
            System.out.print("Enter the degree of the polynomial: ");
            degree = scanner.nextInt();
            coefficients = new int[degree + 1];
            System.out.println("Enter " + (degree + 1) + " coefficients:");
            for (int i = 0; i <= degree; i++) {
                coefficients[i] = scanner.nextInt();
            }
        }

        

        // Step 2: Calculate f(x) for a given function
        // Step 3: Check the sign of consecutive f(x) values

        foundPair = false;
        // Iterating over an array of 11 numbers from -5 to +5
        for (int i = -5; i <= 5 && !foundPair; i++) {
            double x01 = i;
            double x02 = i + 1;
            checkSign(x01, x02);
        }


        double tolerance = 1e-6; // Tolerance for convergence
        int maxIterations = 100; // Maximum number of iterations
        
            // Try multiple initial points and choose the one leading to convergence
            double[] initialPoints = {2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0};
            double root = Double.NaN;
    for (double initialPoint : initialPoints) {
        try {
            root = newtonRaphson(initialPoint, tolerance, maxIterations);
            break; // Break out of the loop if convergence is successful
        } catch (ArithmeticException e) {
            // Try the next initial point if convergence failed
            System.out.println("Initial point " + initialPoint + " failed. Trying next initial point...");
        }
    }

    if (!Double.isNaN(root)) {
        System.out.println("Root: " + root);
    } else {
        System.out.println("Failed to find a root within the specified tolerance.");
    }


        // double root = newtonRaphson(x0, tolerance, maxIterations);
        // System.out.println("Root: " + root);
    }
}