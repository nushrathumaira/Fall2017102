#ifndef SHARPEN_FILTER_H
#define SHARPEN_FILTER_H 1

#include <vector>
#include "KernelFilter.h"
#include "../../image/Image.h"
#include "../../image/Pixel.h"

using namespace std;

class SharpenFilter : public KernelFilter {
  protected:
    static const Kernel SHARPEN_3x3;

  public:
    // Public Interface
    SharpenFilter ();
    SharpenFilter (const SharpenFilter&);
    virtual ~SharpenFilter () {}

    // Finally implement!
    virtual void apply(Image&) const;

};

#endif
