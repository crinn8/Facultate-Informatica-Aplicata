#pragma once
#include "TransportMarfa.h"

class Camion : public TransportMarfa
{
protected:
	double cp;
public:
	Camion(string tipVehicul = "\0", int kgMarfa = -1, double cp=-1) : TransportMarfa("Camion", kgMarfa)
	{
		this->cp= cp;
		this->kgMarfa = kgMarfa;
	}
	string GetTipVehicul()
	{
		return tipVehicul;
	}
};