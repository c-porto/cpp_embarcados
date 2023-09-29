#pragma once
#include "clock_transition.h"
#include "vending_machine.h"
#include <cstdint>
#include <ctime>

static volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

void delay(void) {
  for (int i = 0; i < CLOCKS_PER_SEC; ++i) {
    __asm__("NOP");
  }
}

void clock_transition(uint8_t *cmd) {
  clock_t last = clock();
  while ((clock() - last) / CLOCKS_PER_SEC < 3) {
    delay();
  }
  uint32_t sw = (*data >> 8) & 0x000000ff;
  *cmd = sw;
}

void init_gpio() { *direction = 0xffffffff; }

Command which_cmd(uint8_t& cmd) {
  switch (cmd) {
  case 0:
    return Command::NADA;

  case 1:
    return Command::M025;

  case 2:
    return Command::M050;

  case 3:
    return Command::M075;

  case 4:
    return Command::M100;

  case 8:
    return Command::DEV;

  case 16:
    return Command::MEET;

  case 32:
    return Command::ETIRPS;
  default:
    return Command::NADA;
  }
}
