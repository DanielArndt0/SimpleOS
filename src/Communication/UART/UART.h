#pragma once
#include <avr/io.h>
#include <string.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/String/String.h"
#include "DataTypes/Typedefs.h"
#include "DataTypes/Object/Object.h"

// TODO Desenvolver biblioteca UART
namespace SimpleOS
{
  namespace Com
  {
    class UART implements Root::Object
    {
    private:
      static bool status;
      UART *buffer;

    protected:
      UART *send(Data::UChar data);
      UART *send(Data::C_String data);
      static Data::UChar receive(void);

    public:
      void begin(Data::UInt baudRate);
      void flush(void);

      UART &operator<<(SimpleOS::Data::Char command);
      UART &operator<<(SimpleOS::Data::C_String data);
      UART &operator<<(const SimpleOS::Data::String &data);
      UART &operator<<(Data::Int data);
      UART &operator<<(Data::UInt data);
      UART &operator<<(Data::Long data);
      UART &operator<<(Data::ULong data);
      UART &operator<<(float data);
      UART &operator<<(double data);

    public:
      SimpleOS::Data::C_String toString() override { return "UART Class"; }
    };
  }
}