/*
Write a function escape(s, t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s.
Use a switch.
>>>DONE

Write a function for the other direction as well, converting
escape sequences into the real characters.
>>>DONE

*/

void stoescape(char s[], char t[]);
void escapetos(char s[], char t[]);
int getln(char s[], int lim);

#include <stdio.h>

int main() /* count digits, whitespace, others */
{
    int len;
    char t[20];
    while ((len = getln(t, 20)) > 0) {
        char s[20];
        //stoescape(s, t);
        printf("%s\n", s);
        escapetos(s, t);
        printf("%s\n", s);
    }

    return 0;
}

/* copy string t into string s, replacing escape chars with visible escape sequences */
void stoescape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != EOF; i++) {
        switch (t[i]) {
            case '\n': {
                s[j] = '\\';
                s[++j] = 'n';
                j++;
                break;
                break;
            }
            case '\t': {
                s[j] = '\\';
                s[++j] = 't';
                j++;
                break;
            }
            default: {
                s[j++] = t[i];
                break;
            }
        }

    }

}

/* copy string t into string s, replacing escape sequences with real characters */
void escapetos(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != EOF; i++) {
        if ( t[i] == '\\' ) {
            switch (t[i+1]) {
                case 'n':
                {
                    s[j++] = '\n';
                    i++;
                    break;
                }
                case 't':
                {
                    s[j++] = '\t';
                    i++;
                    break;
                }
                default:
                {
                    s[j++] = '\\';
                }
            }
        } else {
            s[j++] = t[i];
        }

    }

}

/* getln: read a line into s, return length */
int getln(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c = getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
