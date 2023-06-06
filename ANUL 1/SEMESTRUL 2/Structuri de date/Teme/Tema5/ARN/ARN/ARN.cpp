#include <iostream>
#include <queue>
#include <fstream>
#include <vector>

template<class T>

class NOD
{
public:
    char color;
    T key;
    NOD* st, * dr, * p;

    NOD()
    {
        key = 0;
        color = 'r';
        p = st = dr = nullptr;
    }
};
template<class T>
class ARN
{
public:
    NOD<T>* radacina;
    NOD<T>* nil;
    ARN()
    {
        nil = new NOD<T>;
        nil->color = 'n';
        nil -> p = nil;
        nil->st = nil->dr = nil;
        radacina = nil;
    }

    void CONSTRUCT(std::vector<T> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            Insert(v[i]);
        }
    }

    void Insert(T val)
    {
        NOD<T>* z;
        z = new NOD<T>;
        z->key = val;
        NOD<T>* x, * y;
        y = nil;
        x = radacina;
        while (x != nil)
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
        if (y == nil)
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
        z->st = nil;
        z->dr = nil;
        if (x != nil)
            x->color = 'r';
        Insert_Repara(z);
    }

    void RotatieSt(NOD<T>* y)
    {
        NOD<T>* x;
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
        else
        {
            if (y == y->p->st)
            {
                y->p->st = x;
            }
            else
            {
                y->p->dr = x;
            }
        }
        x->st = y;
        y->p = x;
    }

    void RotatieDr(NOD<T>* y)
    {
        NOD<T>* x;
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

    void Insert_Repara(NOD<T>* z)
    {
        while ( (z->p->color == 'r'))
        {
            if (z->p == z->p->p->st)
            {
                NOD<T>* U;
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
                    if (z== z->p->dr)
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
                    NOD<T>* U;
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

    void Preordine(NOD<T>* n)
    {
        if (n != nil)
        {
            std::cout << n->key << " "<<n->color<<std::endl;
            Preordine(n->st);
            Preordine(n->dr);
        }
    }

    void Inordine(NOD<T>* n)
    {
        if (n != nil)
        {
            Inordine(n->st);
            std::cout << n->key << " ";
            Inordine(n->dr);
        }
    }

    void Postordine(NOD<T>* n)
    {
        if (n != nil)
        {
            Postordine(n->st);
            Postordine(n->dr);
            std::cout << n->key << " ";
        }
    }

    void PRINT_TREE(int opt)
    {
        NOD<T>* n;
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

    NOD<T>* MINIM(NOD<T>* x)
    {
        NOD<T>* index = x;
        while (index->st != nil)
        {
            index = index->st;
        }
        return index;
    }

    NOD<T>* MAXIM(NOD<T>* x)
    {
        NOD<T>* index = x;
        while (index->dr != nil)
        {
            index = index->dr;
        }
        return index;
    }

    NOD<T>* SUCCESOR(NOD<T>* x)
    {
        NOD<T>* index;
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

    NOD<T>* PREDECESOR(NOD<T>* x)
    {
        NOD<T>* index;
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

    NOD<T>* SEARCH(T info)
    {
        NOD<T>* x = radacina;
        while (x != nil && x->key != info)
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

    void TRANSPLANT(NOD<T>* u, NOD<T>* v)
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

    void DELETE_REPARA(NOD<T>* x)
    {
        NOD<T>* F;
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

    void DELETE(NOD<T>* z)
    {
        char color;
        NOD<T>* x, * y;
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

template<class T>
void AfisareArbore(ARN<T> arb)
{
    std::queue<NOD<T>*>c;
    c.push(arb.radacina);
    NOD<T>* index;
    int i = 0, max = 1;
    while (c.empty() == false)
    {
        index = c.front();
        i++;
        std::cout << index->key;
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

template<class T>
void Meniu(ARN<T> arb)
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
            T element;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            arb.Insert(element);
            break;
        }
        case 2:
        {
            T element;
            NOD<T>* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != arb.nil)
                std::cout << "Elementul se afla in arbore";
            else 
                std::cout << "Cheia cautata nu exista."<<std::endl;
            break;
        }
        case 3:
        {
            T element;
            NOD<T>* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != arb.nil)
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
            T element;
            NOD<T>* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != arb.nil)
            {
                std::cout << "Succesorul nodului " << element << " este: " << arb.SUCCESOR(x)->key << std::endl;
            }
            else
                std::cout << "Cheia cautata nu exista." << std::endl;
            break;
        }
        case 7:
        {
            T element;
            NOD<T>* x;
            std::cout << "Introduceti elementul dorit: ";
            std::cin >> element;
            x = arb.SEARCH(element);
            if (x != arb.nil)
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
    ARN<int> arb;
    std::ifstream f("Arbore.in");
    int x;
    std::vector <int> v;

    while (f >> x)
    {
        v.push_back(x);
    }
    arb.CONSTRUCT(v);

    Meniu(arb);

    return 0;
}
