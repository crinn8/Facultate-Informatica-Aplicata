#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

class NOD 
{
public:
    int nr_noduri;
    NOD* parent;
    std::vector<int>keys;
    std::vector<NOD*>c;
    bool leaf; 

    NOD(int t) 
    {
        keys.resize(2*t);
        c.resize(2*t);
        nr_noduri = 0;
        parent = NULL;
        leaf = true;
    }

    bool operator == (const NOD& aux) 
    {
        if (nr_noduri != aux.nr_noduri)
            return 0;
        for (int i = 0; i < aux.keys.size(); i++)
            if (keys[i] != aux.keys[i])
                return 0;
        return 1;
    }

    bool operator > (const NOD& aux) 
    {
        return (keys[0] > aux.keys[0]);
    }

    friend std::ostream& operator << (std::ostream& fo, const NOD& aux);
};

std::ostream& operator << (std::ostream& fo, const NOD& aux)
{
    std::cout << "[ ";
    for (int i = 0; i < aux.nr_noduri - 1; i++)
        fo << aux.keys[i] << ',';
    fo << aux.keys[aux.nr_noduri - 1];
    std::cout << " ]";
    return fo;
}

class BArbore
{
public:

    NOD* radacina;
    int t;

    BArbore(int grad) 
    {
        t = grad;
        NOD* x;
        x = new NOD(t);
        radacina = x;
    }

    void InsertRec(NOD* x, int key)
    {
        int nr = x->nr_noduri;
        if (x->leaf == true)
        {
            while (nr >= 1 && key < x->keys[nr - 1])
            {
                x->keys[nr] = x->keys[nr - 1];
                nr--;
            }
            x->keys[nr] = key;
            x->nr_noduri++;
        }
        else
        {
            while (nr >= 1 && key < x->keys[nr])
                nr--;
            nr++;
            std::cout << x->c.size() << std::endl;
            //if (x->c[nr]->nr_noduri == 2 * t - 1)
            {
                //Split(x, nr);
                //if (key > x->keys[nr])
                {
                    nr++;
                }
            }
            //InsertRec(x->c[nr], key);
        }
    }

    void TreeInsert(int key)
    {
        if (radacina->nr_noduri == 2 * t - 1)
        {
            NOD* nou;
            nou = new NOD(t);
            nou->leaf = false;
            nou->nr_noduri = 0;
            nou->c.push_back(radacina);
            radacina = nou;
            //Split(radacina, 1);
        }
        InsertRec(radacina, key);
    }

    /*void Split(NOD* x, int i)
    {
        NOD* y;
        //y = x->c[i];
        x->nr_noduri++;
        /*for (int k = x->nr_noduri; k >= i + 1; k--)
        {
            x->keys[k] = x->keys[k - 1];
        }
        x->keys[i] = y->keys[t];
        for (int k = x->nr_noduri; k >= i + 1; k--)
        {
            x->c[k + 1] = x->c[k];
        }
        NOD* z;
        z = new NOD;
        z->nr_noduri = t - 1;
        for (int k = 1; k <= t - 1; k++)
        {
            z->keys[k] = y->keys[k + t];
        }
        if (y->leaf == false)
        {
            for (int k = 1; k <= t; k++)
            {
                z->c[k] = y->c[k + t];
            }
        }
        z->leaf = y->leaf;
        x->c[i + 1] = z;
    }*/
};
void AfisareArbore(BArbore arb)
{
    std::queue<NOD*>c;
    c.push(arb.radacina);
    NOD* index;
    int i = 0, max = 1;
    while (c.empty() == false)
    {
        index = c.front();
        i++;
        std::cout << index;
        std::cout << " ";
        c.pop();
        for (int i = 0; i < index->c.size(); i++)
        {
            if(index->c[i]!=NULL)
                c.push(index->c[i]);
        }
        if (i == max)
        {
            std::cout << std::endl;
            max = c.size();
            i = 0;
        }
    }
}
int main()
{
    BArbore a(2);
    std::ifstream f("arb.in");
    int x;
    while (f >> x)
    {
        a.TreeInsert(x);
    }
    AfisareArbore(a);
    return 0;
}
