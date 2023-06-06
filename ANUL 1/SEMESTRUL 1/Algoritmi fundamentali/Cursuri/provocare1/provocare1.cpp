#include <iostream>
#include <fstream>
using namespace std;

struct fractie
{
    int x, y;
}matrice[100][100];

int cmmdc(int a, int b)
{
    int  r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void frecventa(int fr[100])
{
    for (int i = 0; i < 100; i++)
    {
        fr[i] = 1;
    }
}

int Verif(int linii, int coloane, fractie matrice[100][100])
{
    for (int i = 1; i <= linii; i++)
    {
        int j;
        for (j = 1; j < coloane && matrice[i][j].x == 0; j++);
        if (j == coloane)
            if (matrice[i][j].x != 0) return 0;
    }
    return 1;
}

void Decizie(int linii, int coloane, int nr, int fr[100], fractie matrice[100][100])
{
    if (Verif(linii, coloane, matrice) == 0)
    {
        cout << "Sistemul este incompatibil!" << endl;
        cout << "=> S=" << char(237);
    }
    else
        if (nr == 0 && coloane - linii == 1)
        {
            cout << "Sistemul este compatibil determinat, iar solutia este: " << endl << "S={";
            for (int i = 1; i < linii; i++)
            {
                cout << matrice[i][coloane].x;
                if (matrice[i][coloane].y != 1 && matrice[i][coloane].x != 0)
                    cout << "/" << matrice[i][coloane].y;
                cout << " , ";
            }
            cout << matrice[linii][coloane].x;
            if (matrice[linii][coloane].y != 1 && matrice[linii][coloane].x != 0)
                cout << "/" << matrice[linii][coloane].y;
            cout << "}" << endl;;
        }
        else
        {
            cout << "Sistemul este compatibil nedeterminat!" << endl;
            cout << "Solutia sistemului este: S={";
            int j = 224, v[100] = { 0 }, a[100] = { 0 };
            for (int k = 1; k < coloane; k++)
            {
                int ok = 1;
                for (int i = 1; i <= linii; i++)
                {
                    if (matrice[i][k].x == 1 && matrice[i][k].y == 1 && a[i] != 1)
                    {
                        fr[k] = 1;
                        v[k] = 0;
                        a[i] = 1;
                    }
                    else
                        if (matrice[i][k].x != 0 && ok == 1)
                        {
                            fr[k] = j;
                            v[k] = j;
                            j++;
                            ok = 0;
                        }
                }

            }
            int nec, n = coloane - 1;
            for (int i = 1; i <= linii; i++)
            {
                nec = 0;
                for (int k = 1; k < coloane; k++)
                    if (matrice[i][k].x != 0)
                        nec++;
                if (nec == 1)
                {
                    n--;
                    cout << matrice[i][coloane].x;
                    if (matrice[i][coloane].y != 1 && matrice[i][coloane].x != 0)
                        cout << "/" << matrice[i][coloane].y;
                }
                else
                {
                    n--;
                    if (matrice[i][coloane].x != 0)
                    {
                        cout << matrice[i][coloane].x;
                        if (matrice[i][coloane].y != 1 && matrice[i][coloane].x != 0)
                            cout << "/" << matrice[i][coloane].y;
                    }
                    for (int k = 1; k < coloane; k++)
                    {
                        if (fr[k] != 1 && matrice[i][k].x != 0)
                        {
                            if (matrice[i][k].x == 1)
                            {
                                cout << "-";
                                cout << char(fr[k]);
                            }
                            else if (matrice[i][k].x == -1)
                            {
                                cout << "+";
                                cout << char(fr[k]);
                            }
                            else
                                if (matrice[i][k].x > 1)
                                {
                                    cout << (-1) * matrice[i][k].x;
                                    if (matrice[i][k].y != 1 && matrice[i][k].x != 0)
                                        cout << "/" << matrice[i][k].y;
                                    cout << char(fr[k]);
                                }
                                else
                                {
                                    cout << "+" << (-1) * matrice[i][k].x;
                                    if (matrice[i][k].y != 1 && matrice[i][k].x != 0)
                                        cout << "/" << matrice[i][k].y;
                                    cout << char(fr[k]);
                                }
                        }
                    }
                }
                if (n > 0)
                    cout << " , ";
                for (int k = i + 1; k < coloane && v[k] != 0; k++)
                {
                    n--;
                    cout << char(v[k]);
                    if (n > 0)
                        cout << " , ";
                    v[k] = 0;

                }

                if (i == linii)
                    cout << " } ";
            }
        }
}

void CitireMatrice(int& linii, int& coloane, fractie matrice[100][100])
{
    ifstream f("date.in");
    f >> linii >> coloane;
    for (int i = 1; i <= linii; i++)
        for (int j = 1; j <= coloane; j++)
        {
            f >> matrice[i][j].x;
            matrice[i][j].y = 1;
        }
    f.close();
}

void AfisareMatrice(int linii, int coloane, fractie matrice[100][100])
{
    for (int i = 1; i <= linii; i++)
    {
        for (int j = 1; j <= coloane; j++)
        {
            if (matrice[i][j].y < 0)
            {
                matrice[i][j].x *= -1;
                matrice[i][j].y *= -1;
            }
            cout << matrice[i][j].x;
            if (matrice[i][j].y != 1 && matrice[i][j].x != 0)
                cout << "/" << matrice[i][j].y;
            cout << " ";
        }
        cout << endl;
    }
}

void InmultireLinieCuOValoare(int linie, int coloane, fractie matrice[100][100], fractie valoare)
{
    for (int j = 1; j <= coloane; j++)
    {
        if ((valoare.x * matrice[linie][j].x) % (valoare.y * matrice[linie][j].y) == 0)
        {
            matrice[linie][j].x = (valoare.x * matrice[linie][j].x) / (valoare.y * matrice[linie][j].y);
            matrice[linie][j].y = 1;
        }
        else if ((valoare.y * matrice[linie][j].y) % (valoare.x * matrice[linie][j].x) == 0)
        {
            matrice[linie][j].y = (valoare.y * matrice[linie][j].y) / (valoare.x * matrice[linie][j].x);
            matrice[linie][j].x = 1;
        }
        else
        {
            matrice[linie][j].x = valoare.x * matrice[linie][j].x;
            matrice[linie][j].y = valoare.y * matrice[linie][j].y;
        }
    }
}

void AdunareLinii(int linie1, int linie2, int coloane, fractie matrice[100][100], fractie valoare)
{
    for (int j = 1; j <= coloane; j++)
    {
        int a = matrice[linie1][j].x * valoare.x, b;
        if (a != 0)
            b = matrice[linie1][j].y * valoare.y;
        else
            b = 1;
        matrice[linie2][j].x = matrice[linie2][j].x * b + a * matrice[linie2][j].y;
        matrice[linie2][j].y = matrice[linie2][j].y * b;
        int d = cmmdc(matrice[linie2][j].x, matrice[linie2][j].y);
        if (matrice[linie2][j].x != 0 && d != 1)
        {
            matrice[linie2][j].x = matrice[linie2][j].x / d;
            matrice[linie2][j].y = matrice[linie2][j].y / d;
        }
    }
}

void InterschimbareLinii(int linie1, int linie2, int coloane, fractie matrice[100][100])
{
    for (int j = 1; j <= coloane; j++)
    {
        swap(matrice[linie1][j].x, matrice[linie2][j].x);
        swap(matrice[linie1][j].y, matrice[linie2][j].y);
    }
}

void Cazul1(int linii, int coloane, fractie matrice[100][100], int j, int linie)
{
    for (int i = 1; i <= linii; i++)
    {
        if (i != linie && matrice[i][j].x != 0)
        {
            fractie valoare;
            valoare.x = (-1) * matrice[i][j].x;
            valoare.y = matrice[i][j].y;
            AdunareLinii(linie, i, coloane, matrice, valoare);
            AfisareMatrice(linii, coloane, matrice);
            cout << endl;
        }
    }
}

void CazulNr(int linii, int coloane, fractie matrice[100][100], int i, int j)
{
    fractie valoare;
    valoare.x = matrice[i][j].y;
    valoare.y = matrice[i][j].x;
    InmultireLinieCuOValoare(i, coloane, matrice, valoare);
    AfisareMatrice(linii, coloane, matrice);
    cout << endl;
}

void Calcul(int linii, int coloane, fractie matrice[100][100])
{
    int aux2 = 1, nr = 0, fr[100];
    frecventa(fr);
    for (int j = 1; j <= linii; j++)
    {
        int aux = aux2;
        if (matrice[j][aux2].x == 0)
        {
            int k;
            for (k = j + 1; k <= linii && matrice[k][j].x == 0; k++);
            if (k <= linii)
            {
                InterschimbareLinii(k, j, coloane, matrice);
                AfisareMatrice(linii, coloane, matrice);
                cout << endl;
            }
            else
            {
                for (k = aux2 + 1; k <= coloane - 1 && matrice[aux2][k].x == 0; k++);
                if (k <= coloane - 1)
                {
                    aux = k;
                    aux2++;
                    nr++;
                }
                fr[k - 1] = 0;
            }
        }
        if (matrice[j][aux].x != 0 && (matrice[j][aux].x != 1 || matrice[j][aux].y != 1))
        {
            CazulNr(linii, coloane, matrice, j, aux);
        }
        if (matrice[j][aux].x == 1 && matrice[j][aux].y == 1)
        {
            Cazul1(linii, coloane, matrice, aux, j);
        }
        aux2++;
    }
    Decizie(linii, coloane, nr, fr, matrice);
}

int main()
{
    int linii, coloane;
    CitireMatrice(linii, coloane, matrice);
    Calcul(linii, coloane, matrice);
}