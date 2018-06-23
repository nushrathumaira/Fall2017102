#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "DateSol.h"

int main(int argc, char const *argv[]) {
  std::ifstream infile(argv[1]);
  std::ofstream outfile(argv[2]);

  // Is this dumb? What happens with uncaught in main?
  if (! (infile && outfile) )
    throw std::runtime_error("Could not open input/output files\n");

  int num;
  infile >> num;

  if (num > 0) {
    int m, d, y, ndx = 0;
    Date dates[num];

    while (infile >> m >> d >> y) {
      dates[ndx].set_month(m);
      dates[ndx].set_day(d);
      dates[ndx].set_year(y);
      ndx++;
    }

    std::sort(dates, dates + num, Date::compare);

    ndx = 0;
    while (ndx < num) {
      outfile << dates[ndx].print() << std::endl;
      ndx++;
    }
  }

  infile.close();
  outfile.close();

  return 0;
}
