# include <iostream>
# include <fstream>
# include <Windows.h>
# include <malloc.h>

using namespace std;
int main()
{
	ifstream f("text.txt");
	ifstream g("matr1.txt");
	int **a,**b, *u, *v;
	int n, m, i, j;
	f >> n;
	a = new int *[n];
	for (i = 0; i < n; i++){
		a[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			f >> a[i][j];
		}
	}
	v = new int[2 * n + n];
	int k=0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i >= j){
				v[k] = a[i][j];
				k++;
			}
		}
	}
	for (i = 0; i < k; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	g >> m;
	b = new int *[m];
	for (i = 0; i < m; i++){
		b[i] = (int*)malloc(m*sizeof(int));
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			g >> b[i][j];
		}
	}
	
	u = new int[2 * m + m];
	int l = 0;
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			if (i >= j){
				u[l] = b[i][j];
				l++;
			}
		}
	}
	for (j = 0; j < l; j++){
		cout << u[j] << " ";
	}
	cout << endl;
	system("pause");
}
