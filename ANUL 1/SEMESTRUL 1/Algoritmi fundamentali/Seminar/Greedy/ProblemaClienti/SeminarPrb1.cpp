// SeminarPrb1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

void citire(int& n, int timpClienti[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> timpClienti[i];
}

int timpMediu(int n, int timpClienti[100])
{
    int s = 0;
    for (int i = n -1; i >= 0; i--)
    {
        s += (i + 1) * timpClienti[n - i - 1];
    }
    return s;
}

int main()
{
    int timpClienti[100], n;
    citire(n, timpClienti);
    sort(timpClienti, timpClienti+n);
    cout << timpMediu(n, timpClienti);
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
