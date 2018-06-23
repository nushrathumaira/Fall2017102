#ifndef PIXEL_H
#define PIXEL_H 1

#include <ostream>
#include <istream>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

class Pixel {
  private:
    uint8_t R, G, B;

  public:
    Pixel ();
    Pixel (const Pixel&);
    Pixel (uint8_t, uint8_t, uint8_t);
    ~Pixel ();

    // Getter and setter combined
    uint8_t& r ();
    uint8_t& g ();
    uint8_t& b ();

    // Clamp function
    static inline int clamp(int lo, int hi, int x) {
      return std::max(lo, std::min(x, hi));
    }

    // Assignment operator
    Pixel& operator = (const Pixel&);

    // Math operators
    friend Pixel operator + (const Pixel& lhs, const Pixel& rhs);
    friend Pixel operator + (const Pixel& lhs, const int rhs);
    friend Pixel operator - (const Pixel& lhs, const Pixel& rhs);
    friend Pixel operator - (const Pixel& lhs, const int rhs);
    friend Pixel operator * (const Pixel& lhs, const uint rhs);
    friend Pixel operator / (const Pixel& lhs, uint rhs);

    // Relational operators
    friend bool operator <  (const Pixel& lhs, const Pixel& rhs);
    friend bool operator <= (const Pixel& lhs, const Pixel& rhs);
    friend bool operator >  (const Pixel& lhs, const Pixel& rhs);
    friend bool operator >= (const Pixel& lhs, const Pixel& rhs);
    friend bool operator == (const Pixel& lhs, const Pixel& rhs);
    friend bool operator != (const Pixel& lhs, const Pixel& rhs);

    // Output operator
    friend std::ostream& operator << (std::ostream&, const Pixel&);
    // Input operator
    friend std::istream& operator >> (std::istream&, Pixel& p);
};


#endif
