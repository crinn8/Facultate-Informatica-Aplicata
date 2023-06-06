#include "Student.h"

Student::Student(char* nume, long long int cnp, char* facultate, float medie):Persoana(nume,cnp)
{
	this->medie = medie;
	if (facultate != nullptr)
	{
		strcpy_s(this->facultate, strlen(facultate) + 1, facultate);
	}
}

char* Student::GetFacultate()
{
	return facultate;
}

float Student::GetMedie()
{
	return medie;
}

void Student::AfisareVirtuala()
{
	std::cout << "Afisare virtuala din student" << std::endl;
}
void Student::Afisare()
{
	std::cout << GetNume() << "," << GetCNP()<<":"<<facultate<<"-"<<medie<<std::endl;
}
