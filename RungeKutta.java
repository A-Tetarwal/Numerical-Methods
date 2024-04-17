import com.singularsys.jep.Jep;
import com.singularsys.jep.JepException;

import java.util.Scanner;

public class RungeKutta {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get initial values of x and y
        System.out.print("Enter initial value of x: ");
        double x0 = scanner.nextDouble();
        System.out.print("Enter initial value of y: ");
        double y0 = scanner.nextDouble();

        // Get step size
        System.out.print("Enter step size (h): ");
        double h = scanner.nextDouble();

        // Get the function
        System.out.print("Enter the function (use 'x' and 'y' as variables): ");
        scanner.nextLine(); // Consume newline
        String function = scanner.nextLine();

        // Create JEP instance
        Jep jep = new Jep();
        try {
            jep.addVariable("x", x0);
            jep.addVariable("y", y0);
            jep.parseExpression(function); // Parse the expression
        } catch (JepException e) {
            System.out.println("Error parsing expression: " + e.getMessage());
            return;
        }

        // Perform 4th order Runge-Kutta method
        double k1, k2, k3, k4;
        do {
            try {
                k1 = h * jep.getValue(); // Evaluate the function for k1
                jep.addVariable("x", x0 + 0.5 * h);
                jep.addVariable("y", y0 + 0.5 * k1);
                k2 = h * jep.getValue(); // Evaluate the function for k2
                jep.addVariable("x", x0 + 0.5 * h);
                jep.addVariable("y", y0 + 0.5 * k2);
                k3 = h * jep.getValue(); // Evaluate the function for k3
                jep.addVariable("x", x0 + h);
                jep.addVariable("y", y0 + k3);
                k4 = h * jep.getValue(); // Evaluate the function for k4

                double delta_y = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

                // Update values for next iteration
                x0 += h;
                y0 += delta_y;

                // Output the result
                System.out.println("x = " + x0 + ", y = " + y0);
            } catch (JepException e) {
                System.out.println("Error evaluating expression: " + e.getMessage());
                return;
            }
        } while (x0 + h <= 10); // Change the condition as needed

        scanner.close();
    }
}
