#include <iostream>
#include <string>
#include "image/Pixel.h"
#include "image/Header.h"
#include "image/Image.h"
#include "filter/kernel/SharpenFilter.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "USAGE: ./PPM <input.ppm>" << endl;
    return 1;
  }

  // Open files
  std::ifstream in(argv[1]);
  std::string filename(argv[1]);
  std::ofstream out("k3_"+filename);

  // Did they open alright?
  if (!in || !out ) {
    std::cerr << "Could not open input/output" << endl;
    return 1;
  }

  // ifstream constructor
  Image k3(in);

  // Instance of a filter
  SharpenFilter sharpen;
  sharpen.apply(k3);

  // Write and close
  k3.write_to(out);

  in.close();
  out.close();
  return 0;
}
