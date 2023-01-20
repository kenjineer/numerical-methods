#ifndef INPUT_EQUATIONS_H
#define INPUT_EQUATIONS_H

#include "config.h"

typedef struct Equations {
    double a[MAX_ARRAY_LIMIT][MAX_ARRAY_LIMIT];
    double b[MAX_ARRAY_LIMIT];
    int count = MAX_EQUATIONS;
} Equations;

struct Equations inputEquations() {
    // Declare variables
    struct Equations equations;
    int i, j;
    bool limit_break = true;

    while (limit_break) {
        // Prompt the user to enter the number of equations
        cout << "\n:: Enter the number of equations: ";
        cin >> equations.count;
        cin.clear();

        if (equations.count > MAX_EQUATIONS) {
            limit_break = true;
            cout << "Maximum number of equations is " << MAX_EQUATIONS << "\n";
            cout << "Please enter a lower number...\n";
        } else {
            limit_break = false;
        }
    }

    // Prompt the user to enter the values per equation
    for (i = 0; i < equations.count; i++) {
        cout << "\nEntering Values for Eqn No. " << i + 1 << " 🟰 f(x) = a" << i + 1 << "ₙxₙ + ... = b" << i + 1 << "\n";
        for (j = 0; j < equations.count; j++)
        {
            cout << ":: Value of a" << j + 1 << ": ";
            cin >> equations.a[i][j];
            cin.clear();
        }
        cout << ":: Value of b" << i + 1 << ": ";
        cin >> equations.b[i];
        cin.clear();
    }

    return equations;
}

#endif