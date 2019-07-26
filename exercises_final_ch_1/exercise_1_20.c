/* Write a program detab that replaces tabs in the input with the proper number of blanks
   to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
   Should n be a variable or a symbolic constant? */

#include <stdio.h>
#define SPACES_PER_TAB 3

int main()
{
    /* read a character */
    int c, i;
    /* while character is not end-of-file, output character just read, then read a new character */
    while ((c = getchar()) != EOF){
        if (c == '\t'){
            for ( i = 0; i < SPACES_PER_TAB; ++i ) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
