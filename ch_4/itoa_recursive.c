/*
Exercise 4-12: use the ideas of printd to write a recursive version of itoa()
That is, write a function that converts an integer to a string by calling a 
recursive routine
 */

#include <stdio.h>
#define MAX_LEN 100 /* Maximum input line length */

void itoa_recursive(int n, char s[], int end_idx);
int ndigits(int n);

int main()
{
    int val;
    char s[MAX_LEN];
    for (val = -100; val <= 100; val++) {
        itoa_recursive(val, s, ndigits(val)-1);
        printf("%s\n", s);
    }

    
    
    
    return 0;
}

/* itoa_recursive: convert n to characters in s */
void itoa_recursive(int n, char s[], int i)
{
    /* if n is negative, print a negative sign 
    and set the number to positive for remainder 
    of the calculation */
    if (n < 0) {
        s[0] = '-';
        n = -n;
        i++;
    }

    /* if n is not evently divisible by 10, call self on n/10 */
    if (n / 10) {
        itoa_recursive(n / 10, s, i-1);
    }

    /* print the last digit of current n (X mod 10 always returns lowest-order digit) */
    s[i+1] = '\0';
    s[i] = (n % 10 + '0');
}

int ndigits(int n) {
    int totalDigits = 0;
    if (n == 0)
        return 1;
    else {
        while(n != 0){
            n /= 10;
            totalDigits ++;
        }
    }
    return totalDigits;
    
}