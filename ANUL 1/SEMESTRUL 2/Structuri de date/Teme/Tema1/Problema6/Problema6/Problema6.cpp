//Compexitatea este O(n^2)
#include <iostream>
#include <fstream>

void AlocareMemorie(int n, int**& matrice)
{
    matrice = new int* [n + 1]();
    matrice[1] = new int[(n + 1) * (n + 1)]();
    for (int index = 2; index <= n; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
}

void CitireMatrice(int &n, int**& matrice)
{
    std::ifstream f("relatii.in");
    f >> n;
    AlocareMemorie(n, matrice);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            f >> matrice[i][j];
    }
    f.close();
}

void AfisareMatrice(int n, int** matrice)
{
    std::cout << std::endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            std::cout << matrice[i][j] << " ";
        std::cout << std::endl;
    }
}

void NumarMaximPrieteni(int n, int* prieteni)
{
    int maxim=0;
    for (int i = 1; i <= n; i++)
    {
        if (prieteni[i] > maxim)
        {
            maxim = prieteni[i];
        }
    }
    std::cout << "Cei mai multi prieteni ii are/au elevul/elevii: ";
    for (int i = 1; i <= n; i++)
    {
        if (prieteni[i] == maxim)
        {
             std::cout<<i << "  ";
        }
    }
    std::cout << "adica " << maxim << " prieteni"<<std::endl;
}

void NumarPrieteni(int n, int** matrice,int *prieteni)
{
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (matrice[i][j] == 1 && matrice[j][i] == 1)
            {
                prieteni[i]++;
                prieteni[j]++;
            }
        }
    }
    NumarMaximPrieteni(n, prieteni);
}

void FaraPrieteni(int n, int* prieteni)
{
    std::cout << "Elevul/Elevii care nu are/au prieteni este/sunt: ";
    for (int i = 1; i <= n; i++)
    {
        if (prieteni[i] == 0)
        {
            std::cout << i << "  ";
        }
    }
    std::cout << std::endl;
}

void EleviNeagreati(int n, int** matrice)
{
    std::cout << "Elevul/Elevii care nu este/sunt agreat/agreati de nimeni este/sunt: ";
    for (int j = 1; j <= n; j++)
    {
        int ok = 0;
        for (int i = 1; i <= n&&ok==0; i++)
        {
            if (i != j && matrice[i][j] == 1)
            {
                ok = 1;
            }
        }
        if (ok == 0)
        {
            std::cout << j << "  ";
        }
    }
}

int main()
{
    int n=0, ** matrice=nullptr,*prieteni;

    CitireMatrice(n, matrice);
    prieteni = new int[n+1]();

    NumarPrieteni(n, matrice, prieteni);
    FaraPrieteni(n, prieteni);
    EleviNeagreati(n, matrice);

    delete[]matrice[1];
    delete[]matrice;
    return 0;
}



