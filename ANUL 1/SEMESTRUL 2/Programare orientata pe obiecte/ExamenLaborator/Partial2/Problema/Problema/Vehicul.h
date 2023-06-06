#pragma once
#include <iostream>
using namespace std;

class Vehicul
{
protected:
	string tipVehicul;
public:
	Vehicul(string tipVehicul = "\0")
	{
		this->tipVehicul = tipVehicul;
	}
	virtual string GetTipVehicul() = 0;
};

