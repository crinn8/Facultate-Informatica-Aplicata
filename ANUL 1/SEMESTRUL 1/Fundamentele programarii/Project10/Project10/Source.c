#include <stdio.h> 
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>


int main()
{
    char* s = "axyz";
    printf("%c%c", *s + 1, *(s + 1));
    return 0;
}