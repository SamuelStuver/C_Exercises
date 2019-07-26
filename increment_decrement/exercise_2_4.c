/*
Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2
-> for each char in s1, check if that char matches a char in s2

for each char c1 in s1:
    for each char c2 in s2:
        if c1 != c2:
            allow c1 to remain in s1
*/

#include <stdio.h>

void squeeze(char s[], char s2[]);

int main()
{
    char s[]  = "hello hello";
    char s2[] = "test test";
    printf("%s\n", s);
    squeeze(s, s2);
    printf("%s\n", s);
}

/* squeeze: delete all c from s */
void squeeze(char s[], char s2[])
{
    int i, j, k, c;

    for ( k = 0; (c = s2[k]) != '\0'; k++ ) {
        for ( i = j = 0; s[i] != '\0'; i++ ) {
            if ( s[i]  != c ) {
                s[j++] = s[i];
            }
        }
        s[j] = '\0';
    }
}
