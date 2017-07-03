/*
  Time Complexity:

    Average case - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
    Worst case   - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int data;
};

void display(struct node *head) {
  struct node *temp = head;

  if (temp == NULL) {
    printf("List is empty!");
  }

  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

struct node* add_front(struct node *head, int value) {
  struct node *temp = malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;
  if (head != NULL) {
    temp->next = head;
  }
  head = temp;
  return head;
}

struct node* add_end(struct node *head, int value) {
  struct node *current = head;
  struct node *temp = malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;
  if (current == NULL) {
    head = temp;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = temp;
  }
  return head;
}

struct node* remove_front(struct node *head) {
  if (head == NULL) {
    printf("List is empty!");
  } else {
    struct node *temp = head;
    head = head->next;
    printf("%d removed from list", temp->data);
    free(temp);
  }
  return head;
}

struct node* remove_end(struct node *head) {
  if (head == NULL) {
    printf("List is empty!");
  } else {
    struct node *temp = NULL;
    struct node *current = head;
    if (head->next == NULL) {
      head = NULL;
    } else {
      while (current->next != NULL)
      {
        temp = current;
        current = current->next;
      }
      temp->next = NULL;
    }
    printf("%d removed from list", current->data);
    free(current);
  }
  return head;
}

void main() {
  int option = 0, value;
  struct node *head = NULL, *temp;

  do {
    printf("\n\n");
    printf("1. Display\n");
    printf("2. Add to front\n");
    printf("3. Add to end\n");
    printf("4. Remove from front\n");
    printf("5. Remove from end\n");
    printf("6. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        display(head);
        break;
      case 2:
        printf("Enter the value to add: ");
        scanf("%d", &value);
        head = add_front(head, value);
        break;
      case 3:
        printf("Enter the value to add: ");
        scanf("%d", &value);
        head = add_end(head, value);
        break;
      case 4:
        head = remove_front(head);
        break;
      case 5:
        head = remove_end(head);
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid option");
        break;
    }
  } while(option > 0);

  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}