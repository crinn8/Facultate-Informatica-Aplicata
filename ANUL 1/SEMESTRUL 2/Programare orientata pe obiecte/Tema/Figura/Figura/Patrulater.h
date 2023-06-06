#pragma once
#include "Figura.h"
#include "Poligon.h"

class PATRULATER :public POLIGON
{
public:
	PATRULATER(std::vector <std::pair<float, float>> puncte):POLIGON(puncte)
	{
		nume = "Patrulater";
		for (int i = 0; i < puncte.size(); i++)
		{
			this->puncte.push_back(puncte[i]);
		}
	}

	virtual float Perimetru()
	{
		return POLIGON::Perimetru();
	}
	virtual float Arie()
	{
		return POLIGON::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};