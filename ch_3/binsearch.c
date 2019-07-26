#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int i;
    int n = 10;
    int val = 11;
    int arr[n];
    for (i=0; i<n; ++i) {
        arr[i] = i*2;
    }
    for (i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    putchar('\n');

    printf("Index of %d is %d\n", val, binsearch(val, arr, n));

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
