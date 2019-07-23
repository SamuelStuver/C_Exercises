/* Write a program to print a histogram of the frequencies of different characters in its input */
#include <stdio.h>

main() {

    int c, i, j, index;
    int char_frequencies[122 - 32];

    for ( i = 0; i < 90; ++i ) {
        char_frequencies[i] = 0;
    }


    while ((c = getchar()) != EOF) {
        index = c - 32;
        ++char_frequencies[index];
        //printf("%c -> ", c);
        //printf("%d\n", c);
    }
    for ( i = 0; i < 90; i++ ){
        printf("%c: ", i+32);
        for ( j = 0; j < char_frequencies[i]; j++ ){
            printf("%c", '=');
        }
        printf("%c", '\n');
    }
}
