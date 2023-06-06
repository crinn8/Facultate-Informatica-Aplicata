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
	int info, size;
	node_arbor *left, *right, *p;
	char color;
	node_arbor() {
		size = 1;
	}
};

struct ARNplus {
	node_arbor *nil, *root;

	ARNplus() {
		nil = new node_arbor;
		nil->color = 'n';
		nil->left = nil->right = nil->p = nil;
		nil->size = 0;
		root = nil;
	}

	void insert(node_arbor *z) {
		node_arbor *y, *x;
		y = nil;
		x = root;
		while (x != nil) {
			y = x;
			if (z->info < x->info) {
				x->size++;
				x = x->left;

			}
			else {
				x->size++;
				x = x->right;

			}
		}
		z->p = y;
		if (y == nil) {
			root = z;
		}
		else
			if (z->info < y->info)
				y->left = z;
			else
				y->right = z;

		z->left = nil;
		z->right = nil;
		z->color = 'r';
		repare_insert(z);
	}

	void repare_insert(node_arbor *z) {
		node_arbor *u;
		while (z->p->color == 'r') {
			if (z->p == z->p->p->left) {
				u = z->p->p->right;
				if (u->color == 'r') {
					u->color = 'n';
					z->p->color = 'n';
					z->p->p->color = 'r';
					z = z->p->p;
				}
				else {
					if (z == z->p->right) {
						z = z->p;
						rotate_left(z);
					}
					z->p->color = 'n';
					z->p->p->color = 'r';
					rotate_right(z->p->p);

				}
			}
			else {
				u = z->p->p->left;
				if (u->color == 'r') {
					u->color = 'n';
					z->p->color = 'n';
					z->p->p->color = 'r';
					z = z->p->p;
				}
				else {
					if (z == z->p->left) {
						z = z->p;
						rotate_right(z);
					}
					z->p->color = 'n';
					z->p->p->color = 'r';
					rotate_left(z->p->p);
				}

			}
		}
		root->color = 'n';
	}

	void remove(node_arbor *z) {
		node_arbor *y = z, *x;
		char yoc = z->color;
		if (z->left == nil) {
			x = z->right;
			transplant(z, x);
		}
		else {
			if (z->right == nil) {
				x = z->left;
				transplant(z, x);
			}
			else {
				y = succesor(z);
				yoc = y->color;
				x = y->right;
				if (y == z->right)
					x->p = y;
				else {
					transplant(y, x);
					y->right = z->right;;
					z->right->p = y;
				}
				y->left = z->left;
				z->left->p = y;
				transplant(z, y);
				y->color = z->color;
				y->size = z->size;
			}
		}
		node_arbor *w = x->p;
		while (w != nil) {
			w->size--;
			w = w->p;
		}

		if (yoc == 'n') {
			repare_remove(x);

		}
	}

	void repare_remove(node_arbor *x) {
		node_arbor *u;
		while (x != root && x->color == 'n') {
			if (x == x->p->left) {
				u = x->p->right;
				if (u->color == 'r') {
					u->color = 'n';
					x->p->color = 'r';
					rotate_left(x->p);
					u = x->p->right;
				}
				if (u->left->color == 'n' && u->right->color == 'n') {
					u->color = 'r';
					x = x->p;
				}
				else {
					if (u->right->color == 'n') {
						u->left->color = 'n';
						u->color = 'r';
						rotate_right(u);
						u = x->p->right;
					}
					u->color = x->p->color;
					x->p->color = 'n';
					u->right->color = 'n';
					rotate_left(x->p);
					x = root;
				}

			}
			else {
				u = x->p->left;
				if (u->color == 'r') {
					u->color = 'n';
					x->p->color = 'r';
					rotate_right(x->p);
					u = x->p->left;
				}
				if (u->right->color == 'n' && u->left->color == 'n') {
					u->color = 'r';
					x = x->p;
				}
				else {
					if (u->left->color == 'n') {
						u->right->color = 'n';
						u->color = 'r';
						rotate_left(u);
						u = x->p->left;
					}
					u->color = x->p->color;
					x->p->color = 'n';
					u->left->color = 'n';
					rotate_right(x->p);
					x = root;
				}

			}

		}
		x->color = 'n';
	}

	void transplant(node_arbor *u, node_arbor *v) {
		if (u == root)
			root = v;
		else
			if (u == u->p->left)
				u->p->left = v;
			else
				u->p->right = v;
		v->p = u->p;
	}

	node_arbor *predecesor(node_arbor *x) {
		node_arbor *y;
		if (x->left != nil)
			return max(x->left);
		else {
			y = x->p;
			while (y != nil && x == y->left) {
				x = y;
				y = y->p;
			}
			return y;
		}
	}

	node_arbor *succesor(node_arbor *x) {
		node_arbor *y;
		if (x->right != nil)
			return min(x->right);
		else {
			y = x->p;
			while (y != nil && x == y->right) {
				x = y;
				y = y->p;
			}
			return y;
		}
	}

	node_arbor *min(node_arbor *x)
	{
		while (x->left != nil)
			x = x->left;

		return x;
	}

	node_arbor *max(node_arbor *x)
	{
		while (x->right != nil)
			x = x->right;

		return x;
	}

	node_arbor *search(int k) {
		node_arbor *x = root;
		while (x != nil && x->info != k) {
			if (x->info > k)
				x = x->left;
			else
				x = x->right;
		}
		return x;
	}

	void rotate_left(node_arbor *x) {
		node_arbor *y = x->right;
		x->right = y->left;
		if (y->left != nil)
			y->left->p = x;
		y->p = x->p;
		if (x->p == nil)
			root = y;
		else
			if (x == x->p->left)
				x->p->left = y;
			else
				x->p->right = y;
		x->p = y;
		y->left = x;
		y->size = x->size;
		x->size = x->left->size + x->right->size + 1;
	}

	void rotate_right(node_arbor *x) {
		node_arbor *y = x->left;
		x->left = y->right;
		if (y->right != nil)
			y->right->p = x;
		y->p = x->p;
		if (x->p == nil)
			root = y;
		else
			if (x == x->p->right)
				x->p->right = y;
			else
				x->p->left = y;
		x->p = y;
		y->right = x;
		y->size = x->size;
		x->size = x->left->size + x->right->size + 1;
	}

	void preordine(node_arbor *x) {
		if (x != nil) {
			cout << x->info << '(' << x->size << ')' << ' ';
			preordine(x->left);
			preordine(x->right);
		}
	}

	void inordine(node_arbor *x) {
		if (x != nil) {
			inordine(x->left);
			cout << x->info << '(' << x->size << ')' << ' ';
			inordine(x->right);
		}
	}

	void postordine(node_arbor *x) {
		if (x != nil) {
			postordine(x->left);
			postordine(x->right);
			cout << x->info << '(' << x->size << ')' << ' ';
		}
	}

	void nivele() {
		queue <node_arbor> C;
		C.push(root);
		while (!C.empty()) {
			node_arbor *aux = C.top();
			C.pop();
			cout << aux->info << '(' << aux->size << ')' << ' ';
			if (aux->left != nil)
				C.push(aux->left);
			if (aux->right != nil)
				C.push(aux->right);
		}

	}

	bool empty() {
		if (root == nil)
			return 1;
		return 0;
	}

	int rank(node_arbor *x)
	{
		node_arbor *y;
		int rank = x->left->size + 1;
		while (x != root) {
			y = x->p;
			if (x == y->right)
				rank = rank + y->left->size + 1;
			x = y;
		}
		return rank;
	}

	node_arbor *select(int n) {
		int rank;
		node_arbor *x = root;
		while (x != nil) {
			rank = x->left->size + 1;
			if (rank == n)
				return x;
			if (rank < n) {
				n = n - rank;
				x = x->right;
			}
			else
				x = x->left;

		}
	}

};

int main() {
	ARNplus H;
	int c;

	do {
		system("cls");
		cout << "-----------------------------" << endl << " Arbore rosu-negru imbogatit.\n" << "-----------------------------" << endl;
		cout << "\n1. Insert\n2. Minimum\n3. Maximum\n4. Search\n5. Remove\n6. Afisare\n";
		cout << "------------------\n7. Rank of an element\n8. The element with a given rank\n------------------\n9.Exit\n";
		cout << "\nchoice = "; cin >> c;

		switch (c) {
		case 1: {
			int n, x;
			cout << "\nn = "; cin >> n; cout << endl;

			for (int i = 0; i < n; i++) {
				node_arbor *y = new node_arbor;
				cin >> x;
				y->info = x;
				y->color = 'r';
				H.insert(y);
			}

			cout << "\nInsertion completed.\n";
			system("pause");
			break;
		}
		case 2: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				cout << "\nMinimum is: " << H.min(H.root)->info << endl;

			}
			system("pause");
			break;
		}
		case 3: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else
				cout << "\nMaximum is: " << H.max(H.root)->info << endl;
			system("pause");
			break;
		}
		case 4: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				node_arbor *x; int k;
				cout << "\nInsert the value you wish to search: "; cin >> k;
				x = H.search(k);
				if (x != H.nil) {
					cout << "\nThe node with the key " << k << " exist. \n";
				}
				else
					cout << "\nThe element doesn't exist.\n";
			}
			system("pause");
			break;

		}
		case 5: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				node_arbor *x; int k;
				cout << "\nInsert the value you wish to remove: "; cin >> k;
				x = H.search(k);
				if (x != H.nil) {
					H.remove(x);
					cout << "\nOperation complete.\n";
				}
				else
					cout << "\nThe element doesn't exist.\n";
			}
			system("pause");
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
			system("pause");
			break;
		}
		case 7: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				int k; node_arbor *x;
				cout << "\nInsert the element you wish to find out his rank: "; cin >> k;
				x = H.search(k);
				if (x != H.nil) {
					cout << "\nThe element with the key " << k << " has the rank " << H.rank(x) << ".\n";
				}
				else
					cout << "\nThe element doesn't exist.\n";
			}

			system("pause");
			break;

		}
		case 8: {
			if (H.empty())
				cout << "\nEmpty arbor.\n";
			else {
				int n; node_arbor *x;
				cout << "\nInsert the rank: "; cin >> n;
				x = H.select(n);
				if (n<1 || n>H.root->size)
					cout << "\nThe element with rank " << n << " doesn't exist.\n";
				else
					cout << "\nThe element with rank " << n << " is " << x->info << ".\n";

			}

			system("pause");
			break;

		}
		case 9: {
			cout << endl;
			return 0;
			system("pause");
			break;
		}
		default: {
			cout << "\nWrong choice!\n";

		}

		}

	} while (c != 9);
	return 0;
}

