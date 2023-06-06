#include <iostream>
#include <fstream>
#include "Scrisoare.h"

void Scrisoare::citire()
{
    std::cin >> _greutate >> _beneficiu;
}
void Scrisoare::afisare()
{
    std::cout << "(" << _greutate << "," << _beneficiu << ")" << std::endl;
}
double Scrisoare::eficienta()
{
    return (double)_beneficiu / _greutate;
}

