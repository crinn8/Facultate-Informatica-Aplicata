// obs: daca 2 chei sunt egale, algoritmul o va introduce pe a doua la dreapta primei chei.

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<fstream>

struct bnode {
	int n;
	bnode* parent;
	std::vector<char> keys;
	std::vector<bnode*> child;

	bnode() {
		this->n = 0;
		this->parent = NULL;
	}
	~bnode() {
		keys.clear();
		child.clear();
	}

	bool operator == (const bnode& aux) {
		if (n != aux.n)
			return 0;
		for (int i = 0; i < aux.keys.size(); i++)
			if (keys[i] != aux.keys[i])
				return 0;
		return 1;
	}
	bool operator > (const bnode& aux) {
		return (keys[0] > aux.keys[0]);
	}
	friend std::ostream& operator << (std::ostream& flux, const bnode& aux) {
		std::cout << "[ ";
		for (int i = 0; i < aux.n - 1; i++)
			flux << aux.keys[i] << ',';
		flux << aux.keys[aux.n - 1];
		std::cout << " ]";
		return flux;
	}

};

struct btree {
	bnode *root; int t;

	btree(int grad) {
		this->root = NULL;
		this->t = grad;
	}

	void insert(bnode* aux, char x) {
		if (root == NULL) {
			root = new bnode;
			root->n++;
			root->keys.push_back(x);
		}
		else
			if (aux->child.size() == 0) {
				if (aux->n == 2 * t - 1) {
					spargere(aux);
					insert(root, x);
				}
				else
					if (aux->n < 2 * t - 1) {
						int i = -1;
						aux->n++;
						do {
							i++;
							if (i == aux->keys.size())
								break;
						} while (aux->keys[i] <= x);
						aux->keys.insert(aux->keys.begin() + i, x);
					}
			}
			else {
				if (aux->keys.size() == 2 * t - 1) {
					spargere(aux);
					insert(root, x);
				}
				else {
					int i = -1;
					do {
						i++;
						if (i == aux->keys.size())
							break;
					} while (aux->keys[i] <= x);
					insert(aux->child[i], x);
				}
			}
	}

	std::pair<bnode*, int> search(bnode* x, char k) {
		int i = -1;
		do {
			i++;
			if (i == x->keys.size())
				break;
		} while (k > x->keys[i]);
		if (i < x->n && k == x->keys[i]) {
			std::pair<bnode*, int> aux;
			aux.first = x;
			aux.second = i;
			return aux;
		}
		else
			if (x->child.size() == 0) {
				std::pair<bnode*, int> aux;
				aux.first = NULL;
				aux.second = -1;
				return aux;
			}
			else
				return search(x->child[i], k);
		std::pair<bnode*, int> aux;
		aux.first = NULL;
		aux.second = -1;
		return aux;
	}

	void spargere(bnode* x) {
		//daca spargem radacina:
		if (x == root) {
			bnode* a = new bnode;
			bnode* b = new bnode;
			bnode* c = new bnode;
			int mijloc = (2 * t - 1) / 2;

			a->n++;
			a->keys.push_back(x->keys[mijloc]);

			for (int i = 0; i < mijloc; i++) {
				b->n++;
				b->keys.push_back(x->keys[i]);

			}
			if (x->child.size() != 0) {
				for (int i = 0; i <= mijloc; i++)
					b->child.push_back(x->child[i]);
				for (int i = 0; i < b->child.size(); i++)
					b->child[i]->parent = b;
			}

			for (int i = mijloc + 1; i <= 2 * t - 2; i++) {
				c->n++;
				c->keys.push_back(x->keys[i]);
			}

			if (x->child.size() != 0) {
				for (int i = mijloc + 1; i < x->child.size(); i++)
					c->child.push_back(x->child[i]);
				for (int i = 0; i < b->child.size(); i++)
					c->child[i]->parent = c;
			}
			root->child.clear();
			for (int i = 0; i < root->child.size(); i++)
				delete root->child[i];
			delete root;
			root = a;
			root->child.push_back(b);
			b->parent = root;
			root->child.push_back(c);
			c->parent = root;
		}
		//daca spargem un nod oarecare:
		else {
			bnode* b = new bnode;
			bnode* c = new bnode;
			b->parent = x->parent;
			c->parent = x->parent;
			int mijloc = (2 * t - 1) / 2, poz = -1;

			x->parent->n++;
			x->parent->keys.push_back(x->keys[mijloc]);
			std::sort(x->parent->keys.begin(), x->parent->keys.end());

			for (int i = 0; i < mijloc; i++) {
				b->n++;
				b->keys.push_back(x->keys[i]);
			}

			if (x->child.size() != 0)
				for (int i = 0; i <= mijloc; i++)
					b->child.push_back(x->child[i]);
				
			if (b->child.size() != 0)
				for (int i = 0; i < b->child.size(); i++)
					b->child[i]->parent = b;

			for (int i = mijloc + 1; i <= 2 * t - 2; i++) {
				c->n++;
				c->keys.push_back(x->keys[i]);
			}

			if (x->child.size() != 0)
				for (int i = mijloc + 1; i < x->child.size(); i++)
					c->child.push_back(x->child[i]);
			if (c->child.size() != 0)
				for (int i = 0; i < c->child.size(); i++)
					c->child[i]->parent = c;
			for (int i = 0; i < x->parent->child.size(); i++)
				if (x->parent->child[i] == x) {
					poz = i;
					break;
				}
			x->parent->child.erase(x->parent->child.begin() + poz);
			x->parent->child.insert(x->parent->child.begin() + poz, b);
			x->parent->child.insert(x->parent->child.begin() + poz + 1, c);
			delete x;
		}
	}

	bool rotate_right(bnode* x, char k) {
		if (x->child.size() != 0) {
			int poz = 0;
			for (int i = 0; i < x->keys.size(); i++)
				if (x->keys[i] == k) {
					poz = i;
					break;
				}
			if (x->child[poz]->keys.size() > t - 1 && x->child[poz + 1]->keys.size() < 2 * t - 1) {
				//mutare cheie
				x->keys[poz] = x->child[poz]->keys[x->child[poz]->keys.size() - 1];
				x->child[poz]->keys.pop_back();
				x->child[poz]->n--;
				x->child[poz + 1]->keys.insert(x->child[poz + 1]->keys.begin(), k);
				x->child[poz + 1]->n++;

				if (x->child[poz]->child.size() != 0) {// mutare copil
					x->child[poz + 1]->child.insert(x->child[poz + 1]->child.begin(), x->child[poz]->child[x->child[poz]->child.size() - 1]);
					x->child[poz]->child.pop_back();
					x->child[poz + 1]->child[0]->parent = x->child[poz + 1];
				}
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}

	bool rotate_left(bnode *x, char k) {
		if (x->child.size() != 0) {
			int poz = 0;
			for (int i = 0; i < x->keys.size(); i++)
				if (x->keys[i] == k) {
					poz = i;
					break;
				}
			if (x->child[poz]->keys.size() < 2 * t - 1 && x->child[poz + 1]->keys.size() > t - 1) {
				// mutare cheie
				x->keys[poz] = x->child[poz + 1]->keys[0];
				x->child[poz + 1]->keys.erase(x->child[poz + 1]->keys.begin());
				x->child[poz + 1]->n--;
				x->child[poz]->keys.push_back(k);
				x->child[poz]->n++;
				if (x->child[poz]->child.size() != 0) {//mutare copil
					x->child[poz]->child.push_back(x->child[poz + 1]->child[0]);
					x->child[poz + 1]->child.erase(x->child[poz + 1]->child.begin());
					x->child[poz]->child[x->child[poz]->child.size() - 1]->parent = x->child[poz];
				}
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}

	bool fuziune(bnode* a, bnode* b) {

		if (a == b) // verific sa nu fie acelasi nod
			return 0;
		else
			if (a->keys.size() != t - 1 || b->keys.size() != t - 1) // verific daca ambele noduri au numarul minim de chei
				return 0;
			else
				if (a->parent != b->parent) // verific fie frati
					return 0;
				else
					if (a->parent->n < t - 1 && a->parent != root) // verific ca tatal sa aiba destule chei
						return 0;
					else {
						if (*a > *b) {
							bnode* aux = a;
							a = b;
							b = aux;
						}
						int poz;
						for (int i = 0; i < a->parent->child.size(); i++)
							if (a->parent->child[i] == a) {
								poz = i;
								break;
							}

						if (a->parent->child[poz + 1] != b) // verific sa fie vecini
							return 0;
						else {
							if (a->parent == root && a->parent->keys.size() == 1) {
								a->n++;
								a->keys.push_back(b->parent->keys[poz]);
								for (int i = 0; i < b->keys.size(); i++) {
									a->n++;
									a->keys.push_back(b->keys[i]);
								}
								if (a->child.size() != 0 && b->child.size() != 0)
									for (int i = 0; i < b->child.size(); i++) {
										b->child[i]->parent = a;
										a->child.push_back(b->child[i]);
									}
								a->parent = NULL;
								delete a->parent;
								delete b;
								root = a;
							}
							else {
								a->n++;
								a->keys.push_back(b->parent->keys[poz]);
								a->parent->n--;
								a->parent->keys.erase(a->parent->keys.begin() + poz);

								for (int i = 0; i < b->keys.size(); i++) {
									a->n++;
									a->keys.push_back(b->keys[i]);
								}
								a->parent->child.erase(a->parent->child.begin() + poz + 1);
								if (a->child.size() != 0 && b->child.size() != 0)
									for (int i = 0; i < b->child.size(); i++) {
										b->child[i]->parent = a;
										a->child.push_back(b->child[i]);
									}
								delete b;
							}
							return 1;
						}

					}
	}

	char predecesor(char c) {
		bnode* x = search(root, c).first;
		if (x->child.size() != 0) {
			int poz;
			for (int i = 0; i < x->keys.size(); i++)
				if (x->keys[i] == c) {
					poz = i;
					break;
				}
			bnode* aux = x->child[poz];
			bool ok = 0;
			while (ok == 0)
				if (aux->child.size() != 0)
					aux = aux->child[aux->child.size() - 1];
				else
					ok = 1;
			return aux->keys[aux->keys.size() - 1];
		}
		else
			return c;
	}
	   
	char succesor(char c) {
		bnode* x = search(root, c).first;
		if (x->child.size() != 0) {
			int poz;
			for (int i = 0; i < x->keys.size(); i++)
				if (x->keys[i] == c) {
					poz = i;
					break;
				}
			bnode* aux = x->child[poz + 1];
			bool ok = 0;
			while (ok == 0)
				if (aux->child.size() != 0)
					aux = aux->child[0];
				else
					ok = 1;
			return aux->keys[0];
		}
		else
			return c;
	}

	void remove(bnode* x, char c) {
		// cazul I
		if (x->child.size() == 0) {
			if (x == root) { // daca x este radacina
				if (x->keys.size() == 1) {
					delete root;
					root = NULL;
				}
				else {
					int poz;
					for (int i = 0; i < x->keys.size(); i++)
						if (x->keys[i] == c) {
							poz = i;
							break;
						}
					x->keys.erase(x->keys.begin() + poz);
					x->n--;
				}
			}
			else {
				// daca x este frunza
				if (x->keys.size() >= t) { // daca x este frunza si are t chei
					int poz;
					for (int i = 0; i < x->keys.size(); i++)
						if (x->keys[i] == c) {
							poz = i;
							break;
						}
					x->keys.erase(x->keys.begin() + poz);
					x->n--;
				}
				else {
					// daca x este frunza si NU are t chei
					int poz;
					for (int i = 0; i < x->parent->child.size(); i++)
						if (x->parent->child[i] == x) {
							poz = i;
							break;
						}
					if (poz + 1 < x->parent->child.size() && x->parent->child[poz + 1]->keys.size() == 1)
						fuziune(x->parent->child[poz], x->parent->child[poz + 1]);
					else
						if (poz - 1 >= 0 && x->parent->child[poz - 1]->keys.size() == 1) {
							bnode* aux = x->parent;
							fuziune(x->parent->child[poz - 1], x->parent->child[poz]);
							x = aux->child[poz - 1];
						}
						else
							if (poz + 1 < x->parent->child.size() && x->parent->child[poz + 1]->keys.size() == t)
								rotate_left(x->parent, x->parent->keys[poz]);
							else
								if (poz - 1 >= 0 && x->parent->child[poz - 1]->keys.size() == t)
									rotate_right(x->parent, x->parent->keys[poz - 1]);

					for (int i = 0; i < x->keys.size(); i++)
						if (x->keys[i] == c) {
							poz = i;
							break;
						}
					x->keys.erase(x->keys.begin() + poz);
					x->n--;
				}
			}
		}
		else {
			
			if (x->child.size() != 0 && x == search(x, c).first) {// cazul II
				int i;
				for (int poz = 0; poz < x->keys.size(); poz++)
					if (x->keys[poz] == c) {
						i = poz;
						break;
					}
				if (x->child[i]->keys.size() >= t) {// cazul II a)
					char k = predecesor(c);
					for (int j = 0; j < x->keys.size(); j++)
						if (x->keys[j] == c)
							x->keys[j] = k;
					remove(x->child[i], k);
				}
				else {
					if (x->child[i + 1]->keys.size() >= t) {// cazul II b)
						char k = succesor(c);
						for (int j = 0; j < x->keys.size(); j++)
							if (x->keys[j] == c)
								x->keys[j] = k;
						remove(x->child[i + 1], k);
					}
					else {// cazul II c)
						fuziune(x->child[i], x->child[i + 1]);
						remove(x->child[i], c);
					}

				}
			}
			else {
				// cazul III
				if (x->child.size() != 0 && x != search(x, c).first) {
					int i = -1;
					do {
						i++;
						if (i == x->keys.size())
							break;
					} while (c > x->keys[i]);
					if (x->child[i]->keys.size() >= t)
						remove(x->child[i], c);
					else {
						// cazul III a)
						if (i + 1 < x->child.size() && x->child[i + 1]->keys.size() >= t) {
							rotate_left(x, x->keys[i]);
							remove(x->child[i], c);
						}
						else
							if (i - 1 >= 0 && x->child[i - 1]->keys.size() >= t) {
								rotate_right(x, x->keys[i - 1]);
								remove(x->child[i], c);
							}
							else { // cazul III b)
								if (i + 1 < x->child.size() && x->child[i + 1]->keys.size() == t - 1) {
									if (x->child[i]->parent == root && x->child[i + 1]->parent == root) {// fuziune cu radacina
										fuziune(x->child[i], x->child[i + 1]);
										remove(root, c);
									}
									else {// fuziune normala
										bnode* aux = x;
										fuziune(x->child[i], x->child[i + 1]);
										remove(aux->child[i], c);
									}
								}
								else
									if (i - 1 >= 0 && x->child[i - 1]->keys.size() == t - 1) {
										if (x->child[i]->parent == root && x->child[i - 1]->parent == root) {// fuziune cu radacina
											fuziune(x->child[i], x->child[i - 1]);
											remove(root, c);
										}
										else {// fuziune normala
											bnode* aux = x;
											fuziune(x->child[i], x->child[i - 1]);
											remove(aux->child[i - 1], c);
										}
									}
							}
					}

				}

			}

		}

	}

	bool empty() {
		if (root == NULL)
			return 1;
		return 0;
	}

	void afisare(bnode* x) {
		if (root == NULL)
			std::cout << "The b-tree is empty!\n";
		else {
			std::cout << "[ ";
			for (int i = 0; i < x->n - 1; i++)
				std::cout << x->keys[i] << ", ";
			std::cout << x->keys[x->n - 1] << " ] ";
			if (x->child.size() != 0) {
				for (int i = 0; i <= x->n; i++)
					afisare(x->child[i]);
			}
		}
	}
};

int main() {
	std::ifstream f("in.txt");
	int grad, choice, ok = 0;
	/*std::cout << "\nEnter constant t of the b-tree: "; std::cin >> grad;*/f >> grad;
	btree T(grad);

	do {
		if (ok)system("cls");
		ok++;
		std::cout << "\n   B-tree Simulator\n";
		std::cout << "\n1. Insert\n2. Search\n3 .Afisare\n4. Rotate right\n5. Rotate left";
		std::cout << "\n6. Stergere\n7. Predecesor\n8. Succesor\n9. Exit\n\n";
		std::cout << "choice: "; std::cin >> choice;

		switch (choice) {
		case 1: {
			int n; char c;
			/*std::cout << "\nn = "; std::cin >> n; std::cout << std::endl;*/f >> n;
			for (int i = 0; i < n; i++) {
				/*std::cin >> c;*/
				f >> c;
				T.insert(T.root, c);
			}
			std::cout << "\nInsertion completed!\n\n";
			system("pause");
			break;
		}
		case 2: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value you want: "; std::cin >> c;
				std::pair<bnode*, int> pereche;
				pereche = T.search(T.root, c);
				if (pereche.first == NULL)
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";
				else {
					std::cout << "\nThe value you're looking for is in the node " << *pereche.first << " on the position ";
					std::cout << pereche.second << ".\n\n";
				}
			}
			system("pause");
			break;
		}
		case 3: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				std::cout << "\nThe b-tree is:\n\n"; T.afisare(T.root);
				std::cout << std::endl << std::endl;
			}
			system("pause");
			break;
		}
		case 4: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value after which do you want to make the rotation: "; std::cin >> c;
				std::pair<bnode*, int> pereche;
				pereche = T.search(T.root, c);
				if (pereche.first == NULL)
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";
				else {
					bnode* x = pereche.first;
					if (T.rotate_right(x, c) == 0)
						std::cout << "\nRotation can not be done!";
					else {
						std::cout << "\nThe new b-tree is:\n\n"; T.afisare(T.root);
					}
					std::cout << std::endl << std::endl;
				}
			}
			system("pause");
			break;
		}
		case 5: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value after which do you want to make the rotation: "; std::cin >> c;
				std::pair<bnode*, int> pereche;
				pereche = T.search(T.root, c);
				if (pereche.first == NULL)
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";
				else {
					bnode* x = pereche.first;
					if (T.rotate_left(x, c) == 0)
						std::cout << "\nRotation can not be done!";
					else {
						std::cout << "\nThe new b-tree is:\n\n"; T.afisare(T.root);
					}
					std::cout << std::endl << std::endl;
				}

			}
			system("pause");
			break;

		}
		case 6: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value you want: "; std::cin >> c;
				std::pair<bnode*, int> pereche;
				pereche = T.search(T.root, c);
				if (pereche.first == NULL)
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";
				else {
					T.remove(T.root, c);
					std::cout << "\nOperation completed! The new b-tree is:\n\n";
					T.afisare(T.root); std::cout << ".\n\n";
				}
			}
			system("pause");
			break;
		}
		case 7: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value you want: "; std::cin >> c;
				std::pair<bnode*, int>pereche;
				pereche = T.search(T.root, c);
				if (pereche.first != NULL)
					std::cout << "\nPredecesorul lui " << c << " este " << T.predecesor(c) << ".\n\n";
				else
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";
			}
			system("pause");
			break;
		}
		case 8: {
			if (T.empty())
				std::cout << "\nEmpty b-tree!\n\n";
			else {
				char c;
				std::cout << "\nEnter the value you want: "; std::cin >> c;
				std::pair<bnode*, int>pereche;
				pereche = T.search(T.root, c);
				if (pereche.first != NULL)
					std::cout << "\nSuccesorul lui " << c << " este " << T.succesor(c) << ".\n\n";
				else
					std::cout << "\nThe key " << c << " doesn't exist in b-tree.\n\n";

			}
			system("pause");
			break;
		}
		case 9: {
			std::cout << "\nBye bye!\n\n";
			return 0;
			system("pause");
			break;
		}
		default: {
			std::cout << "\nWrong choice!\n\n";
			system("pause");
		}

		}

	} while (choice != 9);
	/*f.close();*/
	return 0;
}