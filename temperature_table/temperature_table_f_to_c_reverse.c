#include <stdio.h>

/* print Fahrenheit-Celsuis table
   for fahr = 0, 20, ..., 300 */

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    printf("\nFahrenheit to Celsius Table: %dF to %dF\n\n", UPPER, LOWER);
    printf("  F\t     C\n\n");
    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
    }
}