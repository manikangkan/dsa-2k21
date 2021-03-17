// 16. Write a C program to implement selection sort.

#include <stdio.h>

void main()
{
    int i, j, a[] = {43, 2, 32, 433, 5, 653, 6, 37, 6, 4, 7, 36, 345}, temp, min;
    for (i = 0; i < sizeof(a) / sizeof(a[0]) - 1; i++)
    {

        min = i;

        for (j = i + 1; j < sizeof(a) / sizeof(a[0]); j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\n", a[i]);
    }
}
