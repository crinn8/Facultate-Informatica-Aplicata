#pragma once

#include <iostream>

struct Scrisoare {
	int _greutate, _beneficiu;

	void citire();
	void afisare();

	double eficienta();
};