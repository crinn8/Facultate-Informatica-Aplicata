#include <iostream>
#include <set>
#include <fstream>

class myComparator
{
public:
    bool operator()(int a, int b) const
    {
        return b < a;
    }
};

void AfisareSecventa(std::set <int> secventa_c, std::set <int, myComparator> secventa_d)
{
    for (auto& element : secventa_c)
    {
        std::cout << element << " ";
    }

    for (auto& element : secventa_d)
    {
        std::cout << element << " ";
    }
}

void Operatii(std::set <int> secventa_c, std::set <int, myComparator> secventa_d)
{
    int k,val;
    std::cout << "Introduceti numarul de operatii: ";
    std::cin >> k;
    std::cout << std::endl;
    while (k)
    {
        std::cout << "Introduceti o valoare: ";
        std::cin >> val;
        std::cout << std::endl;
        auto poz = secventa_c.find(val);
        if (poz!=secventa_c.end())
        {
            auto it = secventa_c.end();
            it--;
           if (*poz != *it)
            {
                auto poz2 = secventa_d.find(val);
                if (poz2 == secventa_d.end())
                {
                    secventa_d.insert(val);
                    std::cout << "Valoarea " << val << " a fost introdusa in secventa." << std::endl;
                    std::cout << "Secventa este:" << std::endl;
                    AfisareSecventa(secventa_c, secventa_d);
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Valoarea " << val << " nu poate fi introdusa in secventa." << std::endl;
                }
            }
            else
            {
               std::cout << "Valoarea " << val << " nu poate fi introdusa in secventa." << std::endl;
            }
        }
        else
        {
            secventa_c.insert(val);
            std::cout << "Secventa este:" << std::endl;
            AfisareSecventa(secventa_c, secventa_d);
            std::cout << std::endl;
        }
        k--;
    }
}

void Citire(std::set <int> &secventa_c, std::set <int, myComparator> &secventa_d)
{
    std::ifstream f("secventa.in");
    int x, y;
    f >> x;
    secventa_c.insert(x);
    while (!f.eof())
    {
        f >> y;
        while (y > x && !f.eof())
        {
            secventa_c.insert(y);
            x = y;
            f >> y;
        }

        while (y < x && !f.eof())
        {
            secventa_d.insert(y);
            x = y;
            f >> y;
        }
        secventa_d.insert(y);
    }
}

int main()
{
    std::set <int> secventa_c;
    std::set <int, myComparator> secventa_d;
    Citire(secventa_c, secventa_d);
    Operatii(secventa_c, secventa_d);

    return 0;
}