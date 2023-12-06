#include <absl/strings/str_split.h>
#include <unistd.h>

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#include "libs/cli.hh"
#include "libs/emb_sys_comm.hh"
#include "libs/log_protocol.hh"
#include "libs/queue.hh"
#include "libs/uart.hh"

int main(int argc, const char *argv[]) {
  /* Creating the host application as a pointer*/
  auto host = std::make_shared<monitoring_system::LinuxHost>();
  /* Parsing settings might throw */
  try {
    /* Getting CLI settings */
    auto settings = cli::CliSettings::parse_settings(argc, argv);
    /* Loading settings in host */
    host->load_settings(std::move(settings));
  } catch (std::exception &ex) {
    /* Error message for users */
    std::cerr << "Exception triggered parsing cli commands \n Exception "
                 "description: "
              << ex.what() << '\n';
    std::cerr << "Terminating the program..." << '\n';
    exit(1);
  }
  /* Starting CLI interface */
  host->start_cli_interface(std::cout);
}
