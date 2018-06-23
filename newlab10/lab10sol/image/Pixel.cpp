#include "Pixel.h"

Pixel::Pixel () : R(0), G(0), B(0) {}
Pixel::Pixel (const Pixel& P) : R(P.R), G(P.G), B(P.B) {}
Pixel::Pixel (uint8_t R, uint8_t G, uint8_t B) : R(R), G(G), B(B) {}
Pixel::~Pixel() {}

uint8_t Pixel::r () const { return this->R; }
uint8_t Pixel::g () const { return this->G; }
uint8_t Pixel::b () const { return this->B; }

uint8_t& Pixel::r () { return this->R; }
uint8_t& Pixel::g () { return this->G; }
uint8_t& Pixel::b () { return this->B; }

// Output
std::ostream& operator<< (std::ostream& out, const Pixel& P) {
 return out  << "(" << P.R << " "
                    << P.G << " "
                    << P.B << ")";
}

// Assignment
Pixel& Pixel::operator= (const Pixel& rhs) {
  if (&rhs == this)
    return *this;
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}
