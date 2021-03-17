// 17. Write a C program to implement insertion sort.

#include <stdio.h>

void main()
{
    int i, j, temp, a[] = {43, 2, 32, 433, 5, 653, 6, 37, 6, 4, 7, 36, 345};

    for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
    {

        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] >= temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        printf("%d\n", a[i]);
    }
}
