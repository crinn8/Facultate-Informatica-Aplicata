# include <iostream>
# include <Windows.h>
# include <fstream>

using namespace std;

int main()
{
	ifstream f("text.txt");
	int *v,**a, n, i, j, k,x;
	f >> n;
	v = new int[n];
	for (i = 0; i < n; i++)
		f >> v[i];

	a = new int*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int [n];
	}
	for (j = 0; j < n; j++){
		a[0][j] = v[j];
		cout << a[0][j];
	}

	for (k = 0; k < n - 1; k++){
		x = v[0];
		for (i = 1; i < n; i++){
			v[i - 1] = v[i];
			a[k + 1][i - 1] = v[i];
		}
		v[n - 1] = x;
		a[k + 1][n - 1] = x;
	}
		cout << endl;

		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}

	system("pause");
}