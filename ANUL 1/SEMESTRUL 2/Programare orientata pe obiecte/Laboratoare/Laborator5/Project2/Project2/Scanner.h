#pragma once

class Scanner
{
	char brand[1000];
	int vitezaScanare;

public:
	Scanner()
	{
		brand[0] = '\0';
		vitezaScanare = 0;
	}
	Scanner(char* b,int v)
	{
		strcpy_s(brand, strlen(b) + 1, b);
		vitezaScanare = v;
	}
	int GetVitezaScanare()
	{
		return vitezaScanare;
	}
	virtual char* GetBrand()
	{
		return brand;
	}
};