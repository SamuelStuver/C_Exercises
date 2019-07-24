/* Write a program to "fold" long input lines into two or more shorter lines
   after the last non-blank character that occurs before the n-th column of
   input. Make sure your program does something intelligent with very long
   lines, and if there are no blanks or tabs before the specified column. */

/* My notes: replace last blank/tab before nth column with newline character */

#include <stdio.h>
#define MAXLINE 1000
#define WRAPLINE 20

int getline(char line[], int maxline);
void copy(char to[], char from[]);


main()
{
    int len; /* current line length */
    int i;
    int start = 0;
    int space_found;
    char line[MAXLINE]; /* current input line */

    space_found = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        while (start <= len) {
            i = WRAPLINE;
            while (space_found == 0) {
                if (line[i] == ' ' || line[i] == '\t') {
                    space_found = 1;
                    line[i] = '\n';
                } else {
                    --i;
                }
                if (i == start) {
                    line[WRAPLINE] = '\n';
                    start += WRAPLINE;
                    len -= WRAPLINE;
                }
            }
        }
        printf("%s", line);
        space_found = 0;
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
