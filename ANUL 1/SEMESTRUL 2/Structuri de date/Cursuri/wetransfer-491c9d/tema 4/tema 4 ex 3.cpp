#include<iostream>
#include<vector>
using namespace std;

struct HeapMax {
	vector<int> v;
	int d;
	HeapMax(int x) {
		this->d = x;
	}

	void display() {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';

	}

	void sift_up(int i) {
		int aux, p = (i - 1) / d;
		while (p >= 0 && v[p] < v[i]) {
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
			i = p;
			p = (i - 1) / d;
		}
	}
	void insert(int k) {
		v.push_back(k);
		sift_up(v.size() - 1);
	}

	void sift_down(int i) {
		int fiu = i, aux;
		for(int x=1;x<=d;x++)
			if (d * i + x < v.size() && v[fiu] < v[d * i + x])
				fiu = d * i + x;
		
		if (i != fiu) {
			aux = v[i];
			v[i] = v[fiu];
			v[fiu] = aux;
			sift_down(fiu);
		}
	}
	void extract_max() {
		int aux;
		aux = v[0];
		v[0] = v[v.size() - 1];
		v[v.size() - 1] = aux;
		v.pop_back();
		sift_down(0);
	}

	int det_max() {
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
	int c, d;
	cout << "d = "; cin >> d; cout << endl;

	HeapMax H(d);
	cout << "1. Insert\n2. Extract max\n3. Find max\n4. Display\n5. Exit\n";
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
				H.extract_max();
				cout << "\nComplete extraction.\n";
			}
			break; }
		case 3: {
			if (H.empty())
				cout << "\nEmpty heap.\n";
			else
				cout << "\nMaximum element is: " << H.det_max() << endl;
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