#ifndef CONFIG_H
#define CONFIG_H

#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Supported Methods along with the exit function
const string METHODS[4] = {
    "[1] 🔁 Gauss-Seidel",
    "[2] 🔢 Doolittle",
    "[8] 🛠️ Preferences",
    "[9] ❌ Exit"
};
enum MAIN_OPTION {
    GAUSS_SEIDEL = 1,
    DOOLITTLE,
    PREFERENCES = 8,
    EXIT = 9
};

const int MAX_ARRAY_LIMIT = 250;
const int MAX_PRECISION_LIMIT = 50;
int MAX_EQUATIONS = 10;
int PRECISION = 5;

// Supported preferences options
string PREFERENCES_OPTIONS[3] = {
    "[1] 🟰 Max Equations (" + to_string(MAX_EQUATIONS) + ")",
    "[2] 🔍 Precision (" + to_string(PRECISION) + ")",
    "[9] 🔙 Go Back"
};
enum PREFERENCES_OPTION {
    SET_MAX_EQUATIONS = 1,
    SET_PRECISION,
    BACK = 9
};

// Bold text formatting
const string BOLD_START = "\e[1m";
const string BOLD_END = "\e[0m";

// Project metadata settings
const string PROJECT = "MATH-221-1 Numerical Methods";
const string AUTHOR = "Kenneth C. Karamihan";
const string VERSION = "1.0.0";
const string UPDATE_DATE = "2023-01-21";
const string DESCRIPTION = "\n\tProject developed in partial fulfillment of the course MATH-221-1 Numerical Methods for Ordinary and Partial Differential Equations at Mapua University Intramuros, Philippines.\n\tThis program is designed to implement the numerical methods of Gauss-Seidel and Doolittle using the C++ programming language. The program is presented as a console application, and by default, it allows for a maximum of 10 equations and a number precision of 5, which can be easily modified within the program. Although there is no fixed limit on the number of iterations that can be inputted, it is important to note that large data sets may be difficult to read on the console.";
const string TITLE = "Numerical Methods for Ordinary and Partial Differential Equations";

#endif