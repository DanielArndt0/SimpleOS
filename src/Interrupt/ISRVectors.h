#pragma once
#include "System/Base.h"

#include "Interrupt/Watchdog/WatchdogTimer.h"
#include "Interrupt/Timer0/Timer0.h"
#include "Interrupt/Executors/Executors.h"

INT(WDT_vect)
{
  SimpleOS::Interrupt::WatchdogTimer::watchdogTicks.increment();
  if (SimpleOS::Interrupt::Executors::watchdogExecutor.isEnabled())
    SimpleOS::Interrupt::Executors::watchdogExecutor.execute();
}

INT(TIMER0_OVF_vect)
{
  SimpleOS::Interrupt::Timer0::timerTicks.increment();
  if (SimpleOS::Interrupt::Executors::timerExecutor.isEnabled())
    SimpleOS::Interrupt::Executors::timerExecutor.execute();
}
