// 8. Write a C program to implement singly linked list.

#include <stdio.h>
#include <stdlib.h>

int length();

struct Node
{
    int data;
    struct Node *next;
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
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        t->next = first;
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
    t->next = NULL;
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

    if (pos < 0 || pos > length())
        printf("Invalid Position");
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        t->next = NULL;

        for (i = 0; i < pos - 1 && p; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

// Function to delete from the front of the linked list
void deleteAtFirst()
{
    struct Node *p;
    if (!first)
        printf("\nList is empty\n");
    else
    {
        p = first;
        first = first->next;
        printf("\nData %d delete successfully at front", p->data);
        free(p);
    }
}

// Function to delete from the end of the linked list
void deleteAtEnd()
{
    struct Node *p, *t;
    if (!first)
        printf("\nList is empty\n");
    else
    {
        p = first;
        while (p->next)
        {
            t = p;
            p = p->next;
        }
        t->next = NULL;
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

        for (i = 1; i < pos - 1 && p; i++)
            p = p->next;
        t = p->next;
        p->next = t->next;

        printf("\nData %d delete successfully at end", t->data);
        free(t);
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
    float k;
    while (1)
    {
        printf("\nPRESS:\n 1: To see list\n 2: For Insertion at starting\n 3: For Insertion at end\n 4: For Insertion at any position\n 5: For Deletion of first element\n 6: For Deletion of last element\n 7: For Deletion of element at any position\n 0. To exit\n\nEnter your choice:");
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
