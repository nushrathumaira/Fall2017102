#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

const int ID_LEN = 4;
const int TITLE_LEN = 25;
const int PRICE_LEN = 10;

int main(int argc, char const *argv[]) {
  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  int         id;
  std::string title;

  input.imbue(std::locale("en_US.UTF-8"));
  output.imbue(std::locale("en_US.UTF-8"));

  output  << std::setw(ID_LEN) << "ID"
          << std::setw(TITLE_LEN + 2) << "Title"
          << std::setw(PRICE_LEN) << "Price"
          << std::endl;

  while ( input >> id ) {
    int count = 0;
    long double price;
    long double sum = 0;

    while ( input >> std::get_money(price) ) {
      sum += price;
      count++;
    }

    input.clear();
    std::getline(input, title);

    if (title.length() > TITLE_LEN) {
      title.erase(TITLE_LEN - 1, std::string::npos);
      title.replace(TITLE_LEN - 3, std::string::npos, 3, '.');
    }

    output  << std::setw(ID_LEN) << id
            << std::setw(TITLE_LEN + 2) << title
            << std::setw(PRICE_LEN) << std::put_money(sum / (long double) count)
            << std::endl;
  }

  return 0;
}
