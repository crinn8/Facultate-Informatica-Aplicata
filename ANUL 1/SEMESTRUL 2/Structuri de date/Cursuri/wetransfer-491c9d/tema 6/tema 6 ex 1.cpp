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
	int info, contor, height;
	node_arbor *left, *right, *parinte;
	node_arbor() {
		left = NULL;
		right = NULL;
		parinte = NULL;
		contor = 1;
		height = 1;
	}
};

struct AVL {

	node_arbor *root;

	AVL() {
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
		repare_insert(z);
	}

	void repare_insert(node_arbor *z) {

		node_arbor *aux = z;
		while (aux != NULL) {
			aux->height = height(aux);

			if (determinate_bfactor(aux) == 2 || determinate_bfactor(aux) == -2) {
				int bf = determinate_bfactor(aux);
				int bf_left = determinate_bfactor(aux->left);
				int bf_right = determinate_bfactor(aux->right);

				if (bf == -2 && bf_left == -1) // case 1 left
					rotate_right(aux);
				else
					if (bf == 2 && bf_right == 1) // case 1 right
						rotate_left(aux);
					else
						if (bf == -2 && bf_left == 1) // case 2 left
						{
							rotate_left(aux->left);
							rotate_right(aux);
						}
						else
							if (bf == 2 && bf_right == -1) // case 2 right
							{
								rotate_right(aux->right);
								rotate_left(aux);
							}

			}

			aux = aux->parinte;
		}

	}

	void remove(node_arbor *z) {
		node_arbor *aux=NULL;
		if ((z->left == NULL && z->right == NULL) || (z->left == NULL && z->right != NULL) || (z->left != NULL && z->right == NULL))
			aux = z->parinte;
		else
			if (z->left != NULL && z->right != NULL)
				aux = succesor(z)->parinte;

		if (z->left == NULL)
			transplant(z, z->right);
		else {
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
		repare_remove(aux);
	}

	void repare_remove(node_arbor *z) {

		node_arbor *aux = z;
		while (aux != NULL) {
			aux->height = height(aux);

			if (determinate_bfactor(aux) == 2 || determinate_bfactor(aux) == -2) {
				int bf = determinate_bfactor(aux);
				int bf_left = determinate_bfactor(aux->left);
				int bf_right = determinate_bfactor(aux->right);

				if (bf == -2 && bf_left == -1) // case 1 left
					rotate_right(aux);
				else
					if (bf == 2 && bf_right == 1) // case 1 right
						rotate_left(aux);
					else
						if (bf == -2 && bf_left == 1) // case 2 left
						{
							rotate_left(aux->left);
							rotate_right(aux);
						}
						else
							if (bf == 2 && bf_right == -1) // case 2 right
							{
								rotate_right(aux->right);
								rotate_left(aux);
							}
							else
								if (bf == -2 && bf_left == 0) // case 3 left
									rotate_right(aux);
								else
									if (bf == 2 && bf_right == 0) // case 3 right
										rotate_left(aux);
			}

			aux = aux->parinte;
		}
	}

	int maxim(int a, int b) {
		return (a > b ? a : b);
	}

	int height(node_arbor *z) {
		if (z->left == NULL && z->right == NULL)
			return 1;
		else
			if (z->left == NULL && z->right != NULL)
				return z->right->height + 1;
			else
				if (z->left != NULL && z->right == NULL)
					return z->left->height + 1;
				else
					return maxim(height(z->left), height(z->right)) + 1;
	}

	int determinate_bfactor(node_arbor *z) {
		if (z == NULL)
			return 0;
		int a, b;
		if (z->right == NULL)
			a = 0;
		else
			a = z->right->height;

		if (z->left == NULL)
			b = 0;
		else
			b = z->left->height;
		return a - b;
	}

	void rotate_left(node_arbor *x) {
		node_arbor *y = x->right;
		x->right = y->left;
		if (y->left != NULL)
			y->left->parinte = x;
		y->parinte = x->parinte;
		if (x->parinte == NULL)
			root = y;
		else
			if (x == x->parinte->left)
				x->parinte->left = y;
			else
				x->parinte->right = y;
		x->parinte = y;
		y->left = x;

		node_arbor* aux = x;
		while (aux != NULL) {
			aux->height = height(x);
			aux = aux->parinte;
		}

	}

	void rotate_right(node_arbor *x) {
		node_arbor *y = x->left;
		x->left = y->right;
		if (y->right != NULL)
			y->right->parinte = x;
		y->parinte = x->parinte;
		if (x->parinte == NULL)
			root = y;
		else
			if (x == x->parinte->right)
				x->parinte->right = y;
			else
				x->parinte->left = y;
		x->parinte = y;
		y->right = x;

		node_arbor* aux = x;
		while (aux != NULL) {
			aux->height = height(x);
			aux = aux->parinte;
		}

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
				y = y->parinte;
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
				y = y->parinte;
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

	void preordine(node_arbor *x) {
		if (x != NULL) {
			cout << x->info << '(' << determinate_bfactor(x) << ')' << ' ';
			preordine(x->left);
			preordine(x->right);
		}
	}

	void inordine(node_arbor *x) {
		if (x != NULL) {
			inordine(x->left);
			cout << x->info << '(' << determinate_bfactor(x) << ')' << ' ';
			inordine(x->right);
		}
	}

	void postordine(node_arbor *x) {
		if (x != NULL) {
			postordine(x->left);
			postordine(x->right);
			cout << x->info << '(' << determinate_bfactor(x) << ')' << ' ';
		}
	}

	void nivele() {
		queue <node_arbor> C;
		C.push(root);
		while (!C.empty()) {
			node_arbor *aux = C.top();
			C.pop();
			cout << aux->info << '(' << determinate_bfactor(aux) << ')' << ' ';
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
	AVL H; int c;
	

	do {
		system("cls");
		cout << "--------------" << endl << "AVL simulator.\n" << "--------------" << endl << endl;
		cout << "1. Insert\n2. Minimum\n3. Maximum\n4. Search\n5. Remove\n6. Afisare\n7. Exit\n";
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
				if (x != NULL) {
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
				if (x != NULL) {
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
			cout << endl;
			return 0;
			break;
		}
		default: {
			cout << "\nWrong choice!\n";
			system("pause");
		}

		}

	} while (c != 7);
	return 0;
}