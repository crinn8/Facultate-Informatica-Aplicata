// problema3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


void CitireVector(int lungime, vector<int>& vector)
{
	cout << "Introduceti elementele vectorului:";
	int element;
	for (int i = 0; i < lungime; i++)
	{
		cin >> element;
		vector.push_back(element);
	}
	cout << endl;
}

void SumaSiProdusul(int& suma, int& produsul)
{
	int aux = suma;
	suma = suma + produsul;
	produsul = aux * produsul;
}

void inserare(int &n,int pozitie, vector<int>& vector)
{
	int ok = 0;
	vector.push_back(ok);
	n++;
	int suma = vector[pozitie], produsul = vector[pozitie + 1];
	SumaSiProdusul(suma, produsul);
	for (int i = n - 1; i > pozitie + 1; i--)
	{
		vector[i] = vector[i - 1];
	}
	vector[pozitie + 1] = suma;
	vector.push_back(ok);
	n++;
	for (int i = n - 1; i > pozitie + 2; i--)
	{
		vector[i] = vector[i - 1];
	}
	vector[pozitie + 2] = produsul;
}

void calcul(int &n,vector<int>& vector)
{
	for (int i = 0; i < n-1; i=i+3)
	{
		inserare(n,i, vector);
	}

}

void AfisareVector(int n,vector<int>vector)
{
	for (int i = 0; i <n; i++)
		cout << vector[i] << " ";
}
int main()
{
	int n;
	cout << "Introduceti numarul de elemente ale vectorului: ";
	cin >> n;
	cout << endl;
	vector<int>vector;
	CitireVector(n, vector);
	calcul(n,vector);
	AfisareVector(n,vector);
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

