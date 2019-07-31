/*
Write the function strend(s,t) which returns 1 if the string t 
occurs at the end of the string s, and zero otherwise
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strend(char *s, char *t);

int main()
{
    char *s1 = malloc(256);
    strcpy(s1, "Now is the time for all good men to come to the aid of their country");
    char *s2 = (char *)"of their country";

    if (strend(s1, s2)) {
        printf("\"%s\" occurs at the end of \"%s\"\n", s2, s1);
    } else {
        printf("\"%s\" DOES NOT occur at the end of \"%s\"\n", s2, s1);
    }

    free(s1);
    return 0;
}

int strend(char *s, char *t)
{
    int len_t = 0;
    /* find the ends of string s and t */
    while (*s++)
        ;
    while (*t++)
        len_t++;

    len_t++;
    for (; len_t > 0; len_t--){
        if (*--s != *--t) {
            return 0;
        }
    }
    return 1;
}