#include <iostream>


void Interclasare(int n, int m, int a[100], int b[100],int &k, int c[200])
{
	int i = 0, j = 0;

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
}
int main()
{
	int m, n, k=0, a[100], b[100], c[200] = { 0 };
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < m; i++)
		std::cin >> b[i];
	Interclasare(n, m, a, b, k, c);
	for (int i = 0; i < k; i++)
		std::cout << c[i] << " ";
	return 0;
}