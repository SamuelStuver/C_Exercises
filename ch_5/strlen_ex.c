#include <stdio.h>

int strlen(char *s);

int main()
{
    char *s = (char *)"Hello world test";
    printf("There are %d characters in the string \"%s\"", strlen(s), s);
    return 0;
}

/* mystrlen: return length of string s */
int strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s; /* p-s gives number of units (chars) between current p location and starting location of string */
}