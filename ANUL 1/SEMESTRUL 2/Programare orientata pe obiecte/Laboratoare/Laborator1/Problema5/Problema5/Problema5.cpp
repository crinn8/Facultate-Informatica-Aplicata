/*De la tastatură se citeşte un vector a cu n elemente întregi pozitive. Să se aloce
memorie pentru un vector de vectori cu elemente întregi. Primul vector are a[0]
elemente, al doilea are a[1] elemente, în general al k-lea vector are a[k-1] elemente
(k{1, 2, …, n}). Să se citească de la tastatură elementele vectorilor. Să se
construiască un nou vector (alocat tot dinamic) format cu elementele pătrate perfecte
ale celor n vectori. În final se eliberează toate zonele de memorie alocate dinamic.*/

#include <iostream>
using namespace std;

int main()
{
	int n, * a, ** v;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	v = new int* [n];
	for (int i = 0; i < n; i++)
	{
		v[i] = new int[a[i]];
	}
	int nr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			cin >> v[i][j];
			if (sqrt(v[i][j])==floor(sqrt(v[i][j])))
				nr++;
		}
	}
	int* nou,k=0;
	nou = new int[nr];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++) 
		{
			if (sqrt(v[i][j]) == floor(sqrt(v[i][j])))
			{
				nou[k] = v[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < nr; i++)
		cout << nou[i] << " ";

	for (int index = 0; index < n; ++index)
	{
		delete[]v[index];
	}
	delete[]v;
	delete[]nou;
	delete[]a;
}
