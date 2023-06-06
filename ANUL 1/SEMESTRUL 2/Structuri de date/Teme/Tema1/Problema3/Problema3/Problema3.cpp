#include <iostream>
#include <fstream>
#include <math.h>

std::ifstream f("puncte.in");

struct punct {
    double x;
    double y;

    void citire()
    {
        f >> x;
        f >> y;
    }
};

double distantaEuclidina(punct p1,punct p2)
{
    double d;
    d = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return d;
}

void quickSort(int v[100], int st, int dr)
{
    int i = st, j = dr;
    int piv = v[(st + dr) / 2];
    while (i <= j)
    {
        while (v[i] < piv)
            i++;
        while (v[i] > piv)
            j--;
        if (i <= j)
        {
            swap(v[i], v[i]); i++; j--;
        }
    }
    if (st < j)
        quickSort(v, st, j);
    if (i < dr)
        quickSort(v, i, dr);
}

int main()
{
    
}
