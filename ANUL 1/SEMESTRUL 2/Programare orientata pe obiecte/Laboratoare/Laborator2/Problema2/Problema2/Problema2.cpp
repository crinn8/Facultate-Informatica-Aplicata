/*Funcţie care primeşte ca primi parametri datele despre o matrice de dimensiuni m şi
n.Pornind de la această matrice să se construiască un vector format cu elementele
matricii luate în spirală pornind de la elementul de indici 0 şi 0 şi mergând în sensul
acelor de ceasornic.Funcţia va returna prin referinţă pointerul către vectorul
construit.Menţionăm faptul că, după construcţia vectorului, în interiorul funcţiei se
va elibera memoria ocupată de matrice.*/

#include <iostream>
using namespace std;

void ConstruireVector(int **matrice,int n,int m,int *&v)
{
    int k = 0;

    for(int i=0;i<m;i++)
    {
        for (int j = i; j < n - i; j++)
            v[k++] = matrice[i][j];
        for (int j = i+1; j < m - i; j++)
            v[k++] = matrice[j][n-i-1];
        for (int j = n - i-2; j > i; j--)
            v[k++] = matrice[m-i - 1][j];
        for (int j = m -i- 1; j > i; j--)
            v[k++] = matrice[j][i];
    }
}


int main()
{
    int n, m, ** matrice, * v;
    cin >> m >> n;
    matrice = new int* [m];
    matrice[0] = new int[m * n];
    for (int index = 1; index < m; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrice[i][j];

    v = new int[n * m];
    ConstruireVector(matrice, n, m, v);
    for (int i = 0; i < m * n; i++)
        cout << v[i]<<" ";
    delete[]matrice[0];
    delete[]matrice;
}