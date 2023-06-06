#include "StudentSalariat.h"

StudentSalariat::StudentSalariat(char* nume, long long int cnp,
	float salariu, char* faculate, float medie):Student(nume,cnp,facultate,medie), Angajat(nume,cnp,salariu)
{

}

void StudentSalariat::Afisare()
{
	Student::Afisare();
	Angajat::Afisare();
}

void StudentSalariat::AfisareVirt()
{
	Student::Afisare();
	Angajat::Afisare();
}

