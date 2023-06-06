#include <iostream>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class fractie
{
private:
    int numarator;
    int numitor;
    
public:
    fractie()
    {
        numarator=0;
        numitor=1;
    }

    friend istream& operator>>(istream& fi, fractie& fr);
    friend ostream& operator<<(ostream& fo, fractie& fr);

    void simplificare()
    {
        int div = cmmdc(numarator, numitor);
        numarator /= div;
        numitor /= div;
    }

    double transformareInNrZecimal()
    {
        double numar_zecimal;
        numar_zecimal = numarator / numitor;
        return numar_zecimal;
    }

    fractie operator+(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numitor + f.numarator * numitor;
        rezultat.numitor = numitor * f.numitor;
        rezultat.simplificare();
        return rezultat;
    }

    fractie operator-(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numitor - f.numarator * numitor;
        rezultat.numitor = numitor * f.numitor;
        rezultat.simplificare();
        return rezultat;
    }

    fractie operator*(fractie f)
    {
        fractie rezultat;
        rezultat.numarator = numarator * f.numarator;
        rezultat.numitor = numitor * f.numitor;
        rezultat.simplificare();
        return rezultat;
    }

    fractie operator/(fractie f)
    {
        fractie rezultat;
        std::swap(f.numarator, f.numitor);
        rezultat.numarator = numarator * f.numarator;
        rezultat.numitor = numitor * f.numitor;
        rezultat.simplificare();
        return rezultat;
    }

    fractie operator*(int n)
    {
        fractie rezultat;
        rezultat.numarator = numarator * n;
        rezultat.numitor = numitor;
        rezultat.simplificare();
        return rezultat;
    }

    friend void operator*(int n, fractie &f);

    int operator<(fractie f)
    {
        if (numarator * f.numitor < numitor * f.numarator)
            return 1;
        return 0;
    }

    int operator==(fractie f)
    {
        if (numarator * f.numitor == numitor * f.numarator)
            return 1;
        return 0;
    }

    int operator>(fractie f)
    {
        if (numarator * f.numitor > numitor * f.numarator)
            return 1;
        return 0;
    }
};

void operator*(int n, fractie& f)
{
    f.numarator *= n;
    f.simplificare();
}

istream& operator>>(istream& fi, fractie& fr)
{
    fi >> fr.numarator >> fr.numitor;
    return fi;
}

ostream& operator<<(ostream& fo, fractie& fr)
{
    fo << fr.numarator << "/" << fr.numitor;
    return fo;
}

int main()
{
    int n;
    fractie* arr;
    cin >> n;
    arr = new fractie[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    fractie s;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i] * (i + 1);
    }
    cout << s;
    return 0;
}

