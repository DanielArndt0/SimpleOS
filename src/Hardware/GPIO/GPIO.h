#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "Hardware/Pin/Pin.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class GPIO
    {
    public:
      Pin getPin(unsigned int pin) const;
    };
  }
}