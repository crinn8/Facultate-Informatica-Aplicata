#include <iostream>

using namespace std;

int  verificare(int n,int v[])
{
    int fr[n+1];
    for(int i=0;i<=n;i++)
        fr[i]=0;
    for(int i=0;i<n;i++)
        fr[v[i]]++;
    int ok=0;
    for(int i=1;i<=n;i++)
        if(fr[i]!=1) ok=1;
        return ok;
}
int main()
{
    int n;
    cin>>n;
    int v[n+1];
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(verificare(n,v)==0) cout<<"elementele tabloului sunt toate distincte";
    else cout<<"exista o pereche de elemente cu aceeasi valoare";
    return 0;
}
