/* write a program to copy its input to output, replacing each string of one or more blanks with a single blank */

#include <stdio.h>

main()
{
    /* read a character */
    int c, space_flag;
    /* while character is not end-of-file, output character just read, then read a new character */
    while ((c = getchar()) != EOF){

        if ((c == ' ') || (c  == '\t')){
            while ((c == ' ') || (c  == '\t')){
                c = getchar();
            }
            putchar(' ');
        }
        putchar(c);

    }
}
