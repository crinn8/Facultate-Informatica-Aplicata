#include "Polinom.h"

int main()
{
	int n;
	cin >> n;
	Polinom* arrayP = new Polinom[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arrayP[i];
	}

	Polinom p;
	for (int i = 0; i < n; i++)
	{
		p = p + arrayP[i];
	}
	cout << p;

	delete[] arrayP;

	/*Polinom p1, p2,p3;
	cout << "Introduceti gradul si coeficientii primului polinom: " << std::endl;
	cin >> p1;
	cout << "Introduceti gradul si coeficientii celui de-al doilea polinom: " << std::endl;
	cin >> p2;
	p3= p1 * p2;
	cout << p3;*/
	return 0;
}