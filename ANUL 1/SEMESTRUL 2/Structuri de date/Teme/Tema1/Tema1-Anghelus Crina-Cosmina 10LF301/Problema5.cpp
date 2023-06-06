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

    void afisare()
    {
        std::cout << numarator << "/";
        std::cout << numitor<<" ";
    }
};

fractie adunareFractii(fractie f1,fractie f2)
{
    fractie rezultat;
    rezultat.numarator = f1.numarator * f2.numitor + f2.numarator * f1.numitor;
    rezultat.numitor = f1.numitor * f2.numitor;
    rezultat.reductie();
    return rezultat;
}

fractie scadereFractii(fractie f1, fractie f2)
{
    fractie rezultat;
    rezultat.numarator = f1.numarator * f2.numitor - f2.numarator * f1.numitor;
    rezultat.numitor = f1.numitor * f2.numitor;
    rezultat.reductie();
    return rezultat;
}

fractie inmultireFractii(fractie f1, fractie f2)
{
    fractie rezultat;
    rezultat.numarator = f1.numarator * f2.numarator;
    rezultat.numitor = f1.numitor * f2.numitor;
    rezultat.reductie();
    return rezultat;
}

fractie impartireFractii(fractie f1, fractie f2)
{
    std::swap(f2.numarator, f2.numitor);
    return inmultireFractii(f1, f2);
}

int MaiMica(fractie f1, fractie f2)
{
    if (f1.numarator * f2.numitor < f1.numitor * f2.numarator)
        return 1;
    return 0;
}

int Egale(fractie f1, fractie f2)
{
    if (f1.numarator * f2.numitor == f1.numitor * f2.numarator)
        return 1;
    return 0;
}
int MaiMare(fractie f1, fractie f2)
{
    if (f1.numarator * f2.numitor > f1.numitor * f2.numarator)
        return 1;
    return 0;
}

void quickSort(fractie *fractii, int st, int dr)
{
    int i = st, j = dr;
    fractie piv = fractii[(st + dr) / 2];
    while (i <= j)
    {
        while (MaiMica(fractii[i], piv))
            i++;
        while (MaiMare(fractii[j], piv))
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
        suma = adunareFractii(suma, fractii[index]);
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
    }

    std::cout << "Dupa reducerea fractiilor vectorul este: "<<std::endl;
    for (int index = 0; index < n; ++index)
    {
        fractii[index].citire();
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


