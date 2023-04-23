#include "Communication/UART/UART.h"

bool SimpleOS::Com::UART::status;

SimpleOS::Com::UART *SimpleOS::Com::UART::send(SimpleOS::Data::UChar data)
{
  if (status == false)
    return this;
  while (!(SYSM_CHECK(UCSR0A, UDRE0)))
    ;
  UDR0 = data;
  while (!(SYSM_CHECK(UCSR0A, TXC0)))
    ;
  return this;
}

SimpleOS::Com::UART *SimpleOS::Com::UART::send(SimpleOS::Data::C_String data)
{
  if (data)
  {
    if (status == false)
      return this;
    for ( SimpleOS::Data::UInt i = 0x00; i < (SimpleOS::Data::UInt)strlen(data); i++)
      send(data[i]);
    return this;
  }
  return this;
}

void SimpleOS::Com::UART::begin(SimpleOS::Data::UInt baudRate)
{
  SimpleOS::Data::UInt ubrr = (SYSM_SYSTESYSM_CLOCK / 0x08 / baudRate) - 0x01;
  UBRR0H = (SimpleOS::Data::UChar)SYSM_HIGH(ubrr);
  UBRR0L = (SimpleOS::Data::UChar)ubrr;
  SYSM_WRITE_REG(UCSR0A, U2X0, SYSM_TRUE);
  SYSM_WRITE_REG(UCSR0B, RXEN0, SYSM_TRUE);
  SYSM_WRITE_REG(UCSR0B, TXEN0, SYSM_TRUE);
  SYSM_WRITE_REG(UCSR0B, UCSZ02, SYSM_FALSE);
  SYSM_WRITE_REG(UCSR0C, USBS0, SYSM_FALSE);
  SYSM_WRITE_REG(UCSR0B, RXCIE0, SYSM_TRUE);
  status = true;
}

void SimpleOS::Com::UART::flush(void)
{
  while (SYSM_CHECK(UCSR0A, RXC0))
    [[maybe_unused]]SimpleOS::Data::UChar f = UDR0;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Char command) { return *send(command); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::C_String data) { return *send(data); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(const SimpleOS::Data::String &data) { return *send(data.c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Int data) { return *send(SimpleOS::Data::String(data).c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::UInt data) { return *send(SimpleOS::Data::String(data).c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Long data) { return *send(SimpleOS::Data::String(data).c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::ULong data) { return *send(SimpleOS::Data::String(data).c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(float data) { return *send(SimpleOS::Data::String(data).c_str()); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(double data) { return *send(SimpleOS::Data::String(data).c_str()); }