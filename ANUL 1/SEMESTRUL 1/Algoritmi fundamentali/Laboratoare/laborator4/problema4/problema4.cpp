// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void CitireVectorDinFisier(int& dim, int v[100])
{
    ifstream f("cautari.txt");
    f >> dim;
    for (int i = 1; i <= dim; i++)
        f >> v[i];
}

int CautareSecv(int dim, int v[100], int element)
{
    for (int i = 1; i <=dim; i++)
        if (v[i] == element) return i;
    return -1;
}

void SortareElemente(int dim, int v[100])
{
    for (int i = 1; i < dim ; i++)
    {
        for (int j = i + 1; j <= dim; j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

void Copie(int dim,int v[100],int c[100])
{
    for (int i = 1; i <= dim; i++)
    {
        c[i] = v[i];
    }
}

void Calcul(int dim, int v[100])
{
    int c[100];
    Copie(dim, v, c);
    SortareElemente(dim, v);
    for (int i = 1; i <= dim; i++)
    {
        cout << CautareSecv(dim, c, v[i])<<" ";
    }
}

int main()
{
    int dim, v[100];
    CitireVectorDinFisier(dim, v);
    Calcul(dim, v);
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
