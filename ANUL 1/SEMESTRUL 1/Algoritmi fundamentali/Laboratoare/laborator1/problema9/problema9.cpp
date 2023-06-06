// problema9.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void formarenumar(int n,int &nou)
{
    int nr = numarcifre(n),n1=0,n2=0,i=nr/2,p=1;
    while (nr>i)
    {
        n1 = n1 * 10 + n % 10;
        n = n / 10;
        nr--;
        p = p * 10;
    } 

    while (nr)
    {
        n2 = n2 * 10 + n % 10;
        n = n / 10;
        nr--;
    }
    nou=  n1 * p + n2; 
}

int main()
{
   int n,nou=0;
   cin >> n;
   formarenumar(n,nou);
   cout << nou;
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
