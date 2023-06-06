# include <iostream>
# include <Windows.h>
# include <malloc.h>
# include <fstream>
using namespace std;

int main()
{
	ifstream f("text.txt");
	int n, i, j, s = 0;
	int **a;
	f >> n;
	a = new int *[n];
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j<n; j++){
			f >> a[i][j];
		}
	}
	while (n > 1)
	{
		for (j = 0; j < n; j++){
			s = s + a[0][j];
		}
		for (i = 1; i < n; i++){
			s = s + a[i][n - 1];
		}
		for (j = n - 2; j >= 0; j--){
			s = s + a[n-1][j];
		}
		for (i = n - 2; i>0; i--){
			s = s + a[i][0];
		}
		cout << s << endl;
		s = 0;
		n--;
		for (i = 0; i < n - 1; i++){
			for (j = 0; j < n; j++){
				a[i][j] = a[i + 1][j];
			}
		}
		for (j = 0; j < n - 1; j++){
			for (i = 0; i < n; i++){
				a[i][j] = a[i][j + 1];
			}
		}
		n--;
	}
	cout << a[n][n] << endl;
	delete(a);
	system("pause");
}