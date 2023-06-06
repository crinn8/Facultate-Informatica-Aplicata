#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	int i = 100;
	cout << setfill('.');
	cout << setiosflags(ios::left);
	cout << setw(10) << "Baza 8"; 
	cout << setiosflags(ios::right);
	cout << setw(10) << oct << i << endl;
	cout << resetiosflags(ios::adjustfield);
	cout << setiosflags(ios::left);
	cout << setw(10) << "Baza 10";
	cout << setiosflags(ios::dec | ios::right);
	cout << setw(10) << i << endl;
	cout << resetiosflags(ios::adjustfield);
	cout << setiosflags(ios::left);
	cout << setw(10) << "Baza 16";
	cout << setiosflags(ios::right);
	cout << setw(10) << hex << i << endl;
}