#include "Polinom.h"

Polinom::Polinom(int r)
{
	rank = r;
	coeficienti = new double[r + 1];
	for (int i = 0; i <= r; i++)
	{
		cin >> coeficienti[i];
	}
}

Polinom::Polinom(int rank, double* coef)
{
	this->rank = rank;
	coeficienti = new double[rank + 1];
	/*for (int i = 0; i <= rank; i++)
	{
		this->coeficienti[i]=coef[i];
	}*/

	memcpy(coeficienti,coef,(rank+1)*sizeof(double));
}

Polinom::Polinom(const Polinom& p)
{
	rank = p.rank;
	coeficienti = new double[p.rank + 1];
	for (int i = 0; i <= p.rank; i++)
	{
		coeficienti[i] = p.coeficienti[i];
	}
}

Polinom Polinom::operator+(const Polinom& p)
{
	Polinom p1;
	if (rank < p.rank)
	{
		p1.rank = p.rank;
		p1.coeficienti = new double[p.rank + 1];
		for (int i = 0; i <= rank; i++)
		{
			p1.coeficienti[i] = coeficienti[i] + p.coeficienti[i];
		}
		for (int i = rank+1; i <= p.rank; i++)
		{
			p1.coeficienti[i] =  p.coeficienti[i];
		}
	}
	else
	{
		p1.rank = rank;
		p1.coeficienti = new double[rank + 1];
		for (int i = 0; i <= p.rank; i++)
		{
			p1.coeficienti[i] = coeficienti[i] + p.coeficienti[i];
		}
		for (int i = p.rank + 1; i <= rank; i++)
		{
			p1.coeficienti[i] = coeficienti[i];
		}
	}
	return p1;
}

Polinom Polinom::operator*(const Polinom& p)
{
	Polinom p_produs;
	p_produs.rank = rank+p.rank;
	p_produs.coeficienti = new double[p_produs.rank+1]();
	for (int i = 0; i <= rank; i++)
	{
		for (int j = 0; j <= p.rank; j++)
		{
			p_produs.coeficienti[i + j] += coeficienti[i] * p.coeficienti[j];
		}
	}
	return p_produs;
}

Polinom Polinom::operator*(double d)
{
	for (int i = 0; i <= rank; i++)
	{
		coeficienti[i] *= d;
	}
	return *this;
}

Polinom Polinom::operator=(const Polinom& p)
{
	if (coeficienti)
	{
		delete[] coeficienti;
	}
	rank = p.rank;
	coeficienti = new double[p.rank + 1];
	for (int i = 0; i <= p.rank; i++)
	{
		coeficienti[i] = p.coeficienti[i];
	}
	return *this;
}

Polinom::~Polinom()
{
	if (coeficienti != nullptr)
		delete[] coeficienti;
}

Polinom operator*(double d, const Polinom& p)
{
	Polinom p1;
	p1 = p * d;
	return p1;
}

ostream& operator<<(ostream& fo, const Polinom& p)
{
	fo << p.coeficienti[0];
	for (int i = 1; i <= p.rank; i++)
	{
		fo << "+" << p.coeficienti[i] << "x^" << i;
	}
	return fo;
}

istream& operator>>(istream& fi, Polinom& p)
{
	fi >> p.rank;
	p.coeficienti = new double[p.rank + 1];
	for (int i = 0;i <= p.rank; i++)
	{
		fi >> p.coeficienti[i];
	}
	return fi;
}
