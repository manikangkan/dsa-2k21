// 4. Write a C program to implement stack using array

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *p;
};

void create(struct Stack *st)
{
    int a;
    printf("Enter size of Stack: ");
    scanf("%d", &st->size);

    st->top = -1;
    st->p = (int *)calloc(st->size, sizeof(int));
}

int isEmpty(struct Stack *st)
{
    return st->top == -1;
}

int isFull(struct Stack *st)
{
    return st->top == st->size - 1;
}

int length(struct Stack *st)
{
    int i, count = 0;
    if (isEmpty(st))
        printf("Stack Underflow");
    else
        for (i = st->top; i >= 0; i--)
            count++;
    return count;
}

void display(struct Stack *st)
{
    int i;
    if (isEmpty(st))
        printf("Stack Underflow");
    else
    {
        for (i = st->top; i >= 0; i--)
            printf("%d ", st->p[i]);
    }
}

void push(struct Stack *st)
{
    int x;
    printf("Enter element to be pushed : ");
    scanf("%d", &x);

    if (isFull(st))
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->p[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (isEmpty(st))
        printf("Stack Underflow\n");
    else
        x = st->p[st->top--];
    return x;
}

int peek(struct Stack *st)
{
    int index;
    printf("Enter index to be peeked : ");
    scanf("%d", &index);

    if (st->top - index + 1 < 0)
        return -1;
    else
        return st->p[st->top - index + 1];
}

int stackTop(struct Stack *st)
{
    if (!isEmpty(st))
        return st->p[st->top];
    return -1;
}

void main()
{
    int choice, temp;
    struct Stack *st;
    create(st);

    while (1)
    {
        printf("\nPRESS\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. StackTop\n6. isFull\n7. isEmpty\n8. Length\n0. Quit\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(st);
            break;
        case 2:
            printf("Pop : %d \n", pop(st));
            break;
        case 3:
            display(st);
            break;
        case 4:
            temp = peek(st);
            temp == -1 ? printf("Invalid Index! Try again") : printf("Peek : %d \n", temp);
            break;
        case 5:
            printf("StackTop : %d \n", stackTop(st));
            break;
        case 6:
            isFull(st) ? printf("Stack is Full") : printf("Stack is not Full");
            break;
        case 7:
            isEmpty(st) ? printf("Stack is Empty") : printf("Stack is not Emtpy");
            break;
        case 8:
            printf("Length of the Stack : %d", length(st));
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
