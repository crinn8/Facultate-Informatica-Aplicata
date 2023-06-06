#include<iostream>
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

};

struct arbor {
	node_arbor *root;
	arbor() {
		root = new node_arbor;
		root->parinte = NULL;
		root->left = NULL;
		root->right = NULL;
	}

	void citire(node_arbor* x) {
		int c;
		if (x->parinte == NULL) {
			cout << "\nGive the information of the root: "; cin >> x->info;
		}
		else {
			cout << "\nGive the information of the next node: "; cin >> x->info;
		}
		cout << "\nThe node has left descendent? \n 1. yes\n 2. no\n";
		cout << "\nchoice = "; cin >> c;
		if (c == 1) {
			node_arbor *aux1 = new node_arbor;
			aux1->parinte = x;
			aux1->left = NULL;
			aux1->right = NULL;
			citire(aux1);
			x->left = aux1;
		}
		cout << "\nThe node has right descendent?\n 1. yes\n 2. no\n";
		cout << "\nchoice = "; cin >> c;
		if (c == 1) {
			node_arbor *aux2 = new node_arbor;
			aux2->parinte = x;
			aux2->left = NULL;
			aux2->right = NULL;
			citire(aux2);
			x->right = aux2;
		}

	}

	void preordine() {
		stack <node_arbor> S;
		node_arbor *x;
		S.push(root);
		while (!S.empty()) {
			x = S.top();
			S.pop();
			cout << x->info << ' ';
			if (x->right != NULL)
				S.push(x->right);
			if (x->left != NULL)
				S.push(x->left);
		}
	}

	void inordine() {
		stack <node_arbor> S;
		node_arbor *current = root;
		bool ok = 0;
		while (!ok) {
			while (current != NULL) {
				S.push(current);
				current = current->left;
			}
			if (current == NULL && !S.empty()) {
				node_arbor *aux = S.top();
				cout << aux->info << ' ';
				current = aux->right;
				S.pop();
			}
			else ok = 1;
		}
	}

	void postordine() {
		stack <node_arbor> S;
		node_arbor *aux = root;
		do {
			while (aux != NULL) {
				if (aux->right != NULL)
					S.push(aux->right);
				S.push(aux);
				aux = aux->left;
			}
			aux = S.top();
			S.pop();
			if (aux->right != NULL && aux->right == S.top()) {
				S.pop();
				S.push(aux);
				aux = aux->right;
			}
			else {
				cout << aux->info << ' ';
				aux = NULL;
			}
		} while (!S.empty());
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

	arbor T; int c, ok = 0;
	cout << "1. Citire\n2. Parcurgere in preordine\n3. Parcurgere in inordine\n4. Parcurgere in postordine\n5. Parcurgere pe nivele\n6. Exit\n";
	do {
		cout << "\nalegere = "; cin >> c;
		switch (c) {
		case 1: {
			ok = 1;
			T.citire(T.root);
			cout <<endl<< "Reading completed!"<<endl;
			break;
		}
		case 2: {
			if (ok == 0)
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nParcugere in preordine: ";
				T.preordine();
				cout << endl;
			}
			break;
		}
		case 3: {
			if (ok == 0)
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nParcugere in inordine: ";
				T.inordine();
				cout << endl;
			}
			break;
		}
		case 4: {
			if (ok == 0)
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nParcugere in postordine: ";
				T.postordine();
				cout << endl;
			}
			break;
		}
		case 5: {
			if (ok == 0)
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nParcugere pe nivele: ";
				T.nivele();
				cout << endl;
			}
			break;

		}
		case 6: {
			cout << endl;
			return 0;
			break;
		}
		default: {
			cout << "\nAlegere gresita!\n";
			break;
		}


		}


	} while (c != 6);
	return 0;

}