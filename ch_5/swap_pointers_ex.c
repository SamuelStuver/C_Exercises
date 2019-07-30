#include <stdio.h>
void swap(int *px, int *py);

int main()
{
    int x, y;
    x = 5;
    y = 9;
    printf("\nValues Before Swap:\nx: %d\ny: %d\n", x, y);
    swap(&x, &y); /* swap takes POINTERS as arguments, so we must pass in the addresses of x and y */
    printf("\nValues After Swap:\nx: %d\ny: %d\n", x, y);

}

/* swap: function to switch the values of integers x and y using pointers */
void swap(int *px, int *py)
{
    int temp;
    temp = *px; /* set temp to the thing px points to (the value of the first integer) */
    *px = *py;  /* set the value that px points to as the value that py points to */
    *py = temp;
}