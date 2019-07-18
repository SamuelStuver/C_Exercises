#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = -40, -20, ..., 300 */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -40;   /* lower limit of temperature table */
    upper = 300; /* upper limit of temperature table */
    step = 20;   /* step size */

    celsius = lower;
    printf("\nCelsius to Fahrenheit Table: %dC to %dC\n\n", lower, upper);
    printf("  C\t    F\n\n");
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * (celsius)) + 32;
        printf("%3.0f\t%5.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}