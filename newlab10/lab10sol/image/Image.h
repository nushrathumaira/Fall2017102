#ifndef IMAGE_H
#define IMAGE_H 1

#include "Header.h"
#include "Pixel.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

class Image {
  private:
    Header HDR;
    std::vector<Pixel> PIX;

    // Disallow default and assignment
    Image ();

    // Used by Constructors to build Image
    static vector<Pixel> read_pixels(const Header&, std::ifstream&);
    static Header read_header(std::ifstream&);
    static void ignore_comments(std::ifstream&);

  public:
    // Constructors
    Image (std::ifstream&);
    Image (const Image& i);
    ~Image ();

    // Write to file
    void write_header(std::ofstream&) const;
    void write_to(std::ofstream&) const;
    void make_p3();
    void make_p6();

    // const accessor, dont let someone change the Pixel*
    // otherwise memory leaks.
    const Header& header() const;
    const vector<Pixel>& pixels() const;

    // Allow us to change a pixel... might be a bad idea
    Pixel& operator()(int, int);
    Image& operator=(const Image&);
};

#endif
