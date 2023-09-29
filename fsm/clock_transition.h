#pragma once
#include <cstdint>
#include <time.h>
#include <string>
#include "vending_machine.h"

extern clock_t last; 
extern clock_t now;

void delay(uint8_t delay);
void clock_transition(uint8_t* cmd);
void init_gpio(void);
Command which_cmd(uint8_t*);



