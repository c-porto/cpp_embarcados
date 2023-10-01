#include "command.h"

/* Switches SW0 to SW5 are mapped to GPIO bits 8 to 13.
 * Buttons BTNU, BTNL, BTND, BTNR, BTNC are mapped to GPIO bits 16 to 20. */

static volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

Command::Command()
{
    this->cmd = NADA;
}

std::string Command::cmd_to_string()
{
    switch (this->cmd)
    {
    case NADA:
        return "Nenhum comando";
    case M025:
        return "Moeda de 25 centavos";
    case M050:
        return "Moeda de 50 centavos";
    case M100:
        return "Moeda de 1 real";
    case DEV:
        return "Devolução";
    case ETIRPS:
        return "ETIRPS";
    case MEET:
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
        buttons = (unsigned char)((*data >> 15) & 0x000000FF);
        sw = (unsigned char)((*data >> 7) & 0x0000000F);
        if (buttons & 1U)
        {
            return M025;
        }
        if ((buttons >> 1U) & 1U)
        {
            return M050;
        }
        if ((buttons >> 2U) & 1U)
        {
            return M100;
        }
        if ((buttons >> 3U) & 1U)
        {
            return ETIRPS;
        }
        if ((buttons >> 4U) & 1U)
        {
            return MEET;
        }
        if (sw & 1U)
        {
            return DEV;
        }
    }
}
