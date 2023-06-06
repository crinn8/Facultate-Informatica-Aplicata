#include <iostream>
#include <set>

int SumaPatratelorCifrelorUnuiNr(int numar)
{
    int suma = 0;
    while (numar)
    {
        int c;
        c = numar % 10;
        suma += c * c;
        numar /= 10;
    }
    return suma;
}

bool NumarFericit(int numar)
{
    std::set<int> s;
    int ok = 1;
    s.insert(numar);

    while (ok==1) 
    {
        if (numar == 1)
        {
            ok = 0;
            return true;
        }

        numar = SumaPatratelorCifrelorUnuiNr(numar);

        if (s.find(numar) != s.end())
        {
            ok = 0;
            return false;
        }

        s.insert(numar);
    }

    return false;
}

int main()
{
    int numar;
    std::cout << "Introduceti un numar: ";
    std::cin >> numar;
    if (NumarFericit(numar) == true)
    {
        std::cout << "Numarul introdus este un numar fericit." << std::endl;
    }
    else
    {
        std::cout << "Numarul introdus nu este un numar fericit." << std::endl;
    }

    return 0;
}