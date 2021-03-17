// 11. Write a C program to implement doubly linked list.

#include <stdio.h>
#include <stdlib.h>

int length();

struct Node
{
    int data;
    struct Node *next, *prev;
} *first = NULL;

// Function to insert at the front of the linked list
void insertAtFront()
{
    int data;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);

    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->prev = t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
}

// Function to insert at the end of the linked list
void insertAtEnd()
{
    int data;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);

    struct Node *t, *p = first;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->prev = t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        t->prev = p;
        p->next = t;
    }
}

// Function to insert at any specified position in the linked list
void insertAtPosition()
{
    int i, data, pos;
    struct Node *t, *p = first;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);

    if (pos <= 0 || pos > length())
        printf("Invalid Position");

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->prev = t->next = NULL;

    if (first == NULL)
        first = t;

    for (i = 1; i < pos - 1 && p; i++)
        p = p->next;

    t->prev = p;
    t->next = p->next;
    if (p->next)
        p->next->prev = t;
    p->next = t;
}

// Function to delete from the front of the linked list
void deleteAtFirst()
{
    struct Node *p;
    if (first == NULL)
        printf("\nList is empty\n");
    else
    {
        p = first;
        first = first->next;
        if (first)
            first->prev = NULL;
        printf("\nData %d delete successfully at front", p->data);
        p->next = NULL;
        free(p);
    }
}

// Function to delete from the end of the linked list
void deleteAtEnd()
{
    struct Node *p;
    if (first == NULL)
        printf("\nList is empty\n");
    else
    {
        p = first;
        while (p->next)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        p->prev = NULL;
        printf("\nData %d delete successfully at end", p->data);
        free(p);
    }
}

// Function to delete from any specified position from the linked list
void deleteAtPosition()
{
    int pos, i;
    struct Node *p = first, *t;
    if (first == NULL)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter index :");
        scanf("%d", &pos);

        for (i = 1; i < pos && p; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        printf("\nData %d delete successfully at end", t->data);
        free(p);
    }
}

// Function to traverse the linked list
void traverse()
{
    struct Node *p;
    if (first == NULL)
        printf("\nList is empty\n");
    else
    {
        p = first;
        printf("\nDisplaying Elements: ");
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

// Main function
void main()
{
    int choice, data, pos;
    while (1)
    {
        printf("\nPRESS:\n 1: To see list\n 2: For Insertion at starting\n 3: For Insertion at end\n 4: For Insertion at any position\n 5: For Deletion of first element\n 6: For Deletion of last element\n 7: For Deletion of element at any position\n0. To exit\n\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteAtFirst();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtPosition();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nInvalid Input\n");
            break;
        }
    }
}
