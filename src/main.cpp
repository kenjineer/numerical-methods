#include "config.h"
#include "gaussSeidel.h"
#include "doolittle.h"
#include "preferences.h"

using namespace std;

int main(void) {
    // Set Console to UTF8 for emoji support š
    if(IsValidCodePage(CP_UTF8))
        SetConsoleOutputCP(CP_UTF8);

    // Set Decimal Precision
    cout << setprecision(PRECISION) << fixed;

    // Variable declaration for input Method
    int method;

    // Initiate Start of Program
    cout << "āļø  [... Program Start ...] āļø" << "\n\n";

    // Display Project Metadata
    cout << "š  Project:      " << PROJECT << "\n";
    cout << "šØ  Author:       " << BOLD_START << AUTHOR << BOLD_END << "\n";
    cout << "āØ  Version:      " << VERSION << "\n";
    cout << "š  Last Updated: " << UPDATE_DATE << "\n";
    cout << "š  Description:  " << DESCRIPTION << "\n\n";

    // Perform loop unless [ā Exit] is selected
    while (method != EXIT) {
        // Project Title
        cout << TITLE << "\n";

        // Display Supported Methods 
        for (string option : METHODS) {
            cout << option << "\n";
        }

        // Prompt user to select a method
        cout << "\n:: Select a Numerical Method: ";
        cin >> method;

        // Interpret user input
        if (method == GAUSS_SEIDEL) {
            gaussSeidel();
        } else if (method == DOOLITTLE) {
            doolittle();
        } else if (method == PREFERENCES) {
            preferences();
        } else if (method != EXIT) {
            cout << "INVALID INPUT ERROR\n";
            // clear error state
            cin.clear();
        }
    }

    // End the Program
    cout << "\n\nā  [... End of Program ...]  ā\n\nCtrl-C to exit program\n";
    return 0;
}