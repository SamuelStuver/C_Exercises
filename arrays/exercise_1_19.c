/* write function reverse(s) that reverses the character array s
   Use it to write a program that reverses its input a line at a time */

#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 20

int getline(char line[], int maxline);
void reverse(char s[]);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */


    while ((len = getline(line, MAXLINE)) > 0) {
        printf("%s", line);
        reverse(line);
        printf("%s", line);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void reverse(char s[])
{
    int length = 0;
    int i;

    while (s[length] != '\0') {
        ++length;
    }
    char dummy[length];
    copy(dummy, s);

    i = 0;
    while ((s[i] = dummy[length - i]) != '\0') {
        ++i;
    }
}
