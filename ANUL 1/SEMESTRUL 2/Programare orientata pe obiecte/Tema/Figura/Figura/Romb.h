#pragma once
#include "Paralelogram.h"

class  ROMB :virtual public PARALELOGRAM
{
public:
	ROMB(std::vector <std::pair<float, float>> puncte, float alpha, float l) : PARALELOGRAM(puncte, alpha, l, l)
	{
		nume = "Romb";
		this->puncte.push_back(puncte[0]);
		this->alpha = alpha;
		this->l.first = l;
		this->l.second = l;
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