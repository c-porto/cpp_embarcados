#pragma once
#include "Oled_class.h"
#include "command.h"
#include "state.h"
#include <iostream>
#include <ostream>

class IState;

class Machine 
{
 public:
    std::string drink_;
    IState *current_state_;
    Command *cmd_;
    Oled *display;
    Machine();
    void state_update(std::ostream &os);
    friend std::ostream &operator<<(std::ostream &os, Machine &machine);
};

// new_state function, constructor and destructor,
