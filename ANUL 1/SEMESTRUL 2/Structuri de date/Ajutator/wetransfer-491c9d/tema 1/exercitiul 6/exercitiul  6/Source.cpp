# include <iostream>
# include <Windows.h>
# include <malloc.h>
# include <conio.h>
//# include <fstream>

using namespace std;

int main()
{
	//ofstream g("text".txt);
	int **a;
	int n, i, j, m, d = 1,l,c;
	cout << "n:" << endl;
	cin >> n;
	m = n;
	a = new int *[n];
	for (i = 0; i < n; i++){
		a[i] = (int*)malloc(n*sizeof(int));
	}
	
	// nr impare
	int p=1,r=1;
	if (n % 2 != 0){
		a[(n - 1) / 2][(n - 1) / 2] = p;
		cout << a[(n - 1) / 2][(n - 1) / 2] << " ";
		for (j = (n - 1) / 2 - 1; j >= 0; j--){
			a[(n - 1) / 2][j] = p + 1;
			p++;
			cout << a[(n - 1) / 2][j] << " ";
		}
		for (i = (n - 1) / 2 + 1; i < n; i++){
			a[i][0] = p + 1;
			p++;
			cout << a[i][0] << " ";
		}
		for (j = 1; j < n; j++){
			a[n - 1][j] = p + 1;
			p++;
			cout << a[n - 1][j] << " ";
		}
		for (i = n - 2; i >= 0; i--){
			a[i][n - 1] = p + 1;
			p++;
			cout << a[i][n - 1] << " ";
		}
		for (j = n - 2; j >= 0; j--){
			a[0][j] = p + 1;
			p++;
			cout << a[0][j] << " ";
		}
		for (i = 0; i < (n - 1) / 2 - 1; i++){
			a[i][0] = p + 1;
			p++;
			cout << a[i][0] << " ";
		}
		cout << endl;
	}
	///  nr pare
	else
	{
		l = 0;
		c = n - 1;
		while ((d < m / 2)){
			for (j = l; j < n; j++){
				a[l][j] = r;
				r++;
				cout << a[l][j] << " ";
			}
			for (i = l + 1; i < n; i++){
				a[i][c] = r;
				r++;
				cout << a[i][c] << " ";
			}
			for (j = c - 1; j >= l; j--){
				a[c][j] = r;
				r++;
				cout << a[c][j] << " ";
			}
			for (i = c - 1; i>l; i--){
				a[i][l] = r;
				r++;
				cout << a[i][l] << " ";
			}
			d++;
			l = l + 1;
			n = n - 1;
			c = c - 1;
			cout << "......................" << endl;
		}
		if (d == m / 2){
			a[l][l] = r;
			r++;
			a[l][l + 1] = r;
			r++;
			a[l + 1][l + 1] = r;
			r++;
			a[l + 1][l] = r;
			r++;
		}
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < m; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	delete(a);
	_getch();
}