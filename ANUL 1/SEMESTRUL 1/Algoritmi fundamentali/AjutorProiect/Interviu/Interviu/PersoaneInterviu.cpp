#include <iostream>
#include "PersoaneInterviu.h"

void PersoaneInterviu::citire()
{
    std::cin >> _munca >> _salariul_dorit;
}
void PersoaneInterviu::afisare()
{
    std::cout << "(" << _munca << "," << _salariul_dorit << ")" << std::endl;
}
double PersoaneInterviu::eficienta()
{
    return (double)_munca/ _salariul_dorit;
}