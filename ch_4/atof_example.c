#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double atof_ex(char s[]);
int mygetline(char s[], int lim);

int main()
{
    char line[MAXLINE];
    while (mygetline(line, MAXLINE) > 0) {
        printf("%f\n",atof_ex(line));
    }
    return 0;
}

/* 
atof: convert string s to double 
    this is a simpler version of 
    the stdlib.h function
*/
double atof_ex(char s[])
{
    double val, power;
    int i, sign;

    for ( i = 0; isspace(s[i]); i++)   /* skip whitespace */
        ;

    sign = (s[i] == '-') ? -1 : 1;      /* if next char is '-', set sign multiplier to -1, else just 1 */
    if (s[i] == '+' || s[i] == '-')     /* if that same next char is a sign, skip it since we assigned the sign variable */
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + s[i] - '0';
        power *= 10.0;
    }
    return sign * val / power;
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