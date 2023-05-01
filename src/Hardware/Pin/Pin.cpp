#include "Hardware/Pin/Pin.h"

SimpleOS::Data::UInt SimpleOS::Hardware::Pin::getBits() { return analog_read(pin); }

SimpleOS::Data::Float SimpleOS::Hardware::Pin::getVolts() { return SYSM_ADC_VOLTAGE(analog_read(pin)); }

SimpleOS::Hardware::Pin &SimpleOS::Hardware::Pin::config(SimpleOS::Data::UChar mode)
{
  volatile SimpleOS::Data::UChar *reg[3] = {&DDRD, &DDRB, &DDRC};
  port_selector(reg, pin, mode);
  return *this;
}

void SimpleOS::Hardware::Pin::write(bool value)
{
  volatile SimpleOS::Data::UChar *reg[3] = {&PORTD, &PORTB, &PORTC};
  port_selector(reg, pin, value);
}

bool SimpleOS::Hardware::Pin::read()
{
  volatile SimpleOS::Data::UChar *reg[3] = {&PIND, &PINB, &PINC};
  return port_selector(reg, pin);
}
