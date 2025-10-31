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
        printf("Error: Memory Allocation failed.");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void display(Node* head){
    Node* temp = head;
    if(temp == NULL){
        printf("List empty.\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Stack Operations

void push(Node** top, int data){
    Node* newNode = createNode(data);
    newNode -> next = *top;
    *top = newNode;
    printf("%d pushed into stack.\n", data);
}

int pop(Node** top){
    if(*top == NULL){
        printf("Stack empty."); return -1;
    }
    Node* temp = *top;
    int poppedData = temp -> data;
    *top = (*top) -> next;
    free(temp);
    return poppedData;
}

//Queue Operations

struct Queue{Node* front; Node* rear;};

typedef struct Queue Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Error: Memory Allocation failed.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void enQ(Queue* q, int data){
    Node* newNode = createNode(data);
    if(q->rear == NULL){
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued into queue.\n", data);
}

int deQ(Queue* q){
    if(q -> front == NULL){
        printf("Queue is empty.");
        return -1;
    }
    Node* temp = q -> front;
    int deqData = temp -> data;
    q -> front = q -> front -> next;
    if(q -> front == NULL){
        q -> rear = NULL;
    }
    free(temp);
    return deqData;
}

int main(){
    printf("Stack Operations:\n");
    Node* stackTop = NULL;
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    printf("Stack: "); display(stackTop);
    printf("Poppped %d\n", pop(&stackTop));
    printf("Stack: "); display(stackTop);
    printf("Poppped %d\n", pop(&stackTop));
    printf("Stack: "); display(stackTop);

    printf("Queue operations:\n");
    Queue* q = createQueue();
    enQ(q, 100); enQ(q, 200); enQ(q, 300);
    printf("Queue: "); display(q -> front);
    printf("Dequeued %d\n", deQ(q));
    printf("Dequeued %d\n", deQ(q));
    printf("Queue: "); display(q -> front);
    enQ(q, 400);
    printf("Queue: "); display(q -> front);
    free(q);

    return 0;
}