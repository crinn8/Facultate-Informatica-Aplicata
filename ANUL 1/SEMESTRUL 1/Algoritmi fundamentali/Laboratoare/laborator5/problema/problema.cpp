// problema.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void CitireVectorDinFisier(int &dim, int v[100])
{
    ofstream g("vector.out");
    for (int i = 0; i < dim; i++)
        g<< v[i]<<" ";
}

void ScriereVectorInFisier(int& dim, int v[100])
{
    ifstream f("vector.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
        f >> v[i];
}

void quickSort(int v[100], int st, int dr)
{
    int i, j;
    i = st;
    j = dr;
    int piv = v[(st + dr) / 2];
    while (i <= j)
    {
        while (v[i] < piv)
            i++;
        while (v[j] > piv)
            j--;
        if (i <= j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if (st < j)
        quickSort(v, st, j);
    if (i < dr)
        quickSort(v, i, dr);
}

int main()
{
    int dim, v[100];
    CitireVectorDinFisier(dim, v);
    quickSort(v, 0, dim - 1);
    ScriereVectorInFisier(dim, v);
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
