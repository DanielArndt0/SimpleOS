#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"
#include "Native/GPIO/GPIOCore.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class Pin : extends Native::GPIOCore
    {
    private:
      const Data::UInt pin;

    public:
      Pin() : pin(0) {}
      Pin(Data::UInt pin) : pin(pin) {}

    public:
      Pin &config(Data::UChar mode);
      Data::UInt bits();
      Data::Float volts();
      void write(bool value);
      bool read();
    };
  }
}