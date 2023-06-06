#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void DeterminareSir(int lgSir, char sir[100])
{
    int i = 2, j = 1;
    while (lgSir)
    {
        strcat(sir, "a_");
        sir[i] = '\0';
        char x[10];
        _itoa(j, x, 10);
        strcat(sir, x);
        i = i + strlen(x) + 2;
        lgSir--;
        j++;
    }
    sir[i] = '\0';
}

void calcul(int k, int lgR, int lgP, char r[50], char p[100], char q[100])
{
    int c = k;
    while (k * lgR < lgP)
        k = k + c;
    int x = lgP / lgR;
    char y[10];
    _itoa(x, y, 10);
    strcat(p, "r^");
    strcat(p, y);
    char aux[100] ="";
    DeterminareSir(lgP % lgR, aux);
    strcat(p, aux);
    p[strlen(p)] = '\0';
    strcat(q, r + strlen(aux));
    strcat(q, aux);
    q[strlen(q)] = '\0';
}

int main()
{
    char r[100] = "", p[100] = "", q[100] = "";
    int k, lgP, lgQ, lgR;
    cout << "Introduceti datele de intrare:" << endl;
    cout << "k="; cin >> k;
    cout << "lg(p)="; cin >> lgP;
    cout << "lg(q)="; cin >> lgQ;
    lgR = lgQ;
    DeterminareSir(lgR, r);
    calcul(k, lgR, lgP, r, p, q);
    cout << endl;
    cout << "p in functie de simbolurile lui r: " << p << endl;
    cout << "q in functie de simbolurile lui r: " << q << endl;
    return 0;
}
