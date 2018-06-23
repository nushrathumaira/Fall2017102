#include "stdio.h"
#include "stdlib.h"
#include "sorting.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  FILE* input = fopen(argv[1], "r");

  // Count numbers in file
  int data_size = 0;
  int num;
  while (fscanf(input, "%d ", &num) == 1) {
    data_size++;
  }

  // Reset file, make array
  fseek(input, 0, SEEK_SET);
  int* data = (int*) malloc(sizeof(int)*data_size);

  // Read data into array
  int i;
  for (i = 0; i < data_size; i++) {
    fscanf(input, "%d ", &num);
    data[i] = num;
  }

  // Sort, set file name
  char fname[50];
  if (strcmp("bubble", argv[2]) == 0) {
    bubble_sort(data, data_size);
    sprintf(fname, "bubble_%d.dat", data_size);
  } else if (strcmp("quick", argv[2]) == 0) {
    quick_sort(data, 0, data_size-1);
    sprintf(fname, "quick_%d.dat", data_size);
  } else {
    comb_sort(data, data_size);
    sprintf(fname, "comb_%d.dat", data_size);
  }

  // sprintf to create output file name
  FILE* output = fopen(fname, "w");

  // Write to file
  for (i = 0; i < data_size; i++) {
    fprintf(output, "%d\n", data[i]);
  }

  free(data);
  return 0;
}
