#pragma once
#include "Figura.h"
#include "Poligon.h"

class TRIUNGHI :virtual public POLIGON
{
public:
	float inaltime;
	TRIUNGHI(std::vector <std::pair<float, float>> puncte,float inaltime) :POLIGON(puncte)
	{
		nume = "Triunghi";
		for (int i = 0; i < 3; i++)
		{
			this->puncte.push_back(puncte[i]);
		}
		this->inaltime = inaltime;
	}

	virtual float Perimetru()
	{
		float x, y;
		x = puncte[0].first - puncte[1].first;
		y = puncte[0].second - puncte[1].second;
		float l1;
		l1 = sqrt(x * x + y * y);
		x = puncte[1].first - puncte[2].first;
		y = puncte[1].second - puncte[2].second;
		float l2;
		l2 = sqrt(x * x + y * y);
		x = puncte[0].first - puncte[2].first;
		y = puncte[0].second - puncte[2].second;
		float l3;
		l3 = sqrt(x * x + y * y);
		return (l1 + l2 + l3);
	}
	virtual float Arie()
	{
		float l,x,y;
		x = puncte[0].first - puncte[2].first;
		y = puncte[0].second - puncte[2].second;
		l = sqrt(x * x + y * y);
		return (l*inaltime)/2;
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};