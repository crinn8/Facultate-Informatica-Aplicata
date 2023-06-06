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

void maximDP(int n, int a[100][100], int &poz)
{
	int mx = 0;
	for (int i = 0; i < n; i++)
		if (a[i][i] > mx)
		{
			mx = a[i][i];
			poz = i;
		}
}

void minimDS(int n, int a[100][100], int &poz)
{
	int mini = 1001;
	for (int i = 0; i < n; i++)
		if (a[i][n - i - 1] < mini)
		{
			mini = a[i][n - 1 - i];
			poz = i;
		}
}

void afisareMatrice(int n, int a[100][100])
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";;
		cout << endl;
	}
}

int main()
{
	int n, a[100][100], pozmx = 0, pozmini = 0;
	cout << "Introduceti numarul de elemente ale matricei: ";
	cin >> n;
	cout << endl;
	citireMatrice(n, a);
	maximDP(n, a, pozmx);
	minimDS(n, a, pozmini);
	swap(a[pozmx][pozmx], a[pozmini][n - 1 - pozmini]);
	afisareMatrice(n, a);
	return 0;
}

