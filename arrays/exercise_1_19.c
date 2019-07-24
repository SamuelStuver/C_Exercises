/* write function reverse(s) that reverses the character array s
   Use it to write a program that reverses its input a line at a time */

#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 20

int getline(char line[], int maxline);
void reverse(char s[]);

/* print longest input line */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */


    while ((len = getline(line, MAXLINE)) > 0) {
        //printf("%s", line);
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c = getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse string s */
void reverse(char s[])
{
    int i, j;
    char dummy;
    i = 0;
    while (s[i] != '\0') {
        ++i;
    }          // i is now equal to the string length, minus null terminator
    j = i - 1; // assign j to length - 1
    for ( i = 0; i < j; ++i ) {
        dummy = s[i];
        s[i] = s[j];
        s[j] = dummy;
        --j;
    }

}
