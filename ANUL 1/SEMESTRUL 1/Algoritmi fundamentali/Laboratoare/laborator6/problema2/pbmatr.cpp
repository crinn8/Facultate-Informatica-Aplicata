#include <iostream>
#include <fstream>
using namespace std;

void citire(int& n, int& m, int a[100][100], int& k)
{
    ifstream f("date.in");
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    f >> k;
}

void cautareBinara(int a[100][100], int i, int j_st, int j_dr, int x)
{
    while (j_st <= j_dr)
    {
        int j_mij = (j_st + j_dr) / 2;

        if (a[i][j_mij] == x)
        {
            cout << "( " << i << " " << j_mij << " )";
            return;
        }

        if (a[i][j_mij] > x)
            j_dr = j_mij - 1;
        else
            j_st = j_mij + 1;

    }
    cout << "Nu exista";
}


void cautareMatrice(int a[100][100], int n, int m, int x)
{
    if (n == 1)
    {
        cautareBinara(a, 1, 1, m, x);
        return;
    }

    int i_sus = 1;
    int i_jos = n;
    int j_mij = m % 2 == 0 ? m / 2 : m / 2 + 1;

    while ((i_sus + 1) < i_jos)
    {

        int i_mij = (i_sus + i_jos) / 2;

        if (a[i_mij][j_mij] == x)
        {
            cout << "( " << i_mij << " " << j_mij << " )";
            return;
        }

        if (a[i_mij][j_mij] > x)
            i_jos = i_mij;
        else
            i_sus = i_mij;
    }

    if (a[i_sus][j_mij] == x)
    {
        cout << "( " << i_sus << " " << j_mij << " )";
        return;
    }
    else if (a[i_sus + 1][j_mij] == x)
    {
        cout << "( " << i_sus + 1 << " " << j_mij << " )";
        return;
    }

    if (x <= a[i_sus][j_mij - 1])
        cautareBinara(a, i_sus, 1, j_mij - 1, x);
    else if (x >= a[i_sus][j_mij + 1] && x <= a[i_sus][m])
        cautareBinara(a, i_sus, j_mij + 1, m, x);
    else if (x >= a[i_sus + 1][1] && x <= a[i_sus + 1][j_mij - 1])
        cautareBinara(a, i_sus + 1, 1, j_mij - 1, x);
    else
        cautareBinara(a, i_sus + 1, j_mij + 1, m, x);
}


int main()
{
    int n, m, a[100][100], k;
    citire(n, m, a, k);
    cautareMatrice(a, n, m, k);
}
