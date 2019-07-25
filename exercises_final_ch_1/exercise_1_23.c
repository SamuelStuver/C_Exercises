/* Write a program to remove all comments from a C program. Don't forget to
   handle quoted strings and character constants properly. C comments do not
   nest. */

#include <stdio.h>


int main()
{
    /* read a character */
    int c_current, c_prev, c_next;
    int inside_comment = 0;
    c_current = getchar();
    /* while character is not end-of-file, output character just read, then read a new character */
    while (c_current != EOF){

        c_next = getchar();
        if ((c_current == '/' && c_next == '*') || (c_prev == '/' && c_current == '*')) {
            inside_comment = 1;
        } else if (c_prev == '*' && c_current == '/') {
            inside_comment = 0;
            //putchar(c_next);
        } else if (inside_comment == 0) {
            putchar(c_next);
        }



        c_prev = c_current;
        c_current = c_next;
    }
}
