#include <iostream>
#include "Multifunctionala.h"

int main()
{
	Multifunctionala m((char*)"canon",100,1500);
	m.GetVitezaImprimare();
	m.GetVitezaScanare();
	m.GetRezolutie();
	m.Imprimanta::GetBrand();



	Imprimanta i;
	Scanner s;

	return 0;
}