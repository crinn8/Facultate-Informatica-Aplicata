#include <iostream>

void AfisareMatrice(int n, int** matrice)
{
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrice[i][j] << " ";
        std::cout << std::endl;
    }
}

void ConstruireMatriceNrPar(int n, int** matrice)
{
    int k = 0,nr=1;
    while (k < n - 1)
    {
        for (int i = k; i < n - 1; i++)
            matrice[k][i]=nr++;
        for (int i = k; i < n - 1; i++)
            matrice[i][n-1]=nr++;
        for (int i = n - 1; i > k; i--)
            matrice[n-1][i]=nr++;
        for (int i = n - 1; i > k; i--)
            matrice[i][k]=nr++;
        k++;
        n--;
    }
}

void ConstruireMatriceNrImpar(int n, int** matrice)
{
    int k = n / 2, nr = 1, m = n / 2+1;
    matrice[k][k] = nr++;
    while (k > 0)
    {
        for (int i = k; i <= m; i++)
            matrice[i][k-1] = nr++;
        for (int i = k; i <=m; i++)
            matrice[m][i] = nr++;
        for (int i = m - 1; i >= k-1; i--)
            matrice[i][m] = nr++;
        for (int i = m - 1; i >= k-1; i--)
            matrice[k-1][i] = nr++;
        k--;
        m++;
    }
}

void AlocareMemorie(int n, int** matrice)
{
    matrice[0] = new int[n * n]();
    for (int index = 1; index < n; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
}

int main()
{
    int n,**matrice;
    std::cin >> n;
    matrice = new int* [n];

    AlocareMemorie(n, matrice);
    if (n % 2 == 0)
    {
        ConstruireMatriceNrPar(n, matrice);
    }
    else
    {
        ConstruireMatriceNrImpar(n, matrice);
    }
    AfisareMatrice(n, matrice);


    delete[]matrice[0];
    delete[]matrice;
    return 0;
}


