/*
  Time Complexity:

    Best case    - O(nlog(n))
    Average case - O(nlog(n))
    Worst case   - O(nlog(n))
*/
#include <stdio.h>

void merge(int *elements, int low, int mid, int high) {
  int temp[high], low1 = low, low2 = mid+1, i;

  for (i = low; low1 <= mid && low2 <= high ; i++) {
    if (elements[low1] <= elements[low2]) {
      temp[i] = elements[low1];
      low1++;
    } else {
      temp[i] = elements[low2];
      low2++;
    }
  }

  while (low1 <= mid) {
    temp[i] = elements[low1];
    i++;
    low1++;
  }

  while (low2 <= high) {
    temp[i] = elements[low2];
    i++;
    low2++;
  }

  for(i = low; i <= high; i++) {
    elements[i] = temp[i];
  }
}

void sort(int *elements, int low, int high) {
  if (low < high) {
    int mid = (low + high)/2;
    sort(elements, low, mid);
    sort(elements, mid+1, high);
    merge(elements, low, mid, high);
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