// problema1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int VerificareNrPrim(int x, int d)
{
	if (x == 0 || x == 1) return 1;
	if (d >= x / 2) return 0;
	if (x % d == 0) return 1;
	return VerificareNrPrim(x, d + 1);
}

int CeaMaiMicaCifra(int x)
{
	int mini = 9;
	while (x)
	{
		if (x % 10 < mini)
		{
			mini = x % 10;
		}
		x = x / 10;
	}
	return mini;
}

void CitireVector(int lungime, vector<int>& vector)
{
	int element;
	for (int i = 0; i < lungime; i++)
	{
		cin >> element;
		vector.push_back(element);
	}
}

void calcul(vector<int>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i % 2 == 0)
		{
			vector[i] = CeaMaiMicaCifra(vector[i]);
		}
		else
		{
			vector[i] = VerificareNrPrim(vector[i], 2);
		}
	}
}

void AfisareVector(int n, vector<int>vector)
{
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";
}
int main()
{
	int n;
	cin >> n;
	vector<int>vector;
	CitireVector(n, vector);
	calcul(vector);
	AfisareVector(n, vector);
	//system("pause");
	return 0;
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
