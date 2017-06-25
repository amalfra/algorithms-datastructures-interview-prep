/*
  Time Complexity:

    Average case - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
    Worst case   - access: O(n), search: O(n), insertion: O(1), deletion: O(1)
*/
#include <stdio.h>
#include <stdlib.h>

struct queue {
  int front;
  int rear;
  int size;
  int values_count;
  int *values;
};

int is_empty(struct queue q) {
  return (q.values_count == 0);
}

int is_full(struct queue q) {
  return (q.values_count == q.size);
}

void display(struct queue q) {
  if (is_empty(q)) {
    printf("Queue is empty!");
  } else {
    for (int i = q.front; i <= q.rear; i++) {
      printf("%d ", q.values[i]);
    }
  }
}

int enqueue(struct queue *q, int value) {
  if (is_full(*q)) {
    return -1;
  }

  if (is_empty(*q)) {
    q->front++;
  }

  q->values_count++;
  q->rear++;
  q->values[q->rear] = value;
  return value;
}

int dequeue(struct queue *q) {
  if (is_empty(*q)) {
    return -1;
  }

  int poped_value = q->values[q->front];
  q->front++;
  q->values_count--;
  if (q->values_count == 0) {
    q->front = -1;
    q->rear = -1;
  }
  return poped_value;
}

void main() {
  int option = 0, value, temp;
  struct queue q;

  printf("Enter the size of queue: ");
  scanf("%d", &q.size);

  q.front = -1;
  q.rear = -1;
  q.values_count = 0;
  q.values = malloc(sizeof(int)*q.size);
  
  do {
    printf("\n\n");
    printf("1. Display\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        display(q);
        break;
      case 2:
        if (is_full(q)) {
          printf("Queue is full!");
        } else {
          printf("Enter the value to enqueue: ");
          scanf("%d", &value);
          enqueue(&q, value);
        }
        break;
      case 3:
        temp = dequeue(&q);
        if (temp == -1) {
          printf("Queue is empty!");
        } else {
          printf("%d dequeued", temp);
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

  free(q.values);
}