/*******************************
Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from
standard headers and by direct computation.
*******************************/

#include <stdio.h>
#include <limits.h>


int main()
{
    printf("Computed Values (type min max):\n");
    char c = 0;
    char c_next = 1;
    while (c_next > c){
        c++;
        c_next++;
    }
    printf("\nCHAR  min: %d/%c max: %d/%c\n", c_next, c_next, c, c);

    unsigned char uc = 0;
    unsigned char uc_next = 1;
    while (uc_next > uc){
        uc++;
        uc_next++;
    }
    printf("\nUCHAR min: %d max: %d\n", uc_next, uc);

    int i = 1;
    int i_next = 2;
    while (i_next > i){
        i = i * 2;
        i_next = i_next * 2;
    }
    printf("\nINT   min: %d max: %d\n", i_next, i);

    unsigned int ui = 1;
    unsigned int ui_next = 2;
    while (ui_next > ui){
        ui = ui * 2;
        ui_next = ui_next * 2;
    }
    printf("\nUINT  min: %d max: %d\n", ui_next, ui);

    short s = 1;
    short s_next = 2;
    while (s_next > s){
        s = s * 2;
        s_next = s_next * 2;
    }
    printf("\nSHORT  min: %d max: %d\n", s_next, s);

    unsigned short us = 1;
    unsigned short us_next = 2;
    while (us_next > us){
        us = us * 2;
        us_next = us_next * 2;
    }
    printf("\nUSHORT  min: %d max: %d\n", us_next, us);

    long l = 1;
    long l_next = 2;
    while (l_next > l){
        l = l * 2;
        l_next = l_next * 2;
    }
    printf("\nLONG  min: %d max: %d\n", l_next, l);

    unsigned long ul = 1;
    unsigned long ul_next = 2;
    while (ul_next > ul){
        ul = ul * 2;
        ul_next = ul_next * 2;
    }
    printf("\nULONG  min: %d max: %d\n", ul_next, ul);

    printf("Printed Values (type min max):\n");
    printf("\nCHAR  min: %d/%c max: %d/%c\n", CHAR_MIN, CHAR_MIN, CHAR_MAX, CHAR_MAX);
    printf("\nUCHAR min: %d max: %d\n", 0, UCHAR_MAX);
    printf("\nINT   min: %d max: %d\n", INT_MIN, INT_MAX);
    printf("\nUINT   min: %d max: %d\n", 0, UINT_MAX);
    printf("\nSHORT  min: %d max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("\nUSHORT  min: %d max: %d\n", 0, USHRT_MAX);
    printf("\nLONG  min: %d max: %d\n", LONG_MIN, LONG_MAX);
    printf("\nULONG  min: %d max: %d\n", 0, ULONG_MAX);

    return 0;

}
