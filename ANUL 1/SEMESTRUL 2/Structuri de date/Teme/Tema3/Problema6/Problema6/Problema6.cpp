#include <iostream>
#include <fstream>
#include <queue>

struct NOD {
    char info;
    NOD* st = NULL;
    NOD* dr = NULL;
};

struct Arbore {
    NOD* radacina=new NOD;
    int* RSD;
    int* SRD;

    void CitireParcurgeri(int& n)
    {
        std::ifstream f("parcurgeri.in");
        f >> n;
        RSD = new int[n];
        SRD = new int[n];
        for (int i = 0; i < n; i++)
        {
            f >> RSD[i];
        }
        for (int i = 0; i < n; i++)
        {
            f >> SRD[i];
        }
    }

    void RefacereArbore(int n)
    {
        NOD* index=radacina,*nou;
        for (int i = 0; i < n; i++)
        {
            int poz;
            nou = new NOD;
            nou->info= RSD[i];
            for (int j = 0; j < n; j++)
            {
                if (SRD[j] == index->info)
                    poz = j;
            }
            if (j < i)
            {

            }
        }
    }

    void AfisareArbore()
    {
        std::queue<NOD*>c;
        c.push(radacina);
        NOD* index;
        int i = 0, max = 1;
        while (c.empty() == false)
        {
            index = c.front();
            i++;
            std::cout << index->info << " ";
            c.pop();
            if (index->st != NULL)
            {
                c.push(index->st);
            }
            if (index->dr != NULL)
            {
                c.push(index->dr);
            }
            if (i == max)
            {
                std::cout << std::endl;
                max = c.size();
                i = 0;
            }
        }
    }
};

int main()
{
    Arbore A;
    int n;
    A.CitireParcurgeri(n);
    A.RefacereArbore(n);
    A.AfisareArbore();
    return 0;
}
