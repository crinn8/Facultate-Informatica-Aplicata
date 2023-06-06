#include <iostream>
#include <fstream>
#include <algorithm>

void Citire(int& N, int& S, int CutieScrisori[500],int &total)
{
    std::ifstream f("Scrisori.in");
    f >> N >> S;
    std::cout << "Prietenul tau are " << N << " scrisori pe care doreste sa le arda, avand " << S << " ore la dispozitie." << std::endl << std::endl;

    for (int index = 0; index < N; index++)
    {
        f >> CutieScrisori[index];
        total += CutieScrisori[index];
    }

    f.close();
}

void AfisareSolutie(int N, int S, int timp,int nrScrisoriArse,int total)
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
        std::cout << "Pentru a arde toate scrisorile prietenul tau are nevoie ca focul sa arda pentru inca " << total-S << " minute." << std::endl;
    }
}

void Rezolvare(int N, int S, int CutieScrisori[500],int total)
{
    std::sort(CutieScrisori, CutieScrisori+N);
    S *= 60;
    int nrScrisoriArse = 0, timp = S;
    for (int index = 0; index < N && timp != 0; index++)
    {
        if (CutieScrisori[index] <= timp)
        {
            nrScrisoriArse++;
            timp -= CutieScrisori[index];
        }
    }
    AfisareSolutie(N, S, timp, nrScrisoriArse,total);
}

int main()
{
    int N, S, CutieScrisori[500],total=0;
    Citire(N, S, CutieScrisori,total);
    Rezolvare(N, S, CutieScrisori,total);
}

