// pb1lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <fstream>

void CitireFis(int &dim,int v[100])
{
    ifstream f("date.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
        f >> v[i];
}

int CautareMaxPivot(int v[100],int st,int dr)
{
    if (st == dr) return v[st];
    int m = (st + dr) / 2;
    if (v[m] > v[m - 1])
    {
        if (v[m] > v[m + 1])
            return v[m];
        else
            return CautareMaxPivot(v, m + 1, dr);
    }
    else return CautareMaxPivot(v, st, m - 1);
}

int main()
{
    int dim, v[100];
    CitireFis(dim, v);
    cout << CautareMaxPivot(v,0,dim-1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
