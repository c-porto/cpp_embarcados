#pragma once
#include "vending_machine.h"

class Machine;

class State
{
  public:
    virtual void init(Machine *) = 0;
    virtual void exit(Machine *) = 0;
    virtual void next_state(Machine *) = 0;
    virtual std::string state_name() = 0;
    virtual ~State()
    {
    }
};

class S000 : public State
{
  public:
    void init(Machine *);
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S000()
    {
        value_ = 0.0f;
        change_ = 0.0f;
        state_name_ = "S000";
    }
    S000(const S000 &other);
    S000 &operator=(const S000 &other);
    float value_;
    float change_;
    std::string state_name_;
};

class S025 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S025()
    {
        value_ = 0.25f;
        change_ = 0.0f;
        state_name_ = "S025";
    }
    S025(const S025 &other);
    S025 &operator=(const S025 &other);
    float value_;
    float change_;
    std::string state_name_;
};

class S050 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S050()
    {
        value_ = 0.50f;
        change_ = 0.0f;
        state_name_ = "S050";
    }
    S050(const S050 &other);
    S050 &operator=(const S050 &other);
    float value_;
    float change_;
    std::string state_name_;
};

class S075 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S075()
    {
        value_ = 0.75f;
        change_ = 0.0f;
        state_name_ = "S075";
    }
    S075(const S075 &other);
    S075 &operator=(const S075 &other);
    float value_;
    float change_;
    std::string state_name_;
};

class S100 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S100()
    {
        value_ = 1.00f;
        change_ = 0.0f;
        state_name_ = "S100";
    }
    S100(const S100 &other);
    S100 &operator=(const S100 &other);
    float change_;
    float value_;
    std::string state_name_;
};
class S125 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S125()
    {
        value_ = 1.25f;
        change_ = 0.0f;
        state_name_ = "S125";
    }
    S125(const S125 &other);
    S125 &operator=(const S125 &other);
    float value_;
    float change_;
    std::string state_name_;
};
class S150 : public State
{
  public:
    void init(Machine *) ;
    void exit(Machine *) ;
    void next_state(Machine *) ;
    inline std::string state_name() ;
    static State &state_instance();

  private:
    S150()
    {
        value_ = 1.50f;
        change_ = 0.0f;
        state_name_ = "S150";
    }
    S150(const S150 &other);
    S150 &operator=(const S150 &other);
    float value_;
    float change_;
    std::string state_name_;
};
