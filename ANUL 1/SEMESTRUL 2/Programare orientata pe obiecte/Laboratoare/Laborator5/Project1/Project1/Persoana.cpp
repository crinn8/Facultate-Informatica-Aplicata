#include "Persoana.h"

Persoana::Persoana(char* nume, long long int cnp)
{
	if (nume != nullptr)
	{
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	this->cnp = cnp;
}

char* Persoana::GetNume()
{
	return nume;
}

long long int Persoana::GetCNP()
{
	return cnp;
}

void Persoana::Afisare()
{
	std::cout << nume << "," << cnp;
}

