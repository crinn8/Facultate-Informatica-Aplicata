#include <iostream>
#include <fstream>

void AfisareRezultat(bool survive,int nrMinimZile)
{
    if (survive)
    {
        std::cout << "Pentru a supravietui trebuie sa cumperi in fiecare zi cate o cutie cu bomboane de la magazin pentru minim ";
        if (nrMinimZile != 1)
        {
            std::cout << nrMinimZile << " zile." << std::endl;
        }
        else
        {
            std::cout << nrMinimZile << " zi." << std::endl;
        }
    }
    else
    {
        std::cout << "-1" << std::endl;
        std::cout << "Acest rezultat indica faptul ca nu este posibila supravietuirea.";
    }
}

void Survive(int nrBomboane_cutie, int nrBomboane_zi, int nrZile)
{
    int nrZileMagazinDeschis = nrZile / 7, nrMinimZile=0;
    nrZileMagazinDeschis = nrZile - nrZileMagazinDeschis;
    bool survive = true;
    int nrNecesarBomboane = nrBomboane_zi * nrZile;
    int nrMaximBomboane = nrZileMagazinDeschis * nrBomboane_cutie;
    if (nrNecesarBomboane > nrMaximBomboane)
    {
        survive = false;
    }
    else
    {
        nrMinimZile = nrNecesarBomboane / nrBomboane_cutie;
        if (nrNecesarBomboane % nrBomboane_cutie != 0)
        {
            nrMinimZile++;
        }
    }
    AfisareRezultat(survive, nrMinimZile);
}

int main()
{
    std::ifstream f("ChocoLand.in");
    int N, K, S;
    f >> N >> K >> S;
    Survive(N, K, S);
}

