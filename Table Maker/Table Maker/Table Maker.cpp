#include <iostream>

int main()
{
    //Definit les Variables
    //base: valeur a x = 0 | rateOfChange : monte sur longeur | tableRowFirst : Premier Element que tu veux avoir dans le tableau | tableRowLast : Dernier Element que tu veux avoir dans le tableau
    double base;
    double rateOfChange;
    double tableRowFirst;
    double tableRowLast;
    double increment;
    short mode;
    double findVal;
    double index = 0;
    /* Donne un valeur au Variables*/
    std::cout << "Select mode \n Input 0 or 1\n 0: Write Table From X to X \t 1: Write Table until the equation gives a value of X \n 2: Find Base Value and Rate Of Change\n"; //WARNING!:Pour Mode 1 ton equation doit devenir exactement le valeur que tu cherche
    std::cin >> mode;                                                                                                                  //Sinon ca continuerait indefiniment
    if (mode == 0)
    {
        std::cout << "Enter Base Value\n";      // Tout nombre doit etre entier ou decimal FRACTIONS NE MARCHERONT PAS   
        std::cin >> base;                       //     BON: 0.6, 0.2, 0.3, 3.14159,    1,  5,   8,   19
        std::cout << "Enter Rate of change\n";  // PAS BON: 3/5, 1/5, 3/10, 355/113, 1/1, 5/1, 8/1, 19/1
        std::cin >> rateOfChange;
        std::cout << "Enter first index\n";
        std::cin >> tableRowFirst;
        std::cout << "Enter last index\n";
        std::cin >> tableRowLast;
        std::cout << "Enter Table Increment\n";
        std::cin >> increment;
        std::cout << "\n\tx\t|\ty\n\t \t|\n";  // \t mets une grande espace et \n saut un ligne.
        for (index = tableRowFirst; index <= tableRowLast;)
        {
            std::cout << "\t" << index << "\t|\t" << base + rateOfChange * index << "\n";
            index += increment;
        }
    }
    else if (mode == 1) {
        std::cout << "Enter Base Value\n";      // Tout nombre doit etre entier ou decimal FRACTIONS NE MARCHERONT PAS   
        std::cin >> base;                       //     BON: 0.6, 0.2, 0.3, 3.14159,    1,  5,   8,   19
        std::cout << "Enter Rate of change\n";  // PAS BON: 3/5, 1/5, 3/10, 355/113, 1/1, 5/1, 8/1, 19/1
        std::cin >> rateOfChange;
        std::cout << "Enter Which Value You Would Like To Stop At\n";
        std::cin >> findVal;
        std::cout << "\n\tx\t|\ty\n\t \t|\n";  // \t mets une grande espace et \n saut un ligne.

        while (base + rateOfChange * index != findVal)
        {
            index++;
            std::cout << "\t" << index << "\t|\t" << base + rateOfChange * index << "\n";
        }
        std::cout << "Table Wrote From 1 to " << index;
    }
    else if (mode == 2) {
        double xValues[3];
        double yValues[3];
        //Take in two elements X and Y and find rate of change and base value
        std::cout << "Enter first and second x values individually\n";
        std::cin >> xValues[0]; //20
        std::cin >> xValues[1]; //40
        std::cout << "Enter first and second y values individually\n";
        std::cin >> yValues[0]; //200
        std::cin >> yValues[1]; //400
        //first y - second y
        yValues[2] = yValues[1] - yValues[0]; //200
        //second x - first x
        xValues[2] = xValues[1] - xValues[0]; //20
        //divide ySum by xSum this is rate of change
        rateOfChange = yValues[2] / xValues[2]; //10
        //Substract sum of that from first y this is initial value
        base = yValues[0] - rateOfChange * xValues[0]; //0
        std::cout << "Base Value : " << base << "\tRate Of Change : " << rateOfChange;


    }
    else {
        std::cout << "Error: Invalid Mode";
    }
    std::cin; // Pour que le program ne s'arrete pas immediatement
}
