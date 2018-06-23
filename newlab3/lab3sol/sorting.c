#include "sorting.h"

// Simple bubble sort
void bubble_sort(int* numbers, int size) {
  int num_swaps = 0;

  do {
    num_swaps = 0;
    int i;
    for (i = 0; i+1 < size; i++) {
      if (numbers[i] > numbers[i+1]) {
        swap(&numbers[i], &numbers[i+1]);
        num_swaps++;
      }
    }
  } while (num_swaps != 0);
}

// Comb Sort
void comb_sort(int* numbers, int size) {
  int num_swaps = 0;
  int gap = size;
  double shrink = 1.3;

  do {
    num_swaps = 0;
    gap = gap / shrink;
    gap = gap < 1 ? 1 : gap;
    int i;
    for (i = 0; i+gap < size; i++) {
      if (numbers[i] > numbers[i+gap]) {
        swap(&numbers[i], &numbers[i+gap]);
        num_swaps++;
      }
    }
  } while (num_swaps != 0 || gap > 1);
}

void quick_sort(int* numbers, int low, int high) {
  if (low < high) {
    int pivot = partition(numbers, low, high);
    quick_sort(numbers, low, pivot);
    quick_sort(numbers, pivot + 1, high);
  }
}

int partition(int* numbers, int low, int high) {
  int pivot = numbers[low];
  int i = low - 1;
  int j = high + 1;

  while (1) {
    do { i++; } while (numbers[i] < pivot);
    do { j--; } while (numbers[j] > pivot);

    if (i >= j) { return j; }
    else { swap(&numbers[i], &numbers[j]); }
  }
}

// Simple swap
void swap(int* left, int* right) {
  int temp = *left;
  *left = *right;
  *right = temp;
}
