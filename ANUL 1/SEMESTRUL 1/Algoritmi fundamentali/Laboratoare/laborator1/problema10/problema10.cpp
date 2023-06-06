// problema10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int numarcifre(int n)
{
    int nr = 0;
    while (n)
    {
        nr++;
        n = n / 10;
    }
    return nr;
}
int variantenumere(int n, int poz)
{
    int p = 1;
    while (poz>1)
    {
        p = p * 10;
        poz--;
    }
    return n / (p * 10) * p + n % p;
}
void maxim(int n,int &mx)
{
    int nr = numarcifre(n);
    for (int i = 1; i <= nr; i++)
    {
        int nou;
        nou = variantenumere(n, i);
        if (nou > mx) 
            mx = nou; 
    }
}
int main()
{
    int n,mx;
    cin >> n;
    mx = 0;
    maxim(n,mx);
    cout << mx;
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
