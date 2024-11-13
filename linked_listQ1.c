#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    INTEGER,
    CHARACTER,
    STRING
} DataType;

struct Queue {
    DataType type;
    union {
        int intData;
        char charData;
        char* strData;
    } data;
    struct Queue* next;
};

void insert(struct Queue** head, DataType type, void* newData) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->type = type;
    newNode->next = *head;
    *head = newNode;

    switch (type) {
        case INTEGER:
            newNode->data.intData = *(int*)newData;
            printf("Inserted %d at the beginning of the linked list.\n", newNode->data.intData);
            break;
        case CHARACTER:
            newNode->data.charData = *(char*)newData;
            printf("Inserted '%c' at the beginning of the linked list.\n", newNode->data.charData);
            break;
        case STRING:
            newNode->data.strData = strdup((char*)newData); // Duplicate the string
            printf("Inserted \"%s\" at the beginning of the linked list.\n", newNode->data.strData);
            break;
    }
}

void display(struct Queue* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct Queue* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        switch (current->type) {
            case INTEGER:
                printf("%d ", current->data.intData);
                break;
            case CHARACTER:
                printf("'%c' ", current->data.charData);
                break;
            case STRING:
                printf("\"%s\" ", current->data.strData);
                break;
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Queue* head) {
    struct Queue* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        if (temp->type == STRING) {
            free(temp->data.strData);
        }
        free(temp);
    }
}

int main() {
    struct Queue* head = NULL;
    int choice, numNodes;
    printf("Select data type:\n1. Integer\n2. Character\n3. String\nChoice: ");
    scanf("%d", &choice);
   
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
   
    for (int i = 0; i < numNodes; i++) {
        switch (choice) {
            case 1: {
                int data;
                printf("Enter the integer data for node %d: ", i + 1);
                scanf("%d", &data);
                insert(&head, INTEGER, &data);
                break;
            }
            case 2: {
                char data;
                printf("Enter the character data for node %d: ", i + 1);
                scanf(" %c", &data);
                insert(&head, CHARACTER, &data);
                break;
            }
            case 3: {
                char data[100];
                printf("Enter the string data for node %d: ", i + 1);
                scanf("%s", data);
                insert(&head, STRING, data);
                break;
            }
            default:
                printf("Invalid choice.\n");
                return 1;
        }
    }
   
    display(head);
   
    freeList(head);

    return 0;
}