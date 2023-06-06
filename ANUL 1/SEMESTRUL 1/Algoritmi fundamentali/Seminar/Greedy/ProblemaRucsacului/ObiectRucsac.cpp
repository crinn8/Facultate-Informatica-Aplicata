#include <iostream>
#include "ObiectRucsac.h"

void ObiectRucsac::citire()
{
    std::cin >> _greutate >> _beneficiu;
}
void ObiectRucsac::afisare()
{
    std::cout << "(" << _greutate << "," << _beneficiu << ")" << std::endl;
}
double ObiectRucsac::eficienta()
{
    return (double)_beneficiu / _greutate;
}
