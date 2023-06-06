#include <iostream>
using namespace std;

struct complex {
	double re, im;
};

complex adunare(complex z1, complex z2)
{
	complex s;
	s.re = z1.re + z2.re;
	s.im = z1.im + z2.im;
	return s;
}

complex operator+(complex z1, complex z2)
{
	complex s;
	s.re = z1.re + z2.re;
	s.im = z1.im + z2.im;
	return s;
}

complex operator+(complex z, double r)
{
	complex s;
	s.re = z.re + r;
	s.im = z.im;
	return s;
}

istream& operator>>(istream& fl, complex& z)
{
	fl >> z.re >> z.im;
	return fl;
}

complex operator<<(complex& z,double r)
{
	z.re = r;
	z.im = 0;
	return z;
}

ostream& operator<<(ostream& fl, complex z)
{
	fl << z.re << "," << z.im;
	return fl;
}

int operator!(complex z)
{
	return z.re * z.re + z.im * z.im;
}

int operator<(complex z1, complex z2)
{
	return !z1 < !z2;
}

int operator==(complex z1, complex z2)
{
	return z1.re == z2.re && z1.im == z2.im;
}

int main()
{
	complex z1, z2, s;
	z1.re = 1;
	z1.im = 2;
	z2.re = 3;
	z2.im = 4;
	if (z1 == z2)
		cout << "egale" << endl;
	else cout << "diferite" << endl;
	if (z1 < z2) //operator<(z1,z2)
		s = z1;
	else s = z2;
	cout << endl;
	//s = adunare(z1, z2);
	//s = operator+(z1, z2);
	s = z1 + z2;
	s = z1 + 2; 
	//cout << s.re << " " << s.im << endl;
	cin >> z1>>z2;
	cout << !z1 <<" "<< !z2 << endl;
	cout << z1.re << " " << z1.im << endl;
	cout << z1 << endl << z2 << endl;
	z1 << 10;
	cout << z1 << endl;
}

