#include <stdio.h>
#include <malloc.h>

int getPrimaAparitie(char* s1, char* s2)
{
	char* adr;
	int poz;
	adr= strstr(s1, s2) ;
	poz = adr - s1 + 1;
	return poz;
}

void main()
{
	char *s1,*s2;
	int n =30,m=20;
	s1 = (char*)malloc(n *sizeof(char));
	if (s1 == NULL)
	{
		perror("mem ins!");
		exit(1);
	}
	s2 = (char*)malloc(m * sizeof(char));
	if (s2 == NULL)
	{
		perror("mem ins!");
		exit(1);
	}
	
	puts("Introduceti s1: ");
	gets(s1);
	puts("Introduceti s2: ");
	gets(s2);
	int  x = getPrimaAparitie(s1,s2);

	printf("%d", x);
	free(s1);
	free(s2);
}

/*
#include <stdio.h>
#include <malloc.h>

int getPrimaAparitie(char* s1, char* s2)
{
	char* adr;
	int p;

	adr = strstr(s1, s2);

	p = adr - s1 + 1;

	return p;
}

void main()
{
	char *s1, *s2;

	int n = 30, m = 20;

	int x;

	s1 = (char*) malloc(n * sizeof(char));

	if (s1 == NULL)
	{
		perror("Memorie insuficienta!");
		exit(1);
	}

	s2 = (char*)malloc(m * sizeof(char));

	if (s2 == NULL)
	{
		perror("Memorie insuficienta!");
		exit(1);
	}

	puts("Introduceti sirul de caractere s1:");
	gets(s1);

	puts("Introduceti sirul de caractere s2:");
	gets(s2);

	x = getPrimaAparitie(s1, s2);

	printf("%d", x);

	free(s1); free(s2);
}
*/