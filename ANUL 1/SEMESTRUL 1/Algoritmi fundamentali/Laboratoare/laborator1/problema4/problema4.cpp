// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void maxim(int n, int& val1, int& val2)
{
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int d = cmmdc(a, b);
        if (d > mx)
        {
            mx = d;
            val1 = a;
            val2 = b;
        }
    }
}
void afisare(int n)
{
    int val1 = 0, val2 = 0;
    maxim(n, val1, val2);
    cout << val1 << " " << val2;
}
int main()
{
    int n;
    cin >> n;
    afisare(n);
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
