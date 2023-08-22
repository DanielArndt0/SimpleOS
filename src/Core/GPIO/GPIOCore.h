#pragma once
#include <avr/io.h>
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Core
  {
    class GPIOCore
    {
    protected:
      unsigned char aref = 0x01;

    protected:
      void port_selector(volatile unsigned char **reg, unsigned char pin, bool value);
      bool port_selector(volatile unsigned char **reg, unsigned char pin);
      unsigned int analog_read(unsigned char pin);
    };
  }
}