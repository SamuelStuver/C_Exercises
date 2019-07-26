/*
Write the function any(s1, s2) which returns the first location in the string s1 where any character from the string s2 occurs,
or -1 if s1 contains no characters from s2
*/

#include <stdio.h>

int any(char s[], char s2[]);

int main()
{
    char s[]  = "aaaac";
    char s2[] = "bcbbb";
    printf("%s\n%s\n", s, s2);
    printf("%d\n", any(s, s2));
}

/* squeeze: delete all c from s */
int any(char s[], char s2[])
{
    int i, j, k, c;

    for ( k = 0; (c = s2[k]) != '\0'; k++ ) {
        for ( i = j = 0; s[i] != '\0'; i++ ) {
            if ( s[i]  != c ) {
                j++;
            } else {
                return i;
            }
        }
    }
    return -1;
}
