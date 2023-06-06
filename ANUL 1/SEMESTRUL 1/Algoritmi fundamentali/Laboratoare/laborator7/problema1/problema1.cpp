// problema1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum
{
    SortareDupaElemente, SortareDupaIndex
};

void CitireVector(vector <int> &vec)
{
    ifstream f("date.in");
    int element,dim;
    f >> dim;
    for (int i = 0; i < dim; i++)
    {
        f >> element;
        vec.push_back(element);
    }
}
//construim un vector de perechi (element,pozitie)
vector <pair<int,int>> VectorPerechi(vector <int> vec)
{
    vector <pair<int, int>> perechi;
    perechi.resize(vec.size());
    for (int i = 0; i < vec.size(); i++)
        perechi[i] = make_pair(vec[i], i);
    return perechi;
}

bool comparator(pair<int,int>p1, pair<int, int> p2,int tip_sort)
{
    if (tip_sort == SortareDupaElemente)
        return p1.first <= p2.first;
    else 
        if(tip_sort==SortareDupaIndex)
           return p1.second < p2.second;
}

void Interclasare(vector <pair<int, int>> &perechi, int st, int mij, int dr, int tip_sort)
{
    vector <pair<int, int>> perechi1;
    perechi1.resize(dr - st + 1);
    int i = st, j = mij + 1,k=0;
    while (i <= mij && j <= dr)
    {
        if (comparator(perechi[i], perechi[j], tip_sort))
            perechi1[k] = perechi[i++];
        else
            perechi1[k] = perechi[j++];
        k++;
    }
    while(i<=mij)
        perechi1[k++] = perechi[i++];
    while(j<=dr)
        perechi1[k++] = perechi[j++];
    for (i = st,j=0; i < st+k ; i++,j++)
        perechi[i] = perechi1[j];
}

void MergeSort(vector <pair<int, int>> &perechi,int st,int dr,int tip_sort)
{
    if (st < dr)
    {
        int mij = (st + dr) / 2;
        MergeSort(perechi, st, mij, tip_sort);
        MergeSort(perechi, mij+1, dr, tip_sort);
        Interclasare(perechi, st, mij, dr, tip_sort);
    }
}

void AfisareVector(vector <pair<int, int>> perechi)
{
    for (int i = 0; i < perechi.size(); i++)
        cout << perechi[i].first << " ";
}

void EliminareDuplicate(vector <pair<int, int>> &perechi)
{
    for (int i = 0; i < perechi.size()-1; i++)
        while (perechi[i + 1].first == perechi[i].first)
            perechi.erase(perechi.begin() + i + 1);
}

int main()
{
    vector <int>vec;
    CitireVector(vec);
    vector<pair<int, int>> perechi;
    perechi = VectorPerechi(vec);
    MergeSort(perechi, 0, perechi.size() - 1, SortareDupaElemente);
    EliminareDuplicate(perechi);
    MergeSort(perechi, 0, perechi.size() - 1, SortareDupaIndex);
    AfisareVector(perechi);
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
