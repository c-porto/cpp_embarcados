#include "calendar.h"

Calendar::Calendar(int m, int d, int y) : day{d}, mo{m}, yr{y} {}

void Calendar::setCalendar(int m, int d, int y) {
  this->mo = m;
  this->day = d;
  this->yr = y;
}

void Calendar::readCalendar(int &m, int &d, int &y) {
  m = this->mo;
  y = this->yr;
  d = this->day;
}

void Calendar::advance() {
  this->day++;
  if (this->day >= 30) {
    this->day = 1;
    this->mo++;
  }
  if (this->mo > 12) {
    this->mo = 1;
    this->yr++;
  }
}
