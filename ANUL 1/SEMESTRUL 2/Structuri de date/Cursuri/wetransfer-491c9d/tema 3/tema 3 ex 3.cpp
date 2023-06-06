#include< iostream>
using namespace std;

template<typename T> struct stack {
	struct nod_stiva {
		T *info;
		nod_stiva *leg;
	};
	nod_stiva *varf;
	stack() {
		varf = NULL;
	}
	void push(T* info) {
		nod_stiva *x; x = new nod_stiva;
		x->info = info;
		x->leg = NULL;
		if (varf != NULL)
			x->leg = varf;
		varf = x;
	}
	void pop() {
		if (varf != NULL) {
			nod_stiva *y; y = new nod_stiva;
			y = varf;
			varf = varf->leg;
			delete y;
		}
	}
	T* top() {
		if (varf != NULL)
			return varf->info;
	}
	bool empty() {
		if (varf == NULL)
			return 1;
		else
			return 0;
	}
};

template<typename T> struct lista {
	struct nod_lista {
		T *info;
		nod_lista *leg;
	};
	nod_lista *cap;
	lista() {
		cap = NULL;
	}

	void adaugare(T* info) {
		nod_lista *x; x = new nod_lista;
		x->info = info;
		x->leg = NULL;
		if (cap != NULL)
			x->leg = cap;
		cap = x;

	}
	nod_lista * cautare(int k) {
		nod_lista *x = cap;
		while (x != NULL && x->info->info != k)
			x = x->leg;
		return x;
	}
	void stergere(nod_lista *x) {
		if (x == cap)
			cap = cap->leg;
		else {
			nod_lista *aux;
			aux = cap;
			while (aux->leg != x)
				aux = aux->leg;
			aux->leg = x->leg;
			delete x;
		}
	}
	void afisare() {
		if (cap != NULL) {
			nod_lista *x = cap;
			while (x != NULL)
			{
				cout << x->info->info << " -> ";
				x = x->leg;
			}
			cout << "NULL\n";
		}
	}
	int size() {
		if (cap == NULL)
			return 0;
		else {
			nod_lista* aux = cap; int nr = 0;
			while (aux != NULL) {
				nr++;
				aux = aux->leg;
			}
			return nr;
		}
	}
	void inversare() {
		if (cap != NULL) {
			nod_lista *curent = cap, *precedent = NULL, *urmator;
			while (curent != NULL) {
				urmator = curent->leg;
				curent->leg = precedent;
				precedent = curent;
				curent = urmator;
			}
			cap = precedent;
		}
	}

	T* element(int i) {
		if (cap != NULL) {
			nod_lista *aux = cap; int nr = 1;
			while (i != nr) {
				aux = aux->leg;
				nr++;
			}
			return aux->info;
		}
	}
};

template<typename T> struct queue {
	struct nod_coada {
		T *info;
		nod_coada *leg;
	};

	nod_coada *prim, *ultim;
	queue() {
		prim = NULL;
		ultim = NULL;
	}
	void push(T* info) {
		nod_coada *x; x = new nod_coada;
		x->info = info;
		x->leg = NULL;
		if (prim == NULL) {
			prim = x; ultim = x;
		}
		else {
			ultim->leg = x;
			ultim = x;
		}
	}
	void pop() {
		if (prim != NULL) {
			nod_coada *y; y = new nod_coada;
			y = prim;
			prim = prim->leg;

			delete y;
		}
	}
	bool empty() {
		if (prim == NULL)
			return 1;
		else
			return 0;
	}
	T* top() {
		if (prim != NULL)
			return prim->info;

	}
};

struct arbore {
	struct nod_arbore {
		int info;
		nod_arbore *parinte;
		lista <nod_arbore> fii;
	};
	nod_arbore *radacina;
	arbore() {
		radacina = new nod_arbore;
		radacina->parinte = NULL;
	}
	void citire(nod_arbore* x) {
		int nr, info, i, ok;
		if (x->parinte == NULL) {
			cout << "introduceti radacina arborelui: "; cin >> radacina->info;
		}
		cout << "\nnumarul de fii ai nodului: "; cin >> nr;
		for (i = 0; i<nr; i++) {
			nod_arbore *aux; aux = new nod_arbore;
			aux->parinte = x;
			cout << "\nintroduceti informatia urmatorului nod: "; cin >> aux->info;
			cout << "\nNodul are fii? Daca 'da' atunci tastati 1, altfel 0.\n\nalegere: "; cin >> ok;
			if (ok == 1)
				citire(aux);
			x->fii.adaugare(aux);
		}
		x->fii.inversare();

	}
	void parcurgere_preordine() {
		stack <nod_arbore> S;
		S.push(radacina);
		while (!S.empty()) {
			nod_arbore *x;
			x = S.top();
			S.pop();
			cout << x->info << ' ';

			for (int i = x->fii.size(); i >= 1; i--) {
				S.push(x->fii.element(i));

			}
		}

	}
	void parcurgere_nivele() {
		queue <nod_arbore> C;
		C.push(radacina);
		while (!C.empty()) {
			nod_arbore *x;
			x = C.top();
			C.pop();
			cout << x->info << ' ';

			for (int i = 1; i <= x->fii.size(); i++) {
				C.push(x->fii.element(i));
			}
		}
	}
};

int main() {

	arbore T;
	T.citire(T.radacina);
	cout << "\nparcurgerea pe nivele: "; T.parcurgere_nivele();
	cout << "\nparcurgerea in preordine: "; T.parcurgere_preordine();
	cout << endl << endl;
	return 0;

}