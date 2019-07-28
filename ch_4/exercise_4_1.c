/* Write the function strrindex(s,t) which returns the 
position of the rightmost occurrence of i in s, or -1 if there is none.

while (there is another line)
    if (the line contains the pattern)
        print it
*/

#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line length */

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching mattern */
int main()
{   
    char line[MAXLINE];
    int found = 0;

    while (mygetline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) > 0) {
            printf("\n%s", line);
            printf("\nleft index  - %d\n", strindex(line, pattern));
            printf("\nright index - %d\n", strrindex(line, pattern));
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
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++){
            ;
        }
        if (k > 0 && t[k] == '\0'){
            return i;
        }   

    }

    return -1;
}

/*** strrindex: return index of t in s, -1 if none ***/
int strrindex(char s[], char t[])
{
    /* get lengths of each string, could probably use strlen as well */
    int s_len = 0;
    int t_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }
    while (t[t_len] != '\0') {
        t_len++;
    }

    int i, j, k;
    k = t_len - 1;
    for (i = s_len-1; i >= 0; i--) {
        j = i;

        if (k == 0) {
            return i;
        }

        if (s[j] == t[k] && k > 0) {
            j--, k--;
        }
        
    }

    return -1;
}