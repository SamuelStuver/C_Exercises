/* Write a program to remove all comments from a C program. Don't forget to
   handle quoted strings and character constants properly. C comments do not
   nest. */

#include <stdio.h>

int toggle(int flag);

int main()
{
    /* read a character */
    int c_current, c_prev, c_next;
    int inside_comment = 0;
    int inside_quote = 0;

    c_current = getchar();
    c_next = getchar();
    /* while character is not end-of-file, output character just read, then read a new character */
    while (c_current != EOF){

        if ( c_current == '"' ) {
            inside_quote = toggle(inside_quote);
        }


        if ((c_current == '/' && c_next == '*') || (c_prev == '/' && c_current == '*')) {
            inside_comment = 1;
        } else if (c_prev == '*' && c_current == '/') {
            inside_comment = 0;
        } else if ((inside_comment == 0 && inside_quote == 0) || (inside_comment == 1 && inside_quote == 1)) {
            putchar(c_current);
            //printf("%d-", c_current);
        }


        c_prev = c_current;
        c_current = c_next;
        c_next = getchar();
    }
    putchar('\n');
}

int toggle(int flag)
{
    if (flag == 0) {
        return 1;
    } else if (flag == 1) {
        return 0;
    } else {
        return flag;
    }
}
