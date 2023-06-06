#include <stdio.h>
#include <malloc.h>

struct tstiva
{
	char info;
	struct tstiva *leg; 
}*cap;

typedef struct tstiva tstiva;

int introducere(char c)
{
	struct tstiva *p;
	p = (tstiva*)malloc(sizeof(tstiva));
	if (p == NULL)
	{
		return 0;
	}
	p->info = c;
	p->leg = cap;
	cap = p;
	return 1;
}
void afisare() /* afisarea continutului stivei */
{
	struct tstiva* p = cap;
	while (p != NULL)
	{
		printf("%c ", p->info);
		p = p->leg;
	}
}

void main()
{
	char c,inf;
	tstiva* cap;
	cap = NULL;
	puts("Introduceti un caracter:");
	scanf("%c", &c);
	introducere(c);
	puts("Am introdus in stiva:");
	afisare();
}

