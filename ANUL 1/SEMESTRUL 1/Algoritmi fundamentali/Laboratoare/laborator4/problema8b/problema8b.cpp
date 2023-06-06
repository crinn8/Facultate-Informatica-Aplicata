// primapb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void CitireVectorDinFisier(int& dim, int v[100])
{
    ifstream f("date.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
        f >> v[i];
}

int CautareBinara(int dim, int v[100], int element)
{
    int st = 0, dr = dim - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == element)
            return mij;
        else
            if (v[mij] < element)
                st = mij + 1;
            else dr = mij - 1;
    }
    return -1;
}

int CautareSecv(int dim, int v[100], int element)
{
    for (int i = 0; i < dim; i++)
        if (v[i] == element) return i;
    return -1;
}

void Stergere(int& dim, int v[100], int element)
{
    int poz = CautareBinara(dim, v, element);
    if (poz != -1)
    {
        for (int i = poz; i < dim - 1; i++)
            v[i] = v[i + 1];
        dim--;
    }
}

void InserareElement(int& dim, int v[100], int element)
{
    int poz = 0;
    for (int i = dim - 1; i >= 0 && poz == 0; i--)
    {
        if (v[i] < element)
            poz = i + 1;
    }
    dim++;
    for (int i = dim - 1; i > poz; i--)
    {
        v[i] = v[i - 1];
    }
    v[poz] = element;
}

void ScriereInFisier(int dim, int v[100])
{
    ofstream g("date.out");
    for (int i = 0; i < dim; i++)
        g << v[i] << " ";
}

int main()
{
    int dim, v[100], element;
    CitireVectorDinFisier(dim, v);
    cin >> element;
    Stergere(dim, v, element);
    ScriereInFisier(dim, v);
    cin >> element;
    cout << CautareSecv(dim, v, element)<<endl;
    cin >> element;
    InserareElement(dim, v, element);
    ScriereInFisier(dim, v);
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
