#include <iostream>
#include <fstream>
#include <list>
#include <unordered_set>

void CitireLista(std::list<float>& L)
{
    std::ifstream f("Lista.in");
    float element;
    while (f >> element)
    {
        L.push_back(element);
    }
}

void StergereDuplicate(std::list<float>& L)
{
    std::unordered_set<float> s;
    std::list<float>::iterator it;

    for (it = L.begin(); it != L.end(); it++)
    {
        if (s.find(*it) != s.end())
        {
            std::list<float>::iterator aux = it;
            it--;
            L.erase(aux);
        }
        else
        {
            s.insert(*it);
        }
    }
}

void AfisareLista(std::list<float> L)
{
    while (L.empty() == false)
    {
        std::cout << L.front() << " ";
        L.pop_front();
    }
}

int main()
{
    std::list<float> L;
    CitireLista(L);

    StergereDuplicate(L);
    AfisareLista(L);

    return 0;
}
