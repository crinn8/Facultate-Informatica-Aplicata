#pragma once
#include "Figura.h"
#include "Patrulater.h"

class  PARALELOGRAM:public PATRULATER
{
public:
	float alpha;
	std::pair<float, float> l;
	PARALELOGRAM(std::vector <std::pair<float, float>> puncte,float alpha,float lx, float ly) :PATRULATER(puncte)
	{
		nume = "Paralelogram";
		this->puncte.push_back(puncte[0]);
		this->alpha = alpha;
		l.first = lx;
		l.second = ly;
	}

	virtual float Perimetru()
	{
		return 2 * (l.first + l.second);
	}
	virtual float Arie()
	{
		return l.first * l.second * sin(alpha*3.14/180);
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};