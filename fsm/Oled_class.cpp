#include "Oled_class.h"
#include "Oled.h"
#include <cstring>
#include <sstream>

static volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
static volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
static volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

void Oled::init(void)
{
    oledInit();
}

void Oled::clear(void)
{
    oledClear();
}

void Oled::print_display(std::string drink, float balance, float change)
{
    std::stringstream drink_stream;
    std::stringstream balance_stream;
    std::stringstream change_stream;

    this->clear();

    drink_stream << "Drink escolhido: " << drink;
    setLine(0);
    printString((char *)drink_stream.str().c_str());

    balance_stream << "Saldo(R$): " << balance;
    setLine(1);
    printString((char *)balance_stream.str().c_str());

    change_stream << "Troco(R$): " << change;
    setLine(2);
    printString((char *)change_stream.str().c_str());
}
