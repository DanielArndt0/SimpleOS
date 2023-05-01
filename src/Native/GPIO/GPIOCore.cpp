#include "GPIOCore.h"

void SimpleOS::Native::GPIOCore::port_selector(volatile SimpleOS::Data::UChar **reg, SimpleOS::Data::UChar pin, bool value)
{
  if (pin < 8)
    SYSM_WRITE_REG(*reg[0], pin, value);
  else if (pin >= 8 && pin < 14)
    SYSM_WRITE_REG(*reg[1], (pin - 8), value);
  else if (pin >= 14 && pin < 20)
    SYSM_WRITE_REG(*reg[2], (pin - 14), value);
}

bool SimpleOS::Native::GPIOCore::port_selector(volatile SimpleOS::Data::UChar **reg, SimpleOS::Data::UChar pin)
{
  if (pin < 8)
    return SYSM_CHECK(*reg[0], pin);
  else if (pin >= 8 && pin < 14)
    return SYSM_CHECK(*reg[1], (pin - 8));
  else if (pin >= 14 && pin < 20)
    return SYSM_CHECK(*reg[2], (pin - 14));
  return false;
}

SimpleOS::Data::UInt SimpleOS::Native::GPIOCore::analog_read(SimpleOS::Data::UChar pin)
{
  SimpleOS::Data::UChar low, high;
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

// SimpleOS::Data::UInt SimpleOS::Hardware::GPIO::analogReadBits(SimpleOS::Data::UChar pin) { return analog_read(pin); }

// float SimpleOS::Hardware::GPIO::readVolts(SimpleOS::Data::UChar pin) { return SYSM_ADC_VOLTAGE(analog_read(pin)); }

// void SimpleOS::Hardware::GPIO::pinConfig(SimpleOS::Data::UChar pin, SimpleOS::Data::UChar mode)
// {
//   volatile SimpleOS::Data::UChar *reg[3] = {&DDRD, &DDRB, &DDRC};
//   port_selector(reg, pin, mode);
// }

// void SimpleOS::Hardware::GPIO::pinWrite(SimpleOS::Data::UChar pin, bool value)
// {
//   volatile SimpleOS::Data::UChar *reg[3] = {&PORTD, &PORTB, &PORTC};
//   port_selector(reg, pin, value);
// }

// SimpleOS::Data::UChar SimpleOS::Hardware::GPIO::pinRead(SimpleOS::Data::UChar pin)
// {
//   volatile SimpleOS::Data::UChar *reg[3] = {&PIND, &PINB, &PINC};
//   return port_selector(reg, pin);
// }
