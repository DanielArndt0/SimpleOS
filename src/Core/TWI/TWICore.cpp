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

void SimpleOS::Core::TWICore::write(char data)
{
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!BIT_CHECK(TWCR, TWINT))
    ;
}

char SimpleOS::Core::TWICore::read()
{
  char data = 0x00;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!BIT_CHECK(TWCR, TWINT))
    ;
  data = TWDR;
  return data;
}

void SimpleOS::Core::TWICore::stop() { TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); }

void SimpleOS::Core::TWICore::send(char data, unsigned char addr)
{
  start();
  write((addr & TWI_ADDR_MASK) | TWI_WRITE);
  write(data);
  stop();
}

char SimpleOS::Core::TWICore::receive(unsigned char addr)
{
  char data = 0x00;
  start();
  write((addr & TWI_ADDR_MASK) | TWI_READ);
  data = read();
  stop();
  return data;
}

void SimpleOS::Core::TWICore::disable() { TWCR = 0x00; }
