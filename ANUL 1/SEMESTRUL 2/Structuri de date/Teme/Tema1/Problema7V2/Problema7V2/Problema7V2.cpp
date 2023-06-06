#include <iostream>
#include <fstream>
#include <stack>

void CitireVector(int& dim, int*& v, int &p)
{
    std::ifstream f("numar.in");
    f >> dim >> p;
    v = new int[dim]();
    for (int i = 0; i < dim; i++)
    {
        f >> v[i];
    }
    f.close();
}

void afisare(int dim, std::stack<int> nou)
{
    int* rez,i=dim-1;
    rez = new int[dim]();
    while (nou.empty() == false)
    {
        rez[i] = nou.top();
        nou.pop();
        i--;
    }
    for (i = 0; i < dim; i++)
    {
        std::cout << rez[i];
    }
}

void NumarMaximDupaEliminarePCifre(int dim, int* v, int p, std::stack<int>& nou)
{
    int elim = 0, i;
    nou.push(v[0]);
    for (i = 1; i < dim && elim < p; i++)
    {
        if (v[i] <= nou.top())
        {
            nou.push(v[i]);
        }
        else
        {
            while (nou.empty() == false&&nou.top()<v[i]&&elim<p)
            {
                nou.pop();
                elim++;
            }
            nou.push(v[i]);
        }
    }
    while (i < dim )
    {
        nou.push(v[i]);
        i++;
    }
    while (elim < p)
    {
        nou.pop();
        elim++;
    }
}

int main()
{
    int dim = 0, * v = nullptr, p = 0;
    CitireVector(dim, v, p);
    for (int i = 0; i < dim; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    if (p >= dim)
    {
        std::cout << "Eroare.";
    }
    else
    {
        std::stack<int> nou;
        NumarMaximDupaEliminarePCifre(dim, v, p, nou);
        std::cout << "Cel mai mare numar dupa eliminarea a " << p << " cifre este:";
        afisare(dim - p, nou);
    }

    delete[]v;
    return 0;
}
