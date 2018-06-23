#include "Header.h"

Header::Header () :
  MAGIC(""), W(0), H(0), MC(0) {}
Header::Header (const Header& HDR) :
  MAGIC(HDR.MAGIC), W(HDR.W), H(HDR.H), MC(HDR.MC) {}
Header::Header (std::string m, int w, int h, int mc) :
  MAGIC(m), W(w), H(h), MC(mc) {}
Header::~Header () {}

// Simple getter
std::string Header::magic () const { return this->MAGIC; }
int Header::width () const { return this->W; }
int Header::height () const { return this->H; }
int Header::max_color () const { return this->MC; }

// Ref getter
std::string& Header::magic () { return this->MAGIC; }
int& Header::width () { return this->W; }
int& Header::height () { return this->H; }
int& Header::max_color () { return this->MC; }

std::ostream& operator<< (std::ostream& out, const Header& hdr) {
  return out << hdr.magic() << std::endl
      << hdr.width() << std::endl
      << hdr.height() << std::endl
      << hdr.max_color() << std::endl;
}
