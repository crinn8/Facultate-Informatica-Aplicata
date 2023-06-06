// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

void zerorizare(int fr[])
{
	for (int i = 0; i < 10; i++)
	{
		fr[i] = 0;
	}
}

void ConstruireVectorFrecventa(int n, int fr[])
{
	float medie;
	for (int i = 0; i < n; i++)
	{
		cin >> medie;
		if (medie == 1)
		{
			fr[1]++;
		}
		else
		{
			int x = floor(medie);
			if (x == medie)
			{
				fr[x - 1]++;
			}
			else fr[x]++;
		}
	}
}

void AfisareStatistica(int fr[])
{
	cout << "Statistica mediilor este urmatoare: " << endl;
	cout << fr[1] << " medii cuprinse in intervalul [1,2]" << endl;
	for (int i =2; i < 10; i++)
	{
		cout << fr[i] << " medii cuprinse in intervalul ("<<i<<","<<i+1<<"]" << endl;
	}
}

int main()
{
	int n,fr[10];
	cout << "Introduceti numarul de medii: ";
	cin >> n;
	cout << endl;
	zerorizare(fr);
	ConstruireVectorFrecventa(n, fr);
	AfisareStatistica(fr);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
