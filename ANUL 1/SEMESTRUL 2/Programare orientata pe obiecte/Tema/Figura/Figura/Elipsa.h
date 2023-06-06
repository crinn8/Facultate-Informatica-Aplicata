#pragma once
#include "Figura.h"

class ELIPSA :public FIGURA
{
protected:
	float R1, R2;
public:
	ELIPSA(float R1, float R2)
	{
		nume = "Elipsa";
		this->R1 = R1;
		this->R2 = R2;
	}
	virtual float Perimetru()
	{
		return 3.14 * (R1 + R2);
	}
	virtual float Arie()
	{
		return 3.14 * R1 * R2;
	}
	virtual void Afisare()
	{
		return FIGURA::Afisare();
	}
};
