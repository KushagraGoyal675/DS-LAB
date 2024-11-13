#include <stdio.h>

struct Queue {
    int data;
    struct Queue* next;
};

struct Queue* reverseList(struct Queue* head) {

    struct Queue *curr = head, *prev = NULL, *next;

    while (curr != NULL) {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(struct Queue* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

struct Queue* createNode(int new_data) {
    struct Queue* new_node
        = (struct Queue*)malloc(sizeof(struct Queue));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main() {

    struct Queue* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked list:");
    printList(head);

    head = reverseList(head);

    printf("\nReversed Linked List:");
    printList(head);

    return 0;
}
