/* Re-write the temperature conversion program of section 1.2 to use a function for conversion */

#include <stdio.h>

float f_to_c(float temp_f);
float c_to_f(float temp_c);

main()
{
    int t;
    printf("F TO C:\n");
    for (t = 0; t <= 300; t = t+20) {
        printf("%3.0f F\t%6.1f C\n", (float)t, f_to_c((float)t));
    }

    printf("\nC TO F:\n");
    for (t = -140; t <= 140; t = t+20) {
        printf("%3.0f C\t%6.1f F\n", (float)t, c_to_f((float)t));
    }
}

float f_to_c(float temp_f) {
    float celsius = (5.0/9.0) * (temp_f - 32);
    return celsius;
}

float c_to_f(float temp_c) {
    float fahr = ((9.0/5.0) * temp_c) + 32;
    return fahr;
}
