/*De la tastatură se citeşte o matrice de valori reale.Să se afişeze pe ecran matricea,
astfel încât fiecare element al matricei să fie scris aliniat la dreapta, pe opt caractere şi
cu două zecimale exacte.*/

#include <iostream>
#include <iomanip>

using namespace std;

void Citire(int n, int m, double** matrice)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrice[i][j];
        }
    }
}

void Afisare(int n, int m, double** matrice)
{
    cout << setiosflags(ios::right|ios::fixed|ios::showpoint);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << setprecision(2)<< matrice[i][j];
        }
        cout << endl;
    }
}

int main()
{
    double** matrice;
    int n, m;
    cin >> n >> m;
    matrice = new double* [m];
    matrice[0] = new double[m * n];
    for (int index = 1; index < m; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
    Citire(n, m, matrice);
    Afisare(n, m, matrice);

    delete[]matrice[0];
    delete[]matrice;
}

