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
    struct Node *newNode = createNode(value);
    newNode -> next = *head;
    *head = newNode;
    printf("%d added to the beginning of the list.", value);
}

void addToEnd(struct Node **head, int value){
    struct Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        printf("%d added to the end of the list.\n", value);
        return;
    }
    struct Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    printf("%d added to the end of the list.\n", value);
} 

void addToPos(struct Node **head, int value, int pos){
    struct Node *newNode = createNode(value);
    if(pos == 1){
        newNode -> next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp  =*head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("position out of bounds.");
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    printf("%d added at %d position of the list.", value, pos);
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
    int value, pos, choice;
    while(1){
        printf("\n\n-----Linked List Menu-----\n");
        printf("\n1.Insert at the Beginning.\n2.Insert at the End.\n3.Insert at a position.\n4.Display List.\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            addToBeg(&head, value);
            break;

            case 2:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            addToEnd(&head, value);
            break;

            case 3:
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            printf("Enter postion to be inserted at: ");
            scanf("%d", &pos);
            addToPos(&head, value, pos);
            break;

            case 4:
            display(head);
            break;

            case 5:
            printf("Exiting...");
            exit(0);
            break;

            default: printf("Invaid Input."); break;
        }
    }
    return 0;
}