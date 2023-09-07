#include "clockcalendar.h"
#include <cstdint>
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  int hour, min, sec, pm, year, month, day;
  auto relogio = std::make_unique<ClockCalendar>(8, 30, 2023, 11, 58, 59, 1);
  ClockCalendar clk{8, 30, 2023, 11, 58, 59, 1};
  for (;;) {
    for (uint64_t i = 0; i < 4000000000; ++i) {
      asm("nop");
    }
    relogio->advance();
    clk.advance();
    clk.readClock(hour, sec, min, pm);
    std::string str_pm = pm ? "PM" : "AM";
    std::cout << hour << ":" << min << ":" << sec << " " << str_pm << std::endl;
    clk.readCalendar(month, day, year);
    std::cout << day << "/" << month << "/" << year << std::endl;
  }
  return 0;
}
