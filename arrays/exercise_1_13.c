/* Write a program to print a histogram of the lengths of words in its input */
/* BONUS: print the histogram horizontally instead of vertically (TO DO) */

#include <stdio.h>

main()
{
    int c, i, j, nchars;
    int frequencies[21];

    for ( i = 0; i < 21; i++ ){
        frequencies[i] = 0;
    }

    nchars = 0;
    while ((c = getchar()) != EOF) {
         if (c == ' ' || c == '\n' || c == '\t') {
             frequencies[nchars]++;
             nchars = 0;
         } else {
             nchars++;
         }
    }

    for ( i = 1; i < 21; i++ ){
        printf("%d: ", i);
        for ( j = 0; j < frequencies[i]; j++ ){
            printf("%c", '=');
        }
        printf("%c", '\n');
    }
}
