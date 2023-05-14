#include "Native/UART/UARTCore.h"

void SimpleOS::Native::UARTCore::begin(SimpleOS::Data::UInt baudRate)
{
  this->baudRate = baudRate;
  status = true;
  setBaudRate(baudRate);
  SYSM_WRITE_REG(UCSR0A, U2X0, true);
  SYSM_WRITE_REG(UCSR0B, UCSZ02, false);
  SYSM_WRITE_REG(UCSR0C, USBS0, false);
  enableTransmission();
  enableReception();
}

void SimpleOS::Native::UARTCore::send(SimpleOS::Data::UChar data)
{
  if (status == false)
    return;
  while (!(SYSM_CHECK(UCSR0A, UDRE0)))
    ;
  UDR0 = data;
  while (!(SYSM_CHECK(UCSR0A, TXC0)))
    ;
}

void SimpleOS::Native::UARTCore::send(SimpleOS::Data::C_String data)
{
  if (data || status == false)
    for (SimpleOS::Data::UInt i = 0x00; i < (SimpleOS::Data::UInt)strlen(data); i++)
      send(data[i]);
}

SimpleOS::Data::UChar SimpleOS::Native::UARTCore::receive()
{
  if (status == false)
    return false;
  while (!(SYSM_CHECK(UCSR0A, RXC0)))
    if (SYSM_CHECK(UCSR0A, DOR0) || SYSM_CHECK(UCSR0A, FE0))
    {
      UDR0;
      SYSM_WRITE_REG(UCSR0B, RXEN0, false);
      SYSM_WRITE_REG(UCSR0B, RXEN0, true);
      return false;
    }
  return UDR0;
}

void SimpleOS::Native::UARTCore::flush(void)
{
  while (SYSM_CHECK(UCSR0A, RXC0))
      [[maybe_unused]]
    SimpleOS::Data::UChar f = UDR0;
}

bool SimpleOS::Native::UARTCore::isStarted() { return status; }

SimpleOS::Data::UInt SimpleOS::Native::UARTCore::getBaudRate() const { return baudRate; }

void SimpleOS::Native::UARTCore::setBaudRate(SimpleOS::Data::UInt baudRate)
{
  this->baudRate = baudRate;
  ubrr = ubrrcalc(SYSM_SYSTEM_CLOCK, prescaler, this->baudRate);
  UBRR0H = (SimpleOS::Data::UChar)SYSM_HIGH(ubrr);
  UBRR0L = (SimpleOS::Data::UChar)ubrr;
}

void SimpleOS::Native::UARTCore::disableReception()
{
  SYSM_WRITE_REG(UCSR0B, RXEN0, false);
  SYSM_WRITE_REG(UCSR0B, RXCIE0, false);
}

void SimpleOS::Native::UARTCore::enableReception()
{
  SYSM_WRITE_REG(UCSR0B, RXEN0, true);
  SYSM_WRITE_REG(UCSR0B, RXCIE0, true);
}

void SimpleOS::Native::UARTCore::disableTransmission() { SYSM_WRITE_REG(UCSR0B, TXEN0, false); }

void SimpleOS::Native::UARTCore::enableTransmission() { SYSM_WRITE_REG(UCSR0B, TXEN0, true); }

SimpleOS::Data::Float SimpleOS::Native::UARTCore::ubrrcalc(SimpleOS::Data::ULong clock, SimpleOS::Data::UInt prescaler, SimpleOS::Data::UInt baudRate) const
{
  return (clock / prescaler / baudRate) - 1;
}