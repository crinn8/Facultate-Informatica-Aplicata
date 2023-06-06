#pragma once
#include "Figura.h"

class POLIGON :public FIGURA
{
public:
	POLIGON(std::vector <std::pair<float, float>> puncte)
	{
		nume = "Poligon";
		for (int i = 0; i < puncte.size(); i++)
		{
			this->puncte.push_back(puncte[i]);
		}
	}

	virtual float Perimetru()
	{
		float perimetru = 0;
		for (int i = 0; i < puncte.size() - 1; i++)
		{
			float dist = 0,x,y;
			x = puncte[i + 1].first - puncte[i].first;
			y = puncte[i + 1].second - puncte[i].second;
			dist = sqrt(x * x + y * y);
			perimetru += dist;
		}
		return perimetru;
	}
	virtual float Arie()
	{
		float arie = 0;
		for (int i = 0; i < puncte.size() - 1; i++)
		{
			arie += (puncte[i].first * puncte[i + 1].second - puncte[i + 1].first * puncte[i].second);
		}
		return abs(arie) / 2;
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};