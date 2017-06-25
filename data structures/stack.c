/*
  Time Complexity:

    Average case - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
    Worst case   - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

struct stack {
  int top;
  int size;
  int *values;
};

int is_empty(struct stack s) {
  return (s.top == -1);
}

int is_full(struct stack s) {
  return (s.top == s.size-1);
}

void display(struct stack s) {
  if (is_empty(s)) {
    printf("Stack is empty!");
  } else {
    for (int i = s.top; i >= 0; i--) {
      printf("%d ", s.values[i]);
    }
  }
}

int push(struct stack *s, int value) {
  if (is_full(*s)) {
    return -1;
  }

  s->top++;
  s->values[s->top] = value;
  return value;
}

int pop(struct stack *s) {
  if (is_empty(*s)) {
    return -1;
  }

  int poped_value = s->values[s->top];
  s->top--;
  return poped_value;
}

void main() {
  int option = 0, value, temp;
  struct stack s;

  printf("Enter the size of stack: ");
  scanf("%d", &s.size);

  s.top = -1;
  s.values = malloc(sizeof(int)*s.size);
  
  do {
    printf("\n\n");
    printf("1. Display\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        display(s);
        break;
      case 2:
        if (is_full(s)) {
          printf("Stack is full!");
        } else {
          printf("Enter the value to push: ");
          scanf("%d", &value);
          push(&s, value);
        }
        break;
      case 3:
        temp = pop(&s);
        if (temp == -1) {
          printf("Stack is empty!");
        } else {
          printf("%d popped from stack", temp);
        }
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid option");
        break;
    }
  } while(option > 0);

  free(s.values);
}