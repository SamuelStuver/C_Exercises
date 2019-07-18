#include <stdio.h>

main()
{
    /* read a character */
    int c;
    /* while character is not end-of-file, output character just read, then read a new character */
    while ((c = getchar()) != EOF){
        if (c != 'a'){
            putchar(c);
        }   
    }
}
