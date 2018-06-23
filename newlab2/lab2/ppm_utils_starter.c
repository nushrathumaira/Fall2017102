#include "ppm_utils.h"

image_t* read_ppm(FILE* image_file) {
  header_t header = read_header(image_file);
  image_t* image = NULL;
  if (strcmp("P3", header.MAGIC_NUMBER) == 0) {
    image = read_p3(image_file, header);
  } else if (strcmp("P6", header.MAGIC_NUMBER) == 0) {
    image = read_p6(image_file, header);
  }
  return image;
}
