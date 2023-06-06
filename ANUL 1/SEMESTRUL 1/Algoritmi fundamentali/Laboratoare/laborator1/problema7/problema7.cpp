// problema7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int progresiearitmetica(int n)
{
    int r = n % 10 - n/10  % 10, ok=1;
    n = n / 10;
    while (n>9&&ok==1)
    {
        int r1 = n % 10 - n / 10 % 10;
        if (r1 != r) ok = 0;
        n = n / 10;
    }
    return ok;
}
int main()
{
    int n;
    cin >> n;
    if (progresiearitmetica(n) == 1) cout << " Cifrele lui " << n << " sunt in progresie aritmetica.";
    else cout << " Cifrele lui " << n << " nu sunt in progresie aritmetica.";
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
