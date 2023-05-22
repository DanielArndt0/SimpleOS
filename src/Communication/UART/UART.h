#pragma once
#include <avr/io.h>
#include <string.h>
#include "System/Base.h"
// #include "DataTypes/String/String.h"
#include "DataTypes/Number.h"
#include "Native/UART/UARTCore.h"

namespace SimpleOS
{
  namespace Com
  {
    class UART : extends Native::UARTCore
    {
    public:
      UART(unsigned int baudRate = 9600);

    public:
      UART &operator<<(char command);
      UART &operator<<(const char *data);
      // UART &operator<<(const SimpleOS::Data::String &data);
      UART &operator<<(int data);
      UART &operator<<(unsigned int data);
      UART &operator<<(long data);
      UART &operator<<(unsigned long data);
      UART &operator<<(float data);
      UART &operator<<(double data);
      UART &operator<<(bool data);
      UART &operator<<(void *ptr);
    };
  }
}