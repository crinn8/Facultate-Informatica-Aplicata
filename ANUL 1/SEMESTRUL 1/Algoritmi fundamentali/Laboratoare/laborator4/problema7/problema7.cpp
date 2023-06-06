// problema7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

void CitireMatrice(int& n, int& m, int mat[100][100])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
}

void SortareElementePrimaColoana(int n, int mat[100][100])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][0] > mat[j][0])
            {
                swap(mat[i][0], mat[j][0]);
            }
        }
    }
}

int CautareBinara(int n, int mat[100][100], int element)
{
    int st = 0, dr = n - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (mat[mij][0] == element)
            return mij;
        else
            if (mat[mij][0] < element)
                st = mij + 1;
            else dr = mij - 1;
    }
    return -1;
}

void Verificare(int n, int mat[100][100])
{
    int nr = 0;
    for (int i = 0; i < 100; i++)
    {
        int x = rand();
        if (CautareBinara(n, mat, x) != -1)
            nr++;
    }
    cout << nr;
}

int main()
{
    int n, m, mat[100][100],nr=0;
    CitireMatrice(n, m, mat);
    SortareElementePrimaColoana(n, mat);
    Verificare(n, mat);
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
