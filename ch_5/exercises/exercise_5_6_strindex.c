/*
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. 
Good possibilities include getline(), atoi(), itoa(), reverse(), strindex(), and getop()
*/

#include <stdio.h>
#include <stdlib.h>

int mystrindex(char *s, char c);

int main()
{
    int letter;

    const char *teststring = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf(teststring);
    for (letter = '0'; letter <= 'z'; letter++){
        printf("\nIndex of %c is %d", letter, mystrindex((char *)teststring, letter));
    }

    return 0;
}

int mystrindex(char *s, char c)
{
    int i;
    for (i=0; *s; i++) {
        if (*s++ == c) {
            return i;
        }
    }

    return -1;
}