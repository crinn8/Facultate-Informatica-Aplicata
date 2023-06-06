// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void CitireMatrice(int n, int matrice[100][100])
{
    cout << "Introduceti elementele matricei: " << endl;
    for (int i = 0; i<n; i++)
        for(int j=0;j<n;j++)
          cin >> matrice[i][j];
}

void InterschimbareLinii(int n, int matrice[100][100], int linie1, int linie2)
{
    for (int j = 0; j < n; j++)
    {
        int aux = matrice[linie1][j];
        matrice[linie1][j] = matrice[linie2][j];
        matrice[linie2][j] = aux;
    }
}

void InterschimbareColoane(int n, int matrice[100][100], int col1, int col2)
{
    for (int i = 0; i < n; i++)
    {
        int aux = matrice[i][col1];
        matrice[i][col1] = matrice[i][col2];
        matrice[i][col2] = aux;
    }
}

void PrelucrareMatrice(int n, int matrice[100][100])
{
    for(int i=0;i<n-1;i++)
        for (int j = i + 1; j < n; j++)
        {
            if (matrice[i][i] > matrice[j][j])
            {
                InterschimbareLinii(n, matrice, i, j);
                InterschimbareColoane(n, matrice, i, j);
            }
        }
}

void AfisareMatrice(int n, int matrice[100][100])
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout<<matrice[i][j]<<" ";
        cout << endl;
    }
}

int main()
{
    int n, a[100][100];
    cout << "Introduceti numarul de linii: ";
    cin >> n;
    cout << endl;
    CitireMatrice(n, a);
    PrelucrareMatrice(n, a);
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
