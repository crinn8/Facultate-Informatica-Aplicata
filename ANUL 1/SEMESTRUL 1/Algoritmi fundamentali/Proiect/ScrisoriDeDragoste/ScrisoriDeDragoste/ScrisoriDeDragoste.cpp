#include <iostream>
#include <fstream>
#include <algorithm>

struct Scrisoare {
    int timp_ardere, index;
};

void Citire(int& N, int& S, Scrisoare CutieScrisori[500], int& total)
{
    std::ifstream f("Scrisori.in");
    f >> N >> S;
    std::cout << "Prietenul tau are " << N << " scrisori pe care doreste sa le arda, avand " << S << " ore la dispozitie." << std::endl << std::endl;

    for (int i = 0; i < N; i++)
    {
        int lungime_hartie, tip_hartie;
        f >> lungime_hartie >> tip_hartie;
        CutieScrisori[i].timp_ardere = lungime_hartie * tip_hartie;
        CutieScrisori[i].index = i+1;
        total += CutieScrisori[i].timp_ardere;
    }

    f.close();
}

void AfisareSolutie(int N, int S, int timp, int nrScrisoriArse, int total)
{
    if (nrScrisoriArse == N)
    {
        if (timp == 0)
        {
            std::cout << "Toate cele " << N << " scrisori au fost arse in cele " << S / 60 << " ore." << std::endl << std::endl;
        }
        else
        {
            std::cout << "Toate cele " << N << " scrisori au fost arse in mai putin de " << S / 60 << " ore, ramanand " << timp << " minute." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << "In cele " << S / 60 << " ore au fost arse " << nrScrisoriArse << " scrisori." << std::endl << std::endl;
        std::cout << "Pentru a arde toate scrisorile prietenul tau are nevoie ca focul sa arda pentru inca " << total - S << " minute." << std::endl;
    }
}

bool comparator(Scrisoare x, Scrisoare y)
{
    return x.timp_ardere < y.timp_ardere;
}

void Rezolvare(int N, int S, Scrisoare CutieScrisori[500], int total)
{
    std::sort(CutieScrisori, CutieScrisori + N,comparator);
    S *= 60;
    int nrScrisoriArse = 0, timp = S;
    std::cout << "Scrisorile arse sunt: ";
    for (int i = 0; i < N && timp != 0; i++)
    {
        if (CutieScrisori[i].timp_ardere <= timp)
        {
            nrScrisoriArse++;
            timp -= CutieScrisori[i].timp_ardere;
            std::cout << CutieScrisori[i].index << " ";
        }
    }
    std::cout <<" "<< std::endl;
    AfisareSolutie(N, S, timp, nrScrisoriArse, total);
}

int main()
{
    int N, S, total = 0;
    Scrisoare CutieScrisori[500];
    Citire(N, S, CutieScrisori, total);
    Rezolvare(N, S, CutieScrisori, total);
}
