// 2. Write a C program to find the average, standard deviation of 20 numbers.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20

float arr[SIZE];

int create()
{
    int i;
    printf("Enter %d numbers below -> ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("\n%d no. -> ", i + 1);
        scanf("%f", &arr[i]);
    }
    return 1;
}

float average()
{
    int i;
    float sum = 0;
    for (i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    return sum / SIZE;
}

float standardDeviation()
{
    int i;
    float sum = 0;
    for (i = 0; i < SIZE; i++)
    {
        sum += pow((average() - arr[i]), 2);
    }
    return sqrt(sum / SIZE);
}

void main()
{
    int choice;
    while (1)
    {
        printf("\nPRESS\n1. Average\n2. Standard Deviation\n3. Quit\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            printf("Average : %f", average());
            break;
        case 2:
            create();
            printf("Standard Deviation : %f", standardDeviation());
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid Choice! Try again");
            break;
        }
    }
}
