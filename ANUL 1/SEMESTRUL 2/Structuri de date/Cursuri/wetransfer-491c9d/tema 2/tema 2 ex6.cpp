#include<iostream>
#include<fstream>
using namespace std;

struct coord {
	int x, y;
};

struct queue {
	struct nod {
		coord info;
		nod *leg;
	};
	nod *prim, *ultim;
	queue() {
		prim = NULL;
		ultim = NULL;
	}
	void push(coord n) {
		nod *x; x = new nod;
		x->info = n;
		x->leg = NULL;
		if (prim == NULL) {
			prim = x; ultim = x;
		}
		else {
			ultim->leg = x;
			ultim = x;
		}
	};
	void pop() {
		if (prim != NULL) {
			nod *y; y = new nod;
			y = prim;
			prim = prim->leg;
			delete y;
		}
	};
	bool empty() {
		if (prim == NULL)
			return 1;
		else
			return 0;

	}
	coord front() {
		if (prim != NULL)
			return prim->info;
	}
};

void citire(int a[100][100], unsigned &n, unsigned &m, coord &soricel, coord &branza) {
	ifstream f("labirint.txt");
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f >> a[i][j];
	f >> soricel.x >> soricel.y >> branza.x >> branza.y;
	f.close();
}

void afisare(int a[100][100], unsigned n, unsigned m, coord start, coord branza) {

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == start.x && j == start.y)
				cout << " S ";
			else
				if (i == branza.x && j == branza.y)
					cout << " B ";
				else
					if (a[i][j] == -1)
						cout << ' ' << (char)223 << ' ';
					else
						cout << "   ";
		}
		cout << endl;
	}
}

void bordare(int a[100][100], unsigned &n, unsigned &m) {
	int i;
	for (i = 1; i <= n; i++)
		a[i][0] = a[i][m + 1] = -1;
	m++;
	for (i = 0; i <= m; i++)
		a[0][i] = a[n + 1][i] = -1;

	n++;
}

void lee(int a[100][100], unsigned n, unsigned m, coord &soricel, coord &branza) {
	unsigned  ok = 0, ok2 = 0, q, k = 0;
	int b[100][100], c[100][100];
	queue coada, coada2;
	coord aux, start, stop, v[100];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			b[i][j] = a[i][j];

	start = soricel; stop = branza;

	coada.push(soricel);
	while (!coada.empty() && ok == 0) {
		soricel = coada.front();
		coada.pop();
		if (a[soricel.x - 1][soricel.y] == 0) // sus
		{
			a[soricel.x - 1][soricel.y] = a[soricel.x][soricel.y] + 1;
			aux.x = soricel.x - 1;
			aux.y = soricel.y;
			coada.push(aux);
			if (aux.x == branza.x && aux.y == branza.y) {
				ok = 1; q = a[soricel.x - 1][soricel.y];
			}
			v[k] = aux; k++;

		}
		if (a[soricel.x][soricel.y + 1] == 0) // dreapta
		{
			a[soricel.x][soricel.y + 1] = a[soricel.x][soricel.y] + 1;
			aux.x = soricel.x;
			aux.y = soricel.y + 1;
			coada.push(aux);
			if (aux.x == branza.x && aux.y == branza.y) {
				ok = 1; q = a[soricel.x][soricel.y + 1];
			}
			v[k] = aux; k++;
		}
		if (a[soricel.x + 1][soricel.y] == 0) // jos
		{
			a[soricel.x + 1][soricel.y] = a[soricel.x][soricel.y] + 1;
			aux.x = soricel.x + 1;
			aux.y = soricel.y;
			coada.push(aux);
			if (aux.x == branza.x && aux.y == branza.y) {
				ok = 1; q = a[soricel.x + 1][soricel.y];
			}
			v[k] = aux; k++;
		}
		if (a[soricel.x][soricel.y - 1] == 0) // stanga
		{
			a[soricel.x][soricel.y - 1] = a[soricel.x][soricel.y] + 1;
			aux.x = soricel.x;
			aux.y = soricel.y - 1;
			coada.push(aux);
			if (aux.x == branza.x && aux.y == branza.y) {
				ok = 1; q = a[soricel.x][soricel.y - 1];
			}
			v[k] = aux; k++;
		}
	}
	cout << endl << "Labirintul dat este urmatorul:" << endl << endl; afisare(a, n, m, start, branza);

	soricel = branza;
	branza = start;
	coada2.push(soricel);
	while (!coada2.empty() && ok2 == 0) {
		soricel = coada2.front();
		coada2.pop();
		if (b[soricel.x - 1][soricel.y] == 0) // sus
		{
			b[soricel.x - 1][soricel.y] = b[soricel.x][soricel.y] + 1;
			aux.x = soricel.x - 1;
			aux.y = soricel.y;
			coada2.push(aux);
			if (aux.x == branza.x && aux.y == branza.y)
				ok2 = 1;



		}
		if (b[soricel.x][soricel.y + 1] == 0) // dreapta
		{
			b[soricel.x][soricel.y + 1] = b[soricel.x][soricel.y] + 1;
			aux.x = soricel.x;
			aux.y = soricel.y + 1;
			coada2.push(aux);
			if (aux.x == branza.x && aux.y == branza.y)
				ok2 = 1;


		}
		if (b[soricel.x + 1][soricel.y] == 0) // jos
		{
			b[soricel.x + 1][soricel.y] = b[soricel.x][soricel.y] + 1;
			aux.x = soricel.x + 1;
			aux.y = soricel.y;
			coada2.push(aux);
			if (aux.x == branza.x && aux.y == branza.y)
				ok2 = 1;


		}
		if (b[soricel.x][soricel.y - 1] == 0) // stanga
		{
			b[soricel.x][soricel.y - 1] = b[soricel.x][soricel.y] + 1;
			aux.x = soricel.x;
			aux.y = soricel.y - 1;
			coada2.push(aux);
			if (aux.x == branza.x && aux.y == branza.y)
				ok2 = 1;


		}
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (a[i][j] == -1 && b[i][j] == -1)
				c[i][j] = -1;
			else
				if (a[i][j] + b[i][j] == q)
					c[i][j] = 0;
				else
					c[i][j] = -1;

	if (ok == 0)
		cout << endl << "Soricelul NU poate ajunge la branza." << endl << endl;
	else {
		cout << endl << "Soricelul va face " << q << " mutari." << endl << endl;
		cout << "Traseul cel mai scurt este urmatorul:" << endl << endl;
		afisare(c, n, m, start, stop);
	}
}

int main() {
	coord branza, soricel;
	int a[100][100]; unsigned n, m;

	citire(a, n, m, soricel, branza);
	bordare(a, n, m);
	lee(a, n, m, soricel, branza);

	return 0;
}