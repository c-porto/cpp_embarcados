#include "vending_machine.h"
#include "clock_transition.h"
#include "estados.h"
#include <iostream>
#include <ostream>

vending_machine::vending_machine() {
  state = State::S000;
  drink = "Não Especificado";
  cmd = 0;
  change = 0;
}

std::string vending_machine::state_to_string() {
  switch (state) {
  case State::S000:
    return "S000";
  case State::S025:
    return "S025";
  case State::S050:
    return "S050";
  case State::S075:
    return "S075";
  case State::S100:
    return "S100";
  case State::S125:
    return "S125";
  case State::S150:
    return "S150";
  }
}

void vending_machine::state_update(std::ostream &os, OLED &display) {
  display.print_string(drink, state, change);
  clock_transition(&cmd);
  Command command = which_cmd(&cmd);
  switch (state) {
  case S000:
    switch (command) {
    case Command::NADA:
      state = S000;
      break;
    case Command::M025:
      state = S025;
      break;
    case Command::M050:
      state = S050;
      break;
    case Command::M075:
      state = S075;
      break;
    case Command::M100:
      state = S100;
      break;
    case Command::DEV:
      state = S000;
    case Command::MEET:
      state = S000;
      drink = "MEET";
      break;
    case Command::ETIRPS:
      state = S000;
      drink = "ETIRPS";
      break;
    }
  case S025:
    switch (command) {
    case Command::NADA:
      state = S025;
      break;
    case Command::M025:
      state = S050;
      break;
    case Command::M050:
      state = S075;
      break;
    case Command::M075:
      state = S100;
      break;
    case Command::M100: 
        state = S125;
        break;
    case Command::DEV:
        state = S000;
        break;
    case Command::ETIRPS:
        state = S025;
        drink = "ETIRPS";
    case Command::MEET:
      state = S000;
      drink = "MEET";
      break;
    }
  case S050:
    switch (command) {
        case Command
    
    }

  }
}

std::ostream &operator<<(std::ostream &os, vending_machine &machine) {
  os << "Estado Atual: " << machine.state_to_string() << std::endl;
  os << "Drink: " << machine.drink << std::endl;
  os << "Comando Atual: " << machine.cmd << std::endl;
  return os;
}
