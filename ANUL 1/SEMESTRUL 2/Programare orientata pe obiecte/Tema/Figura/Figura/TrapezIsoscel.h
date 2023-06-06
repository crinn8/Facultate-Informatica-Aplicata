#pragma once
#include "Trapez.h"

class TRAPEZISOSCEL:public TRAPEZ
{
public:
	TRAPEZISOSCEL(std::vector <std::pair<float, float>> puncte, float Baza_mare, float Baza_mica, float inaltime) : TRAPEZ(puncte, Baza_mica, Baza_mare, inaltime)
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
		return TRAPEZ::Perimetru();
	}
	virtual float Arie()
	{
		return TRAPEZ::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};