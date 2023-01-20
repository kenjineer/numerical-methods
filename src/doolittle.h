#ifndef DOOLITTLE_H
#define DOOLITTLE_H

#include "config.h"
#include "inputEquations.h"

void luDecomposition(struct Equations equations) {
    double lower[equations.count][equations.count], upper[equations.count][equations.count], x[equations.count], y[equations.count];
    int i, j, k;
    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    // Decomposing matrix into Upper and Lower matrices
    for (i = 0; i < equations.count; i++) {
        // Upper Matrix
        for (k = i; k < equations.count; k++) {
            // Summation of L(i, j) * U(j, k)
            double sum = 0;
            for (j = 0; j < i; j++) {
                sum += (lower[i][j] * upper[j][k]);
            }

            // Evaluating U(i, k)
            upper[i][k] = equations.a[i][k] - sum;
        }

        // Lower Matrix
        for (k = i; k < equations.count; k++) {
            if (i == k) {
                lower[i][i] = 1; // Diagonal as 1
            } else {
                // Summation of L(k, j) * U(j, i)
                double sum = 0;
                for (j = 0; j < i; j++) {
                    sum += (lower[k][j] * upper[j][i]);
                }

                // Evaluating L(k, i)
                lower[k][i] = (equations.a[k][i] - sum) / upper[i][i];
            }
        }
    }

    // Displaying the Lower Matrix
    cout << "\nLower Matrix 🟰\n";
    for (i = 0; i < equations.count; i++)
    {
        // Lower
        for (j = 0; j < equations.count; j++) {
            cout << lower[i][j] << "     ";
        }
        cout << "\n";
    }

    // Displaying the Upper Matrix
    cout << "\nUpper Matrix 🟰\n";
    for (i = 0; i < equations.count; i++)
    {
        // Upper
        for (j = 0; j < equations.count; j++) {
            cout << upper[i][j] << "     ";
        }
        cout << "\n";
    }
    cout << "\n";

    // Compute and display Y Matrix using forward substitution
    cout << "Y Matrix🔢\n";
    for (i = 0; i < equations.count; i++)
    {
        y[i] = equations.b[i];
        for (j = 0; j < i; j++) {
            y[i] = y[i] - lower[i][j] * y[j];
        }
        cout << "Y" << i + 1 << " = " << y[i] << "\n";
    }
    cout << "\n";

    // Compute and display X Matrix using backward substitution
    cout << BOLD_START << "X Matrix🔢\n";
    for (i = equations.count - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (j = equations.count - 1; j > i; j--) {
            x[i] = x[i] - upper[i][j] * x[j];
        }
        x[i] = x[i] / upper[i][i];
        cout << "X" << equations.count - i << " = " << x[i] << "\n";
    }

    return;
}

// Driver Function
void doolittle() {
    // Declare variables
    struct Equations equations;

    // Initiate Start of Doolittle Method
    cout << BOLD_START << "\n\n🔢 ----- Doolittle Method START ----- 🔢\n\n" << BOLD_END;

    // Prompt the user to enter the number of equations and its values
    equations = inputEquations();

    // Perform the LU Decomposition using Doolittle Method
    luDecomposition(equations);

    // End of Doolittle Method
    cout << "\n\n🔢 ----- Doolittle Method END ----- 🔢\n\n\n" << BOLD_END;
    return;
}

#endif