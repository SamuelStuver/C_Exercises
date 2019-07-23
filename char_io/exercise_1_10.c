/* write a program to copy its input to output, replacing each tab with \t, each backspace with \b, and each backslash with \\ */

#include <stdio.h>

main()
{
    /* read a character */
    int c;
    /* while character is not end-of-file, output character just read, then read a new character */
    while ((c = getchar()) != EOF){

        if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }


    }
}
