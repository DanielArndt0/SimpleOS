#include "WatchdogTimer.h"

SimpleOS::Time::Counter SimpleOS::Interrupt::WatchdogTimer::watchdogTicks;

SimpleOS::Interrupt::WatchdogTimer::WatchdogTimer(SimpleOS::Core::WDTPrescaler prescaler, SimpleOS::Core::WDTMode mode) { setup(prescaler, mode); }