/* strcpy_arr: copy t to s; array subscript version */
void strcpy_arr(char *s, char *t)
{
    int i;

    i=0; 
    while ((s[i] = t[i]) != '\0')
        i++;
}

/*strcpy_ptr1: copy t to s; pointer version 1 */
void strcpy_ptr1(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/*strcpy_ptr2: copy t to s; pointer version 2 */
void strcpy_ptr2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0') {
        ;
    }
}

/*strcpy_ptr3: copy t to s; pointer version 3 */
void strcpy_ptr2(char *s, char *t)
{
    while (*s++ = *t++) {
        ;
    }
}