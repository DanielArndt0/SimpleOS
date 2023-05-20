#pragma once
#include "System/Base.h"
#include "Native/WDT/WDTCore.h"
#include "Time/Ticks/Ticks.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class WatchdogTimer : extends Native::WDTCore
    {
    public:
      static Time::Ticks watchdogTicks;

    public:
      WatchdogTimer(Native::WDTPrescaler prescaler = Native::WDTPrescaler::C2048, Native::WDTMode mode = Native::WDTMode::Interrupt);
    };
  } // namespace Interrupt
} // namespace SimpleOS
