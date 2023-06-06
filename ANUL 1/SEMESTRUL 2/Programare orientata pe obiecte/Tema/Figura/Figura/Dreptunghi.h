#pragma once
#include "Paralelogram.h"

class  DREPTUNGHI :virtual public PARALELOGRAM
{
public:
	DREPTUNGHI(std::vector <std::pair<float, float>> puncte, float lx, float ly) : PARALELOGRAM(puncte,alpha,l.first,l.second)
	{
		nume = "Dreptunghi";
		this->puncte.push_back(puncte[0]);
		this->alpha = 90;
		l.first = lx;
		l.second = ly;
	}

	virtual float Perimetru()
	{
		return PARALELOGRAM::Perimetru();
	}
	virtual float Arie()
	{
		return PARALELOGRAM::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};