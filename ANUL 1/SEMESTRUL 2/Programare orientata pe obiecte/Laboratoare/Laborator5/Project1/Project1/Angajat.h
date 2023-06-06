#pragma once
#include "Persoana.h"

class Angajat : virtual public Persoana
{
	float salariu;
public:
	Angajat(char* nume = nullptr, long long int cnp = -1, float salariu=-1);
	float GetSalariu();
	void Afisare();
	void AfisareVirtuala();
};