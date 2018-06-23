#ifndef IMAGE_H
#define IMAGE_H 1

#include "Header.h"
#include "Pixel.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

class Image {
  private:
    Header HDR;
    Pixel* PIX;

    // Disallow default and assignment
    Image ();
    Image& operator=(const Image& rhs);

    // Used by Constructors to build Image
    static Pixel* read_pixels(const Header&, std::ifstream&);
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
    const Pixel* pixels() const;

    // Allow us to change a pixel... might be a bad idea
    Pixel& operator()(int, int);
};

#endif
