// 1. Write a C program to implement Dynamic Memory allocation

#include <stdio.h>
#include <stdlib.h>
int size, *p;

void dmaUsingMalloc()
{
    int i;
    printf("Enter size of your dynamic array : ");
    scanf("%d", &size);

    if (size <= 0)
        printf("Size must be > 0! Try again");
    else
    {
        p = (int *)malloc(size * sizeof(int));
        if (!p)
        {
            printf("\nUnable to allocate memory using Malloc! Try again");
            exit(1);
        }

        else
        {
            printf("\nMemory allocated successfully using Malloc! Enter data to insert ->");

            for (i = 0; i < size; i++)
            {
                printf("\nEnter %d data -> ", i + 1);
                scanf("%d", &p[i]);
            }
        }
    }
}

void dmaUsingCalloc()
{
    int i;
    printf("Enter size of your dynamic array : ");
    scanf("%d", &size);

    if (size <= 0)
        printf("Size must be > 0! Try again");
    else
    {
        p = (int *)calloc(size, sizeof(int));
        if (!p)
        {
            printf("\nUnable to allocate memory using Calloc! Try again");
            exit(1);
        }

        else
        {
            printf("\nMemory allocated successfully using Calloc! Enter data to insert ->");

            for (i = 0; i < size; i++)
            {
                printf("\nEnter %d data -> ", i + 1);
                scanf("%d", &p[i]);
            }
        }
    }
}

void dmaUsingRealloc()
{
    int x, i;

    printf("Enter size of your dynamic array : ");
    scanf("%d", &x);

    if (x <= size)
        printf("Size must be > %d! Try again", size);
    else
    {
        p = (int *)realloc(p, x * sizeof(int));
        printf("\nMemory reallocate successfully using Realloc! Enter data to insert ->");

        for (i = size; i < x; i++)
        {
            printf("\nEnter %d data -> ", i + 1);
            scanf("%d", &p[i]);
        }
    }
    size = x;
}

void display()
{
    int i;
    if (!p)
        printf("\nNo data to be displayed!");
    else
    {
        printf("\nDisplaying Data -> ");
        for (i = 0; i < size; i++)
            printf("%d ", p[i]);
    }
}

void main()
{
    int choice;

    while (1)
    {
        printf("\nPRESS\n1. Dynamic Memory Allocation Using Malloc\n2. Dynamic Memory Allocation Using Calloc\n3. Increase size Using Realloc\n4. Display\n0. Quit\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            dmaUsingMalloc();
            break;
        case 2:
            dmaUsingCalloc();
            break;
        case 3:
            dmaUsingRealloc();
            break;
        case 4:
            display();
            break;
        case 0:
            exit(1);
        default:
            printf("Invalid Choice! Try again");
        }
    }
    free(p);
}
