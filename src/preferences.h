#ifndef PREFERENCES_H
#define PREFERENCES_H

#include "config.h"

// Set maximum equations that can be inputted
void setMaxEquations() {
    cout << "Set New Max Equations: ";
    cin >> MAX_EQUATIONS;
    cin.clear();

    if (MAX_EQUATIONS > MAX_ARRAY_LIMIT) {
        MAX_EQUATIONS = MAX_ARRAY_LIMIT;
        cout << "Maximum array limit exceeded. Reducing max equations to limit of " << MAX_ARRAY_LIMIT << ".\n";
    }

    PREFERENCES_OPTIONS[SET_MAX_EQUATIONS-1] = "[1] 🟰 Max Equations (" + to_string(MAX_EQUATIONS) + ")";
}

// Set precision/decimal places
void setPrecision() {
    cout << "Set New Decimal Precision: ";
    cin >> PRECISION;
    cin.clear();
    if (PRECISION > MAX_PRECISION_LIMIT) {
        PRECISION = MAX_PRECISION_LIMIT;
        cout << "Maximum precision limit exceeded. Reducing precision to limit of " << MAX_PRECISION_LIMIT << ".\n";
    } else if (PRECISION < 0) {
        PRECISION = 0;
        cout << "Minimum precision limit exceeded. Reducing precision to minimum of " << 0 << ".\n";
    }
    cout << setprecision(PRECISION) << fixed;

    PREFERENCES_OPTIONS[SET_PRECISION-1] = "[2] 🔍 Precision (" + to_string(PRECISION) + ")";
}

void preferences() {
    // Variable declaration for input Preference
    int preference;

    // Initiate Start of Preferences
    cout << BOLD_START << "\n\n🛠️  ----- Preferences START ----- 🛠️\n\n\n" << BOLD_END;


    // Perform loop unless [🔙 Go Back] is selected
    while (preference != BACK) {
        // Display Supported Preferences 
        cout << "Preferences\n";
        for (string option : PREFERENCES_OPTIONS) {
            cout << option << "\n";
        }

        // Prompt user to select a preference
        cout << "\n:: Select a preference to set: ";
        cin >> preference;
        cout << "\n";

        // Interpret user input
        if (preference == SET_MAX_EQUATIONS) {
            setMaxEquations();
            preference = 0;
        } else if (preference == SET_PRECISION) {
            setPrecision();
            preference = 0;
        } else if (preference != BACK) {
            cout << "INVALID INPUT ERROR\n";
            preference = 0;
            // clear error state
            cin.clear();
        }
        
        cout << "\n";
    }

    // End of Preferences
    cout << BOLD_START << "🛠️ ----- Preferences END ----- 🛠️\n\n\n" << BOLD_END;
}

#endif