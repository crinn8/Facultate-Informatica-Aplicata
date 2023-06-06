#pragma once
#include "Vehicul.h"

class TransportPersoane : virtual public Vehicul
{
protected:
	int nrMaximPersoane;
public:
	TransportPersoane(string tipVehicul = "\0", int nrMaximPersoane = -1) : Vehicul(tipVehicul)
	{
		this->tipVehicul = tipVehicul;
		this->nrMaximPersoane = nrMaximPersoane;
	}
	int GetNrMaximPersoane()
	{
		return nrMaximPersoane;
	}
	string GetTipVehicul()
	{
		return tipVehicul;
	}
};