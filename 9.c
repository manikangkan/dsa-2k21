// 9. Write a C program to implement queue using linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue()
{
    int data;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (!t)
        printf("Queue is full");
    else
    {
        printf("Enter data to enter : ");
        scanf("%d", &data);

        t->data = data;
        t->next = NULL;

        if (!front)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *p = front;
    if (!front)
        printf("Queue is empty\n");
    else
    {
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display()
{
    int i;
    struct Node *p = front;
    if (!front)
        printf("Queue is empty\n");
    else
    {
        printf("\nDisplaying Data : ");
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

void main()
{
    struct Queue *q;
    int choice, k;
    while (1)
    {
        printf("\nPRESS\n1. enqueue\n2. dequeue\n3. display\n0.Exit\nEnter your choice : ");
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
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid input! Enter again");
        }
    }
}
