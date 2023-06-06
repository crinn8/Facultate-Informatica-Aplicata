#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <string>

struct INTERVAL
{
    int li;
    int ls;

    bool Intersectie(INTERVAL x)
    {
        if ((li >= x.li && ls <= x.ls) || (x.li >= li && x.ls <= ls))
            return true;
        return false;
    }

    bool Egale(INTERVAL x)
    {
        if (li == x.li && ls == x.ls)
            return true;
        return false;
    }
};

class NOD
{
public:
    char color;
    INTERVAL interval;
    NOD* st, * dr, * p;
    int maxi;
    std::string zi;

    NOD()
    {
        interval.li = 0;
        interval.ls = 0;
        color = 'r';
        p = st = dr = nullptr;
        maxi = 0;
    }
};

class ARN
{
public:
    NOD* radacina;
    NOD* nil;
    ARN()
    {
        nil = new NOD;
        nil->color = 'n';
        nil->p = nil;
        nil->st = nil->dr = nil;
        radacina = nil;
    }

    void CONSTRUCT(std::vector<INTERVAL> v1,std::vector<std::string> v2)
    {
        for (int i = 0; i < v1.size(); i++)
        {
            Insert(v1[i],v2[i]);
        }
    }

    void Insert(INTERVAL val,std::string n)
    {
        NOD* z;
        z = new NOD;
        z->interval = val;
        z->zi = n;
        NOD* x, * y;
        y = nil;
        x = radacina;
        while (x != nil)
        {
            y = x;
            if (z->interval.li < x->interval.li)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
            }
        }
        z->p = y;
        if (y == nil)
        {
            radacina = z;
        }
        else
        {
            if (z->interval.li < y->interval.li)
            {
                y->st = z;
            }
            else
            {
                y->dr = z;
            }
        }
        z->st = nil;
        z->dr = nil;
        if (x != nil)
            x->color = 'r';
        Insert_Repara(z);

        z->maxi = std::max(z->dr->maxi, z->interval.ls);
    }

    void RotatieSt(NOD* y)
    {
        NOD* x;
        x = y->dr;
        y->dr = x->st;
        if (x->st != nil)
        {
            x->st->p = y;
        }
        x->p = y->p;
        if (y->p == nil)
        {
            radacina = x;
        }
        else if (y == y->p->st)
        {
            y->p->st = x;
        }
        else
        {
            y->p->dr = x;
        }
        x->st = y;
        y->p = x;
    }

    void RotatieDr(NOD* y)
    {
        NOD* x;
        x = y->st;
        y->st = x->dr;
        if (x->dr != nil)
        {
            x->dr->p = y;
        }
        x->p = y->p;
        if (y->p == nil)
        {
            radacina = x;
        }
        else
        {
            if (y == y->p->dr)
            {
                y->p->dr = x;
            }
            else
            {
                y->p->st = x;
            }
        }
        x->dr = y;
        y->p = x;
    }

    void Insert_Repara(NOD* z)
    {
        while ((z->p->color == 'r'))
        {
            if (z->p == z->p->p->st)
            {
                NOD* U;
                U = z->p->p->dr;

                if (U != nil && U->color == 'r')
                {
                    z->p->color = 'n';
                    U->color = 'n';
                    z->p->p->color = 'r';
                    z = z->p->p;
                }
                else
                {
                    if (z == z->p->dr)
                    {
                        z = z->p;
                        RotatieSt(z);
                    }
                    z->p->color = 'n';
                    z->p->p->color = 'r';
                    RotatieDr(z->p->p);
                }
            }
            else
                if (z->p == z->p->p->dr)
                {
                    NOD* U;
                    U = z->p->p->st;
                    if (U != nil && U->color == 'r')
                    {
                        z->p->color = 'n';
                        U->color = 'n';
                        z->p->p->color = 'r';
                        z = z->p->p;
                    }
                    else
                    {
                        if (z == z->p->st)
                        {
                            z = z->p;
                            RotatieDr(z);
                        }
                        z->p->color = 'n';
                        z->p->p->color = 'r';
                        RotatieSt(z->p->p);
                    }
                }
        }
        radacina->color = 'n';
    }

    void Preordine(NOD* n)
    {
        if (n != nil)
        {
            std::cout <<"(" <<n->interval.li << ","<<n->interval.ls<<") "<< n->color << std::endl;
            Preordine(n->st);
            Preordine(n->dr);
        }
    }

    void Inordine(NOD* n)
    {
        if (n != nil)
        {
            Inordine(n->st);
            std::cout << "(" << n->interval.li << "," << n->interval.ls << ") " << n->color << std::endl;
            Inordine(n->dr);
        }
    }

    void Postordine(NOD* n)
    {
        if (n != nil)
        {
            Postordine(n->st);
            Postordine(n->dr);
            std::cout << "(" << n->interval.li << "," << n->interval.ls << ") " << n->color << std::endl;
        }
    }

    void PRINT_TREE(int opt)
    {
        NOD* n;
        n = radacina;
        if (opt == 1)
        {
            Preordine(n);
        }
        else
            if (opt == 2)
            {
                Inordine(n);
            }
            else
            {
                Postordine(n);
            }
    }

    bool EMPTY()
    {
        if (radacina == nil)
            return true;
        return false;
    }

    NOD* MINIM(NOD* x)
    {
        NOD* index = x;
        while (index->st != nil)
        {
            index = index->st;
        }
        return index;
    }

    NOD* MAXIM(NOD* x)
    {
        NOD* index = x;
        while (index->dr != nil)
        {
            index = index->dr;
        }
        return index;
    }

    NOD* SUCCESOR(NOD* x)
    {
        NOD* index;
        if (x->dr != nil)
        {
            index = MINIM(x->dr);
        }
        else
        {
            index = x->p;
            while (index != nil && x == index->dr)
            {
                x = index;
                index = index->p;
            }
        }
        return index;
    }

    NOD* PREDECESOR(NOD* x)
    {
        NOD* index;
        if (x->st != nil)
        {
            index = MAXIM(x->st);
        }
        else
        {
            index = x->p;
            while (index != nil && x == index->st)
            {
                x = index;
                index = index->p;
            }
        }
        return index;
    }

    NOD* SEARCH(INTERVAL i)
    {
        NOD* x = radacina; 
        while (x != nil&&i.Intersectie(x->interval)==false)
        {
            if (x->st!=nil&&i.li<=x->st->maxi)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
            }
        }
        return x;
    }

    NOD* SEARCH_I(INTERVAL i,std::string n)
    {
        NOD* x = radacina;
        while (x!=nil && i.Egale(x->interval) == false)
        {
            if (i.li < x->interval.li)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
            }
        }
        return x;
    }

    void TRANSPLANT(NOD* u, NOD* v)
    {
        if (u->p == nil)
        {
            radacina = v;
        }
        else
        {
            if (u == u->p->st)
            {
                u->p->st = v;
            }
            else
            {
                u->p->dr = v;
            }
        }
        v->p = u->p;
    }

    void DELETE_REPARA(NOD* x)
    {
        NOD* F;
        while (x != radacina && x->color == 'n')
        {
            if (x == x->p->st)
            {
                F = x->p->dr;
                if (F->color == 'r')
                {
                    F->color = 'n';
                    x->p->color = 'r';
                    RotatieSt(x->p);
                    F = x->p->dr;
                }
                if (F->st->color == 'n' && F->dr->color == 'n')
                {
                    F->color = 'r';
                    x = x->p;
                }
                else
                {
                    if (F->dr->color == 'n')
                    {
                        F->st->color = 'n';
                        F->color = 'r';
                        RotatieDr(F);
                        F = x->p->dr;
                    }
                    F->color = x->p->color;
                    x->p->color = 'n';
                    F->dr->color = 'n';
                    RotatieSt(x->p);
                    x = radacina;
                }

            }
            else
                if (x == x->p->dr)
                {
                    F = x->p->st;
                    if (F->color == 'r')
                    {
                        F->color = 'n';
                        x->p->color = 'r';
                        RotatieDr(x->p);
                        F = x->p->st;
                    }
                    if (F->dr->color == 'n' && F->st->color == 'n')
                    {
                        F->color = 'r';
                        x = x->p;
                    }
                    else
                    {
                        if (F->st->color == 'n')
                        {
                            F->dr->color = 'n';
                            F->color = 'r';
                            RotatieSt(F);
                            F = x->p->st;
                        }
                        F->color = x->p->color;
                        x->p->color = 'n';
                        F->st->color = 'n';
                        RotatieDr(x->p);
                        x = radacina;
                    }
                }
        }
        x->color = 'n';
    }

    void DELETE(NOD* z)
    {
        char color;
        NOD* x, * y;
        color = z->color;
        if (z->st == nil)
        {
            x = z->dr;
            TRANSPLANT(z, x);
        }
        else
        {
            if (z->dr == nil)
            {
                x = z->st;
                TRANSPLANT(z, x);
            }
            else
            {
                y = SUCCESOR(z);
                color = y->color;
                x = y->dr;
                if (y->p == z)
                {
                    x->p = y;
                }
                else
                {
                    TRANSPLANT(y, x);
                    y->dr = z->dr;
                    z->dr->p = y;
                }
                TRANSPLANT(z, y);
                y->st = z->st;
                z->st->p = y;
                y->color = z->color;
            }
        }
        if (color == 'n')
            DELETE_REPARA(x);
    }

    void CLEAR()
    {
        while (EMPTY() == false)
        {
            DELETE(radacina);
        }
    }

};

void AfisareArbore(ARN arb)
{
    std::queue<NOD*>c;
    c.push(arb.radacina);
    NOD* index;
    int i = 0, max = 1;
    while (c.empty() == false)
    {
        index = c.front();
        i++;
        std::cout <<"("<< index->interval.li<<","<<index->interval.ls<<") ";
        std::cout << " ";
        c.pop();
        if (index->st != arb.nil)
        {
            c.push(index->st);
        }
        if (index->dr != arb.nil)
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

NOD* Propunere_Programare(ARN arb,INTERVAL vaccin)
{
    std::cout << "Propunerea pentru vaccinare este: ";
    NOD* aux=arb.SEARCH(vaccin);
    return aux;
}

void Meniu(ARN arb)
{
    int x;
    do
    {
        std::cout << std::endl;
        std::cout << "Introduceti optiunea: " << std::endl;
        std::cout << "0 pentru iesirea din program." << std::endl;
        std::cout << "1 pentru a primi o propunere pentru vaccinare." << std::endl;
        std::cout << "2 pentru a introduce un interval." << std::endl;
        std::cout << "3 pentru a sterge un interval." << std::endl;
        std::cout << "4 pentru a afisa arborele." << std::endl;

        std::cin >> x;
        switch (x)
        {
        case 1:
        {
            std::cout << "Introduceti intervalul dorit:";
            INTERVAL vaccin;
            std::cin >> vaccin.li >> vaccin.ls;
            NOD* propunere = Propunere_Programare(arb, vaccin);
            std::cout << propunere->zi << " " << "(" << propunere->interval.li << "," << propunere->interval.ls << ").";
            break;
        }
        case 2:
        {
            std::string n;
            INTERVAL i;
            NOD* y;
            std::cout << "Introduceti intervalul dorit:";
            std::cin >> i.li >> i.ls;
            std::cout << "Introduceti ziua: ";
            std::cin >> n;
            arb.Insert(i, n);
            break;
        }
        case 3:
        {
            INTERVAL i;
            NOD* y;
            std::string n;
            std::cout << "Introduceti intervalul dorit:";
            std::cin >> i.li >> i.ls;
            std::cout << "Introduceti ziua: ";
            std::cin >> n;
            y = arb.SEARCH_I(i,n);
            if (y != arb.nil)
            {
                arb.DELETE(y);
            }
            else
                std::cout << "Intervalul cautat nu exista nu exista." << std::endl;
            break;
        }
        case 4:
        {
            AfisareArbore(arb);
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            std::cout << "Introduceti 1,2,3,4 sau 0." << std::endl;
            break;
        }
        }
    } while (x != 0);
}

int main()
{
    ARN arb;
    std::ifstream f("ArboreIntervale.in");
    INTERVAL x;
    std::vector <INTERVAL> v1;
    std::vector <std::string> v2;

    std::string n;
    char c;
    while (!f.eof())
    {
        f >> x.li >> x.ls;
        f >> c;
        std::getline(f, n);
        v1.push_back(x);
        v2.push_back(n);
    }
    arb.CONSTRUCT(v1,v2);

    Meniu(arb);

    return 0;
}
