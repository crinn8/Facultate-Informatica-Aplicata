//Complexitate O(n)

#include <iostream>
#include <fstream>
#include <iomanip>

void CitireVector(int& n, int*& V)
{
    std::ifstream f("numere.in");
    f >> n;
    V = new int[n]();
    for (int i = 0; i < n; i++)
    {
        f >> V[i];
    }
    f.close();
}

double MediaCifrelorUnuiNumar(int x)
{
    double suma_cif = 0, nr_cif = 0;
    while (x)
    {
        suma_cif += x % 10;
        nr_cif++;
        x /= 10;
    }
    return suma_cif / nr_cif;
}

void ConstruireVectorW(int n, int* V, double* W)
{
    for (int i = 0; i < n; i++)
    {
        W[i] = MediaCifrelorUnuiNumar(V[i]);
    }
}

void AfisareVector(int n, double* W)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << W[i] << " ";
    }
}

int main()
{
    int n=0, * V=nullptr;
    double* W;
    CitireVector(n, V);
    W = new double[n]();
    ConstruireVectorW(n, V, W);
    AfisareVector(n, W);

}

