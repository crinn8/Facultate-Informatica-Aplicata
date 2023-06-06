// problema2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int  verificare(int n, int v[])
{
    int fr[1000];
    for (int i = 0; i <= n; i++)
        fr[i] = 0;
    for (int i = 0; i < n; i++)
        fr[v[i]]++;
    int ok = 0;
    for (int i = 1; i <= n; i++)
        if (fr[i] != 1) ok = 1;
    return ok;
}
int main()
{
    int n;
    cin >> n;
    int v[1000];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (verificare(n, v) == 0) cout << "elementele tabloului sunt toate distincte";
    else cout << "exista o pereche de elemente cu aceeasi valoare";
    return 0;
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
