#include <stdio.h>
#define size 5

int cqueue[size];
int front = -1, rear = -1;

void insert(){
    int item;
    if(((front == 0) && (rear == size - 1)) || ((rear + 1) % size == front)){
        printf("Queue Overflow.");
        return;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    if(front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }
    cqueue[rear] = item;
}

void delete(){
    if(front == -1){
        printf("Queue Underflow.");
        return;
    }
    printf("%d Deleted from queue.", cqueue[front]);
    if(front == rear){
        front = rear - 1;
    }
    else{
        front = (front + 1) % size;
    }
}

void display(){
    if(front == -1){
        printf("Queue empty.");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while(1){
        printf("q[%d] = %d\n", (i + 1), cqueue[i]);
        if(i == rear){break;}
        i = (i + 1) % size;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n------Queue Menu------\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid input.\n");
        }
    }
}