// 	Implementati o lista dublu inlantuita circulara cu santinela. 

#include<iostream>
using namespace std;

struct nod {
	int info;
	nod *precedent, *urmator;
};

struct lista {

	nod *NIL;
	lista() {
		NIL = new nod;
		NIL->precedent = NIL->urmator = NIL;
	}
	void adaugare(int info) {
		nod *x; x = new nod;
		x->info = info;
		x->urmator = NIL->urmator;
		NIL->urmator->precedent = x;
		NIL->urmator = x;
		x->precedent = NIL;
	}
	nod * cauta(int k) {
		nod *x = new nod; x = NIL->urmator;
		while (x != NIL && x->info != k)
			x = x->urmator;
		return x;
	}
	void stergere(nod *x) {
		x->precedent->urmator = x->urmator;
		x->urmator->precedent = x->precedent;
	}

	void afisare() {
		nod *x;
		if (NIL->urmator == NIL)
			cout << "\nLista este goala!" << endl;
		else
		{
			x = NIL->urmator;
			cout << "NIL <=> ";
			while (x != NIL)
			{
				cout << x->info << " <=> ";
				x = x->urmator;
			}
			cout << "NIL" << endl;
		}
	};

};

int main() {
	lista l; int alegere;

	cout << "1. Adaugare\n2. Stergere\n3. Afisare lista\n4. Exit\n";
	do {
		cout << "\nalegere: "; cin >> alegere;
		switch (alegere) {
		case 1: {
			int x;
			cout << "\nIntroduceti elementul dorit: "; cin >> x;
			l.adaugare(x);
			cout << "\nElementul a fost adaugat cu succes!\n";
			break;
		}
		case 2: {
			if (l.NIL->urmator == l.NIL)
				cout << "\nLista este goala.\n";
			else {
				int k; nod *x;
				cout << "\nIntroduceti elementul pe care doriti sa il stergeti: "; cin >> k;
				x = l.cauta(k);
				if (x != l.NIL) {
					l.stergere(x);
					cout << "\nElementul a fost sters cu succes.\n";
				}
				else
					cout << "\nElementul NU exista in lista.\n";
			}
			break;
		}
		case 3: {
			l.afisare();
			break;
		}
		case 4: {cout << endl; return 0; break; }
		default: {cout << "\nAlegerea este gresita!\n"; break; }
		}
	} while (alegere != 4);

	return 0;
}