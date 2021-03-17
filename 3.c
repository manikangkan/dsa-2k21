// 3. Write a C program to implement matrix multiplication.
//Not done yet

#include <stdio.h>
#define SIZE 3

int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];

void create()
{
    int i, j;
    printf("Enter data of first %d*%d matrix -> ", SIZE, SIZE);
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("\nenter %d %d -> ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter data of second %d*%d matrix -> ", SIZE, SIZE);
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("\nenter %d %d -> ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
}

void metrixMul()
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
    }
}

void main()
{
    create();
}
