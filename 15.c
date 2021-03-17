// 15. Write a C program to implement bubble sort.

#include <stdio.h>

void main()
{
    int i, j, a[] = {43, 2, 32, 433, 5, 653, 6, 37, 6, 4, 7, 36, 345}, temp;
    for (i = 0; i < sizeof(a) / sizeof(a[0]) - 1; i++)
    {

        for (j = 0; j < sizeof(a) / sizeof(a[0]) - 1 - i; j++)
        {

            if ((a[j]) < a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\n", a[i]);
    }
}
