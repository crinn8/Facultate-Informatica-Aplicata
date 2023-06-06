#pragma once
#include "TransportMarfa.h"
#include "TransportPersoane.h"
#include "Vehicul.h"

class Tren : public TransportMarfa, public TransportPersoane
{
protected:
	string tipLocomotiva;
public:
	Tren(string tipVehicul = "\0", int kgMarfa = -1, int nrMaximPersoane = -1, string tipLocomotiva = "\0") : TransportMarfa("Tren", kgMarfa), TransportPersoane("Tren",nrMaximPersoane)
	{

		this->kgMarfa = kgMarfa;
	}
	string GetTipVehicul()
	{
		return tipVehicul;
	}
};