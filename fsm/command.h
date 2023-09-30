#include <string>

enum Commands
{
    NADA,
    M025,
    M050,
    M100,
    DEV,
    MEET,
    ETIRPS,
};

class Command
{
  public:
    Commands cmd{Commands::NADA};
    Command() = default;
    ~Command() = default;
    std::string cmd_to_string();
    Commands wait_for_cmd();
};
