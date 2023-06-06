// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

void ConstruireMatrice(int n, int matrice[100][100])
{
    int m = sqrt(n);
    int k = 0;
    while (k < m-1)
    {
        for (int i = k; i < m - 1; i++)
            cin >> matrice[i][k];
        for (int i = k; i < m - 1; i++)
            cin >> matrice[m - 1][i];
        for (int i = m - 1; i > k; i--)
            cin >> matrice[i][m - 1];
        for (int i = m - 1; i > k; i--)
            cin >> matrice[k][i];
        k++;
        m--;
    }
    if (m-1 == k)
        cin>> matrice[m-1][m-1];
}

void AfisareMatrice(int n, int matrice[100][100])
{
    cout << endl;
    for (int i = 0; i < sqrt(n); i++)
    {
        for (int j = 0; j < sqrt(n); j++)
            cout << matrice[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n, a[100][100];
    cout << "Introduceti numarul de elemente: ";
    cin >> n;
    cout << endl;
    ConstruireMatrice(n, a);
    AfisareMatrice(n, a);
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
