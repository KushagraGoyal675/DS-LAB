#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
    struct Queue *prev;
};

struct Queue *head=NULL;
struct Queue *tail=NULL;

void addNode(int newdata){
    struct Queue *newnode=malloc(sizeof(struct Queue));
    newnode->data = newdata;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head==NULL && tail==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail = newnode;
    }
}


void traverse(){
    struct Queue *ptr=head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}


void insert_front(int newdata){
    struct Queue *newnode=malloc(sizeof(struct Queue));
    if(head==NULL){
        head = tail = newnode;
    }
    newnode->data = newdata;
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}


void addToEmpty(struct Queue *head, int data){
    head->prev = NULL;
    head->data = data;
    head->next = NULL;
}


void addToBeg(struct Queue *head, int data){
    struct Queue *ptr;
    ptr->next = head;
    ptr->data = data;
    ptr->prev = NULL;
    head->prev = ptr;
}


int countNodes() {
    int count = 0;
    struct Queue *ptr1 = head;
    while (ptr1 != NULL) {
        count++;
        ptr1 = ptr1->next;
    }
    return count;
}


void findMiddle() {
    struct Queue *ptr1 = head;
    struct Queue *ptr2 = tail;
    int sec_middle;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while ((ptr1 != ptr2) || (ptr1->next != ptr2)){
        ptr2 = ptr2->prev;
        ptr1 = ptr1->next;
    }

    if (ptr1==ptr2) printf("%d is the middle element.", ptr1->data);
    else printf("%d and %d are the middle elements.", ptr1->data, ptr2->data);
}


void search(int key, int n) {
    struct Queue *ptr1 = head;
    struct Queue *ptr2 = tail;
    int position = 1;
    while ((ptr1 != ptr2) || (ptr1->next != ptr2)) {
        if (ptr1->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        if (ptr2->data == key){
            printf("Element %d found at position %d\n", key, n-position);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}


int main(){
    int n = 5;
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        addNode(data);
    }
    insert_front(25);
    traverse();
    return 0;
}

