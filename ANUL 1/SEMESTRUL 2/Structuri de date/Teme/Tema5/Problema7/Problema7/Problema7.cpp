#include <iostream>
#include <map>
#include <string>
#include <fstream>

void TransformareText(std::string &text)
{
	char c;
	for (int i = 0; i < text.size(); i++)
	{
		c = text[i];
		if (c >= 'A' && c <= 'Z')
		{
			text[i] = char(c + 32);
		}
	}
}

void ConstruireDictionar(std::map<std::string, int> &Dictionar,std::string text)
{
	int i = 0;
	char c;
	while (i < text.size())
	{
		c = text[i];
		while ((c < 'a' || c>'z') && (c < 'A' || c>'Z') && i < text.size())
		{
			i++;
			c = text[i];
		}
		std::string cuvant;
		while (i < text.size() && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		{
			i++;
			cuvant.push_back(c);
			c = text[i];
		}
		if (Dictionar[cuvant] != NULL)
		{
			Dictionar[cuvant]++;
		}
		else
		{
			Dictionar[cuvant] = 1;
		}
		i++;
	}
}

void Afisare(std::map<std::string, int> Dictionar)
{
	for (auto x : Dictionar)
	{
		std::cout << x.first << ":" << x.second << std::endl;
	}
}

int main() 
{
	std::map<std::string, int> Dictionar;
	std::ifstream f("TEXT.in");
	std::string text;
	std::getline(f, text);

	TransformareText(text);
	ConstruireDictionar(Dictionar, text);
	Afisare(Dictionar);

	return 0;
}
