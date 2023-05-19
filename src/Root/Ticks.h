#pragma once
#include "SimpleOS/Base.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class Ticks
    {
    protected:
      static Data::ULong wdtTicks;

    public:
      static Data::ULong getWdtTicks() { return wdtTicks; }
      static void incrementWdtTicks() { wdtTicks += 1; }
      static void resetWdtTicks() { wdtTicks = 0; }
    };
    SimpleOS::Data::ULong SimpleOS::Interrupt::Ticks::wdtTicks = 0;
  } // namespace Time
} // namespace SimpleOS
