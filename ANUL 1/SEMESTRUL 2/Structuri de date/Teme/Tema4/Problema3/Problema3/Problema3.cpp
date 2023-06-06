#include <iostream>
#include <fstream>
#include <vector>

struct pret {
	int rand;
	int nr_locuri;
};

class Priority_Queue
{
public:
	pret *DATA;
	int SIZE;
	Priority_Queue()
	{
		SIZE = 0;
		DATA = nullptr;
	}

	void INSERT(pret val)
	{
		pret element;
		element.rand = 0;
		element.nr_locuri = 0;
		DATA[SIZE]=element;
		SIZE++;
		INCREASE_KEY(SIZE - 1, val);
	}

	pret EXTRACT_MAX()
	{
		pret maxi;
		maxi.rand = 0;
		maxi.nr_locuri = 0;
		if (SIZE >0)
		{
			maxi = DATA[0];
			DATA[0] = DATA[SIZE - 1];
			SIZE--;
			MAX_HEAPFY(0);
		}
		return maxi;
	}

	pret MAX_ELEMENT()
	{
		if (SIZE != 0)
		{
			return DATA[0];
		}
	}

	void INCREASE_KEY(int poz, pret val)
	{
		if (val.rand*val.nr_locuri < DATA[poz].rand * DATA[poz].nr_locuri)
		{
			std::cout << "Valoarea este prea mica.";
		}
		else
			if (poz < SIZE)
			{
				DATA[poz] = val;
				int p = (poz - 1) / 2;
				while (poz > 0 && val.rand * val.nr_locuri > DATA[p].rand * DATA[p].nr_locuri)
				{
					DATA[poz] = DATA[p];
					poz = p;
					p = (poz - 1) / 2;
				}
				DATA[poz] = val;
			}
	}

	void MAX_HEAPFY(int poz)
	{
		int st, dr, poz_max;
		st = 2 * poz + 1;
		dr = 2 * poz + 2;
		poz_max = poz;
		if (st<SIZE && DATA[st].rand*DATA[st].nr_locuri>DATA[poz].rand* DATA[poz].nr_locuri)
		{
			poz_max = st;
		}
		if (dr<SIZE && DATA[dr].rand * DATA[dr].nr_locuri>DATA[poz_max].rand * DATA[poz_max].nr_locuri)
		{
			poz_max = dr;
		}
		if (poz_max != poz)
		{
			pret aux = DATA[poz_max];
			DATA[poz_max] = DATA[poz];
			DATA[poz] = aux;
			MAX_HEAPFY(poz_max);
		}
	}
};

int PretBilet(int n, std::vector<int>locuri)
{
	Priority_Queue c;
	c.DATA = new pret[locuri.size()];
	for (int i = 0; i < locuri.size(); i++)
	{
		pret element;
		element.rand = i + 1;
		element.nr_locuri = locuri[i];
		c.INSERT(element);
	}

	for (int i = 0; i < n-1; i++)
	{
		pret element = c.MAX_ELEMENT();
		c.EXTRACT_MAX();
		element.nr_locuri--;
		c.INSERT(element);
	}

	pret pret_bilet = c.MAX_ELEMENT();
	return pret_bilet.rand*pret_bilet.nr_locuri;
}

void Citire(int &m,std::vector<int> &locuri,int &n)
{
	std::ifstream f("spectacol.in");
	f >> m;
	for (int i = 0; i < m; i++)
	{
		int element;
		f >> element;
		locuri.push_back(element);
	}
	f >> n;
}

int main()
{
	int m,n;
	std::vector<int>locuri;
	Citire(m, locuri,n);
	std::cout << "Emil va plati " << PretBilet(n,locuri) << " lei.";
    return 0;
}
