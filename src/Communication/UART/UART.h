#pragma once
#include <avr/io.h>
#include <string.h>
#include "SimpleOS/Base.h"
#include "DataTypes/String/String.h"
#include "DataTypes/Number.h"
#include "Native/UART/UARTCore.h"

// TODO Desenvolver biblioteca UART
namespace SimpleOS
{
  namespace Com
  {
    class UART : extends Native::UARTCore
    {
    public:
      UART(Data::UInt baudRate = 9600);

    public:
      UART &operator<<(SimpleOS::Data::Char command);
      UART &operator<<(SimpleOS::Data::C_String data);
      UART &operator<<(const SimpleOS::Data::String &data);
      UART &operator<<(Data::Int data);
      UART &operator<<(Data::UInt data);
      UART &operator<<(Data::Long data);
      UART &operator<<(Data::ULong data);
      UART &operator<<(Data::Float data);
      UART &operator<<(Data::Double data);
      UART &operator<<(void* ptr);
    };
  }
}