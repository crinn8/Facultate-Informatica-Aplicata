#pragma once
#include "Mamifer.h"
#include "MamiferTerestru.h"
using namespace std;

class Caine :public MamiferTerestru
{
public:
	Caine(string mediu_de_viata = "\0") : MamiferTerestru("caine", mediu_de_viata, 4)
	{
		this->mediu_de_viata = mediu_de_viata;
	}
	string GetMediuDeViata()
	{
		return mediu_de_viata;
	}
};