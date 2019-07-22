#include <stdio.h>

/* count characters on input, second version */

main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc){
        ;
    }
    printf("%.0f\n", nc);
}