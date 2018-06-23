/*
  Nick Glyder
  CPSC 1021-002
  Lab 2
*/

#include "stdio.h"
#include "stdlib.h"
#include "ppm_utils.h"
//#include "ppm_filters.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("USAGE: ./lab2 <ppm-image> <out-image>\n");
    return 1;
  }

  FILE* in_file = fopen(argv[1], "r");
  FILE* out_file = fopen(argv[2], "w");

  if (!in_file || !out_file) {
    printf("ERROR: File could not be opened.\n");
    return 1;
  }

  image_t* image = read_ppm(in_file);

  if(!image) {
    printf("ERROR: Image could not be read\n");
    return 1;
  }

  //sepia(image);
  write_p6(out_file, image);

  free(image->pixels);
  free(image);
  fclose(in_file);
  fclose(out_file);

  return 0;
}
