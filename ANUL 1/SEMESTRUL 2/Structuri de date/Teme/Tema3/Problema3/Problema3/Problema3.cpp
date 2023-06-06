#include <iostream>
#include <fstream>
#include <queue>

void AlocareDinamica(int n, int** &matrice)
{
    matrice = new int* [n]();
    matrice[0] = new int[n * n]();
    for (int index = 1; index < n; ++index)
    {
        matrice[index] = matrice[index - 1] + n;
    }
}

struct pozitie {
    int x;
    int y;
};

void CitireMatrice(int &n, int** &matrice,pozitie &start,pozitie &finish)
{
    std::ifstream f("joc.in");
    f >> n;
    AlocareDinamica(n, matrice);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            f >> matrice[i][j];
    }
    f >> start.x >> start.y;
    f >> finish.x >> finish.y;
}

int Mutari(int n, int** matrice, pozitie start, pozitie finish, int**& rezultat)
{
    std::queue <pozitie> c;
    int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
    int ok = -1;
    c.push(start);
    rezultat[start.x][start.y] = 1;
    pozitie poz_curenta;
    while (ok == -1 && c.empty() == false)
    {
        poz_curenta = c.front();
        c.pop();
        if (poz_curenta.x == finish.x && poz_curenta.y == finish.y)
        {
            ok = 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            pozitie aux;
            aux.x = poz_curenta.x + dx[i] * matrice[poz_curenta.x][poz_curenta.y];
            aux.y = poz_curenta.y + dy[i] * matrice[poz_curenta.x][poz_curenta.y];
            if (aux.x >= 0 && aux.y >= 0 && aux.x < n && aux.y < n && rezultat[aux.x][aux.y] == 0)
            {
                rezultat[aux.x][aux.y] = rezultat[poz_curenta.x][poz_curenta.y] + 1;
                c.push(aux);
            }
        }
    }
    return ok;
}

int main()
{
    int n, ** matrice = nullptr;
    pozitie start, finish;
    CitireMatrice(n, matrice, start, finish);
    int** rezultat = nullptr;
    AlocareDinamica(n, rezultat);

    int m = Mutari(n, matrice, start, finish, rezultat);
    if (m == -1)
    {
        std::cout << "Personajul nu poate ajunge de la pozitia (" << start.x << "," << start.y << ") la pozitia (" << finish.x << "," << finish.y << ").";
    }
    else
    {
        std::cout << "Numarul minim de mutari este: " << rezultat[finish.x][finish.y]<<".";
    }

    delete[]matrice[0];
    delete[]matrice;
    delete[]rezultat[0];
    delete[]rezultat;

    return 0;
}
