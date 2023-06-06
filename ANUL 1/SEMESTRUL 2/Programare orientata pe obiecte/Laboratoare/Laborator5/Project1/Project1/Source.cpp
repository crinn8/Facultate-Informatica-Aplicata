#include "Student.h"
#include "Angajat.h"
#include "StudentSalariat.h"
using namespace std;

int main()
{
	int n;
	Persoana** p;
	cout << "Dati nr de persoane:" << endl;
	cin >> n;
	p = new Persoana * [n];
	srand(unsigned int(time(0)));
	float medie, salariu;
	char facultate[100];
	for (int i = 0; i < n; i++)
	{
		int tip = rand() % 3;
		cout << "Numele si cnp-ul persoanei " << i << ":" << endl;
		char nume[100];
		long long int cnp;
		cin >> nume >> cnp;

		switch (tip)
		{
		case 0:
		{
			cout << "Facultatea si media persoanei " << i <<" :"<< endl;
			cin >> facultate >> medie;
			p[i] = new Student(nume, cnp, facultate, medie);
			break;
		}
		case 1:
		{
			cout << "Salariu persoanei: " << i << " :" << endl;
			cin >> salariu;
			p[i] = new Angajat(nume, cnp, salariu);
			break;
		}
	case2:
		{
			cout << "Facultatea, media si salariul persoanei " << i << endl;
			cin >> salariu>>medie;
			p[i] = new StudentSalariat(nume, cnp, salariu, facultate, medie);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	for (int i = 0; i < n; i++)
	{
		p[i]->Afisare();
		Student* s = dynamic_cast<Student*>(p[i]);
		if (s != nullptr)
		{
			cout << "Media este: " << s->GetMedie();
		}
		else
		{
			Angajat* a = dynamic_cast<Angajat*>(p[i]);
			if (a)
				cout << "Salariul este: " << a->GetSalariu();
			else
			{
				StudentSalariat* sa = dynamic_cast<StudentSalariat*>(p[i]);
				if (sa)
					cout << "Salariul este: " << sa->GetSalariu() << " si are media: " << sa->GetMedie();
			}
		}
		cout << endl;
	}

	/*int n;
	Persoana** p;
	cout << "Dati nr de persoane:" << endl;
	cin >> n;
	p = new Persoana * [n];
	srand(time(0));
	float medie, salariu;
	char facultate[100];
	for (int i = 0; i < n; i++)
	{
		int tip = rand() % 3;
		cout << "Numele si cnp-ul persoanei " << i<<":" << endl;
		char nume[100];
		long long int cnp;
		cin >> nume >> cnp;

		switch (tip)
		{
		case 0:
		{
			cout << "Facultatea si media persoanei:" << i << endl;
			cin >> facultate >> medie;
			p[i] = new Student(nume, cnp, facultate, medie);
			break;
		}
		case 1:
		{
			cout << "Salariu persoanei:" << i << endl;
			cin >> salariu;
			p[i] = new Angajat(nume, cnp, salariu);
			break;
		}
		default:
		{
			p[i] = new Persoana(nume, cnp);
			break;
		}
		}
	}

	for (int i = 0; i < n; i++)
	{
		p[i]->Afisare();
		Student* s = dynamic_cast<Student*>(p[i]);
		if (s != nullptr)
		{
			cout << "Media este: " << s->GetMedie();
		}
		else
		{
			Angajat* a = dynamic_cast<Angajat*>(p[i]);
			if (a)
				cout << "Salariul este: " << a->GetSalariu();
			else
				p[i]->Afisare();
		}
		cout << endl;
	}
	*/
	/*Persoana p((char*)"Pers", 153048663325);
	Student s((char*)"Student", 2546987412, (char*)"mate", 10);
	Persoana* p1 = new Student((char*)"Student1", 12365585263, (char*)"info", 9.95);
	p1->Afisare();
	Persoana* p2 = &s;
	p2->Afisare();
	Angajat a((char*)"Salariat", 15698725632, 2500);
	a.Afisare();
	Persoana* pa = &a;
	pa->Afisare();*/
	/*std::cout << p.GetNume() << std::endl;
	std::cout << p.GetCNP() << std::endl;
	p.Afisare();
	std::cout << std::endl;*/

	/*std::cout << s.GetNume() << std::endl;
	std::cout << s.GetCNP() << std::endl;
	std::cout << s.GetFacultate() << std::endl;
	std::cout << s.GetMedie() << std::endl;*/
	//s.Afisare();

	return 0;
}