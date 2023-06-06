// adouapb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

#include "ObiectRucsac.h"

bool compareObiectRucsac(ObiectRucsac obj1, ObiectRucsac obj2)
{
    return (obj1.eficienta() > obj2.eficienta());
}

int main()
{
    ObiectRucsac sir[900];
    int dim,G;
    std::cout << "Introduceti numarul de obiecte: ";
    std::cin >> dim;
    std::cout << "Introduceti greutatea maxima: ";
    std::cin >> G;
    std::cout << "Introduceti obiectele: "<<std::endl;
    for (int index = 0; index < dim; index++)
    {
        sir[index].citire();
    }
    
    std::sort(sir, sir + dim,compareObiectRucsac);
 
    std::cout << "Solutia optima este: " << std::endl;

    for (int index = 0; index < dim && G != 0; index++)
    {
        if (sir[index]._greutate <= G)
        {
            sir[index].afisare();
            G -= sir[index]._greutate;
        } 
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
