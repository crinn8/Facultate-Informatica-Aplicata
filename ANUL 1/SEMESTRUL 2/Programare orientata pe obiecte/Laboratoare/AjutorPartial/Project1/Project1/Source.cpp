#include <iostream>
#include "Mamifer.h"
#include "MamiferAcvatic.h"
#include "MamiferTerestru.h"
#include "Delfin.h"
#include "Caine.h"
#include "Foca.h"
using namespace std;

int main()
{
	string mediu_de_viata;
	cin >> mediu_de_viata;
	Foca m(mediu_de_viata);
	cout <<m.GetMediuDeViata()<<" "<<m.GetSunet()<<" "<<m.GetNrPicioare()<<" "<<m.GetNume();
	return 0;
}