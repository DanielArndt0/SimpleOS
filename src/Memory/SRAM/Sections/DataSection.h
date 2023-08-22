#pragma once
#include <stdlib.h>
#include "System/Base.h"

extern uint8_t __data_start;
extern uint8_t __data_end;

namespace SimpleOS
{
  namespace Memory
  {
    class DataSection
    {
    public:
      Data::Size usage() { return reinterpret_cast<uint16_t>(&__data_end) - reinterpret_cast<uint16_t>(&__data_start); }
      uint16_t start() { return reinterpret_cast<uint16_t>(&__data_start) - RAMSTART; }
      uint16_t end() { return reinterpret_cast<uint16_t>(&__data_end) - RAMSTART; }
      Data::Size available() { return total() - usage(); }
      Data::Size total() { return usage(); }
    };
  } // namespace Memory
} // namespace SimpleOS
