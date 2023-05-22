#include "Hardware/Pin/Pin.h"

SimpleOS::Hardware::Pin::Pin(unsigned int pin) : pin(pin) {}

unsigned int SimpleOS::Hardware::Pin::bits() { return !pin ? 0 : analog_read(pin); }

float SimpleOS::Hardware::Pin::volts() { return !pin ? 0 : SYSM_ADC_VOLTAGE(analog_read(pin)); }

SimpleOS::Hardware::Pin &SimpleOS::Hardware::Pin::config(unsigned char mode)
{
  if (!pin)
    return *this;
  volatile unsigned char *reg[3] = {&DDRD, &DDRB, &DDRC};
  port_selector(reg, pin, mode);
  return *this;
}

void SimpleOS::Hardware::Pin::write(bool value)
{
  if (!pin)
    return;
  volatile unsigned char *reg[3] = {&PORTD, &PORTB, &PORTC};
  port_selector(reg, pin, value);
}

bool SimpleOS::Hardware::Pin::read()
{
  if (!pin)
    return false;
  volatile unsigned char *reg[3] = {&PIND, &PINB, &PINC};
  return port_selector(reg, pin);
}
