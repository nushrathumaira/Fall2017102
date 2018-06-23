#ifndef SORTING_H
#define SORTING_H

/**
  Takes an array of integers and the size of said array
  Should sort the array in-place, in ascending order.

  Check the write-up for more info, but as an example here is how bubble
  sort would sort the following sequenceL

  4 1 2 5 6 3     <-- 4 bubbles up until it hits the 5, 6 swaps with 3
  1 2 4 5 3 6     <-- First swap occurs when 5 swaps with 3
  1 2 4 3 5 6     <-- 4 swaps with 3
  1 2 3 4 5 6     <-- Sorted

  My solution is 13 lines of code, including closing brackets
  Keep it simple!
**/
void bubble_sort(int* numbers, int size);

/**
  Takes an array of integers and the size of said array
  Should sort the array in-place, in ascending order.

  Check the write-up for more info, but as an example here is how comb
  sort would sort the following sequenceL

  Gap size is initially 4 (size/shrink factor of 1.3)
  6 3 2 5 4 1     <-- 6 swaps with 4, 3 swaps with 1
  4 1 2 5 6 3     <-- Gap size = 3, no swaps
  4 1 2 5 6 3     <-- Gap size = 2, 4 and 2 swap, 5 and 3 swap
  2 1 4 3 6 5     <-- Gap size = 1, 2 and 1 swap, 4 and 3 swap, 6 and 5 swap
  1 2 3 4 5 6     <-- Sorted

  My solution is 15 lines of code, including closing brackets
  Keep it simple!
**/
void comb_sort(int* numbers, int size);

/**
  Is it fast?
**/
void quick_sort(int* numbers, int low, int high);
int partition(int* numbers, int low, int high);

/**
  Swap the values of left and right
**/
void swap(int* left, int* right);

#endif
