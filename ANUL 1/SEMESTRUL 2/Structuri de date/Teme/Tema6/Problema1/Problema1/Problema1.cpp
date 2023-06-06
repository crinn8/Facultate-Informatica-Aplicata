#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <string>

template <class Key, class Value>

class HashTable
{
    std::list<std::pair<Key, Value>>* items;
    int m;
public:

    void Set_m(int nr)
    {
        m = nr;
    }

    int Get_m()
    {
        return m;
    }

    std::list<std::pair<Key, Value>>* Get_items()
    {
        return items;
    }

    HashTable(int b)
    {
        this->m = b;
        items = new std::list<std::pair<Key, Value>>[m];
    }

    void INSERT(std::pair<Key, Value> element)
    {
        int p = element.second % m;
        items[p].push_back(element);
    }

    bool SEARCH(Value element)
    {
        Value p = element % m;
        for (std::pair<Key, Value> it : items[p])
        {
            if (it.second == element)
            {
                return true;
            }
        }
        return false;
    }

    void INSERT_S(std::pair<Key, std::string>element)
    {
        unsigned int len = element.second.size();
        unsigned int p = 0;
        for (int i = 0; i < len; i++)
        {
            p += int(element.second[i]);
        }
        p %= 10;
        items[p].push_back(element);
    }

    bool SEARCH_S(std::string k)
    {
        unsigned int len = k.size();
        unsigned int p = 0;
        for (int i = 0; i < len; i++)
        {
            p += k[i];
        }
        p %= 10;
        for (std::pair<Key, std::string> it : items[p])
        {
            if (it.second == k)
            {
                return true;
            }
        }
        return false;
    }

    void AfisareLista()
    {
        for (int i = 0; i<m; i++)
        {
            for (std::pair<Key, Value> it : items[i])
            {
                std::cout <<it.second << std::endl;
            }
        }
    }

    std::pair<Key, Value> operator[](int poz)
     {
        std::pair<Key, Value> element = items[poz];
        return element;
     }

     HashTable operator=(std::pair<Key,Value> element)
     {
         INSERT(element);
     }

};

void SolutieNumere()
{
    std::ifstream f("Numere.in");
    HashTable<int, int> T(11);
    int n, m;
    f >> n;
    T.Set_m(11);
    int x, i = 0;

    while (f >> x)
    {
        std::pair<int, int> y;
        y.first = i;
        y.second = x;
        T.INSERT(y);
        i++;
    }
    std::pair<int, int> y;
    y.first = 100;
    y.second = 200;
    T[5] = y;

    T.AfisareLista();
    std::cout << std::endl;
    
}

void SolutieCuvinte()
{
    std::ifstream f("Cuvinte.in");
    HashTable<int, std::string> T(11);
    int n, m;
    f >> n;
    f.get();
    T.Set_m(11);
    int  i = 0;

    while (i < n)
    {
        std::string x;
        std::getline(f, x);
        std::pair<int, std::string>y;
        y.first = i;
        y.second = x;
        T.INSERT_S(y);
        i++;
    }

    T.AfisareLista();
    std::cout << std::endl;

}

int main()
{
    SolutieNumere();
    SolutieCuvinte();

    return 0;
}
