#include <iostream>
#include <vector>
class Persoana
{
protected:
    char* nume;
    char* prenume;
    long long int tel;
public:
    Persoana()
    {
        this->nume = nullptr;
        this->prenume = nullptr;
        tel = -1;
    }
    Persoana(char* nume, char* prenume, long long int tel) : tel(tel)
    {
        if (nume)
        {
            this->nume = new char[strlen(nume) + 1];
            strcpy_s(this->nume, strlen(nume) + 1, nume);
        }
        else
            this->nume = nullptr;
        if (prenume)
        {
            this->prenume = new char[strlen(prenume) + 1];
            strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
        }
        else
            this->prenume = nullptr;
    }
    Persoana(const Persoana& p)
    {
        if (p.nume)
        {
            this->nume = new char[strlen(p.nume) + 1];
            strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
        }
        else
            this->nume = nullptr;
        if (p.prenume)
        {
            this->prenume = new char[strlen(p.prenume) + 1];
            strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
        }
        else
            this->prenume = nullptr;
        tel = p.tel;
    }
    Persoana operator=(const Persoana& p)
    {
        if (nume)
            delete[] nume;
        if (prenume)
            delete[] prenume;
        if (p.nume)
        {
            this->nume = new char[strlen(p.nume) + 1];
            strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
        }
        else
            this->nume = nullptr;
        if (p.prenume)
        {
            this->prenume = new char[strlen(p.prenume) + 1];
            strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
        }
        else
            this->prenume = nullptr;
        tel = p.tel;
    }

    virtual ~Persoana()
    {
        if (nume)
            delete[] nume;
        if (prenume)
            delete[] prenume;
    }
};

class Student : public Persoana
{
protected:
    char* facultate;
public:
    Student(char* nume, char* prenume, long long int tel, char* fac) : Persoana(nume, prenume, tel)
    {
        if (fac)
        {
            this->facultate = new char[strlen(fac) + 1];
            strcpy_s(this->facultate, strlen(fac) + 1, fac);
        }
        else
            this->facultate = nullptr;
    }
    Student(const Student& s) : Persoana(s.nume, s.prenume, s.tel)
    {
        if (s.facultate)
        {
            this->facultate = new char[strlen(s.facultate) + 1];
            strcpy_s(this->facultate, strlen(s.facultate) + 1, s.facultate);
        }
        else
            this->facultate = nullptr;
    }
    ~Student()
    {
        if (facultate)
            delete[] facultate;
    }
};

using namespace std;

int main()
{
    Persoana p((char*)"ionescu", (char*)"maria", 456525858566);
    Student s((char*)"popescu", (char*)"ion", 123456789, (char*)"mate");
    vector<Persoana*> pers = { &p, &s };
}
