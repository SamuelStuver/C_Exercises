#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

#define MAXOP  100   /* max size of operand or operator */

/* reverse Polish calculator */
int main()
{
    int type;
    double op1,op2, dummy, dummy2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF ) {
        switch (type) {
            case NUMBER:
                push(atof(s));          /* if number, push the double value onto stack */
                break;
            case 'c':
                /* printf("clearing stack...\n"); */
                while (pop() != 0.0)
                    ;
                break;
            case 's':
                dummy = pop();
                dummy2 = pop();
                /* printf("swap %g and %g\n", dummy, dummy2); */
                push(dummy);
                push(dummy2);
                break;
            case 'd':
                dummy = pop();
                /* printf("duplicate %g\n", dummy); */
                push(dummy);
                push(dummy);
                break;
            case 'p':
                dummy = pop();
                printf("\ttop value: %.8g\n", dummy);
                push(dummy);
                break;
            case '+':
                push( pop() + pop() );  /* if + sign, pop next two values off stack and push sum onto stack */
                break;
            case '*':
                push( pop() * pop() );  /* if * sign, pop next two values off stack and push product onto stack */
                break;
            case '-':
                op2 = pop();
                push( pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push( pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 != 0.0)
                    push( op1 - ((int)(op1 / op2)  * op2 ));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command (%s)\n", s);
                break;
        }
    }

    return 0;
}