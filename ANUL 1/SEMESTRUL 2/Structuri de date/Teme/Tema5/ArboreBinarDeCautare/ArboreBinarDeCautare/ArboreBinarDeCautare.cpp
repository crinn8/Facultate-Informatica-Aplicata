#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

class NOD
{
public:
    int key;
    NOD* st, * dr, * p;

    NOD(int k = 0)
    {
        key = k;
        p = st = dr = NULL;
    }
};


class ArboreBC
{
public:
    NOD* radacina;
    ArboreBC()
    {
        radacina = NULL;
    }

    void CONSTRUCT(std::vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            Insert(v[i]);
        }
    }

    void Insert(int val)
    {
        NOD* z;
        z = new NOD;
        z->key = val;
        NOD* x, * y;
        y = NULL;
        x = radacina;
        while (x != NULL)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->st;
            }
            else
            {
                x = x->dr;
            }
        }
        z->p = y;
        if (y == NULL)
        {
            radacina = z;
        }
        else
        {
            if (z->key < y->key)
            {
                y->st = z;
            }
            else
            {
                y->dr = z;
            }
        }
        //z->st = NULL;
        //z->dr = NULL;
    }

    void Preordine(NOD* n)
    {
        if (n != NULL)
        {
            std::cout << n->key << " ";
            Preordine(n->st);
            Preordine(n->dr);
        }
    }

    void Inordine(NOD* n)
    {
        if (n != NULL)
        {
            Inordine(n->st);
            std::cout << n->key << " ";
            Inordine(n->dr);
        }
    }

    void Postordine(NOD* n)
    {
        if (n != NULL)
        {
            Postordine(n->st);
            Postordine(n->dr);
            std::cout << n->key << " ";
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
        if (radacina == NULL)
            return true;
        return false;
    }

    NOD* MINIM(NOD* x)
    {
        NOD* index = x;
        while (index->st != NULL)
        {
            index = index->st;
        }
        return index;
    }

    NOD* MAXIM(NOD* x)
    {
        NOD* index = x;
        while (index->dr != NULL)
        {
            index = index->dr;
        }
        return index;
    }

    NOD* SUCCESOR(NOD* x)
    {
        NOD* index;
        if (x->dr != NULL)
        {
            index = MINIM(x->dr);
        }
        else
        {
            index = x->p;
            while (index != NULL && x == index->dr)
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
        if (x->st != NULL)
        {
            index = MAXIM(x->st);
        }
        else
        {
            index = x->p;
            while (index != NULL && x == index->st)
            {
                x = index;
                index = index->p;
            }
        }
        return index;
    }

    NOD* SEARCH(int info)
    {
        NOD* x = radacina;
        while (x != NULL && x->key != info)
        {
            if (info < x->key)
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
        if (u->p == NULL)
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
        if (v != NULL)
        {
            v->p = u->p;
        }
    }

    void DELETE(NOD* z)
    {
        char color;
        NOD* y;
        if (z->st == NULL)
        {
            TRANSPLANT(z, z->dr);
        }
        else
        {
            if (z->dr == NULL)
            {
                TRANSPLANT(z, z->st);
            }
            else
            {
                y = SUCCESOR(z);
                if (y != z->dr)
                {
                    TRANSPLANT(y, y->dr);
                    y->dr = z->dr;
                    z->dr->p = y;
                }
                TRANSPLANT(z, y);
                y->st = z->st;
                z->st->p = y;

            }
        }
    }

    void CLEAR()
    {
        while (EMPTY() == false)
        {
            DELETE(radacina);
        }
    }

};

void AfisareArbore(ArboreBC arb)
{
    std::queue<NOD*>c;
    c.push(arb.radacina);
    NOD* index;
    int i = 0, max = 1;
    while (c.empty() == false)
    {
        index = c.front();
        i++;
        std::cout << index->key;
        std::cout << " ";
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


void Meniu(ArboreBC arb)
{
    int x;
    do
    {
        std::cout << std::endl;
        std::cout << "Introduceti optiunea: " << std::endl;
        std::cout << "0 pentru iesirea din program." << std::endl;
        std::cout << "1 pentru inserarea unui element." << std::endl;
        std::cout << "2 pentru cautarea unui element." << std::endl;
        std::cout << "3 pentru stergerea unui element." << std::endl;
        std::cout << "4 pentru afisarea nodului cu cheia maxima." << std::endl;
        std::cout << "5 pentru afisarea nodului cu cheia minima." << std::endl;
        std::cout << "6 pentru afisarea succesorului unui nod." << std::endl;
        std::cout << "7 pentru afisarea predecesorului unui nod." << std::endl;
        std::cout << "8 pentru afisare." << std::endl;

        std::cin >> x;
        switch (x)
        {
        case 1:
        {
            int element;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            arb.Insert(element);
            break;
        }
        case 2:
        {
            int element;
            NOD* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != NULL)
                std::cout << "Elementul se afla in arbore.";
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 3:
        {
            int element;
            NOD* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != NULL)
                arb.DELETE(x);
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Elementul maxim este: " << arb.MAXIM(arb.radacina)->key << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Elementul minim este: " << arb.MINIM(arb.radacina)->key << std::endl;
            break;
        }
        case 6:
        {
            int element;
            NOD* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != NULL)
            {
                std::cout << "Succesorul nodului " << element << " este: " << arb.SUCCESOR(x)->key << std::endl;
            }
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 7:
        {
            int element;
            NOD* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != NULL)
            {
                std::cout << "Predecesorul nodului " << element << " este: " << arb.PREDECESOR(x)->key << std::endl;
            }
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 8:
        {
            int op;
            std::cout << "Introduceti 1 pentru afisarea in preordine, 2 pentru afisarea in inordine sau 3 pentru afisarea in postordine: ";
            std::cin >> op;
            arb.PRINT_TREE(op);

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
    ArboreBC arb;
    std::ifstream f("ArboreBinarDeCautare.in");
    int x;
    std::vector <int> v;

    while (f >> x)
    {
        v.push_back(x);
    }
    arb.CONSTRUCT(v);
    AfisareArbore(arb);
    std::cout << std::endl;
    Meniu(arb);

    return 0;
}
