#include "Oled.cpp"
#include "Oled.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

class Clock {
public:
  int hr, min, sec, is_pm;

public:
  Clock(int h, int s, int m, int pm);
  void setClock(int h, int s, int m, int pm);
  void readClock(int &h, int &s, int &m, int &pm);
  void advance();
};

class Calendar {
public:
  int mo, day, yr;

public:
  Calendar(int m, int d, int y);
  void setCalendar(int m, int d, int y);
  void readCalendar(int &m, int &d, int &y);
  void advance();
};

class ClockCalendar : public Clock, public Calendar {
public:
  ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm);
  std::string time_to_string(void);
  std::string year_to_string(void);
  void advance();
};

std::string char_decode(int n);
void vDelay(int s);

int main(int argc, char *argv[]) {
  ClockCalendar clk(9, 8, 2023, 1, 58, 2, 1);
  cout << "EAE" << std::endl;
  oledInit();
  for (;;) {
    oledClear();
    clk.advance();
    std::string date = clk.time_to_string();
    std::string year = clk.year_to_string();
    char *str_to_draw = new char[date.length() + 1];
    strcpy(str_to_draw, date.c_str());
    setLine(0);
    printString(str_to_draw);
    char *year_to_draw = new char[year.length() + 1];
    strcpy(year_to_draw, year.c_str());
    setLine(2);
    printString(year_to_draw);
    vDelay(2);
  }
  return 0;
}

void vDelay(int s) {
  for (int i = 0; i < s; ++i) {
    for (size_t i = 0; i < 2000000; ++i) {
      __asm__("NOP");
    }
  }
}
ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm)
    : Clock(h, m, s, pm), Calendar(mt, d, y) {}

void ClockCalendar::advance() {
  int wasPm = this->is_pm;
  Clock::advance();
  if (wasPm && !this->is_pm)
    Calendar::advance();
}
std::string ClockCalendar::time_to_string() {
  std::string str_pm = is_pm ? "PM" : "AM";
  std::string sec_ = char_decode(this->sec);
  std::string min_ = char_decode(this->min);
  std::string hr_ = char_decode(this->hr);
  return hr_ + ":" + min_ + ":" + sec_ + " " + str_pm ;
}
std::string ClockCalendar::year_to_string() {
  std::string day_ = char_decode(this->day);
  std::string month_ = char_decode(this->mo);
  std::string year_ = char_decode(this->yr);
  return day_ + "/" + month_ + "/" + year_;
}

std::string char_decode(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
Clock::Clock(int h, int s, int m, int pm) : hr(h), min(m), sec(s), is_pm(pm) {}

void Clock::setClock(int h, int s, int m, int pm) {
  this->hr = h;
  this->sec = s;
  this->min = m;
  this->is_pm = pm;
}
void Clock::readClock(int &h, int &s, int &m, int &pm) {
  h = this->hr;
  m = this->min;
  s = this->sec;
  pm = this->is_pm;
}
void Clock::advance() {
  this->sec++;
  if (this->sec >= 60) {
    this->min++;
    this->sec = 0;
  }
  if (this->min >= 60) {
    this->hr++;
    this->min = 0;
  }
  if (this->hr >= 12) {
    this->hr = 0;
    this->is_pm = (this->is_pm & 0x01) ^ 1;
  }
}

Calendar::Calendar(int m, int d, int y) : day(d), mo(m), yr(y) {}

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
