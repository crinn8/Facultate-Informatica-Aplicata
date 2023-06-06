/*Func?ie care prime?te ca primi parametrii lungimea unui vector de numere întregi
precum ?i pointerul c?tre acest vector.S? se construiasc? un alt vector(alocat
dinamic) format cu elementele care sunt numere prime ale vectorului ini?ial.S? se
returneze prin referin?? lungimea vectorului construit precum ?i pointerul c?tre noul vector.*/

#include <iostream>

using namespace std;

bool prim(int x, int d = 2)
{
    if (x == 0 || x == 1)
        return false;
    if (d > x / 2)
        return true;
    if (x % d == 0)
        return false;
    return prim(x, d + 1);
}

void vect(int n,int *a,int &m,int *&nou)
{
    int contor = 0;
    for (int i = 0; i < n; i++)
    {
        if (prim(a[i] == true))
            contor++;
    }
    nou=new int[contor];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (prim(a[i] == true))
        {
            nou[j] = a[i];
            j++;
        }
    }
    m = contor;
}

int main()
{
    int n,m,*nou;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    vect(n, a,m,nou);
    for (int i = 0; i < n; i++)
        cout << nou[i] << " ";

    delete[] a;
    return 0;
}
