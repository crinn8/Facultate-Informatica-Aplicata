#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void Interclasare(std::vector<int> a, std::vector<int> b, std::vector<int> &c)
{
	int n, m, i = 0, j = 0;
	n = a.size();
	m = b.size();

	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else
		{
			c.push_back(b[j]);
			j++;
		}
	}
	while (i < n)
	{
		c.push_back(a[i]);
		i++;
	}
	while (j < m)
	{
		c.push_back(b[j]);
		j++;
	}
}

class myComparator
{
public:
	bool operator()(std::vector<int> a, std::vector<int> b)
	{
		return a.size() < b.size();
	}
};

void Copy(std::vector<int>&a, std::vector<int>b)
{
	for (int i = 0; i < b.size(); i++)
	{
		a.push_back(b[i]);
	}
}

void InterclasareOptimala(int n, std::vector<std::vector<int>>& vectori,std::vector<int> &rezultat)
{
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, myComparator> c;
	for (int i = 0; i < n; i++)
	{
		c.push(vectori[i]);
	}
	while (c.size() > 1)
	{
		std::vector<int>a, b,nou;
		Copy(a, c.top());
		c.pop();
		Copy(b, c.top());
		c.pop();
		Interclasare(a, b, nou);
		c.push(nou);
	}
	Copy(rezultat, c.top());
}

void CitireVectori(int &n, std::vector<std::vector<int>> &vectori)
{
	std::ifstream f("vectori.in");
	f >> n;
	for (int i = 0; i < n; i++)
	{
		vectori.push_back(std::vector<int>());
		int m;
		f >> m;
		for (int j = 0; j < m; j++)
		{
			int element;
			f >> element;
			vectori[i].push_back(element);
		}
	}
}

void AfisareVector(std::vector<int>rezultat)
{
	std::cout << "Interclasarea vectorilor este:" << std::endl;
	for (int i = 0; i < rezultat.size(); i++)
	{
		std::cout << rezultat[i] << " ";
	}
}

int main()
{
	int n;
	std::vector<std::vector<int>> vectori;
	std::vector<int>rezultat;
	CitireVectori(n,vectori);
	InterclasareOptimala(n,vectori,rezultat);
	AfisareVector(rezultat);

	return 0;
}

