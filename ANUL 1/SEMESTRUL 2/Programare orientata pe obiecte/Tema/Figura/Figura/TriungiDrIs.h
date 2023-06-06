#pragma once
#include "Triunghi.h"
#include "TriunghiDreptunghic.h"
#include "TriunghiIsoscel.h"
#include "Figura.h"

class TRIUNGHIDRIS :virtual public TRIUNGHIISOSCEL, virtual public TRIUNGHIDREPTUNGHIC, virtual public FIGURA
{
public:
	TRIUNGHIDRIS(std::vector <std::pair<float, float>> puncte, float inaltime) : TRIUNGHIISOSCEL(puncte, inaltime), TRIUNGHIDREPTUNGHIC(puncte, inaltime),FIGURA()
	{
		nume = "Triunghi dreptunghic isoscel";
		for (int i = 0; i < 3; i++)
		{
			this->puncte.push_back(puncte[i]);
		}
		this->inaltime = inaltime;
	}

	virtual float Perimetru()
	{
		return TRIUNGHIISOSCEL::Perimetru();
	}
	virtual float Arie()
	{
		return TRIUNGHIISOSCEL::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};