#ifndef UART_HH_
#define UART_HH_

#include <unistd.h>

#include <cstddef>
#include <cstdint>
#include <ostream>
#include <string>
#include <string_view>
namespace uart {

/* Enum classes for type safe config options */

enum class UartBaudrate { kBR9600, kBR19200, kBR38400, kBR115200 };

enum class UartStopBit { kOneStopBit, kTwoStopBit };

enum class UartParityBit { kDisableParityBit, kEnableParityBit };

enum class UartBitsPerByte {
  kFiveBitsPerByte,
  kSixBitsPerByte,
  kSevenBitsPerByte,
  kEightBitsPerByte
};

/* Class responsible to interface uart communication */
class UartInterface {
 public:
  UartInterface(std::ostream &, std::string, UartBaudrate, UartStopBit,
                UartParityBit, UartBitsPerByte);
  ~UartInterface();
  /* Writing data wrapper */
  std::size_t write_data(const void *send_buffer, std::size_t len) const {
    auto res = write(serial_file_, send_buffer, len);
    return res;
  }
  /* Reading data wrapper */
  std::size_t read_data(void *receive_buffer, std::size_t buflen) const {
    auto msg_len = read(serial_file_, receive_buffer, buflen);
    return msg_len;
  }
  /* File descriptor "getter" */
  auto get_port() const { return serial_file_; }

 protected:
  std::string port_;
  int serial_file_;
};

}  // namespace uart
#endif  // !UART_HH_
