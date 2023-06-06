
#include <iostream>
using namespace std;

void CitireMatrice(int n, int a[100][100])
{
	cout << "Introduceti elementele matricei: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}


void ParcurgereSiAfisareMatrice(int n, int a[100][100])
{
	cout << endl;
	for (int k = 0; k <= 2*n-2; k++)
	{
		
		if (k % 2 == 1)
		{
			if (k < n)
				for (int i = k; i >= 0; i--)
					cout << a[i][k - i]<<" ";
			else 
				for (int i = n-1; i >= k-n+1; i--)
					cout << a[i][k - i]<<" ";
		}
		if(k%2==0)
		{
			if (k < n)
				for (int i = 0; i <= k; i++)
					cout << a[i][k - i]<<" ";
			else
				for (int i = k-n + 1; i <= n- 1; i++)
					cout << a[i][k - i]<<" ";
		}
	}
}

int main()
{
	int n, a[100][100];
	cout << "Introduceti numarul de elemente ale matricei: ";
	cin >> n;
	cout << endl;
	CitireMatrice(n, a);
	ParcurgereSiAfisareMatrice(n, a);
	return 0;
}
