#include "clockcalendar.h"
#include <string>

char *  time_to_string(ClockCalendar& clk){
    std::string str_pm = clk.is_pm ? "PM" : "AM";
}

std::string char_decode(int n){
    return std::to_string(n);
}
