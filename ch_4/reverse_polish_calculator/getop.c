#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* 
getop: get next operator or numeric operand
-Skip blanks and tabs
-if next character is not a digit or a decimal point, return it.
    otherwise, collect a string of digits (which might include a decimal point) and return NUMBER, 
        the signal that a number has been collected
 */
int getop(char s[])
{
    int i, c, c_next;
    i = 0;
    while ( ((s[0]) = c = getch()) == ' '  || c == '\t')    /* skip spaces and tabs */
        ;

    s[1] = '\0';
    if (c == '-' && isdigit(c_next = getch())) { /* must be negative sign; set first char to - and put the digit back. set c to digit to trigger later if statement */
        s[0] = '-';
        c = c_next; 
        ungetch(c_next);
    } else if (c == '-' && !isdigit(c_next)) {
        ungetch(c_next);
        return c;
    } else if (!isdigit(c) && c != '.') {   /* not a number or negative sign*/
        return c;
    }
    
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

