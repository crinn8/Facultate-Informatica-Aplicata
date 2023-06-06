// problema10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <vector>

using namespace std;

void CitireVector(int n, vector<int>& vector)
{
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        vector.push_back(element);
    }
}

void inmultire(int val, vector<int>& vector)
{
    int lg = vector.size();
    int t= vector[lg-1] * val / 10;
    vector[lg-1] = vector[lg-1] * val % 10;
    
    for (int i = lg-2; i >= 0; i--)
    {
        int x;
        x = vector[i] * val + t;
        vector[i] = x % 10;
        t = x/ 10;
    }
    if (t != 0)
    {
        vector.insert(vector.begin(), t);
    }
}

void AfisareVector(vector<int>vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << " ";
    }
}

int main()
{   
    int n,i;
    cout << "Introduceti numarul de cifre al numarului: ";
    cin >> n;
    cout << endl;
    srand((unsigned)time(0));
    i = (rand() % 9) + 1;
    cout <<"Numarul random generat este: "<< i << endl;
    vector<int>vector;
    CitireVector(n,vector);
    inmultire(i, vector);
    AfisareVector(vector);
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
