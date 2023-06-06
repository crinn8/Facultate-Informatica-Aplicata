#include <iostream>
#include <stdlib.h>
#include<time.h>

void GenerareRandom(int v[100], int dim)
{
    srand(time(0));

    for (int i = 0; i < dim; i++)
        v[i] = rand();
}

int VerfificareSirDescrescator(int n, int v[100])
{
    int ok = 1;
    for (int i = 0; i < n - 1 && ok == 1; i++)
    {
        if (v[i] < v[i + 1])
        {
            ok = 0;
        }
    }
    return ok;
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
            if (v[mij] > element)
                st = mij + 1;
            else dr = mij - 1;
    }
    return -1;
}

int CautareBinara2(int dim, int v[100], int element)
{
    int st = 0, dr = dim - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] < element && v[mij - 1]>element)
            return mij;
        else
            if (v[mij] > element)
            {
                if (v[mij + 1] < element)
                    return mij;
                else
                    st = mij + 1;
            }
            else dr = mij - 1;
    }
    return -1;
}

void InserareElement(int& dim, int v[100], int element)
{
    int poz = CautareBinara2(dim, v, element);
    dim++;
    for (int i = dim - 1; i >= poz; i--)
    {
        v[i + 1] = v[i];
    }
    v[poz] = element;
}

void StergereElement(int& dim, int v[100], int element)
{
    int poz = CautareBinara(dim, v, element);
    if (poz != -1)
    {
        for (int i = poz; i < dim - 1; i++)
            v[i] = v[i + 1];
        dim--;
    }
}

void AfisareVector(int dim, int v[100])
{
    for (int i = 0; i < dim; i++)
    {
        std::cout << v[i] << " ";
    }
}

int main()
{
    int dim, v[100] = { 0 }, element_i, element_s;
    std::cin >> dim;
    GenerareRandom(v, dim);
    if (VerfificareSirDescrescator(dim, v) == 0)
    {
        std::cout << "Vectorul nu este sortat strict descrescator.";
    }
    else
    {
        std::cout << "Vectorul este sortat strict descrescator." << std::endl;
        std::cin >> element_i;
        InserareElement(dim, v, element_i);
        AfisareVector(dim, v);
        std::cout << std::endl;
        std::cin >> element_s;
        StergereElement(dim, v, element_s);
        AfisareVector(dim, v);
    }
}
