// probleam 5

# include <iostream>
# include <Windows.h>
# include <malloc.h>
# include <fstream>
using namespace std;

int main()
{
	ifstream f("text.txt");
	int **a, n, i, j;
	f >> n;

	a = new int *[n];
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(n*sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	// elevii care se agreeaza
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (i != j){
				if ((a[i][j] == 1) && (a[j][i] == 1))
					cout << "(" << i + 1 << " " << j + 1 << ")" << endl;
			}
		}
	}
	cout << endl << endl;
	// elevul care nu agreea za pe nimeni
	unsigned ok = 0,p=1;

	for (i = 0; i < n; i++) {
		ok = 0;
		while (ok == 0){
			for (j = 0; j < n; j++) {
				if (i != j){
					if ((a[i][j] != 0) &&(ok==0))
						ok = 1;
					else
						p++;
				}
			}
			if (p == n){
				cout << " elevul care nu agreaza pe nimeni :" << i + 1 << " ";
			}
			p = 1;
			ok = 1;
		}
	}

	cout << endl;
	// elevul care nu este agreata de nimeni
	int *fr;
	int max = 0,poz;
	fr = new int[n];
		for (i = 0; i < n; i++){
			fr[i] = 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i != j) {
					if (a[i][j]==0)
					fr[i]++;
				}
			}
		}
	for (i = 0; i < n; i++){
		if ((fr[i] != 0) && (max < fr[i])){
			max = fr[i];
			poz = i;
		}
	}
	cout <<"elevul care nu este agreat de nimeni :"<< poz+1 << " ";
	delete(a);
	delete(fr);
	system("pause");
}