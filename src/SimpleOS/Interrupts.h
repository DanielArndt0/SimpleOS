#pragma once
#include <avr/io.h>
#include "Root/Ticks.h"


INT(WDT_vect)
{
  SimpleOS::Interrupt::Ticks::incrementWdtTicks();
}
