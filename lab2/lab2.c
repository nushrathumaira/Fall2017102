#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// Circle Type
typedef struct circle_t {
  double x,y,r;
} circle;

circle* read_data(FILE* input, int* num);
void calc_centroid(FILE* output, circle* circles, int num);

int main(int argc, char const *argv[]) {
  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");

  int num;
  circle* circles = read_data(input, &num);
  calc_centroid(output, circles, num);

  return 0;
}

circle* read_data(FILE* input, int* num) {
  fscanf(input, "#%i", num);

  circle* circles = (circle*)malloc(sizeof(circle) * (*num));

  int i;
  for(i = 0; i < (*num); i++) {
    circle c;
    fscanf(input, "%lf %lf %lf", &c.x, &c.y, &c.r);
    *(circles+i) = c;
  }

  return circles;
}

void calc_centroid(FILE* output, circle* circles, int num) {
  int i = 0;
  double x_cent = 0,
         y_cent = 0,
         total_area = 0;

  for(;i < num; i++) {
    double area = M_PI * pow((circles+i)->r,2);
    total_area += area;
    x_cent += (circles+i)->x * area;
    y_cent += (circles+i)->y * area;
  }

  x_cent /= total_area;
  y_cent /= total_area;

  fprintf(output, "%lf %lf", x_cent, y_cent );
}
