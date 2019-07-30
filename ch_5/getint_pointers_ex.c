#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int i = 0;
    while ((getint(&i)) != EOF){
        printf("\nint is %d\n", i);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip whitespace */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);             /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch()) /* while there continue to be digits, keep adding to value pn points to (accounting for powers of 10) */
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c); /* if there's more stuff after the digits, put it back */
    return c;
}