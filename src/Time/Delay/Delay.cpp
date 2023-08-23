#include "Delay.h"

SimpleOS::Time::Delay::Delay(unsigned long ms) { wait(ms); }

void SimpleOS::Time::Delay::wait(unsigned long ms)
{
  if (ms < 1)
    return;
  unsigned long __delay_ms__ = Interrupt::Timer0::timerTicks;
  while (Interrupt::Timer0::timerTicks - __delay_ms__ <= ms);
}