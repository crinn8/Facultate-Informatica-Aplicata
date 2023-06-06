#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Lucrare {
    int penalizare, timp;
};
void citireFis(int& dim, Lucrare v[10])
{
    ifstream f("date.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
        f >> v[i].penalizare >> v[i].timp;

}
void afisare(int dim, Lucrare v[10])
{
    for (int i = 0; i < dim; i++)
        cout << v[i].penalizare << " " << v[i].timp << endl;
}
bool comparare(Lucrare i1, Lucrare i2)
{
    return i1.penalizare >= i2.penalizare;
}

int Calcul(int dim, Lucrare v[10])
{
    int fr[10] = { 0 },ok=0,penalitati=0;
    for (int i = 0; i < dim; i++)
    {
        if (fr[v[i].timp]==0)
        {
            fr[v[i].timp]++;
        }
        else
        {
             j = v[i].timp;
            while (j>=0&&ok==0)
            {
                if (!fr[j])
                {
                    fr[j]++;
                    ok = 1;
                }
                else j--;
            }
        }
        if (ok == 0)
        {
            penalitati += v[i].penalizare;
        }
    }
    return penalitati;
}

int main()
{
    int dim;
    Lucrare v[10];
    citireFis(dim, v);
    sort(v, v + dim, comparare);
    cout << Calcul(dim, v);
    return 0;
}

