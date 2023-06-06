// problema5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int nrprim(int x)
{
    int d = 2,ok=1;
    while (d < x / 2&&ok==1)
    {
        if (x % d == 0) ok = 0;
        else d++;
    }
    return ok;
}

void putere(int k, int& x, int& y)
{
    x = 1;
    while (k > 1)
    {
        x = x * 10;
        k--;
    }
    y = x * 10;
}
void afisare(int a, int b)
{
    for (int i = a; i <= b; i++)
        if (nrprim(i - 1) == 1 && nrprim(i + 1) == 1)
            cout << i << " ";
}

int main()
{
    int a = 0, b = 0, k;
    cin >> k;
    putere(k, a, b);
    afisare(a, b);
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
