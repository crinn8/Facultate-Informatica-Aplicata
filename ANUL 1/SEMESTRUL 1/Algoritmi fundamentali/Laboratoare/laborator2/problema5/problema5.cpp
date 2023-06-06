// problema4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void CitireVector(int n, vector<int>& v)
{
    cout << "Introduceti elementele vectorului: ";
    int element;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        v.push_back(element);
    }
    cout << endl;
}

void stergere(int p, vector<int>& v)
{
    for (int i = p; i < v.size()-1; i++)
    {
        v[i] = v[i + 1];
    }
    v.pop_back(); 
}

void inserare(int p, vector<int>& v)
{
    v.insert(v.begin(), p);
}

void calcul(vector<int>&v)
{
    int p;
    cout << "Introduceti indicele de pozitie: ";
    cin >> p;
    cout << endl;
    stergere(p, v);
    inserare(p, v);
}

void AfisareVector(vector<int>v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int n;
    vector<int>v;
    cout << "Introduceti numarul de elemente ale vectorului: ";
    cin >> n;
    cout << endl;
    CitireVector(n, v);
    calcul(v);
    AfisareVector(v);
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
