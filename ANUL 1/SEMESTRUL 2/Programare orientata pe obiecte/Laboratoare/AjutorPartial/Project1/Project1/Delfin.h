#pragma once
#include "Mamifer.h"
#include "MamiferAcvatic.h"
using namespace std;

class Delfin: public MamiferAcvatic
{
public:
	Delfin(string mediu_de_viata = "\0") :MamiferAcvatic("delfin", mediu_de_viata, "aa")
	{
		this->mediu_de_viata = mediu_de_viata;
	}
	string GetMediuDeViata()
	{
		return mediu_de_viata;
	}
};