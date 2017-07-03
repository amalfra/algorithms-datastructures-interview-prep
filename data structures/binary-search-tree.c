/*
  Time Complexity:

    Average case - search: O(log(n)), insertion: O(log(n)), deletion: O(log(n))
    Worst case   - search: O(n), insertion: O(n), deletion: O(n)
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *left;
  struct node *right;
  int data;
};

struct node* insert(struct node *node, int data) {
  if (node == NULL) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
  }

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else {
    node->right = insert(node->right, data);
  }

  return node;
}

void preorder(struct node *root) {
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(struct node *root) {
  if (root != NULL)
  {
    preorder(root->left);
    printf("%d ", root->data);
    preorder(root->right);
  }
}

void postorder(struct node *root) {
  if (root != NULL)
  {
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
  }
}

int height(struct node* node)
{
  if (node == NULL) {
    return 0;
  } else {
    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight) {
      return lheight+1;
    } else {
      return rheight+1;
    }
  }
}

void printGivenLevel(struct node* root, int level) {
  if (root == NULL) {
    return;
  }

  if (level == 1) {
    printf("%d ", root->data);
  } else {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

void levelorder(struct node *root) {
  int h = height(root);
  for (int i = 0; i < h; i++) {
    printGivenLevel(root, i+1);
  }
}

struct node* minValueNode(struct node *node) {
    struct node *current = node;

    while (current->left != NULL) {
      current = current->left;
    }
 
    return current;
}

struct node* delete(struct node *root, int data) {
  if (root != NULL) {
    if (data < root->data) {
      root->left = delete(root->left, data);
    } else if (data > root->data) {
      root->right = delete(root->right, data);
    } else {
      if (root->left == NULL) {
        struct node *temp = root->right;
        free(root);
        return temp;
      } else if (root->right == NULL) {
        struct node *temp = root->left;
        free(root);
        return temp;
      }

      struct node *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }

  return root;
}

void deleteTree(struct node *node) {
  if (node == NULL) return;
  deleteTree(node->left);
  deleteTree(node->right);
  free(node);
}

void main() {
  int option = 0, value;
  struct node *root = NULL, *temp;

  do {
    printf("\n\n");
    printf("1. Preorder traversal\n");
    printf("2. Inorder traversal\n");
    printf("3. Postorder traversal\n");
    printf("4. Levelorder traversal\n");
    printf("5. Insert\n");
    printf("6. Delete\n");
    printf("7. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        if (root == NULL) {
          printf("Tree is empty!");
        } else {
          preorder(root);
        }
        break;
      case 2:
        if (root == NULL) {
          printf("Tree is empty!");
        } else {
          inorder(root);
        }
        break;
      case 3:
        if (root == NULL) {
          printf("Tree is empty!");
        } else {
          postorder(root);
        }
        break;
      case 4:
        if (root == NULL) {
          printf("Tree is empty!");
        } else {
          levelorder(root);
        }
        break;
      case 5:
        printf("Enter the value to add: ");
        scanf("%d", &value);
        root = insert(root, value);
        break;
      case 6:
        printf("Enter the value to delete: ");
        scanf("%d", &value);
        root = delete(root, value);
        break;
      case 7:
        exit(0);
        break;
      default:
        printf("Invalid option");
        break;
    }
  } while(option > 0);

  deleteTree(root);
  root = NULL;
}
