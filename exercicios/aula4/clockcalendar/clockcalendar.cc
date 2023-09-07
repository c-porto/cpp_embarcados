#include "../calendar/calendar.h"
#include "../clock/clock.h"

class ClockCalendar : public Clock, public Calendar {
public:
  ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm);
  void advance();
};

ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm)
    : Clock(h, m, s, pm), Calendar(mt, d, y) {}

void ClockCalendar::advance() {
  int wasPm = this->is_pm; 
  Clock::advance();
  if (wasPm && !this->is_pm)
    Calendar::advance();
}
