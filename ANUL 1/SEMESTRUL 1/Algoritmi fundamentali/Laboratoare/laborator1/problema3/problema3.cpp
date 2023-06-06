// problema3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int palindrom(int x)
{
    int y = x, og = 0;
    while (y)
    {
        og = og * 10 + y % 10;
        y = y / 10;
    }
    if (og == x) return 1;
    else return 0;
}

void afisare(int a, int b)
{
    for (int i = a; i <= b; i++)
        if (palindrom(i) == 1)
            cout << i << " ";
}
int main()
{
    int a, b;
    cin >> a >> b;
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
