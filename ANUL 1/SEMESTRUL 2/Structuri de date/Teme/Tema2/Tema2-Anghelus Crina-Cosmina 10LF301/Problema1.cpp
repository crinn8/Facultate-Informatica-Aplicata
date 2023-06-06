//Complexitate O(n)

#include <iostream>

struct STIVA {

	struct NOD {
		int info;
		NOD* prev;
	};

	NOD* varf=nullptr;
	int SIZE=0;

	void PUSH(int element)
	{
		NOD* nou;
		nou = new NOD;
		nou->info = element;
		nou->prev = varf;
		varf = nou;
		SIZE++;
	}

	bool EMPTY()
	{
		if (varf == nullptr)
			return true;
		return false;
	}

	void POP()
	{
		if (EMPTY() == false)
		{
			NOD* aux;
			aux = varf;
			varf = varf->prev;
			delete aux;
			SIZE--;
		}
	}

	int TOP()
	{
		if (EMPTY() == false)
		{
			return varf->info;
		}
	}

	void CLEAR()
	{
		while (EMPTY() == false)
		{
			POP();
		}
	}
};

int main()
{
	STIVA S;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int element;
		std::cin >> element;
		S.PUSH(element);
	}
	while (S.EMPTY() == false)
	{
		std::cout << S.TOP() << " ";
		S.POP();
	}
}
