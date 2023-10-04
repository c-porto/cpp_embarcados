#include "vending_machine.h"
#include <iostream>
#include <ostream>

Machine::Machine()
{
    current_state_ = &S000::state_instance();
    drink_ = "Escolha";
    display = new Oled;
    cmd_ = new Command;
    change_ = 0.0f;
}

void Machine::state_update(std::ostream &os)
{
    this->current_state_->exit(this);
    this->current_state_->next_state(this);
    this->current_state_->init(this);
    os << *this;
}

/* Apenas para DEBUG */
std::ostream &operator<<(std::ostream &os, Machine &machine)
{
    os << "Estado Atual: " << machine.current_state_->state_name() << std::endl;
    os << "Drink: " << machine.drink_ << std::endl;
    os << "Comando Atual: " << machine.cmd_->cmd_to_string() << std::endl;
    return os;
}
