#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

// TODO Adicionar modo INPUT_PULLUP
#define OUTPUT 0x01
#define INPUT 0x00

namespace SimpleOS
{
  namespace Native
  {
    class GPIOCore
    {
    protected:
      Data::UChar aref = 0x01;

    protected:
      void port_selector(volatile Data::UChar **reg, Data::UChar pin, bool value);
      bool port_selector(volatile Data::UChar **reg, Data::UChar pin);
      Data::UInt analog_read(Data::UChar pin);
    };
  }
}