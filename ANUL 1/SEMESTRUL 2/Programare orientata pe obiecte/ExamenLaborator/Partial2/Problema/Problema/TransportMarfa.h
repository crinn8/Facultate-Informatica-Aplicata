#pragma once
#include "Vehicul.h"

class TransportMarfa : virtual public Vehicul
{
protected:
	int kgMarfa;
public:
	TransportMarfa(string tipVehicul = "\0", int kgMarfa = -1) : Vehicul(tipVehicul)
	{
		this->tipVehicul = tipVehicul;
		this->kgMarfa = kgMarfa;
	}
	int GetCantitateMarfa()
	{
		return kgMarfa;
	}
	string GetTipVehicul()
	{
		return tipVehicul;
	}
};