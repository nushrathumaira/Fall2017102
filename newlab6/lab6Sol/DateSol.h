#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
  This class represents a simple date and provides a compare
  function for sorting purposes. Also a print() method for well
  formatted printing using stringstream.
**/
class Date {
  private:
    // Basic data members: private so only Date can see them
    int month, day, year;

  public:
    // Static compare function called using the Date:: scope
    static bool compare(const Date& lhs, const Date& rhs);
    // Static string array used in print() to get month names
    static const string MONTHS[12];

    // Default constructor and destructor
    Date ();
    ~Date ();

    // Getter/setter for month
    int get_month() const;
    void set_month(int month);

    int get_day() const;
    void set_day(int day);

    int get_year() const;
    void set_year(int year);

    std::string print();
};

#endif
