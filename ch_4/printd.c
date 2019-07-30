#include <stdio.h>

#define MAX_VAL 1000 /* Maximum input line length */

void printd(int n);

int main()
{
    int val;
    for (val = 0; val < MAX_VAL; val++)
    {
        printd(val);
        putchar('\n');
    }
        

    return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
    /* if n is negative, print a negative sign 
    and set the number to positive for remainder 
    of the calculation */
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    /* if n is evently divisible by 10, call self on n/10 */
    if (n / 10) {
        printd(n / 10);
    }

    /* print the last digit of current n (X mod 10 always returns lowest-order digit) */
    putchar(n % 10 + '0');
}