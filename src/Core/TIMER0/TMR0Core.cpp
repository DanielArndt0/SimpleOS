#include "TMR0Core.h"

void SimpleOS::Core::TMR0Core::enable()
{

  BIT_WRITE_REG(TIMSK0, TOIE0, true);
  TCCR0B = 0x03;
  TCNT0 = 0x06;
  sei();
}

void SimpleOS::Core::TMR0Core::disable()
{
  cli();
  BIT_WRITE_REG(TIMSK0, TOIE0, false);
  sei();
}

bool SimpleOS::Core::TMR0Core::status() { return BIT_CHECK(TIMSK0, TOIE0); }

void SimpleOS::Core::TMR0Core::reset() { TCNT0 = 0x06; }
