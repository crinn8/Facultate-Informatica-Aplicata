#pragma once
#include "TransportPersoane.h"

class Autoturism : public TransportPersoane
{
protected:
	string marca;
public:
	Autoturism(string marca = "\0", string tipVehicul = "\0", int nrMaximPersoane = -1) : TransportPersoane("Autoturism", nrMaximPersoane)
	{
		this->marca = marca;
		this->nrMaximPersoane = nrMaximPersoane;
	}
	string GetTipVehicul()
	{
		return tipVehicul;
	}
	string GetMarca()
	{
		return marca;
	}
};