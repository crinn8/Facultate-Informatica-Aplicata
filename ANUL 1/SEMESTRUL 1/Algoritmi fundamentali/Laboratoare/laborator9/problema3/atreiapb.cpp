#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Interval {
    int dr, st;
};
void citireFis(int& dim, Interval v[10])
{
    ifstream f("date.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
        f >> v[i].st >> v[i].dr;

}
void afisare(int dim, Interval v[10])
{
    for (int i = 0; i < dim; i++)
        cout << v[i].st << " " << v[i].dr << endl;
}
bool comparareSt(Interval i1, Interval i2)
{
    return i1.st < i2.st;
}
int Calcul(int dim, Interval v[10])
{
    int lungime = v[0].dr - v[0].st, lim = v[0].dr;
    for (int i = 1; i < dim; i++)
    {
        if (v[i].st >= lim)
        {
            lungime += v[i].dr - v[i].st;
            lim = v[i].dr;
        }
        else
            if (v[i].dr > lim)
            {
                lungime += v[i].dr - lim;
                lim = v[i].dr;
            }
    }
    return lungime;
}
int main()
{
    int dim;
    Interval v[10];
    citireFis(dim, v);
    sort(v, v + dim, comparareSt);
    cout << Calcul(dim, v);
    return 0;
}