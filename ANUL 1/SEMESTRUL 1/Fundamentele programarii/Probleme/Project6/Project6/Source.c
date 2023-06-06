#include <stdio.h>
#include <string.h>
#define alipire(a,b) (a##b)

void main()
{
	/*char s[100];
	strcpy(s, alipire("Mariana", "Ana"));
	int a;
	a = alipire(10, 2);
	//printf("%d", a);
	//printf("%s", s);*/
	/*float x;
	char s[100];
	printf("%d == %d\n", sizeof x, sizeof(float));
	printf("%d != %d\n", sizeof s, sizeof(char*));*/
	/*char s[100];
	scanf("%s", s);
	printf("Am citit: %s", s);*/
	int n = 1024;
	for (; n / 10; n /= 10);
	printf("%d", n);
}