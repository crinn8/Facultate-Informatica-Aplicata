#include <iostream>
#include "PriorityQueue.h"

int main()
{
    Priority_Queue c;
	int x;
	do
	{
		std::cout << "Introduceti optiunea: " << std::endl;

		std::cin >> x;
		switch (x)
		{
		case 1:
		{
			int val;
			std::cin >> val;
			c.INSERT(val);
			break;
		}
		case 2:
		{
			if (c.SIZE != -1)
			{
				std::cout << c.MAX_ELEMENT();
			}
			break;
		}
		case 3:
		{
			c.EXTRACT_MAX();
			break;
		}
		case 4:
		{
			int val,poz;
			std::cin >> poz>>val;
			c.INCREASE_KEY(poz,val);
			break;
		}
		case 5:
		{
			std::cout << std::endl;
			for (int i = 0; i < c.SIZE; i++)
			{
				std::cout << c.DATA[i] << " ";
			}
			std::cout << std::endl;
			break;
		}
		default:
		{
			std::cout << "Introduceti 1,2,3,4,5 sau 0." << std::endl;
			break;
		}
		}
	} while (x != 0);
}
