#pragma once
#include "Patrulater.h"

class TRAPEZ :public PATRULATER
{
public:
	float Baza_mica, Baza_mare, inaltime;
	TRAPEZ(std::vector <std::pair<float, float>> puncte, float Baza_mare, float Baza_mica, float inaltime) :PATRULATER(puncte)
	{
		nume = "Trapez";
		this->puncte.push_back(puncte[0]);
		this->puncte.push_back(puncte[1]);
		this->inaltime = inaltime;
		this->Baza_mica = Baza_mica;
		this->Baza_mare = Baza_mare;
	}

	virtual float Perimetru()
	{
		float x,y;
		x = puncte[0].first - puncte[1].first;
		y = puncte[0].second - puncte[1].second;
		float l1;
		l1 = sqrt(x * x + y * y);
		x = (puncte[0].first+Baza_mica) - puncte[1].first;
		y = (puncte[0].second+Baza_mare) - puncte[1].second;
		float l2;
		l2 = sqrt(x * x + y * y);
		return (l1+l2+Baza_mare+Baza_mica);
	}
	virtual float Arie()
	{
		return (Baza_mare + Baza_mica) * inaltime / 2;
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};