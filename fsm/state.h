#pragma once
#include "vending_machine.h"
#include <cstdint>

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
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S000()
    {
    }
    S000(const S000 &other);
    S000 &operator=(const S000 &other);
    float value_{0.0f};
    float change_{0.0f};
    std::string state_name_{"S000"};
};

class S025 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S025()
    {
    }
    S025(const S025 &other);
    S025 &operator=(const S025 &other);
    float value_{0.25f};
    float change_{0.0f};
    std::string state_name_{"S025"};
};

class S050 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S050()
    {
    }
    S050(const S050 &other);
    S050 &operator=(const S050 &other);
    float value_{0.50f};
    float change_{0.0f};
    std::string state_name_{"S050"};
};

class S075 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S075()
    {
    }
    S075(const S075 &other);
    S075 &operator=(const S075 &other);
    float value_{0.75f};
    float change_{0.0f};
    std::string state_name_{"S075"};
};

class S100 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S100()
    {
    }
    S100(const S100 &other);
    S100 &operator=(const S100 &other);
    float change_{0.0f};
    float value_{1.00f};
    std::string state_name_{"S100"};
};
class S125 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S125()
    {
    }
    S125(const S125 &other);
    S125 &operator=(const S125 &other);
    float value_{1.25f};
    float change_{0.0f};
    std::string state_name_{"S125"};
};
class S150 : public State
{
  public:
    void init(Machine *) override;
    void exit(Machine *) override;
    void next_state(Machine *) override;
    inline std::string state_name() override;
    static State &state_instance();

  private:
    S150()
    {
    }
    S150(const S150 &other);
    S150 &operator=(const S150 &other);
    float value_{1.50f};
    float change_{0.0f};
    std::string state_name_{"S150"};
};
