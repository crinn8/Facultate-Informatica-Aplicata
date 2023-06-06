# include <iostream>
# include <conio.h>
#include <fstream>
# include <malloc.h>

using namespace std;

int main()
{
	ifstream f("text.txt");
	int *a;
	int n, i, min ,poz,nr=0;
	f >> n;
	a = new int[n];
	for (i = 0; i < n; i++){
		f >> a[i];
	}
	min = a[0];
	for (i = 1; i < n; i++){
		if (min>a[i]){
			nr = 0;
			min = a[i];
			nr++;
		}
		else
		{
			if (min == a[i]){
				nr++;
			}
		}
	}
	cout << min << "de :" << nr <<"ori"<< endl;
	_getch();
}