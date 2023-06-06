// problema5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void CitireMatrice(int n, int matrice[100][100])
{
    cout << "Introduceti elementele matricei: ";
    for (int i = 0; i < n; i++)
        for(int j=0;j<n;j++) 
             cin >> matrice[i][j];
    cout << endl;
}

void RotireMatrice(int n, int a[100][100], int c[100][100])
{
    for (int i = 0; i < n; i++)
        for(int j=0;j<n;j++)
    {
            c[i][j] = a[n - 1 - j][i];
    }
}

void AfisareMatrice(int n, int matrice[100][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrice[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n,a[100][100], c[100][100];
    cout << "Introduceti numarul de linii ale matricei: ";
    cin >> n;
    cout << endl;
    CitireMatrice(n, a);
    RotireMatrice(n, a, c);
    AfisareMatrice(n, c);
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
