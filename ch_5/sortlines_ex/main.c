#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* Number of lines to be sorted */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);
int mygetline(char s[], int lim);

/* sort input lines */
int main() 
{
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too bog to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

/* mygetline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) {      /* do nothing if array contains */
        return;
    }
    swap(v, left, (left+right)/2);
    last = left;

    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];        /* storage for alloc */
static char *allocp = allocbuf;         /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else {
        return 0;       /* not enough room */
    }
}