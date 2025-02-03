#include "Delay.h"

void SimpleOS::Time::Delay::delay(unsigned long ms)
{
  if (ms < 1)
    return;
  unsigned long __delay_ms__ = Instance::Timer0::timerTicks;
  while (Instance::Timer0::timerTicks - __delay_ms__ <= ms)
  {
    com << Instance::Timer0::timerTicks - __delay_ms__ << endl;
  }
}