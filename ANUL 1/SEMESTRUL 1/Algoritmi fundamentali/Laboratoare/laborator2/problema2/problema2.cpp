// problema2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


void CitireVector(int lungime, vector<int>& vector)
{
	int element;
	for (int i = 0; i < lungime; i++)
	{
		cin >> element;
		vector.push_back(element);
	}
}

void stergere(int pozitie, int n, vector<int>& vector)
{
	for (int i = pozitie; i < n - 1; i++)
	{
		vector[i] = vector[i + 1];
	}
}

void calcul(int& n, vector<int>& vector)
{
	for (int i = 1; i < n - 1; i++)
		if (vector[i] == vector[i - 1] + vector[i + 1])
		{
			stergere(i, n, vector);
			n--;
		}
}

void AfisareVector(int n, vector<int>vector)
{
	for (int i = 0; i < n; i++)
		cout << vector[i] << " ";
}
int main()
{
	int n;
	cin >> n;
	vector<int>vector;
	CitireVector(n, vector);
	calcul(n, vector);
	AfisareVector(n, vector);
	system("pause");
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
