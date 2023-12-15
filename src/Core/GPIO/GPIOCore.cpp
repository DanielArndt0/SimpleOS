#include "GPIOCore.h"

void SimpleOS::Core::GPIOCore::port_selector(volatile unsigned char **reg, unsigned char pin, bool value)
{
  if (pin < 8)
    BIT_WRITE_REG(*reg[0], pin, value);
  else if (pin >= 8 && pin < 14)
    BIT_WRITE_REG(*reg[1], (pin - 8), value);
  else if (pin >= 14 && pin < 20)
    BIT_WRITE_REG(*reg[2], (pin - 14), value);
}

bool SimpleOS::Core::GPIOCore::port_selector(volatile unsigned char **reg, unsigned char pin)
{
  if (pin < 8)
    return BIT_CHECK(*reg[0], pin);
  else if (pin >= 8 && pin < 14)
    return BIT_CHECK(*reg[1], (pin - 8));
  else if (pin >= 14 && pin < 20)
    return BIT_CHECK(*reg[2], (pin - 14));
  return false;
}

unsigned int SimpleOS::Core::GPIOCore::analog_read(unsigned char pin)
{
  unsigned char low, high;
  BIT_WRITE_REG(ADCSRA, ADEN, true);
  BIT_WRITE_REG(ADCSRA, ADPS2, true);
  BIT_WRITE_REG(ADCSRA, ADPS1, false);
  BIT_WRITE_REG(ADCSRA, ADPS0, true);
  ADMUX = (aref << 6) | (pin & 0x07);
  BIT_WRITE_REG(DIDR0, pin, true);
  BIT_WRITE_REG(ADCSRA, ADSC, true);
  while (BIT_CHECK(ADCSRA, ADSC))
    ;
  low = ADCL;
  high = ADCH;
  BIT_WRITE_REG(DIDR0, pin, false);
  return SHIFT_LEFT(high, 0x08) | low;
}
