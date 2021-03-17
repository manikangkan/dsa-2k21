// 12. Write a C program to implement stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

int isEmpty()
{
    return top == NULL;
}

int isFull()
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (!t)
        return 1;
    else
        return 0;
    free(t);
}

int length()
{
    struct Node *p = top;
    int count = 0;
    if (!top)
        printf("Stack Underflow");
    else
    {
        while (p)
        {
            count++;
            p = p->next;
        }
    }
    return count;
}

void display()
{
    struct Node *p = top;
    if (!top)
        printf("Stack Underflow");
    // if (isEmpty())
    //     printf("Stack Underflow");
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

void push()
{
    int x;
    struct Node *t;

    printf("Enter element to be pushed : ");
    scanf("%d", &x);

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (!t)
        printf("Stack Overflow");

    // else if (!top)
    // {
    //     top = t;
    // }
    else
    {
        // This portion will work for first node as well
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *p = top;
    int x = -1;

    if (!top)
        printf("Stack Underflow\n");
    else
    {
        top = top->next;
        x = p->data;
        // p->next = NULL;
        free(p);
    }
    return x;
}

int peek()
{
    struct Node *p = top;
    int index, i;
    printf("Enter index to be peeked : ");
    scanf("%d", &index);

    if (index > length())
        return -1;
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        if (p)
            return p->data;
        else
            return -1;
    }
}

int stackTop()
{
    if (top)
        return top->data;
    return -1;
}

void main()
{
    int choice, temp;

    while (1)
    {
        printf("\nPRESS\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. StackTop\n6. Length\n0. Quit\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            printf("Pop : %d \n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            temp = peek();
            temp == -1 ? printf("Invalid Index! Try again") : printf("Peek : %d \n", temp);
            break;
        case 5:
            printf("StackTop : %d \n", stackTop());
            break;
        case 6:
            printf("Length of the Stack : %d", length());
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid Choice! Enter again");
            break;
        }
    }
}
