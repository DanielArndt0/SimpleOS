#include "TWICore.h"

void SimpleOS::Core::TWICore::begin(unsigned long frequency)
{
  TWSR = 0x00;
  TWBR = ((HW_CLOCK / frequency) - 16) / 2;
  TWCR = (1 << TWEN);
}

void SimpleOS::Core::TWICore::start()
{
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while (!BIT_CHECK(TWCR, TWINT))
    ;
}

void SimpleOS::Core::TWICore::restart() { start(); }

void SimpleOS::Core::TWICore::write(unsigned char byte)
{
  TWDR = byte;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!BIT_CHECK(TWCR, TWINT))
    ;
}

unsigned char SimpleOS::Core::TWICore::read()
{
  unsigned char data = 0x00;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!BIT_CHECK(TWCR, TWINT))
    ;
  data = TWDR;
  return data;
}

void SimpleOS::Core::TWICore::stop() { TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); }

void SimpleOS::Core::TWICore::disable() { TWCR = 0x00; }
