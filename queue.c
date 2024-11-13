#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *first = NULL;
struct Queue *last = NULL;

int isEmpty()
{
    return first == NULL;
}

void enqueue(int data)
{
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty())
        first = last = newNode;
    else
    {
        last->next = newNode;
        last = newNode;
    }
    printf("Enqueued: %d", last->data);
}

void dequeue()
{
    if (isEmpty())
        printf("Queue is Empty.");
    else
    {
        struct Queue *x_first = first;
        first = x_first->next;
        printf("Dequeued: %d", x_first->data);
        free(x_first);
    }
}

void peek()
{
    if (isEmpty())
        printf("Queue is Empty.");
    else
        printf("First Element: %d", first->data);
}

void display()
{
    if (isEmpty())
        printf("Queue is Empty.");
    else
    {
        struct Queue *ptr = first;
        printf("Queue:");
        while (ptr != NULL)
        {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
    }
}

void main()
{
    while (1)
    {
        int choice;
        printf("\nSelect your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Is Empty\n5.Display Stack\nPress any other key to exit\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            int data;
            printf("Enter the number: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
                printf("Queue is Empty.");
            else
                printf("Queue is not Empty");
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
        printf("\n");
    }
}