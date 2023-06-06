#pragma once
#include "Dreptunghi.h"
#include "Romb.h"
#include "Paralelogram.h"

class  PATRAT :public DREPTUNGHI, public ROMB
{
public:
	PATRAT(std::vector <std::pair<float, float>> puncte, float l) : DREPTUNGHI(puncte, l, l), ROMB(puncte,alpha,l), PARALELOGRAM(puncte, alpha, l, l)
	{
		nume = "Patrat";
		this->alpha = 90;
		this->l.first = l;
		this->l.second = l;
	}
	virtual float Perimetru()
	{
		return DREPTUNGHI::Perimetru();
	}
	virtual float Arie()
	{
		return DREPTUNGHI::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};