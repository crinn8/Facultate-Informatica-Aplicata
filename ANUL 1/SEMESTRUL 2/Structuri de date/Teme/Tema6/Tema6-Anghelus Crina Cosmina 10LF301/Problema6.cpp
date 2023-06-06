#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>


void Afisare(std::vector<std::vector<std::string>> rezultat)
{
    for (int i = 0; i < rezultat.size(); ++i)
    {
        std::cout << "[";
        int j;
        for (j = 0; j < rezultat[i].size()-1; ++j)
        {
            std::cout << rezultat[i][j] << ", ";
        }
        std::cout << rezultat[i][j];
        std::cout << "]" << std::endl;
    }
}

void Anagrame(std::vector<std::string> cuvinte)
{
    std::map<std::map<char, int>, std::vector<std::string>> m_cuvinte;

    for (std::string s : cuvinte)
    {
        std::map<char, int> cuv;
        std::vector<std::string> list_cuv;
        for (int i = 0; i < s.length(); i++ )
        {
            cuv[s[i]]++;
        }
        auto it = m_cuvinte.find(cuv);
        if (it != m_cuvinte.end())
        {
            it->second.push_back(s);
        }
        else
        {
            list_cuv.push_back(s);
            m_cuvinte.insert({ cuv, list_cuv });
        }
    }

    std::vector<std::vector<std::string>> rezultat;

    for (auto it = m_cuvinte.begin();it != m_cuvinte.end(); ++it)
    {
        rezultat.push_back(it->second);
    }

    Afisare(rezultat);
}

int main()
{
    std::ifstream f("Cuvinte.in");
    std::vector<std::string> cuvinte;
    std::string cuvant;
    while (f >> cuvant)
    {
        cuvinte.push_back(cuvant);
    }

    Anagrame(cuvinte);

    return 0;
}
