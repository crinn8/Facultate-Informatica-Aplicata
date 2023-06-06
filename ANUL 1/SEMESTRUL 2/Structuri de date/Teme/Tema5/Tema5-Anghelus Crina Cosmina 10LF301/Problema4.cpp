#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include <vector>

class NOD
{
public:
    char color;
    std::string nume;
    int dim;
    int punctaj;
    NOD* st, * dr, * p;

    NOD()
    {
        color = 'r';
        p = st = dr = nullptr;
        dim = 1;
        punctaj = 0;
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
        nil->punctaj = 0;
        nil->dim = 0;
        radacina = nil;
    }

    void Insert(std::string val,int punctaj)
    {
        NOD* z;
        z = new NOD;
        z->nume = val;
        z->punctaj = punctaj;
        NOD* x, * y;
        y = nil;
        x = radacina;
        while (x != nil)
        {
            x->dim++;
            y = x;
            if (z->punctaj < x->punctaj)
            {
                x = x->st;
            }
            else
                if (z->punctaj > x->punctaj)
                {
                    x = x->dr;
                }
            else
                    if (z->punctaj == x->punctaj)
                    {
                        if (z->nume < x->nume)
                        {
                            x = x->st;
                        }
                        else
                        {
                            x = x->dr;
                        }
                    }
        }
        z->p = y;
        if (y == nil)
        {
            radacina = z;
        }
        else
        {
            if (z->punctaj < y->punctaj)
            {
                y->st = z;
            }
            else
                if (z->punctaj > y->punctaj)
                {
                    y->dr = z;
                }
                else
                    if (z->punctaj == y->punctaj)
                    {
                        if (z->nume < y->nume)
                        {
                            y->st = z;
                        }
                        else
                        {
                            y->dr = z;
                        }
                    }
        }
        z->st = nil;
        z->dr = nil;
        if (x != nil)
            x->color = 'r';
        Insert_Repara(z);
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
        y->dim = y->st->dim + y->dr->dim + 1;
        x->dim = x->st->dim + x->dr->dim + 1;
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
        y->dim = y->st->dim + y->dr->dim + 1;
        x->dim = x->st->dim + x->dr->dim + 1;
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
            std::cout << n->nume << " " << n->punctaj << std::endl;
            Preordine(n->st);
            Preordine(n->dr);
        }
    }

    void Inordine(NOD* n)
    {
        if (n != nil)
        {
            Inordine(n->st);
            std::cout << n->nume << " " << n->punctaj << std::endl;
            Inordine(n->dr);
        }
    }

    void Postordine(NOD* n)
    {
        if (n != nil)
        {
            Postordine(n->st);
            Postordine(n->dr);
            std::cout << n->nume << " " << n->punctaj << std::endl;
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

    NOD* MAXIM(NOD* x)
    {
        NOD* index = x;
        while (index->dr != nil)
        {
            index = index->dr;
        }
        return index;
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

    NOD* SEARCH(std::string s,int p)
    {
        NOD* x = radacina;
        while (x != nil && x->punctaj != p)
        {
            if (p < x->punctaj)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
            }
        }

        if (x->punctaj == p)
        {
            while (x->nume != s && x != nil)
            {
                if (s < x->nume)
                {
                    x = x->st;
                }
                else
                {
                    x = x->dr;
                }
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
        NOD* x, * y,*aux;
        color = z->color;
        if (z->st == nil)
        {
            aux = z->p;
            x = z->dr;
            TRANSPLANT(z, x);
        }
        else
        {
            if (z->dr == nil)
            {
                aux = z->p;
                x = z->st;
                TRANSPLANT(z, x);
            }
            else
            {
                y = SUCCESOR(z);
                aux = y->p;
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
                y->dim = z->dim-1;
            }
        }

        while (aux != radacina->p)
        {
            aux->dim--;
            aux = aux->p;
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

    int RANG(NOD* x)
    {
        int rang;
        NOD* y;
        rang = x->st->dim + 1;
        while (x != radacina)
        {
            y = x->p;
            if (x == y->dr)
            {
                rang = rang + y->st->dim + 1;
            }
            x = y;
        }
        return rang;
    }

    NOD* SELECT(int i)
    {
        int rang;
        NOD* x;
        x = radacina;
        while (x != nil)
        {
            rang = x->st->dim + 1;
            if (i == rang)
            {
                return x;
            }
            if (i < rang)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
                i = i - rang;
            }
        }
        return x;
    }

    int PersoaneInterval(int li,int ls)
    {
        int nr_pers = 0;
        NOD* index = radacina;
        while (index != nil)
        {
            if (index->punctaj < li)
            {
                index = index->dr;
            }

            if (index->punctaj > ls)
            {
                index = index->st;
            }

        }
        return nr_pers;
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
        std::cout << index->nume<<"-"<<index->punctaj<<" "<<index->dim<<" "<<index->color;
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

void Meniu(ARN arb)
{
    int x;
    do
    {
        std::cout << std::endl;
        std::cout << "Introduceti optiunea: " << std::endl;
        std::cout << "0 pentru iesirea din program." << std::endl;
        std::cout << "1 pentru afisarea listei elevilor in ordinea punctajului primit." << std::endl;
        std::cout << "2 pentru a determina pozitia unui elev in clasament." << std::endl;
        std::cout << "3 pentru a afla cine se afla pe o anumita pozitie in clasament." << std::endl;
        std::cout << "4 pentru a introduce elevi." << std::endl;
        std::cout << "5 pentru a sterge elevi." << std::endl;
        std::cout << "6 pentru a determina numarul de elevi cu punctajul intr-un anumit interval." << std::endl;

        std::cin >> x;
        switch (x)
        {
        case 1:
        {
            std::cout << "Lista elevilor in ordinea punctajului primit:" << std::endl;
            arb.PRINT_TREE(2);
            break;
        }
        case 2:
        {
            std::string n;
            int p;
            NOD* y;
            std::cout << "Introduceti numele: " << std::endl;
            std::cin >> n;
            std::cout << "Introduceti punctajul: ";
            std::cin >> p;
            y = arb.SEARCH(n,p);
            if (y != arb.nil)
            {
                std::cout << "Elevul " << n << " se afla pe pozitia " << arb.RANG(y)<<" in clasament." << std::endl;
            }
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 3:
        {
            int poz;
            NOD* y;
            std::cout << "Introduceti pozitia: ";
            std::cin >> poz;
            y = arb.SELECT(poz);
            std::cout << "Pe pozitia " << poz << " se afla elevul " << y->nume<<"."<<std::endl;
            break;
        }
        case 4:
        {
            int p;
            std::string n;
            std::cout << "Introduceti numele: ";
            std::cin >> n;
            std::cout << "Introduceti punctajul: ";
            std::cin >> p;
            arb.Insert(n, p);
            break;
        }
        case 5:
        {
            int p;
            std::string n;
            std::cout << "Introduceti numele: ";
            std::cin >> n;
            std::cout << "Introduceti punctajul: ";
            std::cin >> p;
            NOD* y;
            y = arb.SEARCH(n, p);
            if (y != arb.nil)
            {
                arb.DELETE(y);
            }
            else
            {
                std::cout << "Elevul introdus nu exista in lista." << std::endl;
            }
            break;
        }
        case 6:
        {
            int li,ls;
            std::cout << "Introduceti intervalul: ";
            std::cin >> li >> ls;
            std::cout << "Numarul de persoane din intervalul (" << li << "," << ls << ") este: " << arb.PersoaneInterval(li, ls);
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            std::cout << "Introduceti 1,2,3,4,5,6,7,8 sau 0." << std::endl;
            break;
        }
        }
    } while (x != 0);
}


int main()
{
    ARN arb;
    std::ifstream f("ArboreS.in");
    int p;
    char c;
    std::string s;

    while (!f.eof())
    {
        f >> p;
        f >> c;
        std::getline(f, s);
        arb.Insert(s, p);
    }

    Meniu(arb);

    return 0;
}
