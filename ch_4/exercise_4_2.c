/****************
Extend atof_ex to handle scientific notation of the form 123.45e-6
where a floating point number may be followed by e or E 
and an optionally signed exponent
*****************/

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
    int i, sign, exp_sign, exponent;

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
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    exp_sign = (s[i] == '-') ? -1 : 1;      /* if next char is '-', set exponent sign multiplier to -1, else just 1 */
    if (s[i] == '+' || s[i] == '-')         /* if that same next char is a sign, skip it since we assigned the exp_sign variable */
        i++;
    for (exponent = 0; isdigit(s[i]); i++) {
        exponent = 10 * exponent + (s[i] - '0');
        
    }
    exponent = exponent * exp_sign;
    while (exponent != 0) {
        if (exponent > 0) {
            power = power / 10;
            exponent--;
        } 
        if (exponent < 0) {
            power = power * 10;
            exponent++;
        }
        
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