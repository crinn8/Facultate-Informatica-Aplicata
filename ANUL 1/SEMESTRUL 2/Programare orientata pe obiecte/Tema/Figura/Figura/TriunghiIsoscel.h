#pragma once
#include "Triunghi.h"

class TRIUNGHIISOSCEL :public TRIUNGHI
{
public:
	TRIUNGHIISOSCEL(std::vector <std::pair<float, float>> puncte,float inaltime) : TRIUNGHI(puncte,inaltime)
	{
		nume = "Triunghi isoscel";
		for (int i = 0; i < 3; i++)
		{
			this->puncte.push_back(puncte[i]);
		}
		this->inaltime = inaltime;
	}

	virtual float Perimetru()
	{
		return TRIUNGHI::Perimetru();
	}
	virtual float Arie()
	{
		return TRIUNGHI::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};