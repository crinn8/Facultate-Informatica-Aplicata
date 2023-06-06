#include <iostream>
#include <fstream>
#include <algorithm>

struct Strada {
    int x, y;
};

void ZerorizareMatrice(int n, int oras[100][100])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            oras[i][j] = 0;
        }
    }
}

void CitireFisier(int& nr_intersectii, int oras[100][100], int& k, int &nr_strazi)
{
    std::ifstream f("MagazineDeInghetata.in");
    f >> nr_intersectii >> k;
    ZerorizareMatrice(nr_intersectii, oras);
    nr_strazi = nr_intersectii-1;
    for (int i = 1; i <= nr_strazi; i++)
    {
        int x, y, z;
        f >> x >> y >> z;
        oras[x][y] = z;
        oras[y][x] = z;
    }
}

void Drumuri()
{
    int a[100];
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] == 0)
                    a[i][j] = a[i][k] * a[k][j];
}

void zerorizare(int nr_intersectii, Strada strazi[100])
{
    for (int i = 1; i <= nr_intersectii; i++)
    {
        strazi[i].x = 0;
        strazi[i].y = i;
    }
}

void ConstruireVectorStrazi(int nr_intersectii, int oras[100][100], Strada strazi[100])
{
    zerorizare(nr_intersectii, strazi);
    for (int i = 1; i <= nr_intersectii; i++)
    {
        for (int j = 1; j <= nr_intersectii; j++)
        {
            strazi[i].x += oras[i][j];
        }
    }
}

void AfisareVector(int nr_locatii, int locatii[100])
{
    std::cout << "Locatiile in care pot fi amplasate magazinele de inghetata sunt numerotate cu: ";
    for (int i = 1; i <= nr_locatii; i++)
    {
        std::cout << locatii[i] << " ";
    }
}

bool comparator(Strada s1, Strada s2)
{
    return s1.x > s2.x;
}

void MagazineDeInghetata(int nr_intersectii, Strada strazi[100], int k, int oras[100][100])
{
    std::sort(strazi + 1, strazi + 1 + nr_intersectii, comparator);
    int locatii[100], nr_locatii = 1;
    locatii[1] = strazi[1].y;
    k--;
   
    for (int i = 2; i <= nr_intersectii && k != 0; i++)
    {
        if (oras[strazi[i].y][locatii[nr_locatii]] != 0)
        {
            nr_locatii++;
            locatii[nr_locatii] = strazi[i].y;
            k--;
        }
    }
    AfisareVector(nr_locatii, locatii);
}

int main()
{
    Strada strazi[100];
    int nr_intersectii, oras[100][100], k, nr_strazi;
    CitireFisier(nr_intersectii, oras, k, nr_strazi);
    for (int i = 1; i <= nr_intersectii; i++)
    {
        for (int j = 1; j <= nr_intersectii; j++)
            std::cout << oras[i][j]<<" ";
        std::cout << std::endl;
    }
    ConstruireVectorStrazi(nr_intersectii, oras, strazi);
    for (int i = 1; i < nr_strazi; i++)
        std::cout << strazi[i].x << std::endl;
    MagazineDeInghetata(nr_intersectii, strazi, k, oras);
}