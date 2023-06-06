#include <iostream>
#include <cstring>
using namespace std;

class Persoana 
{
private:
    char nume[20];
    int anul_nasterii;
    float salariu;

public:

    float get_salariu()
    {
        return salariu;
    }

    float get_anul_nasterii()
    {
        return anul_nasterii;
    }

    char* get_nume()
    {
        return nume;
    }

    friend istream& operator>>(istream& fi, Persoana& p);
    friend ostream& operator<<(ostream& fo,Persoana& p);

    int operator<(Persoana p)
    {
        return strcmp(nume, p.nume);
    }

    int operator!()
    {
        return 2021 - anul_nasterii;
    }

    friend void operator*(Persoana &p, float c);

};

void operator*(Persoana& p, float c)
{
    p.salariu = p.salariu * (100 + c) / 100;
}

istream& operator>>(istream& fi, Persoana& p)
{
    fi >> p.nume;
    fi >> p.anul_nasterii;
    fi >> p.salariu;
    return fi;
}

ostream& operator<<(ostream& fo, Persoana& p)
{
    fo << p.nume<<" ";
    fo << p.anul_nasterii<<" ";
    fo << p.salariu<<" ";
    return fo;
}

int main()
{
    int n;
    Persoana* arr;
    cin >> n;
    arr = new Persoana[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (!arr[i] > 25)
        {
            arr[i]*25;
            cout << arr[i] << " ";
            cout << endl;
        }
    }

    delete[] arr;

    return 0;
}
