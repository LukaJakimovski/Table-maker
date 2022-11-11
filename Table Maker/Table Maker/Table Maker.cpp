#include <iostream>
#include "Functions.h"
int main()
{
    short mode;
    std::cout << "Select mode \n 0: Write Table From X to X \t\t 1: Write Table until the equation gives a value of X \n 2: Find Base Value and Rate Of Change\t 3: Solve Equation\n";
    std::cin >> mode;
    if (mode == 0)
    {
        DrawTable();
    }
    else if (mode == 1)
    {
        FindVal();
    }
    else if (mode == 2)
    {
        FindBaseAndRateOfChange();
    }
    else if (mode == 3) {
        solveEquation();
    }
    else {
        std::cout << "Error: Invalid Mode";
    }
    std::cin >> mode;
}
