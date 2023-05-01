#pragma once
#include <avr/io.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/Typedefs.h"
#include "Hardware/Pin/Pin.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class GPIO
    {
    public:
      Pin pin(Data::UInt pin) const { return Pin(pin); }
    };
  }
}