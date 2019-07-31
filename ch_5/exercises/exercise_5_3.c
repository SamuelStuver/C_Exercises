/*
Write a pointer version of the function strcat(s,t) that copies the string t to the end of s
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcat_ptr(char *s, char *t);
void strcat_original(char s[], char t[]);

int main()
{
    char *s1 = malloc(256);
    strcpy(s1, "part 1 of string - ");
    char *s2 = (char *)"part 2 of string using pointers.\n";
    strcat_ptr(s1, s2);
    printf(s1);
    free(s1);
}


void strcat_ptr(char *s, char *t)
{
    /* find end of s */
    while (*s != '\0')
        s++;
    while ((*s++ = *t++))
        ;
}

void strcat_original(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}