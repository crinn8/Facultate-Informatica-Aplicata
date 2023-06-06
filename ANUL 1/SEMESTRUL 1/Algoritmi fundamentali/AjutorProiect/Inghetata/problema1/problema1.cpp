#include <iostream>
#include <fstream>
#include <algorithm>

void CitireFisier(int& nr_intersectii, int matrice[100][100],int &k)
{
    std::ifstream f("inghetata.in");
    f >> nr_intersectii>>k;
    for (int i = 0; i < nr_intersectii; i++)
    {
        int x, y,z;
        f >> x >> y>>z;
        matrice[x][y] = z;
    }
}

void ConstruireVectorStrazi(int nr_intersectii, int oras[100][100], int strazi[100])
{
    strazi[100] = { 0 };
    for (int i = 0; i < nr_intersectii; i++)
        for (int j = 0; j < nr_intersectii; j++)
        {
            strazi[i] += oras[i][j];
        }
}

void AfisareVector(int nr_locatii, int locatii[100])
{
    std::cout << "Locatiile in care pot fi amplasate magazinele de inghetata sunt numerotate cu: ";
    for (int i = 0; i < nr_locatii; i++)
    {
        std::cout << locatii[i] << " ";
    }
}

bool comparator(int x, int y)
{
    if (x >= y) return true;
    return false;
}

void MagazineDeInghetata(int nr_intersectii, int strazi[100], int k, int oras[100][100])
{
    int magazine[100];
    ConstruireVectorStrazi(nr_intersectii, oras, strazi);
    std::sort(strazi, strazi + nr_intersectii, comparator);
    int locatii[100],nr_locatii=1;
    locatii[0] = strazi[0];

    for (int i = 1; i < nr_intersectii&&k!=0; i++)
    {
        if (oras[i][locatii[nr_locatii]] != 0)
        {
            locatii[nr_locatii] = i;
            nr_locatii++;
        }
    }
    AfisareVector(nr_locatii, locatii);
}

int main()
{
    int nr_intersectii, oras[100][100],k,strazi[100];
    CitireFisier(nr_intersectii, oras,k);
    MagazineDeInghetata(nr_intersectii, strazi, k, oras);
}