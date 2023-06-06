// problema10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void CitireMatrice(int& n, int mat[100][100])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
}

void zerorizare(int fr[9999])
{
    for (int i = 0; i <= 9999; i++)
        fr[i] = 0;
}

void VectorFrecv(int n, int mat[100][100],int fr[9999])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fr[mat[i][j]]++;
}

int Verificare(int n, int mat[100][100])
{
    int fr[9999];
    zerorizare(fr);
    VectorFrecv(n, mat, fr);
    for (int i = 0; i <= n * n - 1; i++)
    {
        if (fr[i] == 0) return -1;
    }
    return 1;
}

void LocalizareZero(int n,int mat[100][100],int linie,int coloana)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                linie = i;
                coloana = j;
                break;
            }
        }
    }
}

void AfisareMatrice(int n,int mat[100][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void Copie(int n, int mat[100][100],int c[100][100])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = mat[i][j];
}

void ConstruireMatrici(int n, int mat[100][100],int linie,int coloana)
{
    int c[100][100];
    Copie(n, mat, c);
    if (linie != 0)
    {
        swap(c[linie][coloana], c[linie - 1][coloana]);
        AfisareMatrice(n, c);
    }
    Copie(n, mat, c);
    if (linie != n-1)
    {
        swap(c[linie][coloana], c[linie + 1][coloana]);
        AfisareMatrice(n, c);
    }
    Copie(n, mat, c);
    if (coloana != 0)
    {
        swap(c[linie][coloana], c[linie][coloana-1]);
        AfisareMatrice(n, c);
    }
    Copie(n, mat, c);
    if (coloana != n-1)
    {
        swap(c[linie][coloana], c[linie][coloana+1]);
        AfisareMatrice(n, c);
    }
}

int main()
{
    int n, mat[100][100];
    CitireMatrice(n, mat);
    if (Verificare(n, mat) == 1)
    {
        cout << "Matricea respecta conditia ceruta!" << endl;
        int linie = 0, coloana = 0;
        LocalizareZero(n, mat, linie, coloana);
        cout << "Elementul 0 se gaseste la indicii: " << linie << " " << coloana << endl;
        ConstruireMatrici(n, mat, linie, coloana);
    }
    else cout << "Matricea nu respecta conditia ceruta!";
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
