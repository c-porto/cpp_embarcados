#include "log_protocol.hh"

#include <absl/strings/str_split.h>
#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unistd.h>
#include <vector>

#include "queue.hh"
#include "uart.hh"

namespace monitoring_system {
namespace logs {

/* Function to communicate with embedded system */
log_queue TotalTimeProtocol::deserialize_data(MessageFrame &mf,
                                              uart::UartInterface &uart) const {
  /* Creating queue */
  log_queue q = new ds::Queue<std::string>(1);

  /* Command buffer */
  const char tx_buffer[1] = {mf.cmd};

  /* Receive buffer */
  char rx_buffer[mf.rx_msg_len_bytes];

  /* Sending command via uart */
  int abytes = uart.write_data(tx_buffer, 1);

  /* Delay to syncronize reading */
  usleep(100000);

  /* Receiving response via uart */
  auto res_len = uart.read_data(rx_buffer, sizeof(rx_buffer));

  /* Time variable */
  uint64_t seconds_on{0};

  /* Calculating time with the serialized data */
  for (std::size_t i{0}; i < res_len; ++i) {
    seconds_on |= (static_cast<uint64_t>(rx_buffer[i]) << (8 * i));
  }
  

  /* Getting total time in normal hour:min:sec format */
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(
      std::chrono::seconds(seconds_on));

  auto hrs = std::chrono::duration_cast<std::chrono::hours>(duration);

  duration -= hrs;

  auto min = std::chrono::duration_cast<std::chrono::minutes>(duration);

  duration -= min;

  /* Getting the corresponding string from it */
  const std::string kTotalTimeOn =
      std::to_string(hrs.count()) + " hours, " + std::to_string(min.count()) +
      " minutes, " + std::to_string(duration.count()) + " seconds On";

  /* Enqueueing time */
  q->enqueue(kTotalTimeOn);

  return q;
}

/* Function to communicate with embedded system */
log_queue EventProtocol::deserialize_data(MessageFrame &mf,
                                          uart::UartInterface &uart) const {
  /* Max possible items on queue */
  constexpr std::size_t kMaxNumberOfEvents{101};

  /* Packet delimiter */
  constexpr char packet_delimiter = '#';

  /* Creating a queue */
  log_queue q = new ds::Queue<std::string>(kMaxNumberOfEvents);

  /* Command buffer */
  const char tx_buffer[1] = {mf.cmd};

  /* Receiving buffer */
  char rx_buffer[mf.rx_msg_len_bytes];

  /* Writing command via uart */
  int abytes = uart.write_data(tx_buffer, 1);

  /* Delay for syncronize commucation */
  usleep(100000);

  /* Receiving response from the embedded system */
  auto res_len = uart.read_data(rx_buffer, sizeof(rx_buffer));

  /* Checking invalid response */
  if (res_len <= 1) {
    throw std::runtime_error("No logs available");
  }

  /* Used for turning the buffer into a string */
  rx_buffer[res_len + 1] = '\0';

  /* Getting all the individual envents from the serialized data */
  std::vector<std::string> events = absl::StrSplit(rx_buffer, packet_delimiter);

  /* Enqueueing all events */
  for (std::string const &event : events) {
    q->enqueue(event);
  }

  /* Log file path */
  std::filesystem::path log_path{"./logs/logs.txt"};

  /* Making sure the log path exists */
  if (!std::filesystem::exists("./logs/")) {
    std::filesystem::create_directory("./logs/");
  }

  /* Log file stream */
  std::ofstream log_file{log_path, std::ios::app};

  /* Getting time for logging */
  auto current_time{
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};

  auto time_info = std::localtime(&current_time);

  std::stringstream ss;

  ss << std::put_time(time_info, "%H:%M:%S | %d/%m/%Y");

  log_file << "________________________________________________________________"
              "_____________________________ \n\n\n"
           << "                                           Logs received on "
           << ss.str() << "\n\n";

  /* Dequeuing "Sending Events" packet */
  if (*q) {
    q->dequeue();
  }

  /* Queue for transference of data */
  log_queue final_queue = new ds::Queue<std::string>(kMaxNumberOfEvents);

  /* Saving logs on the log file */
  for (std::size_t i{0}; i < q->lenght(); ++i) {
    /* Operation might throw */
    try {
      log_file << "Event Number: " << i << "| " << q->peek() << '\n';
      final_queue->enqueue(q->dequeue());
    } catch (std::exception const &ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

  log_file << "________________________________________________________________"
              "_____________________________ \n\n\n";

  /* Returning the queue */
  return final_queue;
}
} // namespace logs
} // namespace monitoring_system
