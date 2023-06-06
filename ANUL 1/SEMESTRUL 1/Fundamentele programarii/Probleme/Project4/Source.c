#include "stdio.h"
#include "malloc.h"
double** matrfloatalloc(int m, int n)
{
	double** a = (double**)malloc(m * sizeof(double*));
	for(int i=0;i<m;i++)
		a[i]= (double**)malloc(n * sizeof(double*));
	return a;
}

void** matrfloatalloc2(int m, int n,double*** a)
{
	*a = (double**)malloc(m * sizeof(double*));
	for (int i = 0; i < m; i++)
		(*a)[i] = (double**)malloc(n * sizeof(double*));
}

int Separare(int n, int* a, int* np, int** ap, int* nn, int** an)
{
	*np = 0;
	*nn = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			(*np)++;
		else 
			if (a[i] < 0)
			  (*nn)++;
	*ap = (int*)malloc(*np * sizeof(int));
	if (!*ap)
		return 0;
	*an = (int*)malloc(*nn * sizeof(int));
	if (!*an)
	{
		free(*ap);
		return 0;
	}
	*np = 0;
	*nn = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			(*ap)[(*np)++]=a[i];
		else
			if (a[i] < 0)
				(*an)[(*nn)++] = a[i];
	return 1;
}

void matrfloatfree(int m, double*** a)
{
	for (int i = 0; i < m; i++)
		free((*a)[i]);
	free(*a);
	*a = NULL;
}
void main()
{
	int n, * a, * ap, * an, np, nn;
	scanf_s("%d%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	if (Separare(n, a, &np, &ap, &nn, &an))
	{
		printf("Pozitive: ");
		for (int i = 0; i < np; i++)
			printf("%d", ap[i]);
		puts("");
		printf("Negative: ");
		for (int i = 0; i < nn; i++)
			printf("%d", an[i]);
		free(ap);
		free(an);
	}
	free(a);
	/*int m, n;
	double** matr = NULL;
	scanf_s("%d%d", &m, &n);
	//matr = matrfloatalloc(m, n);
	matrfloatalloc2(m, n, &matr);
	matrfloatfree(m, matr);*/
}