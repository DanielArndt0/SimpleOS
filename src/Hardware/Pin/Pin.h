#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "Core/GPIO/GPIOCore.h"
#include "Hardware/PinMode.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class Pin : extends Core::GPIOCore
    {
    private:
      const unsigned int pin;

    public:
      Pin(unsigned int pin);
      ~Pin() = default;

    public:
      Pin &config(PinMode mode = PinMode::INPUT);
      unsigned int bits();
      float volts();
      void write(bool value = false);
      bool read();
    };
  }
}