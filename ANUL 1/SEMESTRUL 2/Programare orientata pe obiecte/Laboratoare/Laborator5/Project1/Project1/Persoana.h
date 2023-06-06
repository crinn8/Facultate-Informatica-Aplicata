#pragma once
#include <iostream>
class Persoana
{
	char nume[100];
	long long int cnp;
public:
	Persoana(char* nume = nullptr, long long int cnp = -1);
	char* GetNume();
	long long int GetCNP();
	virtual void Afisare();
	virtual void AfisareVirtuala() = 0;
};