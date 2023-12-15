#pragma once
#include <stdlib.h>
#include "System/Base.h"

extern uint8_t __heap_start;
extern uint8_t __heap_end;
extern uint8_t *__brkval;

namespace SimpleOS
{
  namespace Memory
  {
    class HeapSection
    {
    public:
      uint16_t start() { return reinterpret_cast<uint16_t>(__malloc_heap_start) - RAMSTART; }

      uint16_t end()
      {
        uint8_t sp;
        return reinterpret_cast<uint16_t>(&sp) - RAMSTART - __malloc_margin;
      }

      Data::Size usage() { return reinterpret_cast<uint16_t>(__brkval) - reinterpret_cast<uint16_t>(__malloc_heap_start); }

      Data::Size available()
      {
        uint8_t sp;
        return (reinterpret_cast<uint16_t>(__brkval)
                    ? reinterpret_cast<uint16_t>(&sp) - reinterpret_cast<uint16_t>(__brkval)
                    : reinterpret_cast<uint16_t>(&sp) - reinterpret_cast<uint16_t>(__malloc_heap_start)) -
               __malloc_margin;
      }

      Data::Size total()
      {
        uint8_t sp;
        return reinterpret_cast<uint16_t>(&sp) - reinterpret_cast<uint16_t>(__malloc_heap_start) - __malloc_margin;
      }

      Data::Size stackMargin() { return __malloc_margin; }
    };
  } // namespace Memory
} // namespace SimpleOS
