#include <iostream>
#include <algorithm>

#include "PersoaneInterviu.h"

bool comparePersoaneInterviu(PersoaneInterviu pers1, PersoaneInterviu pers2)
{
    return (pers1.eficienta() > pers2.eficienta());
}

int main()
{
    PersoaneInterviu sir[900];
    int nr_persoane, nr_angajari, salariul_maxim;
    std::cout << "Introduceti numarul de persoane care participa la interviu: ";
    std::cin >> nr_persoane;
    std::cout << "Introduceti maximul de persoane acceptate: ";
    std::cin >> nr_angajari;
    std::cout << "Introduceti salariul maxim pe care il poate oferi angajatorul unui angajat: ";
    std::cin >> salariul_maxim;
    std::cout << "Introduceti persoanele: " << std::endl;
    for (int index = 0; index < nr_persoane; index++)
    {
        sir[index].citire();
    }

    std::sort(sir, sir + nr_persoane, comparePersoaneInterviu);

    int suma_totala=0;

    std::cout << "Solutia optima este: " << std::endl;

    for (int index = 0; index < nr_persoane && nr_angajari != 0; index++)
    {
        if (sir[index]._salariul_dorit <= salariul_maxim)
        {
            sir[index].afisare();
            nr_angajari--;
            suma_totala += sir[index]._salariul_dorit;
        }
    }

    std::cout << std::endl;

    if (nr_angajari != 0)
    {
        std::cout << "Ups! Nu au fost ocupate toate posturile oferite de angajator deoarece salariul maxim pe care il poate oferi ";
        std::cout<<"acesta nu corespunde cu salariile dorite de participantii la interviu.";
    }

    std::cout << std::endl;
    std::cout <<"Angajatorul trebuie sa plateasca noilor angajati suma de "<< suma_totala<<" euro.";
}