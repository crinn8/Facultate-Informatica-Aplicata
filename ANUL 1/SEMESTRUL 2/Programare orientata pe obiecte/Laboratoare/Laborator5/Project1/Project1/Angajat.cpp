#include "Angajat.h"

Angajat::Angajat(char* nume, long long int cnp, float salariu):Persoana(nume,cnp)
{
	this->salariu = salariu;
}

float Angajat::GetSalariu()
{
	return salariu;
}

void Angajat::Afisare()
{
	std::cout << GetNume() << "," << GetCNP() << ":" << salariu << "lei" << std::endl;
}

void Angajat::AfisareVirtuala()
{
	std::cout << "Afisare virtuala angajat" << std::endl;
}
