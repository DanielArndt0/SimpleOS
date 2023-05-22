#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "Native/GPIO/GPIOCore.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class Pin : extends Native::GPIOCore
    {
    private:
      const unsigned int pin;

    public:
      Pin() = default;
      Pin(unsigned int pin);
      ~Pin() = default;
      

    public:
      Pin &config(unsigned char mode);
      unsigned int bits();
      float volts();
      void write(bool value);
      bool read();
    };
  }
}