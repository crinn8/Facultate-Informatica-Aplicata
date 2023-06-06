#pragma once
#include "Mamifer.h"
using namespace std;

class MamiferTerestru : virtual public Mamifer
{
protected:
	int nr_picioare;
public:
	MamiferTerestru(string nume = "\0", string mediu_de_viata = "\0", int nr_picioare=-1) :Mamifer(nume, mediu_de_viata)
	{
		this->nr_picioare = nr_picioare;
	}
	int GetNrPicioare()
	{
		return nr_picioare;;
	}
	string GetMediuDeViata()
	{
		return mediu_de_viata;
	}
};