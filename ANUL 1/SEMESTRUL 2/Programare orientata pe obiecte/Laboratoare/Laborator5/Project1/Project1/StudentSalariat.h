#pragma once
#include "Student.h"
#include "Angajat.h"

class StudentSalariat : public Student, public Angajat
{
public:
	StudentSalariat(char* nume = nullptr, long long int cnp = -1, float salariu, char* faculate = nullptr, float medie = -1);
	void Afisare();
	void AfisareVirt();
};