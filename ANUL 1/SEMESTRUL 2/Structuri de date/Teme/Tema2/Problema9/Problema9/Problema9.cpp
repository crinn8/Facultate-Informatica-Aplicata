//Complexitate O(n^2)

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

void AlocareMemorie(int m, int n, int**& matrice)
{
    matrice = new int* [m];
    matrice[0] = new int[m * n];
    for (int index = 1; index < m; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
}

struct pozitie {
    int x = 0;
    int y = 0;
};

void CitireDate(int& m, int& n, int**& matrice, pozitie& Branza, pozitie& Soricel)
{
    std::ifstream f("matrice.in");
    f >> m >> n;
    AlocareMemorie(m, n, matrice);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            f >> matrice[i][j];
    f >> Soricel.x >> Soricel.y;
    f >> Branza.x >> Branza.y;
}

void AfisareDrum(int m, int n, int** matrice, pozitie Branza, pozitie Soricel)
{
    std::cout << "Drumul de la soricel la branza este: ";
    std::stack <pozitie> drum;
    drum.push(Branza);
    pozitie nod;
    int ok = 0;
    int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
    while (ok == 0)
    {
        nod = drum.top();
        if (nod.x == Soricel.x && nod.y == Soricel.y)
        {
            ok = 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            pozitie aux;
            aux.x = nod.x + dx[i];
            aux.y = nod.y + dy[i];
            if (aux.x != -1 && aux.y != -1 && aux.x != m && aux.y != n)
            {
                if (matrice[aux.x][aux.y] == matrice[nod.x][nod.y] - 1)
                {
                    drum.push(aux);
                    break;
                }
            }
        }
    }
    while (drum.empty() == false)
    {
        pozitie aux;
        aux = drum.top();
        std::cout << "(" << aux.x << "," << aux.y << ")" << " ";
        drum.pop();
    }
    std::cout << std::endl;
}

void DeterminareDrum(int m, int n, int** matrice, pozitie Branza, pozitie Soricel)
{
    std::queue <pozitie> c;
    c.push(Soricel);
    pozitie nod;
    int ok = 0;
    int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
    while (c.empty() == false && ok == 0)
    {
        nod = c.front();
        c.pop();
        if (nod.x == Branza.x && nod.y == Branza.y)
        {
            ok = 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            pozitie aux;
            aux.x = nod.x + dx[i];
            aux.y = nod.y + dy[i];
            if (aux.x != -1 && aux.y != -1 && aux.x != m && aux.y != n)
            {
                if (matrice[aux.x][aux.y] == 0)
                {
                    matrice[aux.x][aux.y] = matrice[nod.x][nod.y] + 1;
                    c.push(aux);
                }
            }
        }
    }
    matrice[Soricel.x][Soricel.y] = 0;

    if (ok == 0) std::cout << "Nu exista drum de la soricel la branza." << std::endl;
    else AfisareDrum(m, n, matrice, Branza, Soricel);
}

void AfisareMatrice(int m, int n, int** matrice)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << matrice[i][j] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    int** matrice = nullptr, m = 0, n = 0;
    pozitie Branza, Soricel;
    CitireDate(m, n, matrice, Branza, Soricel);
    DeterminareDrum(m, n, matrice, Branza, Soricel);
    AfisareMatrice(m, n, matrice);

    delete[]matrice[0];
    delete[]matrice;
}
