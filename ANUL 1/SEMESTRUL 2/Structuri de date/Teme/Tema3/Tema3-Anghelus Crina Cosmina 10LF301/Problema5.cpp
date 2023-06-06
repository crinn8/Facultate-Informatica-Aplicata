#include <iostream>
#include <fstream>
#include <string>
#include <queue>

struct NOD {
    char info='-';
    NOD* st=NULL;
    NOD* dr=NULL;
    NOD* p;
};

struct ARBORE_BINAR {
    NOD* radacina=new NOD;

    void IntroducereCaracter(char c,std::string cod)
    {
        NOD* index = radacina;
        for (int i = 1; i < cod.size(); i++)
        {
            if (cod[i] == '0')
            {
                if (index->st != NULL)
                {
                    index = index->st;
                }
                else
                {
                    NOD* nou = new NOD;
                    nou->info = '-';
                    index->st = nou;
                    nou->p = index;
                    index = nou;
                }
            }
            else
            {
                if (index->dr != NULL)
                {
                    index = index->dr;
                }
                else
                {
                    NOD* nou = new NOD;
                    nou->info = '-';
                    index->dr = nou;
                    nou->p = index;
                    index = nou;
                }
            }
        }
        index->info = c;
    }

    void AfisareArbore()
    {
        std::queue<NOD*>c;
        c.push(radacina);
        NOD* index;
        int i=0,max=1;
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
    std::ifstream f("coduri.in");
    ARBORE_BINAR coduri;
    while (!f.eof())
    {
        std::string cod;
        char c;
        f >> c;
        std::getline(f, cod);
        coduri.IntroducereCaracter(c, cod);
    }
    coduri.AfisareArbore();
}
