#ifndef KERNEL_FILTER_H
#define KERNEL_FILTER_H 1

#include <vector>
#include <string>
#include "../../image/Image.h"
#include "../../image/Pixel.h"
#include "../Filter.h"

using namespace std;
using Kernel = vector<vector<double>>;

class KernelFilter : public Filter {
  protected:
    // Protected methods
    KernelFilter ();
    KernelFilter (string);
    KernelFilter (const KernelFilter&);

    // These apply a passed kernel, and work for any
    // derived class. You could also overload them if you wanted.
    virtual void apply(Image&, const Kernel&) const;
    virtual Pixel apply_kernel(Image&, int x, int y, const Kernel&) const;

  public:
    virtual ~KernelFilter () = 0;

    // Public Interface
    virtual void apply(Image&) const = 0;

};

#endif
