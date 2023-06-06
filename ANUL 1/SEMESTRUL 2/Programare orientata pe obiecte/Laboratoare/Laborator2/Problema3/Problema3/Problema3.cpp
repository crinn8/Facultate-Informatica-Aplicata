#include <iostream>
using namespace std;

struct Complex {
    double re;
    double im;

    friend istream& operator>>(istream& fi,Complex& c)
    {
        fi >> c.re >> c.im;
        return fi;
    }
    ostream& operator<<(ostream& fo)
    {
        fo << re << "+" << im << "i" << endl;
        return fo;
    }
    Complex operator+(Complex c2)
    {
        Complex c;
        c.re = re + c2.re;
        c.im = im + c2.im;
        return c;
    }
};


Complex operator-(Complex c1, Complex c2)
{
    Complex c;
    c.re = c1.re - c2.re;
    c.im = c1.im - c2.im;
    return c;
}

Complex operator*(Complex c1, Complex c2)
{
    Complex c;
    c.re = c1.re * c2.re;
    c.im = c1.im * c2.im;
    return c;
}

Complex operator/(Complex c1, Complex c2)
{
    Complex c;
    c.re = c1.re / c2.re;
    c.im = c1.im / c2.im;
    return c;
}

ostream& operator<<(ostream& fo, Complex c)
{
    fo << c.re << "+" << c.im << "i" << endl;
    return fo;
}


int main()
{
    Complex c1, c2, c;
    cin >> c1;
    cin >> c2;
    c = c1 + c2;
    cout << c;
}
