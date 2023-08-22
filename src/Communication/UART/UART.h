#pragma once
#include <avr/io.h>
#include <string.h>
#include "System/Base.h"
#include "Core/UART/UARTCore.h"
#include "DataTypes/Number.h"
#include "DataTypes/String/SimpleString/SimpleString.h"

namespace SimpleOS
{
  namespace Com
  {
    class UART : extends Core::UARTCore
    {
    public:
      UART(unsigned int baudRate = 9600);

    public:
      template <typename T>
      UART &operator<<(const SimpleOS::Data::Number<T> &data);
      UART &operator<<(char command);
      UART &operator<<(const char *data);
      UART &operator<<(int data);
      UART &operator<<(unsigned int data);
      UART &operator<<(long data);
      UART &operator<<(unsigned long data);
      UART &operator<<(float data);
      UART &operator<<(double data);
      UART &operator<<(bool data);
      UART &operator<<(void *ptr);
      UART &operator<<(const SimpleOS::Data::SimpleString &data);
      UART &operator<<(Concepts::Printable &printable);
    };
  }
}

template <class T>
SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(const SimpleOS::Data::Number<T> &data)
{
  send(data.toString());
  return *this;
}