#pragma once
#include "Figura.h"
#include "Elipsa.h"

class CERC :public ELIPSA
{
protected:
	float raza;
public:
	CERC(float r=0):ELIPSA(r, r)
	{
		nume = "Cerc";
		this->raza = r;
	}
	virtual float Perimetru()
	{
		return ELIPSA::Perimetru();
	}
	virtual float Arie()
	{
		return ELIPSA::Arie();
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};