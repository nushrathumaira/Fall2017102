#ifndef PPM_UTILS
#define PPM_UTILS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// First meaningful line of the PPM file
typedef struct header {
  char MAGIC_NUMBER[3];
  unsigned int HEIGHT, WIDTH, MAX_COLOR;
} header_t;

// Represents an RGB pixel with integer values between 0-255
typedef struct pixel {
  unsigned int R, G, B;
} pixel_t;

// PPM Image representation
typedef struct image {
  header_t header;
  pixel_t* pixels;
} image_t;

header_t read_header(FILE* image_file);
image_t* read_ppm(FILE* image_file);
image_t* read_p6(FILE* image_file, header_t header);
image_t* read_p3(FILE* image_file, header_t header);

void write_header(FILE* out_file, header_t header);
void write_p6(FILE* out_file, image_t* image);
void write_p3(FILE* out_file, image_t* image);

#endif
