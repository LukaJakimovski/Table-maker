#include <iostream>

int main()
{
    //Definit les Variables
    //base: valeur a x = 0 | rateOfChange : monte sur longeur | tableRowFirst : Premier Element que tu veux avoir dans le tableau | tableRowLast : Dernier Element que tu veux avoir dans le tableau
    double base;
    double rateOfChange;
    int tableRowFirst;
    int tableRowLast;
    short mode;
    double findVal;
    int index = 0;

    /* Donne un valeur au Variables*/
    std::cout << "Select mode \n Input 0 or 1\n 0: Write Table From X to X \t 1: Write Table until the equation gives a value of X\n"; //WARNING!:Pour Mode 1 ton equation doit devenir exactement le valeur que tu cherche
    std::cin >> mode;                                                                                                                  //Sinon ca continuerait indefiniment
    std::cout << "Enter Base Value\n";      // Tout nombre doit etre entier ou decimal FRACTIONS NE MARCHERONT PAS   
    std::cin >> base;                       //     BON: 0.6, 0.2, 0.3, 3.14159,    1,  5,   8,   19
    std::cout << "Enter Rate of change\n";  // PAS BON: 3/5, 1/5, 3/10, 355/113, 1/1, 5/1, 8/1, 19/1
    std::cin >> rateOfChange;
    if (mode == 0)
    {
        std::cout << "Enter first index\n";
        std::cin >> tableRowFirst;
        std::cout << "Enter last index\n";
        std::cin >> tableRowLast;
        std::cout << "\n\tx\t|\ty\n\t \t|\n";  // \t mets une grande espace et \n saut un ligne.
            for (int i = tableRowFirst; i <= tableRowLast; i++)
            {
                std::cout << "\t" << i << "\t|\t" << base + rateOfChange * i << "\n";
            }
    }
    else {
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
    std::cin; // Pour que le program ne s'arrete pas immediatement
}
    
    