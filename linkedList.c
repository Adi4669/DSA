#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void addToBeg(struct Node **head, int value){
    struct Node* newNode = createNode(value);
    newNode -> next = *head;
    *head = newNode;
}

void addToEnd(struct Node **head, int value){
    struct Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void addToPos(struct Node **head, int value, int pos){
    struct Node* newNode = createNode(value);
    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *head){
    struct Node *temp = head;
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
int main(){
    struct Node *head = NULL;
    addToBeg(&head, 1);
    addToEnd(&head, 8);
    addToPos(&head, 7, 2);
    addToPos(&head, 399, 3);
    display(head);
    return 0;
}