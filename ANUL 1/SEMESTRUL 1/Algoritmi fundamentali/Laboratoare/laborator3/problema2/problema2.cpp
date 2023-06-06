// ConsoleApplication7.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

void citireMatrice(int n, int a[100][100])
{
	cout << "Introduceti elementele matricei: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

int triunghiulDeSus(int n, int a[100][100])
{
	int s = 0;
	for(int i=0;i<= n/2-1;i++)
		for (int j = i + 1; j < n - i - 1; j++)
		{
			s = s + a[i][j];
		}
	return s;
}

int triunghiulDinDreapta(int n, int a[100][100])
{
	int s = 0;
	for (int j = n-1; j >= n / 2 +1 ; j--)
		for (int i = n-j; i <= j - 1; i++)
		{
			s = s + a[i][j];
		}
	return s;
}

int triunghiulDeJos(int n, int a[100][100])
{
	int s = 0;
	for (int i = n/2+1; i <n; i++)
		for (int j = n-i; j <= i-1; j++)
		{
			s = s + a[i][j];
		}
	return s;
}

int triunghiulDinStanga(int n, int a[100][100])
{
	int s = 0;
	for (int j = 0; j <= n / 2 - 1 ; j++)
		for (int i = j+1; i < n-j-1; i++)
		{
			s = s + a[i][j];
		}
	return s;
}

int main()
{
	int n, a[100][100];
	cout << "Introduceti numarul de elemente ale matricei: ";
	cin >> n;
	cout << endl;
	citireMatrice(n, a);
	cout << triunghiulDeSus(n, a) << endl;
	cout << triunghiulDinDreapta(n, a) << endl;
	cout << triunghiulDeJos(n, a) << endl;
	cout << triunghiulDinStanga(n, a);
	return 0;
}

