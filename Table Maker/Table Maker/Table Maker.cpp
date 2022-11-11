#include <iostream>

int main()
{

    double base;
    double rateOfChange;
    double tableRowFirst;
    double tableRowLast;
    double increment;
    short mode;
    double findVal;
    double index = 0;
    int sign = 1;

    std::cout << "Select mode \n Input 0 or 1\n 0: Write Table From X to X \t 1: Write Table until the equation gives a value of X \n 2: Find Base Value and Rate Of Change\n";
    std::cin >> mode;
    if (mode == 0)
    {
        std::cout << "Enter Base Value\n";      // All numbers must be decimal, fractional numbers wont work
        std::cin >> base;                       // WILL WORK: 0.6, 0.2, 0.3, 3.14159,    1,  5,   8,   19
        std::cout << "Enter Rate of change\n";  // WONT WORK: 3/5, 1/5, 3/10, 355/113, 1/1, 5/1, 8/1, 19/1
        std::cin >> rateOfChange;
        std::cout << "Enter first index\n"; //tableRowFirst has to be SMALLER than tableRowLast
        std::cin >> tableRowFirst;
        std::cout << "Enter last index\n";
        std::cin >> tableRowLast;
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
    else if (mode == 1) {
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
    else if (mode == 2) {
        double xValues[3];
        double yValues[3];

        std::cout << "Enter first and second x values individually\n";
        std::cin >> xValues[0];
        std::cin >> xValues[1];
        std::cout << "Enter first and second y values individually\n";
        std::cin >> yValues[0];
        std::cin >> yValues[1];
        yValues[2] = yValues[1] - yValues[0];
        xValues[2] = xValues[1] - xValues[0];
        rateOfChange = yValues[2] / xValues[2];
        base = yValues[0] - rateOfChange * xValues[0];
        std::cout << "Base Value : " << base << "\tRate Of Change : " << rateOfChange;
    }
    else {
        std::cout << "Error: Invalid Mode";
    }
    std::cin >> index;
}
