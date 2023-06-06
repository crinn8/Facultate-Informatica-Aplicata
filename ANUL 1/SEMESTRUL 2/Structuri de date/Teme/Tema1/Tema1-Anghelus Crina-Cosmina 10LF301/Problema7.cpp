#include <iostream>
#include <fstream>

void CitireVector(int &dim, int*& v,int &p)
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

void afisare(int dim, int* nou)
{
    for (int i = 0; i < dim; i++)
    {
        if (nou[i] != -1)
        {
            std::cout << nou[i];
        }
    }
}

void NumarMaximDupaEliminarePCifre(int dim, int* v, int p,int *nou)
{
    int k=0,elim=0,i;
    nou[0] = v[0];
    for (i = 1; i < dim&&elim<p; i++)
    {
        if (v[i] <= nou[k])
        {
            nou[++k] = v[i];
        }
        else
        {
            if (k > 0)
            {
                while (nou[k-1] < v[i] && k>0 && elim < p-1)
                {
                    nou[k] = -1;
                    k--;
                    elim++;
                }
            }
            if (elim <= p)
            {
                nou[k] = v[i];
                elim++;
            }
        }
    }
    while (k < dim-1)
    {
        nou[++k] = v[i++];
    }
}

void ConstruireNou(int dim, int* nou)
{
    for (int i = 0; i < dim; i++)
    {
        nou[i] = -1;
    }
}

int main()
{
    int dim=0,*v=nullptr,p=0;
    CitireVector(dim, v, p);
    if (p >= dim)
    {
        std::cout << "Eroare.";
    }
    else
    {
        int* nou;
        nou = new int[dim]();
        ConstruireNou(dim,nou);
        NumarMaximDupaEliminarePCifre(dim, v, p, nou);
        std::cout << "Cel mai mare numar dupa eliminarea a " << p << " cifre este:";
        afisare(dim-p, nou);
    }
    
    delete[]v;
    return 0;
}
