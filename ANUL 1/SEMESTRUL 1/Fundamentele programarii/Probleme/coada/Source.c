#include <stdio.h>
#include <stdarg.h>

double media(int n, ...)
{
	va_list a;
	double x;
	double media = 0;

	va_start(a, n);
	for (int i = 0; i < n; i++)
	{
		x = va_arg(a, double);
		media += x;
	}
	va_end(a);

	return media / n;
}

double maxim(int n, ...)
{
	//1 tip de date din starg.h: va_list
	va_list a;
	double max = -1E10;
	double x;
	
	//3 macrocomezi: va_start(a, n);va_arg(a, double);va_end(a);
	
	va_start(a, n);
	for (int i = 0; i < n; i++)
	{
		x = va_arg(a, double);
		if (x > max)
		{
			max = x;
		}
	}
	va_end(a);

	return max;
}

void main()
{
	int n;
	double x, y, z;
	x = 1.00;
	y = 2.00;
	z = 3.00;
	printf("n=");
	scanf("%d", &n);
	printf("Media numerelor este: %.2lf\n", media(3, x, y, z));
	switch (n)
	{
	   case 2: printf("Media numerelor este: %.2lf\n", media(n, x, y)); break;
	   case 3: printf("Media numerelor este: %.2lf\n", media(n, x, y, z)); break;
	   default: break;
	}
	//printf("Maximul nr este: %.2lf\n", maxim(2, 1., 1.5));
	//printf("Maximul nr este: %.2lf\n", maxim(4,1., 2.5, 2.,2.3));
	printf("media nr este: %.2lf\n", media(3, 1., 2.5, 3.75));
	printf("media nr este: %.2lf\n", media(2, 2.5, 1.));
}