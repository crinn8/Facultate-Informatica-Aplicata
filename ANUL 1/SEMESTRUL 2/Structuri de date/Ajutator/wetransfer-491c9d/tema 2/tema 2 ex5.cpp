/*
Sa se construiasca o functie care sa inverseze o lista simplu inlantuita in complexitate O(n), fara a folosi mai mult decât o zona de memorie constanta,
cu exceptia zonei ocupate de lista.

*/

#include<iostream>
using namespace std;

struct nod {
	int info;
	nod *leg;
};

struct lista {

	nod *cap;
	lista() {
		cap = NULL;
	}
	void adaugare(int info) {
		nod *x; x = new nod;
		x->info = info;
		x->leg = NULL;
		if (cap != NULL)
			x->leg = cap;
		cap = x;

	}
	nod * cautare(int k) {
		nod *x;
		x = cap;
		while (x != NULL && x->info != k)
			x = x->leg;
		return x;
	}
	void stergere(nod *x) {
		if (x == cap)
			cap = cap->leg;
		else {
			nod *aux;
			aux = cap;
			while (aux->leg != x)
				aux = aux->leg;
			aux->leg = x->leg;
			delete x;
		}
	}
	void afisare() {
		if (cap == NULL)
			cout << "\nLista este goala.\n";
		else {
			nod *x = cap;
			cout << "\nLista este: ";
			while (x != NULL)
			{
				cout << x->info << " -> ";
				x = x->leg;
			}
			cout << "NULL\n";
		}
	};
	int size() {
		if (cap == NULL)
			return 0;
		else {
			nod* aux = cap; int nr = 0;
			while (aux != NULL) {
				nr++;
				aux = aux->leg;
			}
			return nr;
		}
	}
	void inversare() {
		if (cap == NULL)
			cout << "\nLista este goala!\n";
		else {
			nod *curent = cap, *precedent = NULL, *urmator;
			while (curent != NULL) {
				urmator = curent->leg;
				curent->leg = precedent;
				precedent = curent;
				curent = urmator;
			}
			cap = precedent;
		}
	}
};

int main() {
	lista l; int alegere;

	cout << "1. Adaugare\n2. Stergere\n3. Afisare lista\n4. Inversare lista\n5. Exit\n";
	do {
		cout << "\nalegere: "; cin >> alegere;
		switch (alegere) {
		case 1: {
			int x;
			cout << "\nDati valoarea dorita: "; cin >> x;
			l.adaugare(x);
			cout << "\nElementul a fost adaugat cu succes!\n";
			break;
		}
		case 2: {
			if (l.cap == NULL)
				cout << "\nLista este goala.\n";
			else {
				int k; nod *x;
				cout << "\nIntroduceti elementul pe care doriti sa il stergeti: "; cin >> k;
				x = l.cautare(k);
				if (x != NULL) {
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
		case 4: {
			l.inversare();
			break;
		}
		case 5: {cout << endl; return 0; break; }
		default: {cout << "\nAlegerea este gresita!\n"; break; }
		}
	} while (alegere != 5);

	return 0;
}