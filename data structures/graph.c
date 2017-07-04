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
}

void visit_mark(int vertex, int *visited, struct graph *graph) {
  visited[vertex] = 1;
  printf("%d ", vertex);

  struct node *current = graph->list[vertex].head;
  while (current != NULL) {
    if (visited[current->dest] != 1) {
      visit_mark(current->dest, visited, graph);
    }
    current = current->next;
  }
}

void dfs(struct graph *graph) {
  int visited[graph->v], i;
  for (i = 0; i < graph->v; i++) {
    visited[i] = 0;
  }

  for (i = 0; i < graph->v; i++) {
    if (visited[i] != 1) {
      visit_mark(i, visited, graph);
    }
  }  
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
    printf("2. DFS\n");
    printf("4. Add edge\n");
    printf("5. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        display(graph);
        break;
      case 2:
        dfs(graph);
        break;
      case 4:
        printf("Enter source vertex: ");
        scanf("%d", &value1);
        printf("Enter destination vertex: ");
        scanf("%d", &value2);
        add_edge(graph, value1, value2);
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid option");
        break;
    }
  } while(option > 0);
}