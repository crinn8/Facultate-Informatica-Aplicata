#include <iostream>
#include <fstream>
using namespace std;
void citireFisier(int tipuriBancnote[], int& dim, int& suma) {
    ifstream f("Date.txt");
    f >> dim >> suma;
    for (int i = 0; i < dim; i++) 
    {
        f >> tipuriBancnote[i];
    }
}
void afisare(int v[], int dim) 
{
    for (int i = 0; i < dim; i++) 
    {
        cout << v[i] << ' ';
    }

}
int nrMinBancnote(int tipuriBancnote[], int dim, int suma) {
    if (suma < 0) {
        return -1;
    }
    int nrBanc[100];//dimensiunea vectorului este suma + 1
    nrBanc[0] = 0;
    for (int i = 1; i <= suma; i++) 
    {
        nrBanc[i] = suma;
    }
    for (int i = 1; i <= suma; i++) 
    {
        for (int j = 0; j < dim; j++) 
        {
            if (tipuriBancnote[j] <= i) 
            {
                if (nrBanc[i] > 1 + nrBanc[i - tipuriBancnote[j]]) 
                {
                    nrBanc[i] = 1 + nrBanc[i - tipuriBancnote[j]];
                }
            }
        }
    }
    return nrBanc[suma];
}
int main() {
    int tipuriBancnote[100], suma, nrBancnote;
    citireFisier(tipuriBancnote, nrBancnote, suma);
    cout << nrMinBancnote(tipuriBancnote, nrBancnote, suma);
}