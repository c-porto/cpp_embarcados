#pragma once

#include "../calendar/calendar.h"
#include "../clock/clock.h"

class ClockCalendar : public Clock, public Calendar {
public:
  ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm);
  void advance();
};
