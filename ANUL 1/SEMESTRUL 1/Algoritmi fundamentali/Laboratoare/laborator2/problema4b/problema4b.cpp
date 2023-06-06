// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void CitireVector(int n, vector<int>& vector)
{
    cout << "Introduceti elementele vectorului: ";
    int element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        vector.push_back(element);
    }
    cout << endl;
}

void inserare(int k, vector<int>&vector)
{
   for(int i=1;i<=k;i++) 
    {
        vector.insert(vector.begin(), vector[vector.size()-i]);
    }
}

void stergere(int k, vector<int>& vector)
{
    for (int i = 0; i < k; i++)
    {
        vector.pop_back();
    }
}

void DeplasareElemente(vector<int>& vector)
{
    int k;
    cout << "Introduceti numarul de pozitii: ";
    cin >> k;
    cout << endl;
    inserare(k, vector);
    stergere(k, vector);
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
    int n;
    vector<int>vector;
    cout << "Introduceti numarul de elemente ale vectorului: ";
    cin >> n;
    cout << endl;
    CitireVector(n, vector);
    DeplasareElemente(vector);
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
