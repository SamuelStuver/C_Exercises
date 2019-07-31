/*
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. 
Good possibilities include getline(), atoi(), itoa(), reverse(), strindex(), and getop()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define MAXLINE 1000

int mygetline(char *s, int lim);
int myatoi(char *s);

int main()
{
    char line[MAXLINE];
    int len;

    printf("\n***TEST 1: GETLINE***\n");

    while ((len = mygetline(line, MAXLINE)) > 0) {
        printf("\n%s - (len: %d, strlen: %d)\n", line, len, (int)strlen(line));
        if (len != (int)strlen(line)){
            printf("\n***FUNCTION FAILED***\n");
            exit(EXIT_FAILURE);
        }
    }
    printf("\n***FUNCTION PASSED***\n");
    printf("\n***TEST 2: ATOI***\n");
    
    /* generate random integer strings with n digits to test */
    char *teststring = malloc(256);
    strcpy(teststring, "");
    srand(time(0));
    for (int n = 0; n < 5; n++){
        *teststring = (int)(rand() % 10) + '0';
        //printf("%c", c);
        teststring++;
    }
    //*teststring = '\0';
    printf("%s\n", teststring);
    if (myatoi(teststring) != atoi(teststring)){
        printf("\n***FUNCTION FAILED***\n");
        exit(EXIT_FAILURE);
    }
    free(teststring);
    
    printf("\n***FUNCTION PASSED***\n");

    return 0;
}

int mygetline(char *s, int lim){
    int c, i;

    i = 0;
    for (i=0; --lim > 0 && (c = getchar()) != EOF && c != '\n'; i++){
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return i;
}

int myatoi(char *s)
{
    while (*s++)
        ;
    return -1;
}