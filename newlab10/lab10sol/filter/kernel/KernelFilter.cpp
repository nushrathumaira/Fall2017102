#include "KernelFilter.h"

KernelFilter::KernelFilter () :
  Filter() {}

KernelFilter::KernelFilter (string name) :
  Filter(name) {}

KernelFilter::KernelFilter (const KernelFilter& kf) :
  Filter(kf.name) {}

KernelFilter::~KernelFilter () {}

// Simply apply a kernel to the image
// Derived classes could do something fancier - like apply 2 kernels
// or perform some other processing first
void KernelFilter::apply(Image& img, const Kernel& k) const {
  int k_center = k.size()/2;
  int img_rows = img.header().height();
  int img_cols = img.header().width();

  // Make reference image
  Image copy(img);

  // Apply kernel to each pixel
  // Omit outer edges. Simplest solution
  for (int y = k_center; y < img_rows-k_center; y++) {
    for (int x = k_center; x < img_cols-k_center; x++) {
      img(x,y) = this->apply_kernel(copy, x, y, k);
    }
  }
}

Pixel KernelFilter::apply_kernel(Image& img, int x, int y, const Kernel& k) const {
  int k_center = k.size()/2;
  int r, g, b;
  r = g = b = 0;

  // The kernel is centered at k_center (1 for a 3x3 kernel)
  // This loop takes values -1, 0, 1 which we can use as offsets
  // Nice because we can use as offsets for kernel and image pixel at x,y
  for (int j = -k_center; j <= k_center; j++) {
    for (int i = -k_center; i <= k_center; i++) {
      Pixel& p = img(x+i,y+i);
      double modifier = k[k_center+i][k_center+j];
      r += (int)(p.r() * modifier);
      g += (int)(p.g() * modifier);
      b += (int)(p.b() * modifier);
    }
  }

  // Make sure within RBG range of pixel
  r = Filter::clamp(0,255,r);
  g = Filter::clamp(0,255,g);
  b = Filter::clamp(0,255,b);

  return Pixel(r,g,b);
}
