/*
Write the function htoi(s) that converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0-9, a-f, A-F
EX:
7DE is a hex number
7DE = (7 * 16^2) + (13 * 16^1) + (14 * 16^0)
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAXLINE 1000
#define MINNUM 48
#define MINALPHA 97

int getline(char s[], int lim);
int htoi(char s[]);

int main()
{
    int len;
    char s[MAXLINE];


    while ((len = getline(s, MAXLINE)) > 0 ) {
        printf("%d\n", htoi(s));
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

int htoi(char s[])
{
    int len = 0;
    int c, v;
    while ((c = s[len]) != '\0'){
        ++len;
    }

    int value = 0;
    int exp = 0;
    char start;
    //printf("%d - %d***", len, htoi(s));
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
        start = 2;
    } else {
        start = 0;
    }

    for (int i = 2; len - i >= start; ++i) {
        /* for each char from end of string to beginning, add digit value (v) * 16^i to value*/
        c = tolower(s[len-i]);
        if (c > MINALPHA + 5) {
            continue;
        } else if (c >= MINALPHA) {
            v = 10 + (c - MINALPHA);
        } else if (c >= MINNUM) {
            v = c - MINNUM;
        }

        value = value + (v * pow(16, exp));
        ++exp;

    }
    return value;

}
