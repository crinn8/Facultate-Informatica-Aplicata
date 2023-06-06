#pragma once
#include "Mamifer.h"
using namespace std;

class MamiferAcvatic : virtual public Mamifer
{
protected:
	string sunet;
public:
	MamiferAcvatic(string nume = "\0", string mediu_de_viata="\0", string sunet = "\0") :Mamifer(nume, mediu_de_viata)
	{
		this->sunet = sunet;
	}
	string GetSunet()
	{
		return sunet;
	}
	string GetMediuDeViata()
	{
		return mediu_de_viata;
	}
};