#include "state.h"
#include "Oled.h"
#include "vending_machine.h"
#include <ctime>
#include <sstream>
#include <string>
#include <time.h>

inline std::string S000::state_name()
{
    return state_name_;
}
void S000::init(Machine *mech)
{
    if (mech->cmd_->cmd != DEV && mech->cmd_->cmd != NADA)
    {
        mech->display->clear();
        mech->display->print_display(mech->drink_, state_name_, mech->change_);
    }
    else if ((mech->drink_ == "ETIRPS" || mech->drink_ == "MEET") && (mech->cmd_->cmd == NADA))
    {
        mech->drink_ = "Escolha";
        clock_t last = clock();
        while ((clock() - last) < 3UL * CLOCKS_PER_SEC)
            ;
        mech->display->clear();
        setLine(0);
        printString("Por favor");
        setLine(1);
        printString("Escolha o Refri:");
        setLine(2);
        printString("Preco: R$ 1.50");
    }
    else if (mech->cmd_->cmd == DEV)
    {
        clock_t last = clock();
        while ((clock() - last) < 3UL * CLOCKS_PER_SEC)
            ;
        mech->display->clear();
        setLine(0);
        printString("Por favor");
        setLine(1);
        printString("Escolha o Refri:");
        setLine(2);
        printString("Preco: R$ 1.50");
    }
}
void S000::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S000::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        break;
    case M025:
        mech->current_state_ = &S025::state_instance();
        break;
    case M050:
        mech->current_state_ = &S050::state_instance();
        break;
    case M100:
        mech->current_state_ = &S100::state_instance();
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S000::state_instance()
{
    static S000 state_instance;
    return state_instance;
}
inline std::string S025::state_name()
{
    return state_name_;
}
void S025::init(Machine *mech)
{
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
}
void S025::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S025::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        break;
    case M025:
        mech->current_state_ = &S050::state_instance();
        break;
    case M050:
        mech->current_state_ = &S075::state_instance();
        break;
    case M100:
        mech->current_state_ = &S125::state_instance();
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S025::state_instance()
{
    static S025 state_instance;
    return state_instance;
}
inline std::string S050::state_name()
{
    return state_name_;
}
void S050::init(Machine *mech)
{
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
}
void S050::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S050::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        break;
    case M025:
        mech->current_state_ = &S075::state_instance();
        break;
    case M050:
        mech->current_state_ = &S100::state_instance();
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S050::state_instance()
{
    static S050 state_instance;
    return state_instance;
}
inline std::string S075::state_name()
{
    return state_name_;
}
void S075::init(Machine *mech)
{
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
}
void S075::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S075::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        break;
    case M025:
        mech->current_state_ = &S100::state_instance();
        break;
    case M050:
        mech->current_state_ = &S125::state_instance();
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.25f;
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S075::state_instance()
{
    static S075 state_instance;
    return state_instance;
}
inline std::string S100::state_name()
{
    return state_name_;
}
void S100::init(Machine *mech)
{
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
}
void S100::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S100::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        break;
    case M025:
        mech->current_state_ = &S125::state_instance();
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.50f;
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S100::state_instance()
{
    static S100 state_instance;
    return state_instance;
}
inline std::string S125::state_name()
{
    return state_name_;
}
void S125::init(Machine *mech)
{
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
}
void S125::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S125::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        mech->change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S150::state_instance();
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.25f;
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.75f;
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    }
}
IState &S125::state_instance()
{
    static S125 state_instance;
    return state_instance;
}
inline std::string S150::state_name()
{
    return state_name_;
}
void S150::init(Machine *mech)
{
    std::stringstream ss;
    mech->display->clear();
    mech->display->print_display(mech->drink_, state_name_, mech->change_);
    if (mech->drink_ == "ETIRPS" || mech->drink_ == "MEET")
    {
        mech->current_state_ = &S000::state_instance();
        mech->display->clear();
        setLine(0);
        ss << "Pegue seu " << mech->drink_;
        printString((char *)ss.str().c_str());
        mech->cmd_->cmd = NADA;
        mech->current_state_->init(mech);
    }
}
void S150::exit(Machine *mech)
{
    mech->change_ = 0.0f;
    mech->display->clear();
}
void S150::next_state(Machine *mech)
{
    std::stringstream ss;
    switch (mech->cmd_->cmd)
    {
    case NADA:
        mech->change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.25f;
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 0.50f;
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        mech->change_ = 1.00f;
        break;
    case DEV:
        mech->change_ = value_;
        mech->display->clear();
        ss << "R$" << mech->change_;
        setLine(0);
        printString("Devolvendo");
        setLine(1);
        printString((char*) ss.str().c_str());
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        mech->current_state_ = &S150::state_instance();
        break;
    case MEET:
        mech->drink_ = "MEET";
        mech->current_state_ = &S150::state_instance();
        break;
    }
}
IState &S150::state_instance()
{
    static S150 state_instance;
    return state_instance;
}
