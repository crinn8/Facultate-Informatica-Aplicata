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


void ReuniuneVectori(vector<int>v1, vector<int>v2,vector<int>&rezultat)
{
    int i = 0, j = 0, k = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            rezultat.push_back(v1[i]);
            k++;
            i++;
        }
        else
        {
            rezultat.push_back(v2[j]);
            k++;
            j++;
        }
    }
    while (i < v1.size())
    {
        rezultat.push_back(v1[i]);
        k++;
        i++;
    }
    while (j < v2.size())
    {
        rezultat.push_back(v2[j]);
        k++;
        j++;
    }
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
    int n, m; 
    vector<int>v1,v2,rezultat;
    cout << "Introduceti numarul de elemente ale primului vector: ";
    cin >> n;
    cout << endl;
    CitireVector(n, v1);
    cout << "Introduceti numarul de elemente ale celui de al doilea vector: ";
    cin >> m;
    cout << endl;
    CitireVector(m, v2);
    ReuniuneVectori(v1, v2, rezultat);
    AfisareVector(rezultat);
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
