#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

// Create a new node
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeg(Node **head, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;

    printf("\n%d added at the beginning of the list.", value);
}

// Insert at end
void insertAtEnd(Node **head, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    printf("\n%d added at the end of the list.", value);
}

// Insert at position (0-based index)
void insertAtPos(Node **head, int value, int pos) {
    if (pos == 0) {
        insertAtBeg(head, value);
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nIndex not found.");
        return;
    }

    Node *newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("\n%d inserted at position %d of the list.", value, pos);
}

// Display list
void display(Node *head) {
    printf("\nList: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insertAtBeg(&head, 10);
    insertAtBeg(&head, 20);
    insertAtBeg(&head, 30);

    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    insertAtPos(&head, 25, 2);
    insertAtPos(&head, 35, 4);

    display(head);

    return 0;
}
