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
    std::string inicial_message = "Por favor escolha seu refri e insira as moedas como pagamento";
    printString((char *)inicial_message.c_str());

    while (true)
    {
        soda_machine.cmd_->cmd = soda_machine.cmd_->wait_for_cmd();
        soda_machine.state_update(std::cout);
    }
}
