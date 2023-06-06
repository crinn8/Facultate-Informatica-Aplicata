#pragma once
#include "Persoana.h"

class Student : virtual public Persoana
{
	char facultate[100];
	float medie;
public:
	Student(char* nume = nullptr, long long int cnp = -1, char* faculate = nullptr, float medie = -1);
	char* GetFacultate();
	float GetMedie();
	void Afisare();
	void AfisareVirtuala();
};