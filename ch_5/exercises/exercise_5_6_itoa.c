/*
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing. 
Good possibilities include getline(), atoi(), itoa(), reverse(), strindex(), and getop()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void myitoa(int n, char *s);
void myreverse_num(char *s);
int string_length(char *pointer);

int main()
{
    printf("\n***TEST 3: ITOA***\n");

    int n;
    char *buffer_test = malloc(256);
    char *buffer_true = malloc(256);

    for (n=-1000; n <= 1000; n++) {
        
        myitoa(n, buffer_test);
        itoa(n,buffer_true,10);
        printf("\nTest int: %d -> %s (%s)\n", n, buffer_test, buffer_true);
        //printf("%d", strcmp(buffer_test, buffer_true));
        if (strcmp(buffer_test, buffer_true)){
            printf("\n*FUNCTION FAILED***");
            free(buffer_test);
            free(buffer_true);
            exit(EXIT_FAILURE);
        }
    }
    
    
    printf("\n*FUNCTION PASSED***\n");
    free(buffer_test);
    free(buffer_true);

    return 0;
}

void myitoa(int n, char *s)
{
    /* FIND N DIGITS: */
    int n_chars = 0;

    if (n < 0) {
        *s++ = '-';
        n = -n;
        n_chars++;
    }
    while (n / 10){     /* while n >= 10 or n <= -10 */
        *s++ = (n % 10) + '0';
        n /= 10; 
        n_chars++;
    }
    *s++ = n + '0';
    *s = '\0';
    n_chars++;
    s -= n_chars;
    printf(s);
    myreverse_num(s);

}

void myreverse_num(char *s)
{
    int length, c;
    char *begin, *end, temp;
 
    length = string_length(s);
    begin  = s;
    end    = s;

    if (*s == '-') {
        begin++;
    }
 
    for (c = 0; c < length - 1; c++)
        end++;
 
    for (c = 0; c < length/2; c++)
    {        
        temp   = *end;
        *end   = *begin;
        *begin = temp;
 
        begin++;
        end--;
   }
}
 
int string_length(char *pointer)
{
    int c = 0;
 
    while( *(pointer + c) != '\0' )
    c++;
 
    return c;
}