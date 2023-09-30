#include <string>

typedef enum 
{
    NADA = 0,
    M025, 
    M050,
    M100,
    DEV,
    MEET,
    ETIRPS,
}Commands;

class Command
{
  public:
    Commands cmd;
    Command();
    std::string cmd_to_string();
    Commands wait_for_cmd();
};
