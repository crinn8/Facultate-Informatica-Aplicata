#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

class GRAF {
public:
    int nr_noduri;
    std::vector<int> excentritate;
    std::vector<std::vector<int>>liste;

    void Citire()
    {
        std::ifstream f("graf.in");
        f >> nr_noduri;
        f.get();
        for (int i = 0; i < nr_noduri; i++)
        {
            liste.push_back(std::vector<int>());
            std::string c;
            std::getline(f, c);
            int index = 0, nr;
            if (c != "-")
            {
                while (index < c.size())
                {
                    nr = 0;
                    while (c[index] != ' ' && index < c.size())
                    {
                        nr = nr * 10 + int(c[index] - '0');
                        index++;
                    }
                    index++;
                    liste[i].push_back(nr);
                }
            }
        }
    }

    bool VerificareGrafConex()
    {
        std::queue<int>c;
        std::vector<int>v(nr_noduri, -1);
        c.push(0);
        v[0] = 1;
        int ok = 0, poz;
        while (c.empty() == false)
        {
            poz = c.front();
            c.pop();
            for (int i = 0; i < liste[poz].size(); i++)
            {
                if (v[liste[poz][i]] == -1)
                {
                    c.push(liste[poz][i]);
                    v[liste[poz][i]] = poz;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
            if (v[i] == -1)
                return false;
        return true;
    }

    int Lant(int x, int y)
    {
        std::queue<int>lant;
        std::vector<int>v(nr_noduri, -1);
        lant.push(x);
        v[x] = -2;
        int ok = 0, poz;
        while (lant.empty() == false && ok == 0)
        {
            poz = lant.front();
            lant.pop();
            for (int i = 0; i < liste[poz].size(); i++)
            {
                if (v[liste[poz][i]] == -1)
                {
                    lant.push(liste[poz][i]);
                    v[liste[poz][i]] = poz;
                }
                if (liste[poz][i] == y)
                {
                    ok = 1;
                }
            }
        }
        int lg = 0, i = y;
        while (i != x)
        {
            lg++;
            i = v[i];
        }
        return lg;
    }

    void Excentritate()
    {
        for (int i = 0; i < nr_noduri; i++)
        {
            excentritate.push_back(0);
        }
        for (int i = 0; i < liste.size(); i++)
        {
            int mx = 0,poz=0;
            for (int j = i+1; j < liste.size(); j++)
            {
                int lg = Lant(i, j);
                if (lg > mx)
                {
                    mx = lg;
                    poz = j;
                }
                if (lg > excentritate[j])
                {
                    excentritate[j] = lg;
                }
            }
            if (mx > excentritate[i])
            {
                excentritate[i] = mx;
            }
        }
    }

    int Diametru()
    {
        int diametru = 0;
        for (int i = 0; i < nr_noduri; i++)
        {
            if (excentritate[i] > diametru)
            {
                diametru = excentritate[i];
            }
        }
        return diametru;
    }

    int Raza()
    {
        int raza = nr_noduri;
        for (int i = 0; i < nr_noduri; i++)
        {
            if (excentritate[i] < raza)
            {
                raza = excentritate[i];
            }
        }
        return raza;
    }
};

int main()
{
    GRAF graf;
    graf.Citire();
    int x, y;
    if (graf.VerificareGrafConex() == false)
    {
        std::cout << "Graful nu este conex.";
    }
    else
    {
        graf.Excentritate();
        std::cout << "Diametrul grafului este: " << graf.Diametru()<<std::endl;
        std::cout << "Raza grafului este: " << graf.Raza() << std::endl;
    }
}