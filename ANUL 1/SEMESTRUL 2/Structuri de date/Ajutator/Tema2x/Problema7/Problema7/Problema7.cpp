/*Sa se construiasca o functie care insereaza un anumit element pe o pozitie data, daca aceasta pozitie este mai mare decat ultima pozitie din lista
elementul se va insera la finalul acesteia.*/

#include <iostream>
#include <fstream>

struct NOD {
	int info;
	NOD* next;
};

struct LISTA {

	NOD* FIRST=nullptr, * LAST=nullptr;
	int  NR_ELEM = 0;

	bool EMPTY()
	{
		if (FIRST == nullptr)
			return true;
		return false;
	}

	void PUSH_FRONT(int key)
	{
		NOD* nou;
		nou = new NOD;
		nou->info = key;
		nou->next = NULL;
		LAST = nou;
		if (EMPTY() == true)
		{
			FIRST = nou;
		}
		NR_ELEM++;
	}

	void PUSH_BACK(int key)
	{
		NOD* nou;
		nou = new NOD;
		nou->info = key;
		nou->next = NULL;
		if (EMPTY() == true)
		{
			nou->next = NULL;
			LAST = nou;
			FIRST = nou;
		}
		else
		{
			LAST->next = nou;
			LAST = nou;
		}
		NR_ELEM++;
	}

	NOD* SEARCH(int key)
	{
		if (EMPTY() == false)
		{
			NOD* index;
			index = FIRST;
			while (index != LAST->next)
			{
				if (index->info == key)
					return index;
				index = index->next;
			}
		}
		return NULL;
	}

	void ERASE_Node(NOD* node)
	{
		if (EMPTY() == false)
		{
			NOD* aux = node;
			if (aux == FIRST)
			{
				FIRST = FIRST->next;
				delete aux;
			}
			else
			{
				NOD* index;
				index = FIRST;
				while (index->next != aux)
				{
					index = index->next;
				}
				index->next = aux->next;
				delete aux;
			}
			NR_ELEM--;
		}
	}

	void ERASE_Key(int key)
	{
		if (EMPTY() == false)
		{
			NOD* aux=nullptr;
			aux = SEARCH(key);
			if (aux != NULL)
			{
				ERASE_Node(aux);
			}
		}
	}

	void PRINT()
	{
		if (EMPTY() == false)
		{
			NOD* index = FIRST;
			while (index != NULL)
			{
				std::cout << index->info<<" ";
				index = index->next;
			}
		}
	}

	void CLEAR()
	{
		NOD* index = FIRST;
		if (EMPTY() == false)
		{
			while (index != NULL)
			{
				FIRST = index->next;
				NOD* aux = index;
				index = index->next;
				ERASE_Node(aux);
			}
		}
	}

	void ERASE_DOUBLES(NOD* index,int elem)
	{
		NOD* aux = index;
		while (aux != NULL)
		{
			NOD* node = aux->next;
			if (node != NULL && node->info == elem)
			{
				if (node == LAST)
				{
					LAST = aux;
				}
				aux->next = node->next;
				delete node;
				NR_ELEM--;
			}
			aux = aux->next;
		}
	}

	void ERASE_List(LISTA L)
	{
		if (EMPTY() == false)
		{
			if (L.SEARCH(FIRST->info) != NULL)
			{
				NOD* aux = FIRST;
				FIRST = FIRST->next;
				delete aux;
				NR_ELEM--;
			}
			NOD* index = L.FIRST;
			while (index != NULL)
			{
				NOD* indexL = FIRST;
				int elem = index->info;
				ERASE_DOUBLES(indexL, elem);
				index = index->next;
			}
		}
	}

	void INSERT(int poz,int element)
	{
		int nr = 0;
		NOD* index = FIRST,*nou;
		nou = new NOD;
		nou->info = element;
		if (EMPTY() == true)
		{
			nou->next = NULL;
			LAST = nou;
			FIRST = nou;
		}
		else
		{
			if (poz == 0)
			{
				nou->next = FIRST;
				FIRST = nou;
			}
			else if (poz > NR_ELEM)
			{
				LAST->next = nou;
				nou->next = NULL;
				LAST = nou;
			}
			else
			{
				while (nr < poz - 1)
				{
					index = index->next;
					nr++;
				}
				nou->next = index->next;
				index->next = nou;
			}
		}
		NR_ELEM++;
	}
};

void Meniu(LISTA List)
{
	int x;
	LISTA L;
	do
	{
		std::cout << std::endl;
		std::cout << "Introduceti optiunea: " << std::endl;
		std::cout << "1 pentru adaugarea unui element la inceputul listei" << std::endl;
		std::cout << "2 pentru adaugarea unui element la sfarsitul listei" << std::endl;
		std::cout << "3 pentru cautarea unui element in lista" << std::endl;
		std::cout << "4 pentru stergerea unui nod dat prin valoare" << std::endl;
		std::cout << "5 pentru a verifica daca lista e vida" << std::endl;
		std::cout << "6 pentru a elimina dublurile din lista" << std::endl;
		std::cout << "7 pentru a elimina din lista elementele comune cu cele din lista L" << std::endl;
		std::cout << "8 pentru a goli lista" << std::endl;
		std::cout << "9 pentru a afisa elementele listei" << std::endl;
		std::cout << "10 pentru a introduce un anumit element pe o pozitie data" << std::endl;

		std::cin >> x;
		switch (x)
		{
		case 1:
		{
			int element;
			std::cout << "Introduceti elementul dorit: ";
			std::cin >> element;
			List.PUSH_FRONT(element);
			break;
		}
		case 2:
		{
			int element;
			std::cout << "Introduceti elementul dorit: ";
			std::cin >> element;
			List.PUSH_BACK(element);
			break;
		}
		case 3:
		{
			int element;
			NOD* aux;
			std::cout << "Introduceti elementul dorit: ";
			std::cin >> element;
			aux = List.SEARCH(element);
			if (aux != NULL)
				std::cout << "Elementul introdus se afla in lista." << std::endl;
			else std::cout << "Elementul introdus nu se afla in lista." << std::endl;
			break;
		}
		case 4:
		{
			int element;
			std::cout << "Introduceti elementul dorit: ";
			std::cin >> element;
			List.ERASE_Key(element);
			break;
		}
		case 5:
		{
			if (List.EMPTY() == true)
				std::cout << "Lista este vida." << std::endl;
			else
				std::cout << "Lista nu este vida." << std::endl;
			break;
		}
		case 6:
		{
			NOD* index = List.FIRST;
			while (index != NULL)
			{
				int elem = index->info;
				List.ERASE_DOUBLES(index, elem);
				index = index->next;
			}
			break;
		}
		case 7:
		{
			std::ifstream f("Lista.in");
			int element;
			while (f >> element)
			{
				L.PUSH_BACK(element);
			}
			List.ERASE_List(L);
			break;
		}
		case 8:
		{
			List.CLEAR();
			break;
		}
		case 9:
		{
			std::cout << "Elementele listei sunt: ";
			List.PRINT();
			break;
		}
		case 10:
		{
			int element, pozitie;
			std::cout << "Introduceti elementul: ";
			std::cin >> element;
			std::cout << "Introduceti pozitia: ";
			std::cin >> pozitie;
			List.INSERT(pozitie, element);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			std::cout << "Introduceti 1,2,3,4,5,6,7,8,9,10 sau 0." << std::endl;
			break;
		}
		}
	} while (x != 0);
}

int main()
{
	LISTA List;
	Meniu(List);
	return 0;
}
