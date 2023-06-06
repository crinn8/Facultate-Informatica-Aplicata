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
		f.close();
	}
	
	void floyd_warshall(int x, int y) {
		int i, j, k;
		int **predecesor = new int *[n];
		int **drum = new int*[n];

		for (i = 0; i < n; i++) {
			predecesor[i] = new int[n];
			drum[i] = new int[n];
		}

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				drum[i][j] = a[i][j];
				if (a[i][j] >= 0 && i!=j)
					predecesor[i][j] = i;
				else
					predecesor[i][j] = -1;
			}
	
		for (k = 0; k < n; k++) {
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if ((a[i][k] * a[k][j] >= 0) && (i != j) && (a[i][k] > 0))
						if ((drum[i][k] + drum[k][j] < drum[i][j]) || (drum[i][j] <= 0)) {
							drum[i][j] = drum[i][k] + drum[k][j];
							predecesor[i][j] = k;
						}
		}
		
		drum_minim(x, y, predecesor);

		for (int i = 0; i < n; i++) {
			delete drum[i];
			delete predecesor[i];
		}
		delete[] drum;
		delete[] predecesor;
	}

	void drum_minim(int i, int j, int **predecesor) {
				if (predecesor[i][j] == -1)
					cout << "nu exista predecesor intre " << i + 1 << " si " << j + 1 << "\n";
				else {
					int aux = i;
					cout << "drumul cel mai scurt de la " << i + 1 << " la " << j + 1 << " : ";
					do {
						cout << aux + 1 << " ";
						aux = predecesor[aux][j];
					} while (predecesor[aux][j] != aux);

					if ((aux != i) && (aux != j))
						cout << aux + 1 << " ";
					cout << j + 1 << "\n";
				}
	}
};

int main() {
	graf G;
	G.citire();
	for(int i=0;i<G.n-1;i++)
		for (int j = i + 1; j < G.n; j++) {
			G.floyd_warshall(i,j);
			cout << endl;
		}
	return 0;
}

