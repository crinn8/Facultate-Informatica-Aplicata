#include <iostream>
#include <fstream>

void AlocareMemorieMatrice(int**& matrice, int& n)
{
    matrice[0] = new int[n * n];
    for (int index = 1; index < n; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
}

void CitireMatrice(int**& matrice, int& n)
{
    std::ifstream f("matriceA.in");
    f >> n;
    matrice = new int* [n];
    AlocareMemorieMatrice(matrice, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            f >> matrice[i][j];
        }
}

void TransformareMatriceInVector(int** matrice, int* vector, int n)
{
    int k=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            vector[k] = matrice[i][j];
            k++;
        } 
    }
}

void AfisareVector(int* vector, int dim)
{
    for (int i = 0; i < dim; ++i)
    {
        std::cout << vector[i] << " ";
    }
}

int main()
{
    int** matrice,*V, n=0;

    CitireMatrice(matrice, n);
    int dim = (n * n + n) / 2;

    V = new int[dim]();

    TransformareMatriceInVector(matrice, V, n);
    
    AfisareVector(V, dim);

    delete[]V;
    delete[]matrice[0];
    delete[]matrice;

    return 0;
}
