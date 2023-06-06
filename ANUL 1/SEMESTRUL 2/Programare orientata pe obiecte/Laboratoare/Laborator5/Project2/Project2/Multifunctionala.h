#pragma once
#include "Imprimanta.h"
#include "Scanner.h"

class Multifunctionala : public Imprimanta, public Scanner
{
public:
	Multifunctionala(char* b, int v, int r) :Imprimanta(b, v, r), Scanner(b, v)
	{

	}

	char* GetBrand()override
	{
		return Scanner::GetBrand();
	}
};