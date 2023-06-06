#include <iostream>

/**
* Lucrare: stive , arbori binari de cautare
*/

/* Node Structure */
struct Node
{
	int data;
	Node *left;
	Node *right;
};

/* Create New Node */
Node *createNode(int data)
{
	Node *newNode = new Node();

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/* Insert Node in Binary Search Tree */
Node *insertNode(Node *root, int data)
{
	if (root == NULL)
		root = createNode(data);
	else if (data <= root->data)
		root->left = insertNode(root->left, data);
	else
		root->right = insertNode(root->right, data);

	return root;
}

/* Search Node Value in Binary Search Tree */
bool searchNode(Node *root, int data)
{
	if (root == NULL)
		return false;
	else if (data == root->data)
		return true;
	else if (data <= root->data)
		return searchNode(root->left, data);
	else
		return searchNode(root->right, data);
}

/* Find Node By Value in Binary Search Tree */
Node *findNode(Node *root, int data)
{
	Node *empty = NULL;

	if (root == NULL)
		// empty node
		return empty;
	else if (data == root->data)
		return root;
	else if (data <= root->data)
		return findNode(root->left, data);
	else
		return findNode(root->right, data);
}

void searchPredecessor(Node *root, int data)
{
	Node *search = findNode(root, data);

	if (search == NULL) {
		std::cout << "Nodul cautat nu a fost gasit in arbore" << std::endl;
	}
	else if (search->left == NULL) {
		std::cout << "Nodul nu are predecesori" << std::endl;
	}
	else {
		std::cout << "Valoare predecesor: " << search->left->data << std::endl;
	}
}

void searchSuccessor(Node *root, int data)
{
	Node *search = findNode(root, data);

	if (search == NULL) {
		std::cout << "Nodul cautat nu a fost gasit in arbore" << std::endl;
	}
	else if (search->right == NULL) {
		std::cout << "Nodul nu are succesori" << std::endl;
	}
	else {
		std::cout << "Valoare succesor: " << search->right->data << std::endl;
	}
}

/* Find Minimal Node Value in Binary Search Tree */
Node *findMinNode(Node *root)
{
	while (root->left != NULL)
		root = root->left;

	return root;
}

/* Find Minimal Node Value in Binary Search Tree */
Node *findMaxNode(Node *root)
{
	while (root->right != NULL)
		root = root->right;

	return root;
}

/* Delete Node in Binary Search Tree */
Node *deleteNode(Node *root, int data)
{
	if (root == NULL)
		return root;
	else if (data < root->data)
		root->left = deleteNode(root->left, data);
	else if (data > root->data)
		root->right = deleteNode(root->right, data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if (root->left == NULL)
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			Node *min = findMinNode(root->right);
			root->data = min->data;
			root->right = deleteNode(root->right, min->data);
		}
	}
	return root;
}

void inorder(Node* t)
{
	if (t == NULL)
		return;
	inorder(t->left);
	std::cout << t->data << " ";
	inorder(t->right);
}

void help() {
	std::cout << "Comenzi:" << std::endl;
	std::cout << "\ti : Inserare nod" << std::endl;
	std::cout << "\ts : Stergere nod" << std::endl;
	std::cout << "\ta : Afisare arbore in ordine" << std::endl;
	std::cout << "\tc : Cautare nod" << std::endl;
	std::cout << "\tn : Cautare minim" << std::endl;
	std::cout << "\tm : Cautare maxim" << std::endl;
	std::cout << "\tp : Cautare predecesor" << std::endl;
	std::cout << "\tu : Cautare succesor" << std::endl;
	std::cout << "\tq : Terminare" << std::endl;
}

int main()
{
	Node *root = NULL;

	char c;
	int n;

	help();

	while (true) {
		std::cout << "Introduceti operatie:" << std::endl;
		std::cin >> c;

		if (c == 'q') {
			return 0;
		}

		switch (c) {
			// adaugare
		case 'a':
			inorder(root);
			std::cout << std::endl;
			break;
			// inserare
		case 'i':
			std::cout << "Dati valoare nod: " << std::endl;
			std::cin >> n;
			root = insertNode(root, n);
			break;
			// stergere
		case 's':
			std::cout << "Introduceti valoare pentru stergere: " << std::endl;
			std::cin >> n;
			if (!(root = deleteNode(root, n))) {
				std::cout << "Acest element nu a fost gasit sau nu poate fi sters." << std::endl;
			}
			break;
			// cautare
		case 'c':
			std::cout << "Introduceti valoare pentru cautare: " << std::endl;
			std::cin >> n;
			if (searchNode(root, n)) {
				std::cout << "Nodul a fost gasit" << std::endl;
			}
			else {
				std::cout << "Nodul nu a fost gasit" << std::endl;
			}
			break;
			// minim
		case 'n': {
			Node *min = findMinNode(root);
			if (min == NULL) {
				std::cout << "Arbore vid!" << std::endl;
			}
			else {
				std::cout << "Minimul: " << min->data << std::endl;
			}
		} break;
			// maxim
		case 'm': {
			Node *max = findMaxNode(root);
			if (max == NULL) {
				std::cout << "Arbore vid!" << std::endl;
			}
			else {
				std::cout << "Maximul: " << max->data << std::endl;
			}
		} break;
			// nod predecesor
		case 'p':
			std::cout << "Introduceti valoare pentru cautare: " << std::endl;
			std::cin >> n;
			searchPredecessor(root, n);
			break;
			// nod succesor
		case 'u':
			std::cout << "Introduceti valoare pentru cautare: " << std::endl;
			std::cin >> n;
			searchSuccessor(root, n);
			break;
		default:
			help();
			break;
		}
	}
}
