#pragma once
#include <avr/io.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/Object/Object.h"
#include "DataTypes/Typedefs.h"

// TODO Adicionar modo INPUT_PULLUP
#define OUTPUT 0x01
#define INPUT 0x00

namespace SimpleOS
{
  namespace Hardware
  {
    class GPIO implements Root::Object
    {
    protected:
      static Data::UChar aref;

    protected:
      static Data::UChar port_selector(volatile Data::UChar **reg, Data::UChar pin, bool value);
      static Data::UChar port_selector(volatile Data::UChar **reg, Data::UChar pin);
      static Data::UInt analog_read(Data::UChar pin);

    public:
      static Data::UInt analogReadBits(Data::UChar pin);
      static float readVolts(Data::UChar pin);
      static void pinConfig(Data::UChar pin, Data::UChar mode);
      static void pinWrite(Data::UChar pin, bool value);
      static Data::UChar pinRead(Data::UChar pin);
    };
  }
}