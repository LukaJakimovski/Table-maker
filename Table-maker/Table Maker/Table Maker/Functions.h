#pragma once
#include <iostream>
#include <string>
using namespace std;

void solveEquation() {
    std::string equation;
    std::cout << "Enter the Equation\n";
    std::cin >> equation;
    int equationSize = equation.size(), sign = 1, coeff = 0;
    int total = 0, i = 0;

    // Traverse the equation 
    for (int j = 0; j < equationSize; j++) {
        if (equation[j] == '+' || equation[j] == '-') {
            if (j > i)
                total += sign * stoi(equation.substr(i, j - i));
            i = j;
        }

        // For cases such as: x, -x, +x 
        else if (equation[j] == 'x') {
            if ((i == j) || equation[j - 1] == '+')
                coeff += sign;
            else if (equation[j - 1] == '-')
                coeff -= sign;
            else
                coeff += sign * stoi(equation.substr(i, j - i));
            i = j + 1;
        }

        // Flip sign once '=' is seen 
        else if (equation[j] == '=') {
            if (j > i)
                total += sign * stoi(equation.substr(i, j - i));
            sign = -1;
            i = j + 1;
        }
    }

    // There may be a number left in the end 
    if (i < equationSize)
        total += sign * stoi(equation.substr(i));
    // For infinite solutions 
    if (coeff == 0 && total == 0)
        std::cout << "Infinite solutions\n";
    return;
    // For no solution 
    if (coeff == 0 && total)
        std::cout << "No solution\n";
    return;

    // x = total sum / coeff of x 
    // '-' sign indicates moving 
    // numeric value to right hand side 
    int ans = -total / coeff;
    std::cout << "x = " + to_string(ans);
}
void FindBaseAndRateOfChange() {
    double xValues[2];
    double yValues[2];
    double deltaY;
    double deltaX;
    double rateOfChange;
    double base;
    std::cout << "Enter first and second x values individually\n";
    std::cin >> xValues[0];
    std::cin >> xValues[1];
    std::cout << "Enter first and second y values individually\n";
    std::cin >> yValues[0];
    std::cin >> yValues[1];
    deltaY = yValues[1] - yValues[0];
    deltaX = xValues[1] - xValues[0];
    rateOfChange = deltaY / deltaX;
    base = yValues[0] - rateOfChange * xValues[0];
    std::cout << "Base Value : " << base << "\tRate Of Change : " << rateOfChange;
}
void FindVal() {
    double base;
    double rateOfChange;
    double findVal;
    double index = 0;
    int sign;
    std::cout << "Enter Base Value\n";
    std::cin >> base;
    std::cout << "Enter Rate of change\n";
    std::cin >> rateOfChange;
    std::cout << "Enter Which Value You Would Like To Stop At\n";
    std::cin >> findVal;
    std::cout << "\n\tx\t|\ty\n\t \t|\n";

    while (index != (findVal - base) / rateOfChange)
    {
        if ((findVal - base) / rateOfChange < 0)
        {
            index--;
            if (index < (findVal - base) / rateOfChange) {
                index = (findVal - base) / rateOfChange;
            }
            sign = -1;
        }
        else
        {
            index++;
            if (index > (findVal - base) / rateOfChange) {
                index = (findVal - base) / rateOfChange;
            }
            sign = 1;
        }
        std::cout << "\t" << index << "\t|\t" << base + rateOfChange * index << "\n";
    }
    std::cout << "Table Wrote From " << sign << " to " << index;
}
void DrawTable() {
    double base;
    double rateOfChange;
    double tableRowFirst;
    double tableRowLast;
    double increment;
    double index;
    std::cout << "Enter Base Value\n";      // All numbers must be decimal, fractional numbers wont work
    std::cin >> base;                       // WILL WORK: 0.6, 0.2, 0.3, 3.14159,    1,  5,   8,   19
    std::cout << "Enter Rate of change\n";  // WONT WORK: 3/5, 1/5, 3/10, 355/113, 1/1, 5/1, 8/1, 19/1
    std::cin >> rateOfChange;
    std::cout << "Enter first index\n"; //tableRowFirst has to be SMALLER than tableRowLast
    std::cin >> tableRowFirst;
    std::cout << "Enter last index\n";
    std::cin >> tableRowLast;
    if (tableRowFirst > tableRowLast)
    {
        std::cout << "Error: First index must be bigger than last index";
        std::cin;
        return;
    }
    std::cout << "Enter Table Increment\n"; //Increment has to be a positive value
    std::cin >> increment;
    std::cout << "\n\tx\t|\ty\n\t \t|\n";
    index = tableRowFirst;
    do
    {
        std::cout << "\t" << index << "\t|\t" << base + rateOfChange * index << "\n";
        index += increment;
    } while (index <= tableRowLast);
}
void DrawAppleFallDistance() {
    // Gravity = 9.81m/s^2    Gravity * s^2 = d
    // But we need to take the average velocity over time so /2 to get the average between two points    
    // The Equation basically just takes two points in time finds the average velocity and multiplies it by time elapsed
    // Ex, V at X=0 is 0    V at X=1 is 9.81 the average is (0 + 9.81)/2 = 4.905  this works for any two points
    // So : f(x) = 9.81x^2/2
    std::cout << "\n\tTime\t|\tDistance\n\t \t|\n";
    int index = 0;
    do
    {
        std::cout << "\t" << index << "\t|\t" << 9.81*pow(index,2)/2 << "\n";
        index++;
    } while (index <= 100);
}
