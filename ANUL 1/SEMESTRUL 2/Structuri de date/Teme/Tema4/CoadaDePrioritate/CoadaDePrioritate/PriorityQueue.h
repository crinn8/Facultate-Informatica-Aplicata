#pragma once
#include <vector>

class Priority_Queue 
{
public:
	std::vector <int> DATA;
	int SIZE;
	Priority_Queue()
	{
		SIZE = 0;
	}

	void INSERT(int val)
	{
		DATA.push_back(0);
		SIZE++;
		INCREASE_KEY(SIZE - 1, val);
	}

	int EXTRACT_MAX()
	{
		if (SIZE < 1)
			return 0;
		int maxi;
		if (SIZE != 0)
		{
			maxi = DATA[0];
			DATA[0] = DATA[SIZE - 1];
			SIZE--;
			MAX_HEAPFY(0);
		}
		return maxi;
	}

	int MAX_ELEMENT()
	{
		if (SIZE != 0)
		{
			return DATA[0];
		}
	}

	void INCREASE_KEY(int poz,int val)
	{
		if (val < DATA[poz])
		{
			std::cout << "Valoarea este prea mica.";
		}
		else
			if (poz < SIZE)
			{
				DATA[poz] = val;
				int p = (poz - 1) / 2;
				while (poz > 0 && DATA[p] < val)
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
		int st, dr,poz_max;
		st = 2 * poz + 1;
		dr = 2 * poz + 2;
		poz_max = poz;
		if (st<SIZE && DATA[st]>DATA[poz_max])
		{
			poz_max = st;
		}
		if (dr<SIZE && DATA[dr]>DATA[poz_max])
		{
			poz_max = dr;
		}
		if (poz_max != poz)
		{
			int aux = DATA[poz_max];
			DATA[poz_max] = DATA[poz];
			DATA[poz] = aux;
			MAX_HEAPFY(poz_max);
		}
	}
};