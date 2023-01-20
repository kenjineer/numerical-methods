#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include "config.h"
#include "inputEquations.h"

void doIterate(struct Equations equations, int iterationsCount, double x[]) {
    double y[equations.count];
    int currentIteration = 1, i, j;
    while (iterationsCount > 0) {
        // Display current iteration
        cout << BOLD_START << "Iteration No. " << currentIteration << "🔁\n";

        // Perform Iteration
        for (i = 0; i < equations.count; i++) {
            // Set initial value as b[i]
            y[i] = equations.b[i];
            for (j = 0; j < equations.count; j++)
            {
                // Skip if x[i] = x[j]
                if (j == i) continue;

                // Deduct the a[i][j] * x[j] from y[i]
                // Then set the new value of y[i]
                y[i] = y[i] - (equations.a[i][j] * x[j]);

                // Set new value of x[i]
                x[i] = y[i];
            }
            // Divide the final value of y[i] by a[i][i]
            // Then set the final value of x[i]
            x[i] = y[i] / equations.a[i][i];

            // Display the result of new x[i]
            cout << "x" << i + 1 << " = " << x[i] << "\n";
        }
        cout << "\n";
        iterationsCount--;
        currentIteration++;
    }
}

// Driver Function
void gaussSeidel() {
    // Declare variables
    struct Equations equations;
    double x[equations.count];
    int iterationsCount, i;

    // Initiate Start of Gauss-Seidel Method
    cout << BOLD_START << "\n\n🔁 ----- Gauss-Seidel Method START ----- 🔁\n\n" << BOLD_END;

    // Prompt the user to enter the number of equations and its values
    equations = inputEquations();

    // Prompt the user to enter the initial values of x
    cout << "\nEntering initial values of x 🟰\n";
    for (i = 0; i < equations.count; i++) {
        cout << ":: Value of x" << i + 1 << ": ";
        cin >> x[i];
        cin.clear();
    }

    // Prompt the user to enter the number of iterations to be generated
    cout << "\n:: Enter the no. of iterations: ";
    cin >> iterationsCount;
    cin.clear();
    cout << "\n";

    // Perform the iteration using Gauss-Seidel Method
    doIterate(equations, iterationsCount, x);

    // End of Gauss-Seidel Method
    cout << "\n🔁 ----- Gauss-Seidel Method END ----- 🔁\n\n\n" << BOLD_END;
    return;
}

#endif