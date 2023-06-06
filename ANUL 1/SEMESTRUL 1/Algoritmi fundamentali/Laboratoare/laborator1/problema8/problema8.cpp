// problema8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void oglindit(int &n,int &nr)
{
    int og = 0;
    while (n % 10 == 0)
    {
        nr++;
        n = n / 10;
    }
    while (n)
    {
        og = og * 10 + n % 10;
        n = n / 10;
    }
    n = og;
}
int formarenumar(int n,int c,int nr)
{
    int nou = 0;
    while (n)
    {
        if (n % 10 != c)
            nou = nou * 10 + n % 10;
            
        n = n / 10;
    }
    if(c!=0)
        while (nr)
        {
            nou = nou * 10;
            nr--;
        }
    return nou;
}
int main()
{
    int n, c, nr=0;
    cin >> n >> c;
    oglindit(n, nr);
    cout << formarenumar(n, c, nr);
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
