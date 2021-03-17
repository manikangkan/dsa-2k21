// 6. Write a C program to implement circular queue using array.

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size, front, rear, *q;
};

void create(struct Queue *t)
{
    int x;
    printf("Enter size of your queue : ");
    scanf("%d", &x);

    t->size = x + 1;
    t->front = t->rear = 0;
    t->q = (int *)malloc(t->size * sizeof(int));
}

int isFull(struct Queue *p)
{
    return (p->rear + 1) % p->size == p->front;
}

int isEmpty(struct Queue *p)
{
    return p->front == p->rear;
}

void enqueue(struct Queue *p)
{
    int data;

    if (isFull(p))
        printf("Queue is full");
    else
    {
        printf("Enter data to enter : ");
        scanf("%d", &data);
        p->rear = (p->rear + 1) % p->size;
        p->q[p->rear] = data;
    }
}

int dequeue(struct Queue *p)
{
    int x = -1;
    if (isEmpty(p))
        printf("Queue is empty\n");
    else
    {
        p->front = (p->front + 1) % p->size;
        x = p->q[p->front];
    }
    return x;
}

void display(struct Queue *p)
{
    if (isEmpty(p))
        printf("Queue is empty\n");
    else
    {
        printf("\nDisplaying Data : ");

        int i = p->front + 1;
        while (i != (p->rear + 1) % p->size)
        {
            printf("%d ", p->q[i]);
            i = (i + 1) % p->size;
        }
    }
}

void main()
{
    struct Queue *q;
    int choice, k;
    create(q);
    while (1)
    {
        printf("\nPRESS\n1. enqueue\n2. dequeue\n3. display\n4. isFull\n5. isEmpty\n0.Exit\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            k = dequeue(q);
            k == -1 ? printf("Unable to delete")
                    : printf("%d deleted successfully from queue", k);
            break;
        case 3:
            display(q);
            break;
        case 4:
            isFull(q) ? printf("Queue is full") : printf("Queue is not full");
            break;
        case 5:
            isEmpty(q) ? printf("Queue is empty") : printf("Queue is not empty");
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid input! Enter again");
        }
    }
}
