#include "Timer0.h"

SimpleOS::Time::Counter SimpleOS::Interrupt::Timer0::timerTicks;

SimpleOS::Interrupt::Timer0::Timer0() { this->enable(); }