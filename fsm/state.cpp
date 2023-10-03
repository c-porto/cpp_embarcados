#include "state.h"
#include "vending_machine.h"
#include "Oled.h"
#include <string>

inline std::string S000::state_name()
{
    return state_name_;
}
void S000::init(Machine *mech)
{
    mech->display->clear();
    if (mech->cmd_->cmd != DEV && mech->cmd_->cmd != CONFIRM) {
        mech->display->print_display(state_name_, value_, change_);
    } else if(mech->cmd_->cmd == CONFIRM) {
        mech->drink_ = "Ainda não escolhido";
        setLine(0);
        printString("Pegue seu Refri :)");
        setLine(1);
        printString("Obrigado S2");
        setLine(2);
        printString("Por favor desligue o switch 1");
    }
}
void S000::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S000::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
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
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->print_display(state_name_, value_, change_);
    if (mech->cmd_->cmd == CONFIRM) {
        setLine(3);
        printString("Saldo insuficiente");
    }
    change_ = 0.0f;
}
void S025::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S025::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
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
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->print_display(state_name_, value_, change_);
    if (mech->cmd_->cmd == CONFIRM) {
        setLine(3);
        printString("Saldo insuficiente");
    }
    change_ = 0.0f;
}
void S050::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S050::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
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
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->print_display(state_name_, value_, change_);
    if (mech->cmd_->cmd == CONFIRM) {
        setLine(3);
        printString("Saldo insuficiente");
    }
    change_ = 0.0f;
}
void S075::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S075::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S100::state_instance();
        break;
    case M050:
        mech->current_state_ = &S125::state_instance();
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.25f;
        break;
    case DEV:
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->print_display(state_name_, value_, change_);
    if (mech->cmd_->cmd == CONFIRM) {
        setLine(3);
        printString("Saldo insuficiente");
    }
    change_ = 0.0f;
}
void S100::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S100::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S125::state_instance();
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.50f;
        break;
    case DEV:
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->print_display(state_name_, value_, change_);
    if (mech->cmd_->cmd == CONFIRM) {
        setLine(3);
        printString("Saldo insuficiente");
    }
    change_ = 0.0f;
}
void S125::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S125::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S150::state_instance();
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.25f;
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.75f;
        break;
    case DEV:
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
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
    mech->display->clear();
    mech->display->print_display(state_name_, value_, change_);
    if (mech->drink_ == "ETIRPS" || mech->drink_ == "MEET"){
        setLine(3);
        printString("SW1 para confirmar");
    }
    if (mech->cmd_->cmd == CONFIRM){
        setLine(3);
        printString("Escolha um refri primeiro");
    }
    change_ = 0.0f;
}
void S150::exit(Machine *mech)
{
    change_ = 0.0f;
    mech->display->clear();
}
void S150::next_state(Machine *mech)
{
    switch (mech->cmd_->cmd)
    {
    case NADA:
        change_ = 0.0f;
        break;
    case M025:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.25f;
        break;
    case M050:
        mech->current_state_ = &S150::state_instance();
        change_ = 0.50f;
        break;
    case M100:
        mech->current_state_ = &S150::state_instance();
        change_ = 1.00f;
        break;
    case DEV:
        change_ = value_;
        mech->display->print_display( "Saldo: R$ 0.00", 0.0f, change_);
        mech->current_state_ = &S000::state_instance();
        break;
    case ETIRPS:
        mech->drink_ = "ETIRPS";
        break;
    case MEET:
        mech->drink_ = "MEET";
        break;
    case CONFIRM:
        if (mech->drink_ == "ETIRPS" || mech->drink_ == "MEET") {
        mech->current_state_ = &S000::state_instance();
        }
        break;
    }
}
IState &S150::state_instance()
{
    static S150 state_instance;
    return state_instance;
}
