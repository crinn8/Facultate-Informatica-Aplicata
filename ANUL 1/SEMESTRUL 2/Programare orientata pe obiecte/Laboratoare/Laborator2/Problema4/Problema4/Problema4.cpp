#include <iostream>
using namespace std;

template<class T1>

T1 CautareBinara(int dim, T1 *v, T1 element)
{
    int st = 0, dr = dim - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == element)
            return mij;
        else
            if (v[mij] < element)
                st = mij + 1;
            else dr = mij - 1;
    }
    return -1;
}

template<class T>

T CautareSecv(int dim, T* v, T element)
{
    for (int i = 0; i < dim; i++)
        if (v[i] == element) return i;
    return -1;
}

template <class T2>
T2 Interclasare(int n, int m, T2 *a, T2 *b,T2 *&c,int li,int ls)
{
	int i = li, j = ls,k=0;

	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	while (i < n)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j < m)
	{
		c[k] = b[j];
		k++;
		j++;
	}
	return k;
}

template<class T3>
T3 SortarePrinInterclasare(T3 *v, int li, int ls)
{
	if (li < ls)
	{
		int m = (li + ls) / 2;
		SortarePrinInterclasare(v, li, m);
		SortarePrinInterclasare(v, m + 1, ls);
		Interclasare(v, li, ls, m, ls + 1);
	}
	return 0;
}

int main()
{
    int n,m;
    cin >> n>>m;
    int* a = new int[n];
	int* b = new int[m];
	int* c = new int[n+m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
    int element;
    cin >> element;
    cout<<CautareBinara(n, a, element);
	int k;
	k=Interclasare(n, m, a, b, c,0,0);
	for (int i = 0; i < k; i++)
		cout<< c[i]<<" ";
    delete[] a;
    return 0;
}