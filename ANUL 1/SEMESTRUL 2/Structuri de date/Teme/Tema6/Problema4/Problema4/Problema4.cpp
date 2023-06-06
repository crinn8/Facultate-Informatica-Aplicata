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

    std::unordered_set<float> s(L.begin(), L.end());
    L.assign(s.begin(), s.end());

    AfisareLista(L);

    return 0;
}
