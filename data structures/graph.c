#include <stdio.h>
#include <stdlib.h>

struct node {
  int dest;
  struct node *next;
};

struct nodeList {
  struct node *head;
};

struct graph {
  int v;
  struct nodeList *list;
};

void display(struct graph *graph) {
  for (int i = 0; i < graph->v; i++) {
    struct node *current = graph->list[i].head;
    printf("%d: ", i);
    while (current != NULL) {
      printf("-> %d ", current->dest);
      current = current->next;
    }
    printf("\n");
  }
}

void add_edge(struct graph* graph, int src, int dest) {
  struct node *temp = malloc(sizeof(struct node));
  temp->dest = dest;
  temp->next = graph->list[src].head;
  graph->list[src].head = temp;

  struct node *temp1 = malloc(sizeof(struct node));
  temp1->dest = src;
  temp1->next = graph->list[dest].head;
  graph->list[dest].head = temp1;
}

void main() {
  int option = 0, value1, value2;
  struct graph *graph = malloc(sizeof(struct graph));

  printf("Enter the number of vertexes: ");
  scanf("%d", &graph->v);
  graph->list = malloc(graph->v * sizeof(struct nodeList));
  for (int i = 0; i < graph->v; i++) {
    graph->list[i].head = NULL;
  }

  do {
    printf("\n\n");
    printf("1. Display adjacency list\n");
    printf("2. Add edge\n");
    printf("3. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        display(graph);
        break;
      case 2:
        printf("Enter source vertex: ");
        scanf("%d", &value1);
        printf("Enter destination vertex: ");
        scanf("%d", &value2);
        add_edge(graph, value1, value2);
        break;
      case 3:
        exit(0);
        break;
      default:
        printf("Invalid option");
        break;
    }
  } while(option > 0);
}