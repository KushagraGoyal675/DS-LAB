#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int first;
    int last;
    unsigned int max;
    int *arr;
};

int isEmpty(struct Queue *queue)
{
    return queue->first == queue->last;
}

int isFull(struct Queue *queue)
{
    return queue->last == queue->max;
}

struct Queue *create(unsigned int max)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->max = max;
    queue->first = -1;
    queue->last = -1;
    queue->arr = (int *)malloc(queue->max * sizeof(int));
    return queue;
}

void enqueue(struct Queue *queue, int num)
{
    if (isFull(queue))
        printf("Memory Overflow.");
    else
    {
        queue->arr[++(queue->last)] = num;
        printf("Enqueued: %d", num);
    }
    printf("\n");
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        printf("Memory Underflow");
    else
    {
        int x = queue->arr[++queue->first];
        printf("Dequeued: %d", x);
        return x;
    }
    printf("\n");
}

int peek(struct Queue *queue)
{
    int first = queue->first + 1;
    if (isEmpty(queue))
        printf("Queue is Empty");
    else
    {
        printf("First Element: %d", queue->arr[first]);
        return queue->arr[first];
    }
    printf("\n");
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
        printf("Queue is Empty");
    else
    {
        printf("Queue: ");
        for (int i = 0; i <= queue->last; i++)
        {
            printf("%d ", queue->arr[i]);
        }
    }
    printf("\n");
}

void main()
{
    unsigned int n;
    printf("Enter the max size of the queue: ");
    scanf("%d", &n);
    struct Queue *queue = create(n);
    while (1)
    {
        int choice;
        printf("\nSelect your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Is Empty\n5.Is Full\n6.Display Queue\nPress any other key to exit\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            int num;
            printf("\nEnter the number to enqueue: ");
            scanf("%d", &num);
            enqueue(queue, num);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            peek(queue);
            break;
        case 4:
            if (isEmpty(queue))
                printf("Queue is Empty.");
            else
                printf("Queue is not Empty.");
            printf("\n");

            break;
        case 5:
            if (isFull(queue))
                printf("Queue is Full.");
            else
                printf("Queue is not Full");
            printf("\n");
            break;
        case 6:
            display(queue);
            break;
        default:
            exit(0);
        }
    }
}