#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newNode;
  }
}

void deleteFirst()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  struct Node *temp = head;
  head = head->next;
  printf("Deleted first element: %d\n", temp->data);
  free(temp);
}

void deleteLast()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  struct Node *prev = NULL;

  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL)
  {
    head = NULL;
  }
  else
  {
    prev->next = NULL;
  }

  printf("Deleted last element: %d\n", temp->data);
  free(temp);
}

void deleteSpecified(int value)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  struct Node *prev = NULL;

  while (temp != NULL && temp->data != value)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Element %d not found.\n", value);
    return;
  }

  if (prev == NULL)
  {
    head = head->next;
  }
  else
  {
    prev->next = temp->next;
  }

  printf("Deleted specified element: %d\n", temp->data);
  free(temp);
}

void display()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct Node *temp = head;
  printf("Linked List: ");
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  int choice, value;

  while (1)
  {
    printf("\n--- Singly Linked List Menu ---\n");
    printf("1. Insert element\n");
    printf("2. Delete first element\n");
    printf("3. Delete last element\n");
    printf("4. Delete specified element\n");
    printf("5. Display list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      insert(value);
      break;
    case 2:
      deleteFirst();
      break;
    case 3:
      deleteLast();
      break;
    case 4:
      printf("Enter value to delete: ");
      scanf("%d", &value);
      deleteSpecified(value);
      break;
    case 5:
      display();
      break;
    case 6:
      printf("Exiting program.\n");
      exit(0);
    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}
