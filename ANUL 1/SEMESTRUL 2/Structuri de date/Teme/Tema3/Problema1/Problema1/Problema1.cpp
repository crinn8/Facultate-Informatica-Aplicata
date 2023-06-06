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

    void Afisare()
    {
        for (int i = 0; i < liste.size(); i++)
        {
            for (int j = 0; j < liste[i].size(); j++)
            {
                std::cout << liste[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void AfisareDrum(std::vector<int>v, int x, int y)
    {
        std::cout << "Drumul de la " << x << " la " << y << " este:" << std::endl;
        std::stack<int>s;
        int i = y;
        while (i != x)
        {
            s.push(i);
            i = v[i];
        }
        std::cout << "{";
        while (s.empty() == false)
        {
            std::cout << "(" << v[s.top()] << "," << s.top() << ")";
            s.pop();
        }
        std::cout << "}";
    }

    void AfisareLant(std::vector<int>v, int x, int y,GRAF g)
    {
        std::cout << "Lantul de la " << x << " la " << y << " este:" << std::endl;
        std::stack<int>s;
        int i = y;
        while (i != x)
        {
            s.push(i);
            i = v[i];
        }
        std::cout << "{";
        while (s.empty() == false)
        {
            int ok = 0;
            for (int j = 0; j < g.liste[s.top()].size()&&ok==0; j++)
            {
                if (g.liste[s.top()][j] == v[s.top()])
                    ok = 1;
            }
            if (ok == 1)
            {
                std::cout << "(" << s.top() << "," << v[s.top()] << ")";
            }
            else
            {
                std::cout << "(" << v[s.top()] << "," << s.top() << ")";
            }
            s.pop();
        }
        std::cout << "}";
    }

    void Drum(int a,GRAF g)
    {
        int x, y;
        std::cout  << "Introduceti x si y:" << std::endl;
        std::cin >> x >> y;
        std::queue<int>drum;
        std::vector<int>v(nr_noduri, -1);
        drum.push(x);
        v[x] = -2;
        int ok = 0, poz;
        while (drum.empty() == false && ok == 0)
        {
            poz = drum.front();
            drum.pop();
            for (int i = 0; i < liste[poz].size(); i++)
            {
                if (v[liste[poz][i]] == -1)
                {
                    drum.push(liste[poz][i]);
                    v[liste[poz][i]] = poz;
                }
                if (liste[poz][i] == y)
                {
                    ok = 1;
                }
            }
        }
        if (ok == 1)
        {
            if (a == 1)
                AfisareDrum(v, x, y);
            else AfisareLant(v, x, y, g);
        }
        else
        {
            if(a==0)
                std::cout<< "Nu exista lant de la " << x << " la " << y << ".";
            else
              std::cout << "Nu exista drum de la " << x << " la " << y << ".";
        }
    }

    void ConstruireListaAux(GRAF &graf_aux)
    {
        for (int i = 0; i < liste.size(); i++)
        {
            graf_aux.liste.push_back(std::vector<int>());
        }
        for (int i = 0; i < liste.size(); i++)
        {
            for (int j = 0; j < liste[i].size(); j++)
            {
                graf_aux.liste[i].push_back(liste[i][j]);
                int ok = 1;
                for (int k = 0; k < graf_aux.liste[liste[i][j]].size()&&ok==1; k++)
                {
                    if (graf_aux.liste[liste[i][j]][k] == i)
                        ok = 0;
                }
                if (ok == 1)
                    graf_aux.liste[liste[i][j]].push_back(i);
            }
        }
    }

    void ComponenteConexe()
    {
        std::vector <int> comp(nr_noduri);
        std::queue<int>c;
        int nr=1,i=0;
        while (i < liste.size())
        {
            c.push(i);
            comp[i] = nr;
            while (c.empty() == false)
            {
                int nod = c.front();
                c.pop();
                for (int j = 0; j < liste[nod].size(); j++)
                {
                    if (comp[liste[nod][j]] == 0)
                    {
                        c.push(liste[nod][j]);
                        comp[liste[nod][j]] = nr;
                    }
                }
                i++;
            }
            nr++;
        }
        nr--;
        std::cout << "In graful dat exista: " <<nr<<" componente conexe."<<std::endl;
        std::cout << "Acestea sunt: "<<std::endl;

        while (nr)
        {
            std::cout << "{ ";
            for (int i = 0; i < liste.size(); i++)
            {
                if (comp[i] == nr)
                    std::cout << i << " ";
            }
            std::cout << "}"<<std::endl;
            nr--;
        }
    }

};

int main()
{
    GRAF graf,graf_aux;
    int nr_noduri;
    graf.Citire();

    graf_aux.nr_noduri = graf.nr_noduri;
    graf.ConstruireListaAux(graf_aux);

    int a = 1;
    std::cout << "a) ";
    graf.Drum(a, graf);
    std::cout << std::endl;

    a = 0;
    std::cout << "b) ";
    graf_aux.Drum(a, graf);
    std::cout << std::endl;

    std::cout << "c) ";
    graf_aux.ComponenteConexe();
    std::cout << std::endl;

    return 0;
}