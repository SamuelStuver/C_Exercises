#include <stdio.h>

void squeeze(char s[], int c);

int main()
{
    char s[] = "hello world";
    squeeze(s, 'o');
    printf("%s\n", s);
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;

    for ( i = j = 0; s[i] != '\0'; i++ ) {
        if ( s[i]  != c ) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
