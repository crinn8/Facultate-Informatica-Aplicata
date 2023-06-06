#pragma once

class Imprimanta
{
	char brand[1000];
	int vitezaImprimare;
	int rezolutie;
public:
	Imprimanta()
	{
		brand[0] = '\0';
		vitezaImprimare = 0;
		rezolutie = 0;
	}
	Imprimanta(char *b,int v,int r)
	{
		strcpy_s(brand,strlen(b)+1,b);
		vitezaImprimare = v;
		rezolutie = r;
	}
	int GetVitezaImprimare()
	{
		return vitezaImprimare;
	}
	char* GetBrand()
	{
		return brand;
	}
	int GetRezolutie()
	{
		return rezolutie;
	}
};
