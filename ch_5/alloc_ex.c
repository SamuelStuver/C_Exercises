#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* allocp is a pointer to the next free position 
                                        -could also be written as
                                        static char *allocp = &allocbuf[0] */

char *alloc(int n)      /* return pointer to n characters */
{
    if ( allocbuf + ALLOCSIZE - allocp >= n ) {     /* check that n chars will fit (there are >= n remaining chars free) */
        allocp += n;
        return allocp - n; /* old allocp */
    } else {
        return 0;       /* not enough room, return 0 */
    }
}

void afree(char *p)     /* free the storage that p points to */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) /* if p is within the range of the buffer (allocbuf[0] <= p <= allocbuf[ALLOCSIZE]) */
        allocp = p;                                 /* set allocp (next free pointer) to point to the storage p points to */
}