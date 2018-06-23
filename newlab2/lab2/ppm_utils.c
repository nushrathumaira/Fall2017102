#include "ppm_utils.h"

header_t read_header(FILE* image_file) {
  header_t header;
  fscanf(image_file, "%s %d %d %d ",
    header.MAGIC_NUMBER, &header.WIDTH, &header.HEIGHT, &header.MAX_COLOR);
  return header;
}

void write_header(FILE* out_file, header_t header) {
  fprintf(out_file, "%s %d %d %d ",
    header.MAGIC_NUMBER, header.WIDTH, header.HEIGHT, header.MAX_COLOR);
}

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

image_t* read_p6(FILE* image_file, header_t header) {
  int num_pixels = header.HEIGHT * header.WIDTH;
  image_t* image = (image_t*) malloc(sizeof(image_t));
  image->header = header;
  image->pixels = (pixel_t*) malloc(sizeof(pixel_t) * num_pixels);
  for(int i = 0; i < num_pixels; i++) {
    char r,g,b;
    fscanf(image_file, "%c%c%c", &r, &g, &b);
    image->pixels[i].R = (int) r;
    image->pixels[i].G = (int) g;
    image->pixels[i].B = (int) b;
  }
  return image;
}

image_t* read_p3(FILE* image_file, header_t header) {
  int num_pixels = header.HEIGHT * header.WIDTH;
  image_t* image = (image_t*) malloc(sizeof(image_t));
  image->header = header;
  image->pixels = (pixel_t*) malloc(sizeof(pixel_t) * num_pixels);
  for(int i = 0; i < num_pixels; i++) {
    int r,g,b;
    fscanf(image_file, "%d %d %d ", &r, &g, &b);
    image->pixels[i].R = r;
    image->pixels[i].G = g;
    image->pixels[i].B = b;
  }
  return image;
}

void write_p6(FILE* out_file, image_t* image) {
  header_t header = image->header;
  header.MAGIC_NUMBER[1] = '6';
  write_header(out_file, header);
  int num_pixels = image->header.HEIGHT * image->header.WIDTH;
  for(int i = 0; i < num_pixels; i++) {
    fprintf(out_file, "%c%c%c",
      (char) image->pixels[i].R,
      (char) image->pixels[i].G,
      (char) image->pixels[i].B
    );
  }
}

void write_p3(FILE* out_file, image_t* image) {
  header_t header = image->header;
  header.MAGIC_NUMBER[1] = '3';
  write_header(out_file, header);
  int num_pixels = image->header.HEIGHT * image->header.WIDTH;
  for(int i = 0; i < num_pixels; i++) {
    fprintf(out_file, "%d %d %d ",
      image->pixels[i].R,
      image->pixels[i].G,
      image->pixels[i].B
    );
  }
}
