// problema5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

void CitireVectorFisier(int& n, int v[100])
{
    ifstream f("date.in");
    f >> n;
    for (int i = 0; i < n; i++)
        f >> v[i];
}

void CitireVectorTastatura(int& m, int v[100])
{
    cin >>m;
    for (int i = 0; i < m; i++)
        cin >> v[i];
}

int CautareBinara(int n, int v[100], int element)
{
    int st = 0, dr = n - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == element)
            return mij;
        else
            if (v[mij] > element)
                st = mij + 1;
            else dr = mij - 1;
    }
    return -1;
}

void VerificareApartenenta(int n, int m, int v1[100], int v2[100])
{
    ofstream g("date.out");
    g << "Elementele din v2 care apar in v1 si pozitile acestora sunt: " << endl;
    for (int i = 0; i < m; i++)
    {
        int x=CautareBinara(n, v1, v2[i]);
        if (x != -1)
        {
            g << v2[i] << " : " << x << endl;
        }
    }
}

int main()
{
    int n, v1[100], v2[100], m;
    CitireVectorFisier(n, v1);
    CitireVectorTastatura(m, v2);
    VerificareApartenenta(n, m, v1, v2);
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
