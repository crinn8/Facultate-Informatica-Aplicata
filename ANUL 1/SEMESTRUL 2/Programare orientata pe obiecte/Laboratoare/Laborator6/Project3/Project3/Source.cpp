#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("test.txt");
	if (f.bad())
	{
		cout << "Nu s-a deschis fisierul." << endl;
		return 1;
	}
	char s[100];
	int bufsize = 10;
	while (!f.eof())
	{
		f.read(s, bufsize);
		s[f.gcount()] = '\0';
		cout << s << endl;
	}
	/*int n = 0;
	while (!f.eof())
	{
		f.getline(s, 100);
		n++;
		cout << s << endl;
	}*/

	/*int n;
	f >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete[] a;*/

	return 0;
}