#include <iostream>

class Base
{
	int *x;
	int n;
public:
	Base(int n) : n(n)
	{
		x = new int[n];
	}
	Base(const Base& b)
	{
		n = b.n;
		x = new int[n]();
		for (int i = 0; i < n; i++)
			x[i] = b.x[i];
	}
	~Base()
	{
		delete[] x;
	}
};

class Derived : public Base
{
	int m, n;
public:
	Derived(int x1, int y1) :m(x1), n(y1), Base(x1, y1)
	{
	}
};