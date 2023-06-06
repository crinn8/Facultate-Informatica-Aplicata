#pragma once
#ifndef __POLINOM__
#define __POLINOM__

#include <iostream>
using namespace std;

class Polinom
{
private:
	int rank;
	double* coeficienti;

public:
	Polinom()
	{
		rank = -1;
		coeficienti = nullptr;
	}
	Polinom(int r);
	Polinom(int rank, double* coef);
	Polinom(const Polinom& p);
	Polinom operator+(const Polinom& p);
	Polinom operator-(const Polinom& p);
	Polinom operator*(const Polinom& p);
	Polinom operator*(double d);
	Polinom operator=(const Polinom& p);


	friend Polinom operator*(double d,const Polinom& p);
	friend ostream& operator<<(ostream& fo,const Polinom& p);
	friend istream& operator>>(istream& fi, Polinom& p);


	~Polinom();
};

#endif