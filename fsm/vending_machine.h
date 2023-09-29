#pragma once
#include <cstdint>
#include <iostream>
#include <ostream>

enum State {
  S000 = 0,
  S025 = 25,
  S050 = 50,
  S075 = 75,
  S100 = 100,
  S125 = 125,
  S150 = 150,
};

enum Command {
  NADA,
  M025,
  M050,
  M075,
  M100,
  DEV,
  MEET,
  ETIRPS,
};

class vending_machine final {
  State state;
  std::string drink;
  uint8_t cmd;
  float change;

public:
  vending_machine();
  ~vending_machine() = default;
  void state_update(std::ostream &os);
  std::string state_to_string();
  friend std::ostream &operator<<(std::ostream &os, vending_machine &machine);
};

// new_state function, constructor and destructor,
