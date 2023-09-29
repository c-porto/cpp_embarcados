#include "clock.h"

Clock::Clock(int h, int s, int m, int pm) : hr{h}, min{m}, sec{s}, is_pm{pm} {}

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
