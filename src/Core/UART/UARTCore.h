#pragma once
#include <avr/io.h>
#include <string.h>
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Core
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
      char receive(void);
      void flush(void);
      bool isStarted() const;
      unsigned int getBaudRate() const;
      void setBaudRate(unsigned int baudRate);
      void disableReception();
      void enableReception();
      void disableTransmission();
      void enableTransmission();
    };
  }
}