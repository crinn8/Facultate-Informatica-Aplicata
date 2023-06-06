// Lproblema2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int oglindit(int n)
{
    int og = 0;
    while (n)
    {
        og = og * 10 + n % 10;
        n = n / 10;
    }
    return og;
}
void afisare(int n,int primul)
{
    if (oglindit(primul) == primul)
        cout << primul << " ";
    for(int i=1;i<n;i++)
    {
        int x;
        cin >> x;
        if (oglindit(x) == primul)
            cout << x << " ";
    }
}
int main()
{
    int n, primul;
    cin >> n >> primul;
    afisare(n, primul);
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
