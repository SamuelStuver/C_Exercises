/*
As originally written, getint() treats a + or a - with no following 
digits as a valid representation of zero. Fix it to push such a 
character back on the input.
*/

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int i, c;
    while ((c = getint(&i))) {
        printf("\nint is %d\n", i);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, c_next;

    while (isspace(c = getch())) /* skip whitespace */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);             /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c_next = getch();
        if (!isdigit(c_next)) {
            ungetch(c_next);
            ungetch(c);
        } else {
            c = c_next;
        }
    }
        
    for (*pn = 0; isdigit(c); c = getch()) /* while there continue to be digits, keep adding to value pn points to (accounting for powers of 10) */
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c); /* if there's more stuff after the digits, put it back */
    return c;
}