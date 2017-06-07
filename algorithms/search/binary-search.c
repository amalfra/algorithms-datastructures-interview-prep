#include <stdio.h>

int search(int elements[], int left, int right, int element_to_search_for) {
  if (left <= right) {
    int mid = left + (right - left)/2;

    if (elements[mid] == element_to_search_for) {
      return mid;
    }
    if (elements[mid] > element_to_search_for) {
      return search(elements, left, mid-1, element_to_search_for);
    }
    return search(elements, mid+1, right, element_to_search_for);
  }

  return -1;
} 

void main() {
  int element_index, number_of_elements, element_to_search_for, i = 0;

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

  printf("\n\nEnter element to search for: ");
  scanf("%d", &element_to_search_for);

  element_index =
    search(elements, 0, number_of_elements-1, element_to_search_for);
  if (element_index == -1) {
    printf("\nElement not found!\n");
  } else {
    printf("\nElement found at index: %d\n", element_index);
  }
}