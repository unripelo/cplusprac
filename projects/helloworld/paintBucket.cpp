#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) { // 1 instruction
    int mid = low + (high - low) / 2; // 4 instructions 

    if (x == array[mid])
      return mid; // 1 instructions

    if (x > array[mid])
      low = mid + 1; // 2 instructions

    else
      high = mid - 1; // 1 instruction
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}

// Total number of instructions: (1 + 4 + 1 + 2 + 1 ) = 9 

//  While it's true that each step in binary search involves a few basic operations, 
// the exact number of these operations is not crucial for determining the Big O complexity.

// Since the number of comparisons and array accesses is proportional 
// to the number of times we halve the search space (log₂(n)),
// we say that binarySearch has a time complexity of O(log n).