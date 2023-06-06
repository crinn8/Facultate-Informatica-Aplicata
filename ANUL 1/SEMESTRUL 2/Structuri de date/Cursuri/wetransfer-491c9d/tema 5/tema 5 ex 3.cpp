#include <iostream>
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
	int info,contor;
	node_arbor *left, *right, *parinte;
	node_arbor() {
		left = NULL;
		right = NULL;
		parinte = NULL;
		contor = 1;
	}
};

struct binary_arbor {

	node_arbor *root;

	binary_arbor() {
		root = NULL;
	}

	void insert(node_arbor* z) {
		node_arbor *x, *y;
		x = root;
		y = NULL;
		while (x != NULL) {
			y = x;
			if (z->info < x->info)
				x = x->left;
			else
				x = x->right;

		}
		z->parinte = y;
		if (y == NULL)
			root = z;
		else
			if (y->info < z->info)
				y->right = z;
			else
				if (y->info > z->info)
					y->left = z;
				else
					if (y->info == z->info)
						y->contor++;
	}

	node_arbor *search(int k) {
		node_arbor *x = root;
		while (x != NULL && x->info != k) {
			if (x->info > k)
				x = x->left;
			else
				x = x->right;
		}
		return x;
	}

	node_arbor *min(node_arbor *x)
	{
		while (x->left != NULL)
			x = x->left;

		return x;
	}

	node_arbor *max(node_arbor *x)
	{
		while (x->right != NULL)
			x = x->right;

		return x;
	}

	node_arbor *predecesor(node_arbor *x) {
		node_arbor *y;
		if (x->left != NULL)
			return max(x->left);
		else {
			y = x->parinte;
			while (y != NULL && x == y->left) {
				x = y;
				y = y->right;
			}
			return y;
		}
	}

	node_arbor *succesor(node_arbor *x) {
		node_arbor *y;
		if (x->right != NULL)
			return min(x->right);
		else {
			y = x->parinte;
			while (y != NULL && x == y->right) {
				x = y;
				y = y->right;
			}
			return y;
		}
	}

	void transplant(node_arbor *u, node_arbor *v) {
		if (u->parinte == NULL)
			root = v;
		else {
			if (u == u->parinte->left)
				u->parinte->left = v;
			else
				u->parinte->right = v;
		}
		if (v != NULL)
			v->parinte = u->parinte;

	}

	void remove(node_arbor *z) {

		if (z->left == NULL)
			transplant(z, z->right);
		else
			if (z->right == NULL)
				transplant(z, z->left);
			else {
				node_arbor *y;
				y = succesor(z);
				if (y != z->right) {
					transplant(y, y->right);
					y->right = z->right;
					z->right->parinte = y;
				}
				transplant(z, y);
				y->left = z->left;
				z->left->parinte = y;
			}
	}

	void preordine(node_arbor *x) {
		if (x != NULL) {
			cout << x->info << '(' << x->contor << ')' << ' ';
			preordine(x->left);
			preordine(x->right);
		}
	}

	void inordine(node_arbor *x) {
		if (x != NULL) {
			inordine(x->left);
			cout << x->info << '(' << x->contor << ')' << ' ';
			inordine(x->right);
		}
	}

	void postordine(node_arbor *x) {
		if (x != NULL) {
			postordine(x->left);
			postordine(x->right);
			cout << x->info << '(' << x->contor << ')' << ' ';
		}
	}

	void nivele() {
		queue <node_arbor> C;
		C.push(root);
		while (!C.empty()) {
			node_arbor *aux = C.top();
			C.pop();
			cout << aux->info << '(' << aux->contor << ')' << ' ';
			if (aux->left != NULL)
				C.push(aux->left);
			if (aux->right != NULL)
				C.push(aux->right);
		}

	}

	bool empty() {
		if (root == NULL)
			return 1;
		return 0;
	}

};

int main() {
	binary_arbor H; int c;
	cout << "1. Insert\n2. Minimum\n3. Maximum\n4. Search\n5. Remove\n6. Afisare\n7. Exit\n";

	do {
		cout << "\nchoice = "; cin >> c;

		switch (c) {
		case 1: {
			int n, x;
			cout << "\nn = "; cin >> n; cout << endl;
			
			for (int i = 0; i < n; i++) {
				node_arbor *y = new node_arbor;
				cin >> x;
				y->info = x;
				H.insert(y);
				
			}

			cout << "\nInsertion completed.\n";
			break;
		}
		case 2: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nMinimum is: " << H.min(H.root)->info << endl;

			}
			break;
		}
		case 3: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else
				cout << "\nMaximum is: " << H.max(H.root)->info << endl;

			break;
		}
		case 4: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				node_arbor *x; int k;
				cout << "\nInsert the value you wish to search: "; cin >> k;
				x = H.search(k);
				if (x != NULL) {
					cout << "\nThe node with the key " << k << " exist. \n";
				}
				else
					cout << "\nThe element doesn't exist.\n";
			}
			break;

		}
		case 5: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				node_arbor *x; int k;
				cout << "\nInsert the value you wish to remove: "; cin >> k;
				x = H.search(k);
				if (x != NULL) {
					H.remove(x);
					cout << "\nOperation complete.\n";
				}
				else
					cout << "\nThe element doesn't exist.\n";
			}
			break;
		}
		case 6: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nHow you want to output the arbor?\na. preordine\nb. inordine\nc. postordine\nd. nivele\n\n";
				char c; cin >> c; cout << endl;
				switch (c) {
				case 'a': H.preordine(H.root); cout << endl; break;
				case 'b': H.inordine(H.root); cout << endl; break;
				case 'c': H.postordine(H.root); cout << endl; break;
				case 'd': H.nivele(); cout << endl; break;
				default: cout << "Wrong choice!\n"; break;
				}

			}
			break;
		}
		case 7: {
			cout << endl;
			return 0;
			break;
		}
		default: {
			cout << "\nWrong choice!\n";
		}

		}

	} while (c != 7);
	return 0;
}