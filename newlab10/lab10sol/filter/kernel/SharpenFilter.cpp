#include "SharpenFilter.h"

const Kernel SharpenFilter::SHARPEN_3x3 = {
  { 0,-1, 0 },
  {-1, 5,-1 },
  { 0,-1, 0 }
};

SharpenFilter::SharpenFilter () :
  KernelFilter("Sharpen") {}

SharpenFilter::SharpenFilter (const SharpenFilter& sf) :
  KernelFilter(sf.name) {}

// Finally implement!
void SharpenFilter::apply(Image& img) const {
  KernelFilter::apply(img, SharpenFilter::SHARPEN_3x3);
}
