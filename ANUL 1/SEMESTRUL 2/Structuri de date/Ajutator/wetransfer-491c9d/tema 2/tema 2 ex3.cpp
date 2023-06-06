// 	Sa se implementeze algoritmul Bucket-Sort utilizand liste dublu inlantuite. 

#include<iostream>
#include<fstream>
using namespace std;

struct nod {
	float info;
	nod *precedent, *urmator;
};

struct lista {
	nod *cap;
	lista() {
		cap = NULL;
	}
	void adaugare(float info) {
		nod *x; x = new nod;
		x->info = info;
		x->urmator = cap;
		if (cap == NULL)
			cap = x;
		else {
			cap->precedent = x;
			x->precedent = NULL;
			cap = x;
		}
	}
	nod * cauta(int k) {
		nod *x;
		x = cap;
		while (x != NULL && x->info != k)
			x = x->urmator;
		return x;
	}

	void stergere(nod *x) {
		if (x->precedent == NULL)
			cap = x->urmator;
		else
			x->precedent->urmator = x->urmator;
		if (x->urmator != NULL)
			x->urmator->precedent = x->precedent;
	}
	void afisare() {
		if (cap == NULL)
			cout << "\nLista este goala.\n";
		else {
			nod *x = cap;
			while (x != NULL)
			{
				cout << x->info;
				x = x->urmator;
				if (x != NULL)
					cout << " <=> ";
			}
			cout << " -> NULL\n";
		}
	};

};

void citire(float* &v, int &n) {
	ifstream f("vector.txt");
	int i;
	f >> n;
	v = new float[n];
	for (i = 0; i < n; i++)
		f >> v[i];
	f.close();
}

void afisare(float *v, int n) {
	cout << "Vectorul sortat: ";
	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';
	cout << endl << endl;
}

void sortare(lista l) {
	nod *aux; int ok; float a;
	do {
		ok = 0;
		aux = l.cap;
		while (aux->urmator != NULL) {
			if (aux->info > aux->urmator->info) {
				a = aux->info;
				aux->info = aux->urmator->info;
				aux->urmator->info = a;
				ok = 1;
			}
			aux = aux->urmator;
		}
	} while (ok == 1);

}

void bucket_sort(float *a, int n) {
	lista *b; b = new lista[n];
	int i;

	for (i = 0; i < n; i++)
		b[int(n*a[i])].adaugare(a[i]);

	for (i = 0; i < n; i++)
		if (b[i].cap != NULL)
			sortare(b[i]);

	cout << "\nBuckets:\n\n";
	for (i = 0; i <n; i++)
		if (b[i].cap != NULL) {
			cout << "bucket: "; (b[i]).afisare();
			cout << endl;
		}
	int j = 0;
	for (i = 0; i <n; i++)
		if (b[i].cap != NULL) {
			nod *aux = b[i].cap;
			while (aux != NULL) {
				a[j] = aux->info;
				j++;
				aux = aux->urmator;
			}
		}
	afisare(a, n);
	delete[] b;
}

int main() {
	float *a; int n;
	citire(a, n);
	bucket_sort(a, n);

	delete[] a;
	return 0;
}