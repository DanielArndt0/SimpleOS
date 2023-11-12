#include "Hardware/Pin/Pin.h"

SimpleOS::Hardware::Pin::Pin(unsigned int pin) : pin(pin) { config(); }

unsigned int SimpleOS::Hardware::Pin::bits() { return !pin ? 0 : analog_read(pin); }

float SimpleOS::Hardware::Pin::volts() { return !pin ? 0 : SYS_ADC_VOLTAGE(analog_read(pin)); }

SimpleOS::Hardware::Pin &SimpleOS::Hardware::Pin::config(SimpleOS::Hardware::PinMode mode)
{
  if (!pin)
    return *this;
  volatile unsigned char *reg[3] = {&DDRD, &DDRB, &DDRC};
  port_selector(reg, pin, mode == PinMode::OUTPUT ? true : false);
  return *this;
}

SimpleOS::Hardware::Pin &SimpleOS::Hardware::Pin::write(bool value)
{
  if (!pin)
    return *this;
  volatile unsigned char *reg[3] = {&PORTD, &PORTB, &PORTC};
  port_selector(reg, pin, value);
  return *this;
}

bool SimpleOS::Hardware::Pin::read()
{
  if (!pin)
    return false;
  volatile unsigned char *reg[3] = {&PIND, &PINB, &PINC};
  return port_selector(reg, pin);
}
