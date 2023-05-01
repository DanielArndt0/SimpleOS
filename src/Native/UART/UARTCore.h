#pragma once
#include <avr/io.h>
#include <string.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/String/String.h"
#include "DataTypes/Typedefs.h"

// TODO Desenvolver biblioteca UART
namespace SimpleOS
{
  namespace Native
  {
    class UARTCore
    {
    private:
      bool status = false;
      Data::UChar prescaler = 8;
      Data::UInt baudRate;
      Data::UInt ubrr;

    private:
      Data::Float ubrrcalc(Data::ULong clock, Data::UInt prescaler, Data::UInt baudRate) const;

    protected:
      void begin(Data::UInt baudRate);
      void send(Data::UChar data);
      void send(Data::C_String data);
      Data::UChar receive(void);
      void flush(void);
      bool isStarted();
      Data::UInt getBaudRate() const;
      void setBaudRate(Data::UInt baudRate);
      void disableReception();
      void enableReception();
      void disableTransmission();
      void enableTransmission();
    };
  }
}