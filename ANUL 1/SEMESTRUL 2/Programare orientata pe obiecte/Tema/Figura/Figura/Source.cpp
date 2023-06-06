#include <iostream>
#include "Figura.h"
#include "Elipsa.h"
#include "Cerc.h"
#include "Poligon.h"
#include "Patrulater.h"
#include "Paralelogram.h"
#include "Dreptunghi.h"
#include "Romb.h"
#include "Patrat.h"
#include "Trapez.h"
#include "TrapezIsoscel.h"
#include "Triunghi.h"
#include "TriunghiIsoscel.h"
#include "TriungiDrIs.h"

int main()
{
	std::vector <std::pair<float, float>> a;
	std::pair<float, float>b;
	b.first = 8;
	b.second = 7;
	a.push_back(b);
	b.first = 4;
	b.second = 5;
	a.push_back(b);
	b.first = 4;
	b.second = 4;
	a.push_back(b);
	TRIUNGHIDRIS e(a,4);
	e.Afisare();
	return 0;
}