# include <iostream>
# include <fstream>
# include <Windows.h>
# include <malloc.h>

using namespace std;

int main()
{
	ifstream f("text.txt");
	int **a, n, m, i, j;
	f >> n;
	f >> m;
	a = new int *[n]; 
	for (i = 0; i < n; i++){
		a[i] = new int[n]; 
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			f >> a[i][j];
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	unsigned x;
	cout << "dati linia si coloana care se va sterge" << endl;  cin >> x;
	for (i = x; i < n-1; i++){
		for (j = 0; j < m; j++){
			a[i][j] = a[i + 1][j];
		}
	}
	for (j = x; j < m - 1; j++){
		for (i = 0; i < n; i++){
			a[i][j] = a[i][j + 1];
		}
	}
	n--;
	m--;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}