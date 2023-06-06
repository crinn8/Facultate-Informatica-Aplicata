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

void DeplasareElemente(vector<int>& vector)
{
    int k;
    cout << "Introduceti numarul de pozitii: ";
    cin >> k;
    cout << endl;
    while (k)
    {
        vector.insert(vector.begin(), 0);
        k--;
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
