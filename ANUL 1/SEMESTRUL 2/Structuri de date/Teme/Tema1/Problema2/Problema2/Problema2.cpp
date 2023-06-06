//Complexitatea este O(k*n), unde k reprezinta numarul de cifre ale fiecarui element

#include <iostream>
#include <fstream>

void CitireVector(int &nr, int*& numere)
{
    std::ifstream f("numere.in");
    f >> nr;
    numere = new int[nr]();
    for (int i = 0; i < nr; i++)
    {
        f >> numere[i];
    }
    f.close();
}

void DeterminareCifra(int* fr)
{
    int maxim = 0,cifra=0;
    for (int i = 0; i < 10; i++)
    {
        if (fr[i] > maxim)
        {
            maxim = fr[i];
            cifra = i;
        }
    }
    std::cout << "Cifra cu numar maxim de aparitii este: " << cifra << " si apare de " << fr[cifra] << " ori.";
}

void ConstruireVectorFrecventa(int nr, int* numere)
{
    int fr[10] = { 0 };
    for (int i = 0; i < nr; i++)
    {
        int x = numere[i];
        while (x>0)
        {
            fr[x % 10]++;
            x /= 10;
        }
    }
    DeterminareCifra(fr);
}

int main()
{
    int* numere=nullptr,nr=0;
    CitireVector(nr, numere); 
    ConstruireVectorFrecventa(nr, numere);
    return 0;
}

