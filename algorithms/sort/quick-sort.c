/*
  Time Complexity:

    Best case    - O(nlog(n))
    Average case - O(nlog(n))
    Worst case   - O(n^2)
*/
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *elements, int left, int right) {
  int i = left, j = right, pivot = elements[left];

  while (i < j) {
    while (elements[i] <= pivot && i <= right) {
      i++;
    }
    while (elements[j] > pivot && j >= 0) {
      j--;
    }
    if (i < j) {
      swap(&elements[i], &elements[j]);
    }
  }

  elements[left] = elements[j];
  elements[j] = pivot;
  return j;
}

void sort(int *elements, int left, int right) {
  if (left < right) {
    int pivot = partition(elements, left, right);
    sort(elements, left, pivot-1);
    sort(elements, pivot+1, right);
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

  sort(elements, 0, number_of_elements-1);

  printf("\n\nThe sorted array is: ");
  for (i = 0; i < number_of_elements; i++) {
    printf("%d ", elements[i]);
  }
}