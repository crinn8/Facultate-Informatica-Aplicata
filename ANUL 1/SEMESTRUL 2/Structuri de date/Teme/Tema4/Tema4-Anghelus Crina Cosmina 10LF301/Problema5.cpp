#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

struct NOD {
	int frecv = 0;
	char c = '-';
	NOD* st = nullptr, * dr = nullptr, * parinte = nullptr;
};

class Comparator
{
public:
	int operator() (NOD* p1, NOD* p2)
	{
		return p1->frecv > p2->frecv;
	}
};

class ArboreHuffmann {

public:

	NOD* radacina;
	void ConstruireArboreHuffmann(std::priority_queue <NOD*, std::vector<NOD*>, Comparator > Q)
	{
		while (Q.size() > 1)
		{
			NOD* X, * Y, * NOU;
			X = new NOD;
			Y = new NOD;
			X = Q.top();
			Q.pop();
			Y = Q.top();
			Q.pop();
			NOU = new NOD;
			NOU->frecv = X->frecv + Y->frecv;
			NOU->st = X;
			NOU->dr = Y;
			X->parinte = NOU;
			Y->parinte = NOU;
			Q.push(NOU);
		}
		radacina = Q.top();
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
			if (index->frecv > 0)
				std::cout << index->c << " " << index->frecv << "|";
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


void CitireText(int fr[257], std::string &text)
{
	std::ifstream f("text.in");
	std::getline(f, text);
	int i = 0;
	while (i < text.size())
	{
		char x;
		x = text[i];
		int poz = int(x);
		fr[poz]++;
		i++;
	}
}

void ConstruireCoada(std::priority_queue <NOD*, std::vector<NOD*>, Comparator > &Q, int fr[257])
{
	for (int i = 0; i < 257; i++)
	{
		char ch = char(i);
		if (fr[i] != 0)
		{
			NOD* x = new NOD;
			x->c = ch;
			x->frecv = fr[i];
			Q.push(x);
		}
	}
}

void matr(int matr_coduri[257][257])
{
	for (int i = 0; i < 257; i++)
	{
		for (int j = 0; j < 257; j++)
		{
			matr_coduri[i][j] = -1;
		}
	}
}

void MatriceCoduri(NOD* radacina, int size,int matr_coduri[257][257],int cod[100])
{
	if (radacina->st != nullptr)
	{
		cod[size] = 0;
		MatriceCoduri(radacina->st, size + 1,matr_coduri,cod);
	}

	if (radacina->dr != nullptr)
	{
		cod[size] = 1;
		MatriceCoduri(radacina->dr, size + 1, matr_coduri,cod);
	}

	if (radacina->dr == nullptr && radacina->st == nullptr)
	{
		int c = int (radacina->c);
		matr_coduri[c][0]=radacina->frecv;
		for (int i = 0; i < size; i++)
		{
			matr_coduri[c][i+1]=cod[i];
		}
	}
}

void AfisareCoduri(int matr_coduri[257][257])
{
	for (int i = 0; i < 257; i++)
	{
		if (matr_coduri[i][0] > 0)
		{
			std::cout << (char)i << " " << matr_coduri[i][0] << " ";
			for (int j = 1; j < 257&& matr_coduri[i][j]!=-1; j++)
			{
				std::cout << matr_coduri[i][j];
			}
			std::cout << std::endl;
		}
	}
}

void AfisareCodificare(std::string text, int matr_coduri[257][257])
{
	for (int i = 0; i < text.size(); i++)
	{
		int c = int(text[i]);
		for (int j = 1; j < 257 && matr_coduri[c][j] != -1; j++)
		{
			std::cout << matr_coduri[c][j];
		}
	}
}

void Zeroizare(int fr[257])
{
	for (int i = 0; i < 257; i++)
	{
		fr[i] = 0;
	}
}

int main()
{
	std::priority_queue <NOD*, std::vector<NOD*>, Comparator > Q;
	int fr[257];
	Zeroizare(fr);

	std::string text;
	CitireText(fr,text);
	ConstruireCoada(Q, fr);

	int n = Q.size();

	int cod[100], size = 0, matr_coduri[257][257];
	ArboreHuffmann coduri;
	coduri.ConstruireArboreHuffmann(Q);
	coduri.AfisareArbore();

	matr(matr_coduri);
	MatriceCoduri(coduri.radacina, size, matr_coduri,cod);
	std::cout << std::endl << std::endl;
	std::cout << "Codurile caracterelor sunt:" << std::endl;
	AfisareCoduri(matr_coduri);

	std::cout << std::endl << std::endl;
	std::cout << "Codificarea textului este:" << std::endl;
	AfisareCodificare(text, matr_coduri);
	std::cout << std::endl;

	return 0;
}
