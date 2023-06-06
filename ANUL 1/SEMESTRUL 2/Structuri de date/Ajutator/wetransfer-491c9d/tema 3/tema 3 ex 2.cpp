#include <iostream>
#include<fstream>
using namespace std;

struct graf {
	int **a, n;
	~graf() {
		for (int i = 0; i < n; i++)
			delete a[i];
		delete a;
	}
	void citire() {
		ifstream f("matrice.txt");
		f >> n;
		a = new int *[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				f >> a[i][j];
	}
	bool verificare_arbore() {
		int *s = new int[n], i, j, sum;

		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = 0; j < n; j++)
				sum = sum + a[j][i];
			s[i] = sum;
		}
		j = 0; sum = 0;
		for (i = 0; i < n; i++) {
			if (s[i] == 1)
				j++;
			if (s[i] == 0)
				sum++;
		}
		if (sum == 1 && j == n - 1)
			return 1;
		return 0;
		delete[] s;
	}

};

int main() {
	graf G;
	G.citire();
	if (G.verificare_arbore() == 1)
		cout << "Graful este un arbore.\n";
	else
		cout << "Graful NU este un arbore.\n";
	return 0;
}

