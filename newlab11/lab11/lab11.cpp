#include "Pixel.h"
#include <iostream>
#include <sstream>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[]) {
  Pixel p1(100, 100, 100);
  Pixel p2(50, 50, 50);
  Pixel p3(p2);

  // Does equality work? Needed for other tests
  assert(p1 == p1);
  assert(p2 == p3);
  assert(!(p1 == p2));
  assert(p1 != p2);

  // operator +
  assert(p1 + 50 == Pixel(150, 150, 150));
  assert(p1 + p2 == Pixel(150, 150, 150));
  assert(p1 + -50 == p2);
  assert(p1 + 500 == Pixel(255, 255, 255));
  assert(p1+p1+p1 == Pixel(255, 255, 255));

  // operator -
  assert(p1 - 50 == p2);
  assert(p1 - p2 == p2);
  assert(p1 - -50 == Pixel(150, 150, 150));
  assert(p1 - 500 == Pixel(0, 0, 0));
  assert(p1-p1-p1 == Pixel(0, 0, 0));

  // operator *
  assert(p1 * 2 == Pixel(200, 200, 200));
  assert(p1 * 1 == p1);
  assert(p1 * 3 == Pixel(255, 255, 255));

  // operator /
  assert(p1 / 1 == p1);
  assert(p1 / 2 == p2);
  assert(p2 / 1 == p3);
  assert(p1 / 10 == Pixel(10, 10, 10));
  assert(p1 / 1000 == Pixel(0, 0, 0));

  // relational operators
  assert(!(p1 < p1));
  assert(p2 < p1);
  assert(p2 <= p1);
  assert(p2 <= p3);
  assert(!(p1 > p1));
  assert(p1 > p2);
  assert(p1 >= p2);
  assert(p2 >= p3);

  // combinations
  assert(p1 + p2 > p1);
  assert(p1 + p2 >= p3);
  assert((p1 - 50) + 25 > p2);
  assert((p1 / 100) <= p3);
  assert((p3 * 2) + p2 - 50 == p1);
  assert((p1 / 2) - 50 + p2 == p3);

  // input operator
  stringstream pixels(string("100 100 100 200 200 200"));
  Pixel p4, p5;
  pixels >> p4 >> p5;
  assert(p4 == Pixel(100, 100, 100));
  assert(p5 == Pixel(200, 200, 200));

  cout << "ALL TESTS PASSED!" << endl;
  return 0;
}
