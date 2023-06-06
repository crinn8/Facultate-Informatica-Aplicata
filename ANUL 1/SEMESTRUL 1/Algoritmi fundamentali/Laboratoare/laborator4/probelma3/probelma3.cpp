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

bool VerficareMonotonie(int dim,int v[100])
{
    bool verificare = 1;
    for (int i = 0; i < dim; i++)
    {
        if (v[i] >v[i + 1])
        {
            verificare = 0;
            return verificare;
        }
    }
    return verificare;
}

void stergere(int& dim, int v[100], int poz)
{
   
     for (int i = poz; i < dim - 1; i++)
            v[i] = v[i + 1];
       dim--;

}
int stricaOrdinea(int dim, int v[100])
{
    int pozElem;
    int nrEl = 0;
    for (int i = 0; i < dim - 1 && nrEl < 2; i++)
        if ((v[i] > v[i - 1] && v[i] > v[i + 1])||)
        {
            pozElem = i;
            nrEl++;
        }
    if (nrEl == 1)
        return pozElem;
    return -1;
}

void ScriereInFisier(int dim, int v[100])
{
    ofstream g("date.out");
    for (int i = 0; i < dim; i++)
        g << v[i] << " ";
}

int main()
{
    int dim, v[100],poz;
    CitireVectorDinFisier(dim, v);
    cout << VerficareMonotonie(dim, v) << endl;
    if (!VerficareMonotonie(dim, v))
        poz = stricaOrdinea(dim, v);
    if (poz != -1)
        stergere(dim,v, poz);
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
