#include<iostream>
using namespace std;

template<typename T> struct queue {
	struct node_queue {
		T *info;
		node_queue *leg;
	};
	node_queue *first, *last;
	queue() {
		first = NULL;
		last = NULL;
	}
	void push(T *info) {
		node_queue *x; x = new node_queue;
		x->info = info;
		x->leg = NULL;
		if (first == NULL) {
			first = x; last = x;
		}
		else {
			last->leg = x;
			last = x;
		}
	}
	void pop() {
		node_queue *y; y = new node_queue;
		y = first;
		first = first->leg;
		delete y;
	}
	void display() {
		node_queue *x = first;
		cout << "\nThe queue is: ";
		while (x != NULL)
		{
			cout << x->info << " -> ";
			x = x->leg;
		}
		cout << "NULL\n";
	}
	bool empty() {
		if (first == NULL)
			return 1;
		else
			return 0;
	}
	T* top() {
		if (first != NULL)
			return first->info;

	}
};

struct node_arbor {
	int info;
	node_arbor *left, *right, *parinte;
	node_arbor(int item) {
		info = item;
		left = NULL;
		right = NULL;
		parinte = NULL;
	}
};

struct arbor {
	node_arbor *root;

	arbor(int* SRD, int* RSD, int n) {
		int contor = 0;
		root = build_tree(SRD, RSD, 0, n - 1,contor);
	}
	
	int search(int* v, int start, int stop, int x) {
		int i;
		for (i = start; i <= stop; i++)
			if (v[i] == x)
				return i;
		return i;
	}

	node_arbor *build_tree(int* SRD, int* RSD, int start, int stop,int &contor)
	{
		if (start > stop)
			return NULL;
		else {
			node_arbor *luki = new node_arbor(RSD[contor++]);

			if (start == stop)
				return luki;
			else {
				int index = search(SRD, start, stop, luki->info);
				luki->left = build_tree(SRD, RSD, start, index - 1,contor);
				luki->right = build_tree(SRD, RSD, index + 1, stop,contor);
				return luki;
			}
		}
	}

	void preordine(node_arbor *x) {

		if (x != NULL) {
			cout << x->info << ' ';
			preordine(x->left);
			preordine(x->right);
		}
	}

	void inordine(node_arbor *x) {
		if (x != NULL) {
			inordine(x->left);
			cout << x->info << ' ';
			inordine(x->right);
		}
	}

	void postordine(node_arbor *x) {
		if (x != NULL) {
			postordine(x->left);
			postordine(x->right);
			cout << x->info << ' ';
		}
	}

	void nivele() {
		queue <node_arbor> C;
		C.push(root);

		while (!C.empty()) {
			node_arbor *aux = C.top();
			C.pop();
			cout << aux->info << ' ';
			if (aux->left != NULL)
				C.push(aux->left);
			if (aux->right != NULL)
				C.push(aux->right);
		}

	}

};

int main() {
	int *RSD, *SRD, n;
	cout << "n = "; cin >> n;
	RSD = new int[n];
	SRD = new int[n];
	cout << "\nParcurgerea in preordine: ";
	for (int i = 0; i < n; i++) {
		cin >> RSD[i];
	}
	cout << "\nParcurgerea in inordine: ";
	for (int i = 0; i < n; i++) {
		cin >> SRD[i];
	}

	arbor T(SRD, RSD, n);
	char c;
	cout << "\nThe tree construction was completed successfully.\n\nHow you want to output the arbor?\na. preordine\nb. inordine\nc. postordine\nd. pe nivele\ne. exit\n\n";
	do {
		cout << "\nchoice = "; cin >> c;
		switch (c) {
		case 'a': cout << "\nparcurgere in preordine: "; T.preordine(T.root); cout << endl; break;
		case 'b': cout << "\nparcurgere in inordine: "; T.inordine(T.root); cout << endl; break;
		case 'c': cout << "\nparcurgere in postordine: "; T.postordine(T.root); cout << endl; break;
		case 'd':cout << "\nparcurgere pe nivele: "; T.nivele(); cout << endl; break;
		case 'e': cout << endl; return 0; break;
		default: cout << "\nWrong choice!\n"; break;
		}
	} while (c != 'e');

	delete[] RSD;
	delete[] SRD;
}