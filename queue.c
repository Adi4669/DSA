#include <stdio.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void insert(){
    int item;
    if(rear == size - 1){
        printf("Queue Overflow.\n");
        return;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    if(front == -1)
        front = 0;
    queue[++rear] = item;
}

void delete(){
    if((front == -1) || (front > rear)){
        printf("Queue Underflow.\n");
        return;
    }
    printf("%d Deleted from queue.\n", queue[front++]);
    if(front > rear){
        front = rear = -1;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
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