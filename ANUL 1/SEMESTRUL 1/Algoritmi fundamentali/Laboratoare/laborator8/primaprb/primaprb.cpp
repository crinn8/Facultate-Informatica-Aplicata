// primaprb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int numarator, numitor;
    cin >> numarator>>numitor;
    if (numitor == 0||numarator==0)
    {
        cout << "Prb nu are pas de rezolvare";
        return 0;
    }
    if (numarator % numitor == 0)
    {
        cout << numarator / numitor;
        return 0;
   }
    if (numarator == 1)
    {
        cout << numarator / numitor;
        return 0;
    }
    if (numarator > numitor)
    {
        cout << numarator / numitor << "+";
        numarator = numarator % numitor;
    }
    while (numarator > 0)
    {
        if (numitor % numarator == 0)
        {
            cout << "1/" << numitor / numarator;
            return 0;
        }
        long long int nrMax = (numitor / numarator) + 1;
        cout << "1/" << nrMax << "+";
        numarator = numarator * nrMax - numitor;
        numitor = numitor * nrMax;
    }
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
