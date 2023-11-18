#pragma once
#include "System/Base.h"

#include "Communication/UART/UART.h" // DONE
#include "Hardware/Pin/Pin.h"        // DONE
#include "Memory/EEPROM/EEPROM.h"    // DONE

namespace SimpleOS
{
  namespace Instance
  {
    class Drivers
    {
    public:
      static Com::UART serial;
      static Memory::EEPROM eeprom;
    };
    Com::UART Drivers::serial;
    Memory::EEPROM Drivers::eeprom;
  } // namespace Instance
} // namespace SimpleOS
