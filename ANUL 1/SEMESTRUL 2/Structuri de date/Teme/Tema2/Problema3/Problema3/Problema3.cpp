//Complexitate O(n)

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <math.h>
#include <string>

int Prioritate(char c)
{
	if (c == '(' || c == ')')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	if (c == '^')
		return 3;
}

bool VerificareExpresie(std::string expresie)
{
	int nr_nr = 0, nr_op = 0, nr_d = 0, nr_i = 0;
	if (expresie[0] < '0' || expresie[0] > '9')
		if (expresie[0] != '(' && expresie[0] != ' ')
			return false;
	for (int i = 0; i < expresie.size(); i++)
	{
		if (expresie[i] == '(')
		{
			nr_d++;
		}
		else
			if (expresie[i] == ')')
			{
				if (nr_d == 0)
					return false;
				nr_d--;
			}
			else {
				if (expresie[i] != '(' && expresie[i] != ')' && expresie[i] != ' ' && expresie[i] != '+' && expresie[i] != '-' && expresie[i] != '*' && expresie[i] != '/' && expresie[i] != '^' && expresie[i] != '.')
					if (expresie[i] < '0' || expresie[i] > '9')
					{
						return false;
					}
			}
	}
	if (nr_d != nr_i)
		return false;
	int i = 0;
	while (i < expresie.size())
	{
		int nr_p = 0, ok = 0;
		while (i < expresie.size() && expresie[i] != '(' && expresie[i] != ')' && expresie[i] != ' ' && expresie[i] != '+' && expresie[i] != '-' && expresie[i] != '*' && expresie[i] != '/' && expresie[i] != '^')
		{
			ok = 1;
			if (expresie[i] == '.')
			{
				nr_p++;
				if (i == 0 || i == expresie.size() - 1)
					return false;
				if (expresie[i - 1] < '0' || expresie[i - 1] > '9' || expresie[i + 1] < '0' || expresie[i + 1] > '9')
					return false;
			}
			i++;
		}
		nr_nr += ok;
		if (i < expresie.size())
			if (expresie[i] == '*' || expresie[i] == '+' || expresie[i] == '-' || expresie[i] == '/' || expresie[i] == '^')
			{
				nr_op++;
			}
		if (nr_p > 1)
			return false;
		i++;
	}
	if (nr_op != nr_nr - 1)
		return false;

	i = 0;
	char k;
	while (i < expresie.size())
	{
		std::vector<char> nr;
		k = expresie[i];
		int poz1 = -1, poz2 = 0;
		if (k >= '0' && k <= '9')
		{
			while (k != '-' && k != '+' && k != '*' && k != '/' && k != '^' && k != ')' && k != '(' && i < expresie.size())
			{
				nr.push_back(k);
				if (k >= '0' && k <= '9')
				{
					if (poz1 == -1)
					{
						poz1 = i;
					}
					else poz2 = i;
				}
				i++;
				k = expresie[i];
			}
			for (int j = poz1; j <= poz2 && j < expresie.size(); j++)
			{
				if (expresie[j] == ' ')
					return false;
			}
		}
		i++;
	}

	i = 0;
	while (i < expresie.size())
	{
		k = expresie[i];
		if (k == '/')
		{
			int ok = 0;
			while (i < expresie.size() - 1)
			{
				if (expresie[i] == '0' && expresie[i + 1] != '.')
				{
					if (ok == 0)
						return false;
					else
					{
						ok = 1;
						break;
					}
				}
				i++;
			}
			if (expresie[i] == '0' && ok == 0)
				return false;
		}
		i++;
	}

	return true;
}

void ConstruireFormaPoloneza(std::vector<std::vector<char>>& fp, std::string expresie)
{
	std::stack<char>operatori;
	std::ifstream f("expresie.in");
	char c;
	int i = 0;
	while (i < expresie.size())
	{
		std::vector<char> nr;
		c = expresie[i];
		while (c == ' ')
		{
			i++;
			c = expresie[i];
		}
		while (c >= '0' && c <= '9' || c == '.')
		{
			nr.push_back(c);
			i++;
			c = expresie[i];
		}
		fp.push_back(nr);
		if (c == '(')
		{
			operatori.push(c);
		}
		else
			if (c == ')')
			{
				while (operatori.empty() == false && operatori.top() != '(')
				{
					std::vector<char>element;
					element.push_back(operatori.top());
					operatori.pop();
					fp.push_back(element);
				}
				if (operatori.empty() == false && operatori.top() == '(')
					operatori.pop();
			}
			else
				if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
				{
					int p = Prioritate(c);
					while (operatori.empty() == false)
					{
						char aux = operatori.top();
						if (p <= Prioritate(aux) && operatori.empty() == false)
						{
							std::vector<char>element;
							element.push_back(operatori.top());
							fp.push_back(element);
							operatori.pop();
						}
						else break;
					}
					operatori.push(c);
				}
		i++;
	}
	while (operatori.empty() == false)
	{
		std::vector<char>element;
		element.push_back(operatori.top());
		operatori.pop();
		fp.push_back(element);
	}
	i++;
}

double Calcule(char c, double x, double y)
{
	if (c == '+')
		return x + y;
	if (c == '-')
		return x - y;
	if (c == '*')
		return x * y;
	if (c == '/')
		return x / y;
	if (c == '^')
		return pow(x, y);
}

double ConstruireNumar(std::vector<char>c)
{
	double nr = 0;
	int j = 0;
	while (j < c.size() && c[j] != '.')
	{
		int cif = int(c[j] - '0');
		nr = nr * 10 + cif;
		j++;
	}
	if (j < c.size())
		if (c[j] == '.')
		{
			j++;
			double p = 0.1;
			while (j < c.size())
			{
				int cif = int(c[j] - '0');
				nr = nr + cif * p;
				p *= 0.1;
				j++;
			}
		}
	return nr;
}

double RezultatulExpresiei(std::vector<std::vector<char>> fp)
{
	std::stack<double>rezultat;
	for (int i = 0; i < fp.size(); i++)
	{
		std::vector<char>c;
		c = fp[i];
		double nr = 0;
		if (c.size() != 0)
		{
			if (c[0] >= '0' && c[0] <= '9')
			{
				nr = ConstruireNumar(c);
				rezultat.push(nr);
			}
			else
			{
				char op = c[0];
				double y = 0, x = 0;
				if (rezultat.empty() == false)
					y = rezultat.top();
				rezultat.pop();
				if (rezultat.empty() == false)
					x = rezultat.top();
				rezultat.pop();
				double rez = 0;
				rez = Calcule(op, x, y);
				rezultat.push(rez);
			}
		}
	}
	return rezultat.top();
}

int main()
{
	std::vector<std::vector<char>>fp;
	std::string expresie;
	std::ifstream f("expresie.txt");
	getline(f, expresie);
	if (VerificareExpresie(expresie) == false)
	{
		std::cout << "Expresia nu este corecta!";
	}
	else
	{
		ConstruireFormaPoloneza(fp, expresie);
		std::cout << "Forma poloneza este:" << std::endl;
		for (int i = 0; i < fp.size(); i++)
		{
			if (fp[i].size() != 0)
			{
				for (int j = 0; j < fp[i].size(); j++)
					std::cout << fp[i][j];
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		std::cout << "Rezultatul expresiei este:" << std::endl;
		std::cout << RezultatulExpresiei(fp);
	}
	return 0;
}
