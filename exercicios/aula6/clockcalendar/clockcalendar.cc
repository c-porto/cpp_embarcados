#include "../calendar/calendar.h"
#include "../clock/clock.h"
#include "clockcalendar.h"
#include<string>

ClockCalendar::ClockCalendar(int mt, int d, int y, int h, int m, int s, int pm)
    : Clock(h, m, s, pm), Calendar(mt, d, y) {}

void ClockCalendar::advance() {
  int wasPm = this->is_pm; 
  Clock::advance();
  if (wasPm && !this->is_pm)
    Calendar::advance();
}
std::string ClockCalendar::time_to_string(){
    std::string str_pm = is_pm ? "PM" : "AM";
    auto sec = char_decode(this->sec);
    auto min = char_decode(this->min);
    auto hr = char_decode(this->hr);
    auto day = char_decode(this->day);
    auto month = char_decode(this->mo);
    auto year = char_decode(this->yr);
    return  hr + ":" + min + "sec" + " " + str_pm + "  " + day + "/" + month +  "/" + year;
}

std::string char_decode(int n){
    return std::to_string(n);
}
