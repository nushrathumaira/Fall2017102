#include <iostream>
#include <string>
#include "src/image/Pixel.h"
#include "src/image/Header.h"
#include "src/image/Image.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "USAGE: ./out <in.ppm> <out.ppm>";
    return 1;
  }

  // Open files
  std::ifstream in(argv[1]);
  std::ofstream out(argv[2]);

  if (!in || !out) {
    std::cerr << "Could not open input/output\n";
    return 1;
  }

  // ifstream constructor, copy
  Image puppy(in);
  Image copy(puppy);

  // Just changes header value
  copy.make_p6();
  copy.write_to(out);

  in.close();
  out.close();

  return 0;
}
