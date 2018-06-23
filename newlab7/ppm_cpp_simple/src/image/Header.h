#ifndef HEADER_T
#define HEADER_T 1

#include <string>
#include <iostream>

class Header {
private:
    std::string MAGIC;
    int W, H, MC;

  public:
    Header ();
    Header (const Header& HDR);
    Header (std::string m, int w, int h, int mc);
    ~Header ();

    // Value getter, use only these for immutable headers
    std::string magic() const;
    int width() const;
    int height() const;
    int max_color() const;

    // Ref getter, might want to make these true setters...
    std::string& magic();
    int& width();
    int& height();
    int& max_color();

    // Output
    friend std::ostream& operator<< (std::ostream&, const Header&);
};

#endif
