#include <iostream>

using namespace std;
int operatii(int &suma, int&produs)
{
    int aux=suma;
    suma=suma+produs;
    produs=produs*aux;
}
int main()
{
    int nr1,nr2;
    cin>>nr1>>nr2;
    operatii(nr1,nr2);
    cout<<"suma="<<nr1<<endl<<"produsul="<<nr2;
    return 0;
}
