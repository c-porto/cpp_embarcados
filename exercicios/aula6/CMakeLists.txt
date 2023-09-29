project(ClockCalendar)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)
add_executable(${PROJECT_NAME} main.cc clockcalendar/clockcalendar.cc clock/clock.cc calendar/calendar.cc)

target_include_directories(${PROJECT_NAME} PUBLIC calendar/ PUBLIC clock/ PUBLIC clockcalendar/)

