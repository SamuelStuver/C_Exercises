/* Write a program to print each line of its input that 
contains a particular pattern or string of characters 

while (there is another line)
    if (the line contains the pattern)
        print it
*/

#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line length */

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching mattern */
int main()
{   
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) > 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

/* mygetline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i=0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++){
            ;
        }
        if (k > 0 && t[k] == '\0'){
            return i;
        }   

    }

    return -1;
}