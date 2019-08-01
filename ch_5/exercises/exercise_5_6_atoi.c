/*
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. 
Good possibilities include getline(), atoi(), itoa(), reverse(), strindex(), and getop()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAXLINE 1000

int myatoi(char *s);

int main()
{
    printf("\n***TEST 2: ATOI***\n");

    char *buffer;
    size_t bufsize = 32;
    size_t len;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while ((int)(len = getline(&buffer,&bufsize,stdin)) != EOF){
        printf("\nTest string: %9sTrue int: %11d\nMy int: %13d\n",buffer, atoi(buffer), myatoi(buffer));
        if (myatoi(buffer) != atoi((const char *)buffer)){
            printf("\n***FUNCTION FAILED***\n");
            exit(EXIT_FAILURE);
        }
    }
    
    printf("\n*FUNCTION PASSED***\n");

    return 0;
}

int myatoi(char *s)
{
    int n, sign;
    while (isspace(*s))          /* skip white space */
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        s++;
    for (n=0; isdigit(*s);) {
        n = 10 * n + (*s++ - '0');
    }
    return sign * n;
}