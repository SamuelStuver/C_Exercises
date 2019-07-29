/***********************
Extend calculator to add modulus (%) operator (DONE) and provisions for negative numbers (NOT DONE)
************************/
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP  100   /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number has been found */

int getop(char[]);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op1,op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF ) {
        switch (type) {
            case NUMBER:
                push(atof(s));          /* if number, push the double value onto stack */
                break;
            case '+':
                push( pop() + pop() );  /* if + sign, pop next two values off stack and push sum onto stack */
                break;
            case '*':
                push( pop() * pop() ); /* if * sign, pop next two values off stack and push product onto stack */
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

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* this is the value stack itself */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
        
}

#include <ctype.h>
int getch(void);
void ungetch(int);
/* 
getop: get next operator or numeric operand
-Skip blanks and tabs
-if next character is not a digit or a decimal point, return it.
    otherwise, collect a string of digits (which might include a decimal point) and return NUMBER, 
        the signal that a number has been collected
 */
int getop(char s[])
{
    int i, c, c_next;
    i = 0;
    while ( ((s[0]) = c = getch()) == ' '  || c == '\t')    /* skip spaces and tabs */
        ;

    s[1] = '\0';
    if (c == '-' && isdigit(c_next = getch())) {
        s[0] = '-';
        c = c_next;
        ungetch(c_next);
    } else if (c == '-' && !isdigit(c_next)) {
        ungetch(c_next);
        return c;
    } else if (!isdigit(c) && c != '.') {   /* not a number or negative sign*/
        return c;
    }
    
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}