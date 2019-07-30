/*
Write a recursive version of the function reverse(s), 
which reverses the string s in-place
*/

#include <stdio.h>

void reverse(char s[], int start, int end);
void swap(char v[], int i, int j);

int main()
{

    char teststring[] = "this is a test\n";

    printf(teststring);
    reverse(teststring, 0, 13);
    printf(teststring);

    return 0;
}

void reverse(char s[], int start, int end)
{
    /* terminating condition -> end and start are the same or pass each other */
    if (start >= end){
        return;
    }
    /* swap s[start] with s[end], then call self with start+1 and end-1 */
    swap(s, start, end);
    reverse(s, start+1, end-1);

}

/* swap: interchange v[i] and v[j] */
void swap(char v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}