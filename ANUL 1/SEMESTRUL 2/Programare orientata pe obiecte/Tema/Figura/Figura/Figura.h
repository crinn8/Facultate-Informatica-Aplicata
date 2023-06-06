#pragma once
#include <iostream>
#include <string>
#include <vector>

class FIGURA
{
public:
	std::string nume;
	std::vector <std::pair<float, float>> puncte;
	virtual float Perimetru() = 0;
	virtual float Arie() = 0;

	std::string Get_nume()
	{
		return nume;
	}

	virtual void Afisare()
	{
		std::cout << nume << " are perimetrul " << Perimetru() <<"."<< std::endl;
		std::cout << nume << " are aria " << Arie() << "." << std::endl;
	}

};