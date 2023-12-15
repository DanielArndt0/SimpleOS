#pragma once
#include <stdlib.h>
#include "System/Base.h"

namespace SimpleOS
{
  namespace Memory
  {
    class StackSection
    {
    public:
      Data::Size usage() { return end() - start(); }
      uint16_t start()
      {
        uint8_t sp;
        return reinterpret_cast<uint16_t>(&sp) - RAMSTART;
      }
      uint16_t end() { return RAMEND - RAMSTART; }
      Data::Size available() { return total() - usage(); }
      Data::Size total() { return usage(); }
    };
  } // namespace Memory
} // namespace SimpleOS
