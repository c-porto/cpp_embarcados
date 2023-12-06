#include "Oled.h"
#include "Oled_class.h"
#include "state.h"
#include "vending_machine.h"
#include <iostream>

int main()
{
    Machine soda_machine;
    soda_machine.display->init();
    soda_machine.display->clear();
    setLine(0);
    printString("Por favor");
    setLine(1);
    printString("Escolha o Refri:");
    setLine(2);
    printString("Preco: R$ 1.50");

    while (true)
    {
        soda_machine.cmd_->cmd = soda_machine.cmd_->wait_for_cmd();
        soda_machine.state_update(std::cout);
    }
}
