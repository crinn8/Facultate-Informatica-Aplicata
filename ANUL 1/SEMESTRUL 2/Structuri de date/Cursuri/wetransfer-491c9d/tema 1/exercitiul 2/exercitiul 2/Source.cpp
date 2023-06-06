# include <iostream>
# include <fstream>
# include <Windows.h>
# include <malloc.h>

using namespace std;

int main(){
	int n,i,m=100;
	int *a;
	int *fr;
	ifstream f("text.txt");
	f >> n;
	fr = new int[m];
	for (i = 0; i < m; i++){
		fr[i] = 0;
	}
	a = new int[n];    
	for (i = 0; i < n; i++){
		f >> a[i];
		fr[a[i]]++;
	}
	int max=0,poz;
	for (i = 0; i < 100; i++){
		if ((fr[i] != 0) && (max < fr[i])){
			max = fr[i];
			poz = i;
		}
	}
	cout << " numarul "<<poz << " apare de : "<<max<<" ori"<<endl;
	delete(a);
	delete(fr);
	system("pause");
}