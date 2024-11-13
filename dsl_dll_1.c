#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
    struct Queue *prev;
};

struct Queue *head=NULL;
struct Queue *tail=NULL;


void createNode(struct Queue *newNode, int data) {
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
}


void addNode(int data) {
    struct Queue *newnode = malloc(sizeof(struct Queue));
    createNode(newnode, data);
    printf("newnode->data: %d\n", newnode->data);
    if (head==NULL && tail==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail = newnode;
        tail = newnode;
    }
}


void addToBeg(int data){
    struct Queue *ptr = malloc(sizeof(struct Queue));
    createNode(ptr, data);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}


void addToEnd(int data){
    struct Queue *ptr = malloc(sizeof(struct Queue));
    createNode(ptr, data);
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
}


void insertAfter(int key, int data) {
    struct Queue *curr = head;

    while (curr != NULL) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }

    if (curr == NULL){
        head
    }

    struct Queue *newnode = malloc(sizeof(struct Queue));
    createNode(newnode, data);

    newnode->prev = curr;

    newnode->next = curr->next;

    curr->next = newnode;
    
    if (newnode->next != NULL) newnode->next->prev = newnode;

}


void traverse(){
    struct Queue *ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}


int main(){
    int n = 5;
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        addNode(data);
    }
    addToBeg(45);
    insertAfter(45, 10);
    addToEnd(50);
    traverse();
    return 0;
}

