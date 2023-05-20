#pragma once
#include <avr/io.h>
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"
#include "Hardware/Pin/Pin.h"

namespace SimpleOS
{
  namespace Hardware
  {
    class GPIO
    {
    public:
      Pin getPin(Data::UInt pin) const;
    };
  }
}