//Complexitatea este O(n*logn)
#include <iostream>
#include <fstream>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

std::ifstream f("fractii.txt");
struct fractie {
    int numarator;
    int numitor;

    void citire()
    {
        f >> numarator;
        f >> numitor;
    }

    void afisare()
    {
        std::cout << numarator << "/";
        std::cout << numitor<<" ";
    }

    void reductie()
    {
        int div = cmmdc(numarator, numitor);
        numarator /= div;
        numitor /= div;
    }

    double transformareInNrZecimal()
    {
        double numar_zecimal;
        numar_zecimal = numarator / numitor;
        return numar_zecimal;
    }

    fractie operator+(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numitor + f.numarator * numitor;
        rezultat.numitor = numitor * f.numitor;
        rezultat.reductie();
        return rezultat;
    }

    fractie operator-(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numitor - f.numarator * numitor;
        rezultat.numitor = numitor * f.numitor;
        rezultat.reductie();
        return rezultat;
    }

    fractie operator*(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numarator;
        rezultat.numitor = numitor * f.numitor;
        rezultat.reductie();
        return rezultat;
    }

    fractie operator/(fractie f)
    {
        fractie rezultat;
        std::swap(f.numarator, f.numitor);
        rezultat.numarator = numarator * f.numarator;
        rezultat.numitor = numitor * f.numitor;
        rezultat.reductie();
        return rezultat;
    }

    int operator<(fractie f)
    {
        if (numarator * f.numitor < numitor * f.numarator)
            return 1;
        return 0;
    }

    int operator==(fractie f)
    {
        if (numarator * f.numitor == numitor * f.numarator)
            return 1;
        return 0;
    }

    int operator>(fractie f)
    {
        if (numarator * f.numitor > numitor * f.numarator)
            return 1;
        return 0;
    }
};

void quickSort(fractie *fractii, int st, int dr)
{
    int i = st, j = dr;
    fractie piv = fractii[(st + dr) / 2];
    while (i <= j)
    {
        while (fractii[i] < piv)
            i++;
        while (fractii[j] > piv)
            j--;
        if (i <= j)
        {
            std::swap(fractii[i], fractii[j]); i++; j--;
        }
    }
    if (st < j)
        quickSort(fractii, st, j);
    if (i < dr)
        quickSort(fractii, i, dr);
}

fractie SumaElementelor(fractie *fractii, int n)
{
    fractie suma;
    suma.numarator = fractii[0].numarator;
    suma.numitor = fractii[0].numitor;
    for (int index = 1; index < n; ++index)
    {
        suma = suma+fractii[index];
    }
    return suma;
}

int main()
{
    int n;
    f >> n;
    fractie *fractii;
    fractii = new fractie[n];
    for (int index = 0; index < n; ++index)
    {
        fractii[index].citire();
        if (fractii[index].numitor == 0)
        {
            std::cout << "Numitorul fractiei cu numarul "<<index+1<<" este 0. Introduceti o alta fractie."<<std::endl;
            std::cin >> fractii[index].numarator>> fractii[index].numitor;
        }
    }

    std::cout << "Dupa reducerea fractiilor vectorul este: "<<std::endl;
    for (int index = 0; index < n; ++index)
    {
        fractii[index].reductie();
        fractii[index].afisare();
    }
    std::cout << std::endl;

    std::cout << "Vectorul ordonat crescator este: ";
    int st = 0, dr = n-1;
    quickSort(fractii, st, dr);
    for (int index = 0; index < n; ++index)
    {
        fractii[index].afisare();
    }
    std::cout << std::endl;

    std::cout << "Suma elementelor vectorului este: ";
    fractie suma = SumaElementelor(fractii, n);
    suma.afisare();

    return 0;
}


