#include <iostream>
#include <string>
#include "Vehicul.h"
#include "TransportMarfa.h"
#include "TransportPersoane.h"
#include "Autoturism.h"
#include "Camion.h"
#include "Tren.h"
using namespace std;

int main()
{
	int n;
	cout << "Introduceti numarul de vehicule: ";
	cin >> n;
	Vehicul** v;
	v = new Vehicul * [n];
	srand(unsigned int(time(0)));

	for (int i = 0; i < n; i++)
	{
		string tipVehicul, marca, tipLocomotiva;
		int nrMaximPersoane, kgMarfa;
		double cp;

		int tip = rand() % 3;

		switch (tip)
		{
		case 0:
		{
			cout << "Marca si nr maxim de persoane ale autoturismului " << i << " :" << endl;
			cin >> marca >> nrMaximPersoane;
			v[i] = new Autoturism(marca, tipVehicul, nrMaximPersoane);
			break;
		}
		case 1:
		{
			cout << "Nr maxim de persoane, kg de marfa si tipul locomotivei pentru trenul " << i << " :" << endl;
			cin >> nrMaximPersoane >> kgMarfa >> tipLocomotiva;
			v[i] = new Tren(tipVehicul, kgMarfa, nrMaximPersoane, tipLocomotiva);
			break;
		}
	    case 2:
		{
			cout << "Kg de marfa si cp pentru camionul" << i << endl;
			cin >> kgMarfa >> cp;
			v[i] = new Camion("Camion", kgMarfa, cp);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	int CantitateMarfa = 0;
	for (int i = 0; i < n; i++)
	{
		Autoturism* a = dynamic_cast<Autoturism*>(v[i]);
		if (a != nullptr)
		{
			cout << a->GetMarca() << endl;
		}
		else
		{
			Tren* t = dynamic_cast<Tren*>(v[i]);
			if (t != nullptr)
			{
				CantitateMarfa += t->GetCantitateMarfa();
			}
			else
			{
				Camion* c = dynamic_cast<Camion*>(v[i]);
				if (c != nullptr)
				{
					CantitateMarfa += c->GetCantitateMarfa();
				}
			}
		}
	}



	return 0;
}


