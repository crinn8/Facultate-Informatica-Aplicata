#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <climits>

void rezolvare();
void citireMarimiPesti(int, std::vector<int>&);
void aflarePiranhaDominant(std::vector<int>&);
int aflareMaximSir(std::vector<int>&);
bool verificareEgaliateTermeniSir(std::vector<int>&);

void main()
{
	rezolvare();
}

void rezolvare()
{
	int numar_pesti;
	std::vector<int>pesti;

	std::cout << "Numar de pesti: ";
	std::cin >> numar_pesti;

	if (numar_pesti < 2)
	{
		std::cout << "Numarul pestilor trebuie sa fie >= 2";
		std::cout << std::endl;
	}
	else
	{
		citireMarimiPesti(numar_pesti, pesti);
		aflarePiranhaDominant(pesti);
	}

}

void citireMarimiPesti(int numar_de_pesti, std::vector<int>& pesti)
{
	srand(time(NULL));

	for (int index_peste = 0; index_peste < numar_de_pesti; index_peste++)
	{
		pesti.push_back(rand() % 20 + 1);
		std::cout << pesti[index_peste] << " ";
	}
	std::cout << std::endl;
}

void aflarePiranhaDominant(std::vector<int>& sir_de_pesti)
{
	int index_peste_dominant = -1;
	int marime_maxima = aflareMaximSir(sir_de_pesti);

	if (verificareEgaliateTermeniSir(sir_de_pesti) == true)
	{
		std::cout << -1 << " (NU EXISTA PESTE DOMINANT) " << std::endl;
	}
	else
	{
		if (sir_de_pesti[0] == marime_maxima && sir_de_pesti[1] < marime_maxima)
		{
			std::cout << "Pestele dominant se afla pe pozitia " << 1 << std::endl;
		}
		else
			if (sir_de_pesti[sir_de_pesti.size() - 1] == marime_maxima && sir_de_pesti[sir_de_pesti.size() - 2] < marime_maxima)
			{
				std::cout << "Pestele dominant se afla pe pozitia " << sir_de_pesti.size() << std::endl;
			}
			else
			{
				for (int index_peste = 1; index_peste < sir_de_pesti.size() - 1; index_peste++)
				{
					if ((sir_de_pesti[index_peste] == marime_maxima && sir_de_pesti[index_peste - 1] < marime_maxima) || (sir_de_pesti[index_peste] == marime_maxima && sir_de_pesti[index_peste + 1] < marime_maxima))
					{
						index_peste_dominant = index_peste + 1;
						break;
					}
				}

				std::cout << "Pestele dominant se afla pe pozitia: " << index_peste_dominant << std::endl;
			}
	}
}

bool verificareEgaliateTermeniSir(std::vector<int>& sir_dat)
{
	int primul_termen = sir_dat[0];

	for (int index = 1; index < sir_dat.size(); index++)
		if (primul_termen != sir_dat[index])
			return false;

	return true;
}

int aflareMaximSir(std::vector<int>& sirDat)
{
	int maxim = INT_MIN;

	for (int index = 0; index < sirDat.size(); index++)
		if (sirDat[index] > maxim)
			maxim = sirDat[index];

	return maxim;
}
