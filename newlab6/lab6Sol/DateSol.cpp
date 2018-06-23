#include "DateSol.h"

// Just an array of strings. Access a month using:
// Date::MONTHS[0] ---> "JANUARY"
// GLOBAL TO THE CLASS
// Also, why is this const?
const string Date::MONTHS[] = {
  "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",
  "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER",
  "NOVEMBER", "DECEMBER"
};

// Default, just make sure the fields are set to something
Date::Date() {
  this->month = 1;
  this->day = 1;
  this->year = 1000;
}
// Destructor, end of object life cycle
Date::~Date() {}

// STATIC COMPARE
bool Date::compare(const Date& lhs, const Date& rhs) {
  if (lhs.year == rhs.year) {
    if (lhs.month == rhs.month) {
      return lhs.day < rhs.day;
    } else {
      return lhs.month < rhs.month;
    }
  } else {
    return lhs.year < rhs.year;
  }
}

// Sample getter/setter
// What does this const mean?
int Date::get_month() const {
  return this->month;
}
void Date::set_month(int month) {
  this->month = month;
}

int Date::get_day() const {
  return this->day;
}
void Date::set_day(int day) {
  this->day = day;
}

int Date::get_year() const {
  return this->year;
}
void Date::set_year(int year) {
  this->year = year;
}

std::string Date::print() {
  std::stringstream ss;
  ss << setw(10) << Date::MONTHS[this->month-1]
     << setw(3) << this->day
     << setw(5) << this->year;
  return ss.str();
}

// IMPLEMENT OTHER METHODS HERE
//  * * * *
//  * * * *
//  * * * *
