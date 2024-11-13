#include <stdio.h>
#include <stdlib.h>


struct Queue{
    int data;
    struct Queue *next;
};


struct Queue *head, *tail=NULL;
int count = 0;


void addNode(int data){
    
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}


void display(){
    struct Queue *current = head;

    if(head==NULL){
        printf("list is empty\n");
        exit(0);
    }
    printf("Nodes of singly linked list: \n");
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


void insert(int value){
    struct Queue *newNode = malloc(sizeof(struct Queue));
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
}

void insert_at_random(int value, int pos){
    struct Queue *newNode = malloc(sizeof(struct Queue));
    newNode -> data = value;
    struct Queue *ptr = head;
    int i=0;
    while(1){
        if(i==pos-1){
            ptr->next = newNode;
            newNode->next = newNode->next->next;
            break;
        }
        ptr = ptr->next;
    }
}



void delete_first(){
    struct Queue *ptr = head;
    head = head->next;
    free(ptr);
}


void delete_end(){
    struct Queue *current = head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head->next == NULL){
        free(head);
        return;
        
    }
    while(current!=NULL){
        current = current->next;
        if(current->next == NULL){
            free(current);
            return;
        }
    }
}


void freeList(struct Queue* head) {
    struct Queue* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    int numNodes;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);
        addNode(data);
    }
    display();

    int value = 5;

    insert(value);
    insert_at_random(2, 3);
    display();

    freeList(head);

    return 0;
}