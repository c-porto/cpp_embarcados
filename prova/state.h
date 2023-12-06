#pragma once
#include "vending_machine.h"

class Machine;

class IState
{
  public:
    virtual void init(Machine *) = 0;
    virtual void exit(Machine *) = 0;
    virtual void next_state(Machine *) = 0;
    virtual std::string state_name() = 0;
    virtual ~IState()
    {
    }
};

class S000 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S000()
    {
        value_ = 0.0f;

        state_name_ = "Saldo: R$ 0.00";
    }
    S000(const S000 &other);
    S000 &operator=(const S000 &other);
    float value_;

    std::string state_name_;
};

class S025 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S025()
    {
        value_ = 0.25f;

        state_name_ = "Saldo: R$ 0.25";
    }
    S025(const S025 &other);
    S025 &operator=(const S025 &other);
    float value_;

    std::string state_name_;
};

class S050 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S050()
    {
        value_ = 0.50f;

        state_name_ = "Saldo: R$ 0.50";
    }
    S050(const S050 &other);
    S050 &operator=(const S050 &other);
    float value_;

    std::string state_name_;
};

class S075 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S075()
    {
        value_ = 0.75f;

        state_name_ = "Saldo: R$ 0.75";
    }
    S075(const S075 &other);
    S075 &operator=(const S075 &other);
    float value_;

    std::string state_name_;
};

class S100 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S100()
    {
        value_ = 1.00f;

        state_name_ = "Saldo: R$ 1.00";
    }
    S100(const S100 &other);
    S100 &operator=(const S100 &other);

    float value_;
    std::string state_name_;
};
class S125 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S125()
    {
        value_ = 1.25f;

        state_name_ = "Saldo: R$ 1.25";
    }
    S125(const S125 &other);
    S125 &operator=(const S125 &other);
    float value_;

    std::string state_name_;
};
class S150 : public IState
{
  public:
    void init(Machine *);
    void exit(Machine *);
    void next_state(Machine *);
    inline std::string state_name();
    static IState &state_instance();

  private:
    S150()
    {
        value_ = 1.50f;

        state_name_ = "Saldo: R$ 1.50";
    }
    S150(const S150 &other);
    S150 &operator=(const S150 &other);
    float value_;

    std::string state_name_;
};
