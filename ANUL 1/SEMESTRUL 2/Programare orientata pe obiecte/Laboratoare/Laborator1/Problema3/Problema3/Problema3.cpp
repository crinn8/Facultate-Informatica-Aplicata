/*De la tastatură se citesc numele şi vârstele unor persoane. Să se afişeze tabelar, sortat
după nume, aceste date precum şi media vârstelor.*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Persoana {
    char Nume[30];
    char Prenume[30];
    int varsta;
    int Nr_crt;
};
bool ComparePers(Persoana p1, Persoana p2)
{
    if (strcmp(p1.Nume, p2.Nume) < 0)
        return true;
    if (!strcmp(p1.Nume, p2.Nume))
        if (strcmp(p1.Prenume, p2.Prenume))
            return true;
    return false;
}

void Afisare(int n, Persoana Pers[100],double Media_varstelor)
{
    cout << "| Nr.crt | Nume si prenume | Varsta |" << endl;
    for (int i = 0; i < 40; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|    " << Pers[i].Nr_crt << ".  |" << Pers[i].Nume << " " << Pers[i].Prenume << "             | " << Pers[i].varsta << " |";
        if (i < n-1)
        {
            cout << endl;
        }
    }
    cout << endl;
    for (int i = 0; i < 40; i++)
        cout << "-";
    cout << endl;
    cout << "| Media varstelor            | " << Media_varstelor << " |";
}

void AfisareOK(int n, Persoana Pers[100],int Media_varstelor)
{
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        cout << setw(3) << i+1 << "." << "|";
        cout << Pers[i].Nume << " " << setw(30 - strlen(Pers[i].Nume) + 1) << Pers[i].Prenume;
        cout << "|" << setw(4) << Pers[i].varsta << "|" << endl;
    }
    cout << "|" << setw(35) << "Media varstelor" << "|" << setw(4) << Media_varstelor << "|";
}

int main()
{
    int n;
    cin >> n;
    double Media_varstelor = 0;
    Persoana Pers[100];
    for (int i = 0; i < n; i++)
    {
        Pers[i].Nr_crt = i + 1;
        cin >>  Pers[i].Nume >> Pers[i].Prenume >> Pers[i].varsta;
        Media_varstelor+= Pers[i].varsta;
    }
    Media_varstelor /= n;
    sort(Pers, Pers+n, ComparePers);
    for (int i = 0; i < n; i++)
    {
        Pers[i].Nr_crt = i + 1;
    }
    AfisareOK(n, Pers,Media_varstelor);
}


