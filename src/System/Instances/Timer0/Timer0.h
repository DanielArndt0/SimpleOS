#pragma once
#include "System/Base.h"
#include "Core/TIMER0/TMR0Core.h"
#include "Time/Counter/Counter.h"

namespace SimpleOS
{
  namespace Instance
  {
    class Timer0 : extends Core::TMR0Core
    {
    public:
      static Time::Counter timerTicks;

    public:
      Timer0() = default;
    };
  } // namespace Instance
} // namespace SimpleOS
