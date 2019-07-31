/*
Write versions of the library functions strncpy, strncat, and strncmp, 
which operate on at most the first n characters of their argument strings. 
For example, strncpy(s,t,n) copies at most n characters of t to s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);


int main()
{
    char *s1 = malloc(256);
    char *s2 = (char *)"123456789123456789";

    for (int n = 1; n < 18; n++) {
        mystrncpy(s1, s2, n);
        printf("\nn chars: %d - %s", n, s1);
        putchar('\n');
    }   
    free(s1);

    for (int n = 1; n < 18; n++) {
        char *s3 = malloc(256);
        strcpy(s3, "Append to this: ");
        mystrncat(s3, s2, n);
        printf("\nn chars: %d - %s", n, s3);
        putchar('\n');  
        free(s3);
    }

    char *s4 = malloc(256);
    strcpy(s4, "123456789000000000");
    for (int n = 1; n < 18; n++) {
        if (strncmp(s4, s2, n) > 0){
            printf("\nn chars: %d - \"%s\" > \"%s\"", n, s4, s2);
        } else if (strncmp(s4, s2, n) < 0){
            printf("\nn chars: %d - \"%s\" < \"%s\"", n, s4, s2);
        } else
        {
            printf("\nn chars: %d - \"%s\" == \"%s\"", n, s4, s2);
        }
        
    }

    return 0;
}

void mystrncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n > 0)
        ;
    *s = '\0';
}

void mystrncat(char *s, char *t, int n)
{
    /* find end of s */
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) && --n > 0)
        ;
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++,t++, n--){
        if (*s == '\0' || n == 0)
            return 0;
    }
    return *s - *t;
}