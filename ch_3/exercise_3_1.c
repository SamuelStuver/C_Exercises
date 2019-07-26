/*
Write a version of binsearch that only makes one test inside the loop
and measure the difference in runtime
*/

#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch_singletest(int x, int v[], int n);

int main()
{
    int i;
    int n = 100;
    int val = 97;
    int arr[n];
    for (i=0; i<n; ++i) {
        arr[i] = i*2;
    }
    for (i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    putchar('\n');

    clock_t begin;
    clock_t end;

    begin = clock();
    printf("Index of %d is %d\n", val, binsearch(val, arr, n));
    end = clock();
    printf("time elapsed (original): %d\n",(int)(end-begin));
    begin = clock();
    printf("Index of %d is %d\n", val, binsearch_singletest(val, arr, n));
    end = clock();
    printf("time elapsed (single test): %d\n",(int)(end-begin));

}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid  = (low+high)/2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else { /* found match */
            return mid;
        }
    }
    return -1; /* no match */
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch_singletest(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid  = (low+high)/2;
        if (x <= v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (v[mid] == x) {
        return mid;
    } else {
        return -1; /* no match */
    }

}
