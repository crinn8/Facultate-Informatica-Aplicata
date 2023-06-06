#pragma once
#include "Mamifer.h"
#include "MamiferTerestru.h"
#include "MamiferAcvatic.h"
using namespace std;

class Foca : public MamiferTerestru, public MamiferAcvatic, virtual public Mamifer
{
public:
	Foca(string mediu_de_viata = "\0") :MamiferTerestru("foca", mediu_de_viata, 2), MamiferAcvatic("foca", mediu_de_viata, "bb"), Mamifer("foca",mediu_de_viata)
	{
		this->mediu_de_viata = mediu_de_viata;
	}
	string GetMediuDeViata()
	{
		return mediu_de_viata;
	}
};