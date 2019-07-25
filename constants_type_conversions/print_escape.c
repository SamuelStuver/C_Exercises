#include <stdio.h>

enum boolean {FALSE, TRUE};
enum escapes {BELL='\a', BACKSPACE='\b', TAB='\t', NEWLINE='\n', VTAB='\v', RETURN='\r'};

int main()
{
    putchar('a');
    putchar(TAB);
    putchar('b');
    putchar(TAB);
    putchar('c');
    putchar(TAB);

}
