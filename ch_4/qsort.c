#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define MAX_VAL 100

void my_qsort(int v[], int left, int right);

int main()
{
    int array[N];
    srand(time(0));
    /* populate array with random integers */
    for (int i = 0; i < N; i++) {
        array[i] = (rand() % MAX_VAL);
        printf("%d ", array[i]);
    }
    putchar('\n');
    putchar('\n');

    my_qsort(array, 0, N-1);
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
    return 0;
}

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    /* do nothing if array contains fewer than 2 elements (terminating condition) */
    if (left >= right)
        return;
    
    /*  */
    swap(v, left, (left + right)/2); /* move partition element to v[0] partition*/
    last = left;
    for (i = left+1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}