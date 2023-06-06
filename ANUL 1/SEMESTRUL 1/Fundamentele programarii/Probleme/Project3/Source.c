#include <stdio.h>
#include<malloc.h>
union tpers
{
	char serieid[6];
	char cnp[16];
};

typedef union tpers tpers;

void main()
{
    tpers pers;
	int op;
	op = -1;
	printf("Introduceti op dvs 1 pt serie si 2 pt cnp: ");
	scanf_s("%d", &op);
	getchar();
	switch (op)
	{
	case 1:  printf("Introduceti seria buletinului");
	         gets(pers.serieid);
			 break;
	case 2:printf("Introduceti cnp-ul");
	       gets(pers.cnp);
		   break;
	default:"Date incorecte!";
	}

	printf("\n");

	switch (op)
	{
	case 1:  printf("Am citit seria buletinului");
		     break;
	case 2:printf("Am citit cnp-ul");
		gets(pers.cnp);
	}
	

	
	printf("\n");
	printf("Am citit seria buletinului %s", pers.serieid);
	printf("Am citit cnp-ul %s", pers.cnp);

}