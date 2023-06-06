#include<iostream>
#include<vector>
using namespace std;

struct HeapMin {
	vector<int> v;

	void display() {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';

	}

	void sift_up(int i) {
		int aux, p = (i - 1) / 2;
		while (p >= 0 && v[p] > v[i]) {
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
			i = p;
			p = (i - 1) / 2;
		}
	}
	void insert(int k) {
		v.push_back(k);
		sift_up(v.size() - 1);
	}

	void sift_down(int i) {
		int fiu = i, aux;
		if (2 * i + 1 < v.size() && v[fiu] > v[2 * i + 1])
			fiu = 2 * i + 1;
		if (2 * i + 2 < v.size() && v[fiu] > v[2 * i + 2])
			fiu = 2 * i + 2;
		if (i != fiu) {
			aux = v[i];
			v[i] = v[fiu];
			v[fiu] = aux;
			sift_down(fiu);
		}
	}
	void extract_min() {
		int aux;
		aux = v[0];
		v[0] = v[v.size() - 1];
		v[v.size() - 1] = aux;
		v.pop_back();
		sift_down(0);
	}

	int det_min() {
		return v[0];
	}
	bool empty() {
		if (v.size() == 0)
			return 1;
		else
			return 0;
	}
};


int main() {
	HeapMin H;
	int c;
	cout << "1. Insert\n2. Extract min\n3. Find min\n4. Display\n5. Exit\n";
	do {
		cout << "\nchoice: "; cin >> c;
		switch (c) {
		case 1: {
			int i, n, luki;
			cout << "\nn = "; cin >> n;
			cout << endl;
			for (i = 0; i < n; i++) {
				cin >> luki;
				H.insert(luki);
			}
			cout << "\nInsertion completed.\n";
			break;
		}
		case 2: {
			if (H.empty())
				cout << "\nEmpty heap.\n";
			else {
				H.extract_min();
				cout << "\nComplete extraction.\n";
			}
			break; }
		case 3: {
			if (H.empty())
				cout << "\nEmpty heap.\n";
			else
				cout << "\nMinimum element is: " << H.det_min() << endl;
			break; }
		case 4: {
			if (H.empty())
				cout << "\nEmpty heap.\n";
			else {
				cout << endl;
				H.display();
				cout << endl;
			}
			break;
		}
		case 5: {
			cout << endl;
			return 0;
			break; }
		default: {cout << "\nWrong choice!\n"; break; }
		}
	} while (c != 5);


	return 0;
}