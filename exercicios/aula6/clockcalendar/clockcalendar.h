#pragma once

#include "../calendar/calendar.h"
#include "../clock/clock.h"
#include <string>

class ClockCalendar : public Clock, public Calendar {
public:
  ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm);
  std::string  time_to_string(void);
  void advance();
};

std::string char_decode(int n);
