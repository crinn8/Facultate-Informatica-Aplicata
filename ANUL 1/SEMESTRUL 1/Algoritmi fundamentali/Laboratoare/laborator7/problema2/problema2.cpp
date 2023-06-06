// problema2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void CitireVector(vector <int>& vec)
{
    ifstream f("date.in");
    int element, dim;
    f >> dim;
    for (int i = 0; i < dim; i++)
    {
        f >> element;
        vec.push_back(element);
    }
}

void AfisareVector(vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void Calcul(vector <int>vec,int st,int dr,int k,int ok)
{
    int pivot = vec[st],i=st;
    swap(vec[st], vec[dr - 1]);
    for (int j = st; j < dr - 1; j++)
    {
        if (vec[j] < pivot)
        {
            swap(vec[i], vec[j]);
            i++;
        }
    }
    swap(vec[i], vec[dr-1]);
    if (ok == 1)
    {
        if (vec.size()- k > i)
            Calcul(vec, i+1 , dr, k,ok);
        else
            if (vec.size()- k < i)
                Calcul(vec, st, i, k, ok);
            else cout << vec[i] << " ";
    }
    else
    {
        if ( k > i+1)
            Calcul(vec, i + 1, dr - 1, k,ok);
        else
            if (k < i+1)
                Calcul(vec, st, i, k,ok);
            else cout << vec[i] << " ";
    }
}

int main()
{
    vector <int>vec;
    CitireVector(vec);
    int st = 0, dr = vec.size(), k,ok;
    cout << "Introduceti 1 pentru cel mai mare al k-ulea element sau 0 pentru cel mai mic al k-ulea element: ";
    cin >> ok;
    cout << endl;
    cout << "Introduceti valoarea lui k: ";
    cin >> k;
    Calcul(vec, st, dr, k,ok);
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
