#include "Hardware/Pin/Pin.h"

SimpleOS::Hardware::Pin::Pin(SimpleOS::Data::UInt pin) : pin(pin) {}

SimpleOS::Data::UInt SimpleOS::Hardware::Pin::bits() { return !pin ? 0 : analog_read(pin); }

SimpleOS::Data::Float SimpleOS::Hardware::Pin::volts() { return !pin ? 0 : SYSM_ADC_VOLTAGE(analog_read(pin)); }

SimpleOS::Hardware::Pin &SimpleOS::Hardware::Pin::config(SimpleOS::Data::UChar mode)
{
  if (!pin)
    return *this;
  volatile SimpleOS::Data::UChar *reg[3] = {&DDRD, &DDRB, &DDRC};
  port_selector(reg, pin, mode);
  return *this;
}

void SimpleOS::Hardware::Pin::write(bool value)
{
  if (!pin)
    return;
  volatile SimpleOS::Data::UChar *reg[3] = {&PORTD, &PORTB, &PORTC};
  port_selector(reg, pin, value);
}

bool SimpleOS::Hardware::Pin::read()
{
  if (!pin)
    return false;
  volatile SimpleOS::Data::UChar *reg[3] = {&PIND, &PINB, &PINC};
  return port_selector(reg, pin);
}
