#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error: Memory Allocation failed.\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void insert(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void display(Node* head){
    Node* temp = head;
    if(temp == NULL){
        printf("List is empty.");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void sort(Node* head){
    if(head == NULL) return;
    int swapped;
    Node* ptr1; Node* lptr = NULL;

    do{
        swapped = 0;
        ptr1 = head;
        while(ptr1 -> next != lptr){
            if(ptr1 -> data > ptr1 -> next -> data){
                int temp = ptr1 -> data;
                ptr1 -> data = ptr1 -> next -> data;
                ptr1 -> next -> data = temp;

                swapped = 1;
            }
            ptr1 = ptr1 -> next;
        }
        lptr = ptr1;
    }
    while(swapped);
}

void reverse(Node** head){
    Node* prev = NULL; Node* next = NULL;
    Node* current = *head;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concat(Node** head1, Node** head2){
    if(*head1 == NULL){
        *head1 = *head2;
        return;
    }
    if(*head2 == NULL) return;
    Node* temp = *head1;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = *head2;
}

int main(){
    Node* l1 = NULL; Node* l2 = NULL;
    insert(&l1, 10);
    insert(&l1, 80);
    insert(&l1, 90);
    insert(&l1, 30);
    insert(&l1, 20);
    insert(&l1, 40);
    printf("Original List1: ");
    display(l1);
    sort(l1);
    printf("Sorted List1: "); display(l1);
    reverse(&l1);
    printf("Reversed List1: "); display(l1);

    insert(&l2, 77); insert(&l2, 99);
    printf("Original List2: "); display(l2);
    printf("Concatenating l1 and l2: ");
    concat(&l1, &l2); display(l1);
    return 0;
}