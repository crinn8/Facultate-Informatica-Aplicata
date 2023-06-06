// problema6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

void GenerareRandom(int& dim, int v[100])
{
    cin >> dim;
    for (int i = 0; i < dim; i++)
    {
        v[i] = rand();
    }
}

void SortareElementePare(int dim, int v[100])
{
    for (int i = 0; i < dim - 1; i++)
    {
        if (v[i]%2==0)
        {
            for (int j = i + 1; j < dim; j++)
            {
                if (v[j] % 2 == 0 && v[i] > v[j])
                {
                    swap(v[i], v[j]);
                }
            }
        }
    }
}

void AfisareVector(int dim, int v[100])
{
    for (int i = 0; i < dim; i++)
        cout << v[i] << " ";
}

int main()
{
    int dim, v[100];
    GenerareRandom(dim, v);
    AfisareVector(dim, v);
    cout << endl;
    SortareElementePare(dim, v);
    AfisareVector(dim, v);
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
