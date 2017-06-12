/*
  Time Complexity:

    Best case    - O(n)
    Average case - O(n^2)
    Worst case   - O(n^2)
*/
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int *elements, int number_of_elements) {
  int i, j;

  for (i = 0; i < number_of_elements-1; i++)
  {
    for (j = 0; j < number_of_elements-i-1; j++) {
      if (elements[j] > elements[j+1]) {
        swap(&elements[j], &elements[j+1]);
      }
    }
  }
}

void main() {
  int element_index, number_of_elements, i = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &number_of_elements);

  int elements[number_of_elements];
  while(i < number_of_elements) {
    printf("Enter element(%d): ", i+1);
    scanf("%d", &elements[i]);
    i++;
  }

  printf("\n\nThe array is: ");
  for (i = 0; i < number_of_elements; i++) {
    printf("%d ", elements[i]);
  }

  sort(elements, number_of_elements);

  printf("\n\nThe sorted array is: ");
  for (i = 0; i < number_of_elements; i++) {
    printf("%d ", elements[i]);
  }
}