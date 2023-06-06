#pragma once
#include <iostream>
using namespace std;

class Mamifer
{
protected:
	string nume;
	string mediu_de_viata;
public:
	Mamifer(string nume = "\0", string mediu_de_viata = "\0")
	{
		this->nume = nume;
		this->mediu_de_viata = mediu_de_viata;
	}
	string GetNume()
	{
		return nume;
	}
	virtual string GetMediuDeViata() = 0;
};