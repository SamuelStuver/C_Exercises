#include <stdio.h>
/* count blanks, tabs, and newlines in input */

main()
{
    int c, n_blanks, n_tabs, n_newlines;

    n_blanks = n_tabs = n_newlines = 0;
    while ( (c = getchar()) != EOF ){

        if (c == '\n'){
            ++n_newlines;
        } else if (c == '\t') {
            ++n_tabs;
        } else if (c == ' ') {
            ++n_blanks;
        }
    }
    printf("# blanks: %d\n", n_blanks);
    printf("# tabs  : %d\n", n_tabs);
    printf("# lines : %d\n", n_newlines);
    printf("# total : %d\n", (n_blanks + n_tabs + n_newlines));

}