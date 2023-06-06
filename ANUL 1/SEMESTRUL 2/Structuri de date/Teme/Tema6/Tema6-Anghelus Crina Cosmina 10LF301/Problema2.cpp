#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

bool Palindrom(std::vector<char>sir)
{
    std::unordered_map<char, int> frecventa;
    for (const auto& i : sir) 
    {
        if (frecventa.find(i) == frecventa.end())
        {
            frecventa[i] = 1;
        }
        else 
        {
            frecventa[i] ++;
        }
    }

    int nr = 0;
    for (auto i = frecventa.begin(); i != frecventa.end(); i++)
    {
        if (i->second % 2 != 0)
        {
            nr++;
        }
        if (nr > 1)
        {
            return false;
        }
    }
    return true;

}

int main()
{
    std::ifstream f("Sir.in");
    std::vector<char>sir;
    char c;
    while (f >> c)
    {
        sir.push_back(c);
    }

    if (Palindrom(sir) == true)
    {
        std::cout << "da";
    }
    else
    {
        std::cout << "nu";
    }

    return 0;
}
