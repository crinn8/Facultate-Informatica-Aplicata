/*Să se aloce dinamic memorie pentru un vector de vectori de elemente de tip double cu
următoarea proprietate: primul vector are un element, al doilea are două elemente, în
general al k-lea vector are k elemente, k{1, 2, …, n}. Să se citească de la tastatură n
(numărul de vectori) precum şi elementele vectorilor. Să se construiască un nou
vector format cu mediile aritmetice ale celor n vectori. În final să se elibereze toate
zonele de memorie alocate dinamic.*/
#include <iostream>
using namespace std;

void Citire(int n, double** v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cin >> v[i][j];
        }
    }
}

void Afisare(int n, double* nou )
{
    for (int i = 0; i < n; i++)
    {
        cout << nou[i] << " ";
    }
}

void ConstruireVectorNou(int n, double** v, double* nou)
{
    for (int i = 0; i < n; i++)
    {
        double media = 0;
        for (int j = 0; j <= i; j++)
        {
            media += v[i][j];
        }
        media /= i + 1;
        nou[i] = media;
    }
}

void Alocare(int &n,double**& v)
{
    //merge si cu bloc mare
    cin >> n;
    v = new double*[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = new double[i + 1];
    }
}

int main()
{
    int n;
    double** v,*nou;
    Alocare(n, v);
    nou = new double[n];

    Citire(n, v);
    ConstruireVectorNou(n, v, nou);
    Afisare(n, nou);
    
    for (int index = 0; index < n; ++index)
    {
        delete[]v[index];
    }
    delete[]v;
    delete[]nou;
    return 0;
}
