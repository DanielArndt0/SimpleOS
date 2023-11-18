#pragma once
#include "System/Base.h"
#include "Core/WDT/WDTCore.h"
#include "Time/Counter/Counter.h"

namespace SimpleOS
{
  namespace Instance
  {
    class WatchdogTimer : extends Core::WDTCore
    {
    public:
      static Time::Counter watchdogTicks;

    public:
      WatchdogTimer(Core::WDTPrescaler prescaler = Core::WDTPrescaler::C2048, Core::WDTMode mode = Core::WDTMode::Interrupt);
    };
  } // namespace Instance
} // namespace SimpleOS
