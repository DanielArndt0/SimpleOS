#include "WatchdogTimer.h"

SimpleOS::Time::Ticks SimpleOS::Interrupt::WatchdogTimer::ticks;

SimpleOS::Interrupt::WatchdogTimer::WatchdogTimer(SimpleOS::Native::WDTPrescaler prescaler, SimpleOS::Native::WDTMode mode) { setup(prescaler, mode); }

INT(WDT_vect)
{
  SimpleOS::Interrupt::WatchdogTimer::ticks.increment();
}