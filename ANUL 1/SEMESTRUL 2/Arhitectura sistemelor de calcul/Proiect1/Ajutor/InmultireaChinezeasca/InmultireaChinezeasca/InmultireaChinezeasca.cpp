#include <iostream>
#include <algorithm>

int nrCifre(int x)
{
    int nr_cifre = 0;
    while (x)
    {
        nr_cifre++;
        x /= 10;
    }
    return nr_cifre;
}

void AlocareDinamica(int dim, int** matrice)
{
    matrice[0] = new int[dim * dim];
    for (int index = 1; index < dim; ++index)
    {
        matrice[index] = matrice[index - 1] + dim;
    }
}

void TransformareNumarInVector(int x, int* v,int dim)
{
    for (int i = dim - 1; i >= 0; i--)
    {
        v[i] = x % 10;
        x /= 10;
    }
}

void ConstruireMatrice(int dim, int** matrice, int* v1, int* v2)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            matrice[i][j] = v1[i] * v2[j];
        }
    }
}

void AfisareMatrice(int dim, int** matrice)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void ConstruireNumar(int dim, int* fr)
{
    int tr;
    tr = fr[dim - 1] / 10;
    fr[dim - 1] %= 10;
    for (int i = dim-2; i >= 0; i--)
    {
        fr[i] += tr;
        tr = fr[i] / 10;
        fr[i] = fr[i] % 10;
    }
    if (tr != 0)
    {
        std::cout << tr;
    }
    int i = 0;
    while (fr[i] == 0)
        i++;
    for (int j = i; j < dim; j++)
    {
        std::cout << fr[j];
    }
}

void InmultireaChinezeasca(int dim, int** matrice)
{
    int *fr;
    fr = new int[2 * dim - 1]();
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            fr[i + j] += matrice[i][j];
        }
    }
    ConstruireNumar(2 * dim - 1, fr);
}

int main()
{
    int Numar1, Numar2,nr_cif1,nr_cif2,**matrice,dim,*v1,*v2;
    std::cin >> Numar1 >> Numar2;
    nr_cif1 = nrCifre(Numar1);
    nr_cif2 = nrCifre(Numar2);
    dim = std::max(nr_cif1, nr_cif2);

    v1 = new int[dim]();
    v2 = new int[dim]();

    TransformareNumarInVector(Numar1, v1, dim);
    TransformareNumarInVector(Numar2, v2, dim);

    matrice = new int* [dim];
    AlocareDinamica(dim, matrice);

    ConstruireMatrice(dim, matrice, v1, v2);
    AfisareMatrice(dim, matrice);
    InmultireaChinezeasca(dim, matrice);
    delete[]matrice[0];
    delete[]matrice;
}