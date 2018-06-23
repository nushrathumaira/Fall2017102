#include "Pixel.h"

Pixel::Pixel () : R(0), G(0), B(0) {}
Pixel::Pixel (const Pixel& P) : R(P.R), G(P.G), B(P.B) {}
Pixel::Pixel (uint8_t R, uint8_t G, uint8_t B) : R(R), G(G), B(B) {}
Pixel::~Pixel() {}

uint8_t& Pixel::r () { return this->R; }
uint8_t& Pixel::g () { return this->G; }
uint8_t& Pixel::b () { return this->B; }

// Output
std::ostream& operator<< (std::ostream& out, const Pixel& P) {
 return out  << "(" << (int)P.R << " "
                    << (int)P.G << " "
                    << (int)P.B << ")";
}

// Input
std::istream& operator >> (std::istream& in, Pixel& p) {
  return in >> (uint&)p.r() >> (uint&)p.g() >> (uint&)p.b();
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

Pixel operator + (const Pixel& lhs, const Pixel& rhs) {
  int r = Pixel::clamp(0, 255, (int)lhs.R + (int)rhs.R);
  int g = Pixel::clamp(0, 255, (int)lhs.G + (int)rhs.G);
  int b = Pixel::clamp(0, 255, (int)lhs.B + (int)rhs.B);
  return Pixel(r,g,b);
}

Pixel operator + (const Pixel& lhs, const int rhs) {
  int r = Pixel::clamp(0, 255, (int)lhs.R + rhs);
  int g = Pixel::clamp(0, 255, (int)lhs.G + rhs);
  int b = Pixel::clamp(0, 255, (int)lhs.B + rhs);
  return Pixel(r,g,b);
}

Pixel operator - (const Pixel& lhs, const Pixel& rhs) {
  int r = Pixel::clamp(0, 255, (int)lhs.R - (int)rhs.R);
  int g = Pixel::clamp(0, 255, (int)lhs.G - (int)rhs.G);
  int b = Pixel::clamp(0, 255, (int)lhs.B - (int)rhs.B);
  return Pixel(r,g,b);
}

Pixel operator - (const Pixel& lhs, const int rhs) {
  int r = Pixel::clamp(0, 255, (int)lhs.R - rhs);
  int g = Pixel::clamp(0, 255, (int)lhs.G - rhs);
  int b = Pixel::clamp(0, 255, (int)lhs.B - rhs);
  return Pixel(r,g,b);
}

Pixel operator * (const Pixel& lhs, const uint rhs) {
  int r = min(255u, (uint)lhs.R * rhs);
  int g = min(255u, (uint)lhs.G * rhs);
  int b = min(255u, (uint)lhs.B * rhs);
  return Pixel(r,g,b);
}

Pixel operator / (const Pixel& lhs, const uint rhs) {
  int r = lhs.R / rhs;
  int g = lhs.G / rhs;
  int b = lhs.B / rhs;
  return Pixel(r,g,b);
}

bool operator <  (const Pixel& lhs, const Pixel& rhs) {
  return tie(lhs.R, lhs.G, lhs.B) < tie(rhs.R, rhs.G, rhs.B);
}

bool operator == (const Pixel& lhs, const Pixel& rhs) {
  return tie(lhs.R, lhs.G, lhs.B) == tie(rhs.R, rhs.G, rhs.B);
}

bool operator >  (const Pixel& lhs, const Pixel& rhs) { return rhs < lhs; }
bool operator <= (const Pixel& lhs, const Pixel& rhs) { return !(lhs > rhs); }
bool operator >= (const Pixel& lhs, const Pixel& rhs) { return !(lhs < rhs); }
bool operator != (const Pixel& lhs, const Pixel& rhs) { return !(lhs == rhs); }
