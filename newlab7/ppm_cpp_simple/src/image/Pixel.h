#ifndef PIXEL_H
#define PIXEL_H 1

#include <math.h>
#include <ostream>

class Pixel {
  private:
    uint8_t R, G, B;

  public:
    Pixel ();
    Pixel (const Pixel&);
    Pixel (uint8_t, uint8_t, uint8_t);
    ~Pixel ();

    // Plain getters, use only these for immutable pixels
    uint8_t r () const;
    uint8_t g () const;
    uint8_t b () const;

    // Non-const ref getters, use for Python style accessors
    // If we want to do validation, we can use true setters...
    // But a Pixel is basically a glorified struct
    uint8_t& r ();
    uint8_t& g ();
    uint8_t& b ();

    // Assignment operator
    Pixel& operator=(const Pixel&);
    // Output operator
    friend std::ostream& operator<<(std::ostream&, const Pixel&);
};

#endif
