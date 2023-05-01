#pragma once
#include "SimpleOS/Base.h"
#include "Communication/UART/UART.h"

namespace SimpleOS
{
  namespace Helpers
  {
    class MemoryHelper
    {
    public:
      static void printMemoryMap(SimpleOS::Data::UChar *array, SimpleOS::Data::UInt arraySize, SimpleOS::Com::UART &uart, SimpleOS::Data::UInt row, SimpleOS::Data::UInt base);
    };
  }
}