#pragma once
#include <avr/io.h>
#include <string.h>
#include "System/Macros.h"
#include "DataTypes/String/String.h"

namespace SimpleOS
{
  namespace Native
  {
    class UARTCore
    {
    private:
      bool status = false;
      unsigned char prescaler = 8;
      unsigned int baudRate;
      unsigned int ubrr;

    private:
      float ubrrcalc(unsigned long clock, unsigned int prescaler, unsigned int baudRate) const;

    protected:
      void begin(unsigned int baudRate);
      void send(unsigned char data);
      void send(const char *data);
      unsigned char receive(void);
      void flush(void);
      bool isStarted();
      unsigned int getBaudRate() const;
      void setBaudRate(unsigned int baudRate);
      void disableReception();
      void enableReception();
      void disableTransmission();
      void enableTransmission();
    };
  }
}