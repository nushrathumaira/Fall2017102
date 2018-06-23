#include "Image.h"

Image::Image (std::ifstream& in) :
 HDR (Image::read_header(in)), PIX () {
   this->PIX = Image::read_pixels(this->HDR, in);
 }

Image::Image (const Image& img) :
  HDR(img.header()),
  PIX(new Pixel[img.header().width() * img.header().height()]) {
    int num_pixels = img.header().width() * img.header().height();
    for (int i = 0; i < num_pixels; i++) {
      this->PIX[i] = img.pixels()[i];
    }
  }

Image::~Image () {
  delete[] PIX;
}

// accessors
const Header& Image::header () const { return this->HDR; }
const Pixel* Image::pixels () const { return this->PIX; }

// Get one pixel
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}

Header Image::read_header (std::ifstream& in) {
  std::string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

void Image::ignore_comments (std::ifstream& in) {
  char c;
  in.get(c);

  while ( isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}

Pixel* Image::read_pixels (const Header& hdr, std::ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  Pixel* pixels = new Pixel[num_pixels];

  if (hdr.magic() == "P3") {
    unsigned int r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      in >> r >> g >> b;
      pixels[i] = Pixel((uint8_t) r, (uint8_t) g, (uint8_t) b);
    }
  } else {
    uint8_t r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      in >> r >> g >> b;
      pixels[i] = Pixel(r, g, b);
    }
  }

  return pixels;
}

void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

void Image::write_header (std::ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

void Image::write_to (std::ofstream& out) const {
  write_header(out);

  int num_pixels = this->HDR.width() * this->HDR.height();

  if (this->HDR.magic() == "P3") {
    for (int i = 0; i < num_pixels; i++) {
      Pixel* p = this->PIX + i;
      out << (int) p->r() << ' '
          << (int) p->g() << ' '
          << (int) p->b() << ' ';
    }
  } else {
    for (int i = 0; i < num_pixels; i++) {
      Pixel* p = this->PIX + i;
      out << p->r() << p->g() << p->b();
    }
  }
}
