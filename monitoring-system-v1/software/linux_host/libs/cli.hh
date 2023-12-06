#ifndef CLI_HH_
#define CLI_HH_

#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>

namespace cli {

/* Class used to parse CLI settings */
class CliSettings {
  /* Just typedef's for convenience */
  using config_handler =
      std::function<void(CliSettings &, std::string const &)>;
  using help_handler = std::function<void(CliSettings &)>;

 public:
  /* Constructors */
  CliSettings();
  /* "Getter" functions */
  auto get_baudrate() { return baudrate_; }
  auto get_port() { return port_; }
  auto get_help() { return help_; }
  /* Main parsing function */
  static std::unique_ptr<CliSettings> parse_settings(int argc,
                                                     const char **argv) {
    /* Creating pointer to store parsed settings */
    auto settings = std::make_unique<CliSettings>();

    /* Iterating over argv */
    for (std::size_t i{1}; i < argc; ++i) {
      std::string user_input{argv[i]};

      /* Checking for help flag */
      if (auto h{settings->help_map_.find(user_input)};
          h != settings->help_map_.end()) {
        h->second(*settings);
      } else if (auto c{settings->uart_config_map_.find(
                     user_input)}; /* Checking for uart settings */
                 c != settings->uart_config_map_.end()) {
        if (++i >
            argc) { /* Might throw if user provides not enough arguments */
          throw std::runtime_error("Not enough parameters");
        }
        c->second(*settings, {argv[i]});
      } else { /* Invalid parameters provided */
        throw std::runtime_error("Invalid parameters");
      }
    }
    /* Returning parsed settings */
    return settings;
  }

 private:
  bool help_{false};
  std::optional<std::string> port_;
  std::optional<uint32_t> baudrate_;
  std::unordered_map<std::string, config_handler> uart_config_map_;
  std::unordered_map<std::string, help_handler> help_map_;
};
}  // namespace cli
#endif  // !CLI_HH_
