#include <iostream>
#include <algorithm>
#include <fstream>

#include "Scrisoare.h"

bool compareObiectRucsac(Scrisoare obj1, Scrisoare obj2)
{
    return (obj1.eficienta() > obj2.eficienta());
}

int main()
{
    Scrisoare CutieScrisori[900];

    int dim, G;
    std::cout << "Introduceti numarul de obiecte: ";
    std::cin >> dim;
    std::cout << "Introduceti greutatea maxima: ";
    std::cin >> G;
    std::cout << "Introduceti obiectele: " << std::endl;
    for (int index = 0; index < dim; index++)
    {
        CutieScrisori[index].citire();
    }

    std::sort(CutieScrisori, CutieScrisori + dim, compareObiectRucsac);

    std::cout << "Solutia optima este: " << std::endl;

    for (int index = 0; index < dim && G != 0; index++)
    {
        if (CutieScrisori[index]._greutate <= G)
        {
            CutieScrisori[index].afisare();
            G -= CutieScrisori[index]._greutate;
        }
    }
}