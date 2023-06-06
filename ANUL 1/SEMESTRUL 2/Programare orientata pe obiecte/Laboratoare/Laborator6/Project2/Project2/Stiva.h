#pragma once
using namespace std;
template <class T>
class Stiva
{
public:
	class Nod
	{
	public:
		T info;
		Nod* next;
	};
private:
	Nod* cap;
public:
	Stiva()
	{
		cap = nullptr;
	}
	void AddNod(T info)
	{
		Nod* p = cap;
		cap = new Nod;
		cap->info = info;
		cap->next = p;
	}

	T RemoveNod()
	{
		if (!cap)
			throw "Stiva este goala.";

		Nod* p = cap;
		T x = p->info;
		cap = cap->next;
		delete p;
		return x;
	}

	void GolireStiva()
	{
		while (cap)
		{
			Nod* p = cap;
			cap = cap->next;
			delete p;
		}
	}
	void PrintStiva()
	{
		Nod* p = cap;
		while (p)
		{
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}

	~Stiva()
	{
		GolireStiva();
	}
};