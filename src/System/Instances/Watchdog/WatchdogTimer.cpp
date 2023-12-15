#include "WatchdogTimer.h"

SimpleOS::Time::Counter SimpleOS::Instance::WatchdogTimer::watchdogTicks;

SimpleOS::Instance::WatchdogTimer::WatchdogTimer(SimpleOS::Core::WDTPrescaler prescaler, SimpleOS::Core::WDTMode mode) { setup(prescaler, mode); }