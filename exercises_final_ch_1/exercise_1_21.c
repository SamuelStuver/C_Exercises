/* Write a program entab that replaces strings of blanks by the minimum number of tabs
   and blanks to achieve the same spacing. Use the same tab stops as for detab (1-20)
   When either a tab or a single blank would suffice to reach a tab stop, which should
   be given preference? */

#include <stdio.h>
#define SPACES_PER_TAB 3

main()
{
    /* read a character */
    int c, blank_count;

    blank_count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank_count;
        } else if (c == '\t') {
            blank_count += 3;
        } else {
            while (blank_count >= SPACES_PER_TAB) {
                putchar('\t');
                blank_count -= 3;
            }
            while (blank_count > 0) {
                putchar(' ');
                --blank_count;
            }
            putchar(c);
        }
    }
}
