#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>

struct NOD{
	std::vector<char> info;
	NOD* st=nullptr;
	NOD* dr=nullptr;
	NOD* p=nullptr;
};

struct Arbore {
	NOD* radacina;

	void ConstruireArbore(std::string expresie)
	{
		std::ifstream f("expresie.in");
		std::stack<NOD*>s;
		int i = 0;
		while(i < expresie.size())
		{
			char c;
			c = expresie[i];
			while (c == ' ')
			{
				i++;
				c= expresie[i];
			}
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			{
				NOD* nou = new NOD;
				nou->info.push_back(c);
				NOD* x, * y;
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				nou->dr = x;
				nou->st = y;
				x->p = nou;
				y->p = nou;
				s.push(nou);
			}
			else
			{
				NOD* nou = new NOD;
				while (c!=' ')
				{
					nou->info.push_back(c);
					i++;
					c = expresie[i];
				}
				s.push(nou);
			}
			i++;
		}
		radacina = s.top();
		s.pop();
	}

	void Preordine(NOD* n)
	{
		if (n != NULL)
		{
			for (int i = 0; i < n->info.size(); i++)
				std::cout << n->info[i];
			std::cout << " ";
			Preordine(n->st);
			Preordine(n->dr);
		}
	}

	void AfisareArbore()
	{
		std::queue<NOD*>c;
		c.push(radacina);
		NOD* index;
		int i = 0, max = 1;
		while (c.empty() == false)
		{
			index = c.front();
			i++;
			for(int j=0;j<index->info.size();j++)
			    std::cout << index->info[j] << " ";
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
};

int main()
{
	std::vector<std::vector<char>>fp;
	std::string expresie;
	std::ifstream f("expresie.in");
	getline(f, expresie);
	Arbore exp;
	exp.ConstruireArbore(expresie);
	exp.AfisareArbore();
	std::cout << std::endl;
	std::cout << "Preordine:" << std::endl;
	exp.Preordine(exp.radacina);
	return 0;
}
