#include "command.h"
#include <cstdint>

/* Switches SW0 to SW5 are mapped to GPIO bits 8 to 13.
 * Buttons BTNU, BTNL, BTND, BTNR, BTNC are mapped to GPIO bits 16 to 20. */

static volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

std::string Command::cmd_to_string()
{
    switch (cmd)
    {
    case Commands::NADA:
        return "Nenhum comando";
    case Commands::M025:
        return "Moeda de 25 centavos";
    case Commands::M050:
        return "Moeda de 50 centavos";
    case Commands::M100:
        return "Moeda de 1 real";
    case Commands::DEV:
        return "Devolução";
    case Commands::ETIRPS:
        return "ETIRPS";
    case Commands::MEET:
        return "MEET";
    default:
        return "Não conseguiu ler o comando";
    }
}

Commands Command::wait_for_cmd()
{
    uint8_t buttons;
    uint8_t sw;
    while (true)
    {
        buttons = (uint8_t)((*data >> 15) & 0x000000FF);
        sw = (uint8_t)((*data >> 7) & 0x0000000F);
        if (buttons & 1U)
        {
            return Commands::M025;
        }
        if ((buttons >> 1U) & 1U)
        {
            return Commands::M050;
        }
        if ((buttons >> 2U) & 1U)
        {
            return Commands::M100;
        }
        if ((buttons >> 3U) & 1U)
        {
            return Commands::ETIRPS;
        }
        if ((buttons >> 4U) & 1U)
        {
            return Commands::MEET;
        }
        if (sw & 1U)
        {
            return Commands::DEV;
        }
    }
}
