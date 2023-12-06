#include "emb_sys_comm.hh"

#include <absl/strings/numbers.h>
#include <absl/strings/str_split.h>

#include <array>
#include <chrono>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <unistd.h>
#include <vector>

#include "log_protocol.hh"
#include "request.hh"
#include "uart.hh"

namespace monitoring_system {

/* Function that makes the request for the embedded system */
void LinuxHost::make_request(RequestP rq, ProtocolP pr, UartRef uart) {

  /* Getting the correct message frame */
  logs::MessageFrame msg_frame = rq->emb_sys_log_request(uart);

  /* Commucation might throw */
  try {
    /* Actually sends and receives messages via uart, also deserializes the data */
    stored_logs_ = pr->deserialize_data(msg_frame, uart);
  } catch (std::exception const &ex) { 
    std::cerr << ex.what() << '\n';
    std::cerr << "Restarting the program" << '\n';
    system("clear");
  }
}

/* Depending on the user's choice it's needed different types of requests, hence this factory function */
RequestP LinuxHost::request_factory(logs::RequestTypes &rq) {
  RequestP request;
  switch (rq) {
  case logs::RequestTypes::kTotalTime:
    request = new logs::TotalTimeRequest;
    return request;
  case logs::RequestTypes::kEvents:
    request = new logs::EventsRequest;
    return request;
  default:
    return nullptr;
  }
}

/* Depending on the user's choice it's needed different types of requests, hence this factory function */
ProtocolP LinuxHost::protocol_factory(logs::RequestTypes &rq) {
  ProtocolP protocol;
  switch (rq) {
  case logs::RequestTypes::kTotalTime:
    protocol = new logs::TotalTimeProtocol;
    return protocol;
  case logs::RequestTypes::kEvents:
    protocol = new logs::EventProtocol;
    return protocol;
  default:
    return nullptr;
  }
}

/* Function for parsing the time window log events */
void LinuxHost::parse_time_window_events(std::ostream &os) {
  os << "\n\n";

  os << "Log file, stored in ./logs/, stores embedded system events sorted by "
        "time of request. To analyze a specific time window its only needed to "
        "look for the closest request made in the log file "
     << "\n\n";

  std::this_thread::sleep_for(std::chrono::seconds{3});

  system("clear");

  os << "Displaying stored events from the log file"
     << "\n\n\n";

  /* Log file path */
  const std::filesystem::path log_path{"./logs/logs.txt"};

  /* Log file stream, used for read/write of the file */
  std::fstream log_file{log_path, std::ios::in | std::ios::app};

  /* String to hold the log file lines */
  std::string line;

  /* Printing all log file lines */
  while (std::getline(log_file, line)) {
    os << line << '\n';
  }

  std::cout << '\n';

  /* Deleting host application queue, since there's no needed for old data on memory */
  delete stored_logs_;

  std::this_thread::sleep_for(std::chrono::seconds{3});

  return;
}

/* Function used for handled user input */
logs::EventDisplayOptions
LinuxHost::handle_user_event_option(std::ostream &os) const {
  static int err_count{0};
  int opt;

  /* Getting input from the user */
  while (!(std::cin >> opt)) {
    system("clear");
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    os << "Attempted a invalid option, please try again :)"
       << "\n\n";
    os << "Please choose one of the Options Below:"
       << "\n\n";
    os << "1. Request all events provided by the embedded system"
       << "\n";
    os << "2. Request new events and display all events stored in log file, "
          "including previous "
          "requests"
       << "\n\n";
    os << "Enter your option: ";
  }
  /* Based on the input getting the request type */
  switch (opt) {
  case 1:
    return logs::EventDisplayOptions::kAllEvents;
  case 2:
    return logs::EventDisplayOptions::kTimeWindowEvents;
  default:
    ++err_count;
  }
  /* Wrong input handler */
  if (err_count < 3) {
    return this->handle_user_event_option(os);
  }
  exit(1);
}

/* Displaying logs function */
void LinuxHost::display_logs(std::ostream &os, logs::RequestTypes &type) {
  os << "\n\n";

  /* Switch to accomodate all request options */
  switch (type) {
  /* Total time case */
  case logs::RequestTypes::kTotalTime:
    os << "Option choosen was Total Time online"
       << "\n";
    os << "The result provided by the embedded system was: "
       << stored_logs_->dequeue() << "\n"; /* Print item on the queue, while simultaneously removing from the queue */
    /* Deleting host internal queue from the memory */
    delete stored_logs_;
    return;
  /* Events case */
  case logs::RequestTypes::kEvents:
    os << "Option choosen was Log Events"
       << "\n";
    break;
  }

  os << "___________________________________________________" << '\n';
  os << "              Log Events Display Options "
     << "\n\n";
  os << "Choose one of the Options Below:"
     << "\n\n";
  os << "1. Request all events provided by the embedded system"
     << "\n";
  os << "2. Request new events and display all events stored in log file, "
        "including previous "
        "requests"
     << "\n\n";
  os << "___________________________________________________"
     << "\n\n";
  os << "Enter your option: ";

  /* Calling user input handler */
  auto display_option = this->handle_user_event_option(os);

  /* Handling All events case */
  if (display_option == logs::EventDisplayOptions::kAllEvents) {
    os << '\n' <<  "Displaying all events" << "\n\n";
    /* Dequeueing might throw */
    try {
      /* While there's itens on queue, print and dequeue */
      while (*stored_logs_) {
        os << stored_logs_->dequeue() << '\n';
      }
      /* Deleting host internal queue from memory */
      delete stored_logs_;
    } catch (std::exception const &ex) {
      os << "Exception Ocurred parsing time window events"
         << "\n"
         << "Description: " << ex.what() << '\n';
    }
  os 
     << "\n\n";
    return;
  }

  /* Handling time window case, which might throw */
  try {
    this->parse_time_window_events(os);
  } catch (std::exception const &ex) {
    os << "Exception Ocurred parsing time window events"
       << "\n"
       << "Description: " << ex.what() << '\n';
  }
}

logs::RequestTypes LinuxHost::handle_user_option(std::ostream &os) const {
  static int err_count{0};
  int opt;

  while (!(std::cin >> opt)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    os << "Attempted a invalid option, please try again :)"
       << "\n\n";
    os << "Please choose one of the Options Below:"
       << "\n\n";
    os << "1. Request total time online to embedded system "
       << "\n";
    os << "2. Request event logs to embedded system "
       << "\n\n";
    os << "Enter your option: ";
  }

  switch (opt) {
  case 1:
    return logs::RequestTypes::kTotalTime;
  case 2:
    return logs::RequestTypes::kEvents;
  default:
    ++err_count;
  }

  if (err_count < 3) {
    return this->handle_user_option(os);
  }

  exit(1);
};

FinalSettings LinuxHost::handle_settings(std::ostream &os) const {
  if (user_settings_->get_help()) {
    os << "This program is used to open a uart connection to communicate "
          "with "
          "embedded systems"
       << '\n';
    os << "Usage: ";
    os << "linuxhost [OPTION]..." << '\n';
    os << "OPTIONS:" << '\n' << '\n';
    os << "     -p,  --port: serial port" << '\n';
    os << "     -b, --baudrate: baudrate used in uart" << '\n';
    os << "     -h, --help: used to open this menu" << '\n' << '\n';
    os << "Examples: \n";
    os << "linuxhost --port /dev/ttyUSB0 --baudrate 115200" << '\n';
    exit(0);
  }

  os << "Starting Monitoring System Linux Host" << '\n';

  uart::UartBaudrate baud;

  if (!user_settings_->get_baudrate()) {
    os << "Baudrate wasn't provided, using defaults" << '\n';
  } else {
    switch (static_cast<uart::UartBaudrate>(
        user_settings_->get_baudrate().value())) {
    case uart::UartBaudrate::kBR9600:
      baud = uart::UartBaudrate::kBR9600;
    case uart::UartBaudrate::kBR19200:
      baud = uart::UartBaudrate::kBR19200;
    case uart::UartBaudrate::kBR38400:
      baud = uart::UartBaudrate::kBR38400;
    case uart::UartBaudrate::kBR115200:
      baud = uart::UartBaudrate::kBR115200;
    default:
      os << "Baudrate provided isn't supported, using defaults" << '\n'
         << "Default Baudrate: 115200" << '\n';
      baud = uart::UartBaudrate::kBR115200;
    }
  }

  std::string port;

  if (!user_settings_->get_port()) {
    os << "Port wasn't provided, using defaults" << '\n'
       << "Default Port: /dev/ttyUSB0" << '\n';
    port = "/dev/ttyUSB0";
  } else if (user_settings_->get_port().value().find("/dev/") ==
             std::string::npos) {
    os << "Port provided isn't valid, using defaults" << '\n'
       << "Default Port: /dev/ttyUSB0" << '\n';
    port = "/dev/ttyUSB0";
  } else {
    port = user_settings_->get_port().value();
  }

  os << "\n Finished configurations, trying to create a Uart Connection \n";

  return {baud, port};
}

void LinuxHost::start_cli_interface(std::ostream &os) {
  auto self = shared_from_this();

  auto cfg = self->handle_settings(os);

  uart::UartInterface *channel;

  try {
    channel = new uart::UartInterface(
        os, cfg.second, uart::UartBaudrate::kBR115200,
        uart::UartStopBit::kOneStopBit, uart::UartParityBit::kDisableParityBit,
        uart::UartBitsPerByte::kEightBitsPerByte);
  } catch (std::exception &ex) {
    std::cerr << "Could not open uart connection \n";
    std::cerr << "Exception occurred: " << ex.what() << '\n';
    std::cerr << "Terminating the program... \n";
    exit(1);
  }

  while (true) {
    os << "___________________________________________________" << '\n';
    os << "              Linux Host CLI Started"
       << "\n\n";
    os << "Choose one of the Options Below:"
       << "\n\n";
    os << "1. Request total time online to embedded system "
       << "\n";
    os << "2. Request event logs to embedded system "
       << "\n\n";
    os << "___________________________________________________"
       << "\n\n";
    os << "Enter your option: ";

    auto request_type = self->handle_user_option(os);

    system("clear");

    ProtocolP proto = self->protocol_factory(request_type);

    RequestP rq = self->request_factory(request_type);

    try {
      self->make_request(rq, proto, *channel);
    } catch (std::exception &ex) {
      std::cerr << "Exception occurred, it's description is: " << ex.what()
                << "\n";
      std::cerr << "Restarting the program..."
                << "\n";
      system("clear");
      continue;
    }

    self->display_logs(os, request_type);

    delete rq;
    delete proto;

    os << "Restarting the cli in 5 seconds"
       << "\n";
    std::this_thread::sleep_for(std::chrono::seconds{5});

    system("clear");
  }
}
} // namespace monitoring_system
