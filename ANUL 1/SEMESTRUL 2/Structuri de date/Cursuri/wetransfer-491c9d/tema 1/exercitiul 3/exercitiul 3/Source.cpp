# include <iostream>
# include <fstream>
# include <Windows.h>
# include <malloc.h>

using namespace std;

int crescattor(int *a, int n)
{
	int i;
	for (i = 0; i < n-1; i++){
		if (a[i] > a[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

int descrescattor(int *a, int n)
{
	int i;
	for (i = 0; i < n - 1; i++){
		if (a[i] < a[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	ifstream f("text.txt");
	int n, *a, i;
	f >> n;
	a = new int[n];
	for (i = 0; i < n; i++){
		f >> a[i];
	}
	if (crescattor(a, n))
		cout << "e crescator" << endl;
	else
	{
		if (descrescattor(a, n))
			cout << "e descrescator" << endl;
		else
		{
			cout << "sir neordonat" << endl;
		}
	}
	system("pause");
}
