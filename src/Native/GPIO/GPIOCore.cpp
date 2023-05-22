#include "GPIOCore.h"

void SimpleOS::Native::GPIOCore::port_selector(volatile unsigned char **reg, unsigned char pin, bool value)
{
  if (pin < 8)
    SYSM_WRITE_REG(*reg[0], pin, value);
  else if (pin >= 8 && pin < 14)
    SYSM_WRITE_REG(*reg[1], (pin - 8), value);
  else if (pin >= 14 && pin < 20)
    SYSM_WRITE_REG(*reg[2], (pin - 14), value);
}

bool SimpleOS::Native::GPIOCore::port_selector(volatile unsigned char **reg, unsigned char pin)
{
  if (pin < 8)
    return SYSM_CHECK(*reg[0], pin);
  else if (pin >= 8 && pin < 14)
    return SYSM_CHECK(*reg[1], (pin - 8));
  else if (pin >= 14 && pin < 20)
    return SYSM_CHECK(*reg[2], (pin - 14));
  return false;
}

unsigned int SimpleOS::Native::GPIOCore::analog_read(unsigned char pin)
{
  unsigned char low, high;
  SYSM_WRITE_REG(ADCSRA, ADEN, true);
  SYSM_WRITE_REG(ADCSRA, ADPS2, true);
  SYSM_WRITE_REG(ADCSRA, ADPS1, false);
  SYSM_WRITE_REG(ADCSRA, ADPS0, true);
  ADMUX = (aref << 6) | (pin & 0x07);
  SYSM_WRITE_REG(DIDR0, pin, true);
  SYSM_WRITE_REG(ADCSRA, ADSC, true);
  while (SYSM_CHECK(ADCSRA, ADSC))
    ;
  low = ADCL;
  high = ADCH;
  SYSM_WRITE_REG(DIDR0, pin, false);
  return SYSM_SHIFTL(high, 0x08) | low;
}
