#pragma once
#include <stdlib.h>
#include "System/Base.h"

extern uint8_t __bss_start;
extern uint8_t __bss_end;

namespace SimpleOS
{
  namespace Memory
  {
    class BssSection
    {
    public:
      Data::Size usage() { return reinterpret_cast<uint16_t>(&__bss_end) - reinterpret_cast<uint16_t>(&__bss_start); }
      uint16_t start() { return reinterpret_cast<uint16_t>(&__bss_start) - RAMSTART; }
      uint16_t end() { return reinterpret_cast<uint16_t>(&__bss_end) - RAMSTART; }
      Data::Size available() { return total() - usage(); }
      Data::Size total() { return usage(); }
    };
  } // namespace Memory
} // namespace SimpleOS
