#include "Core/UART/UARTCore.h"

void SimpleOS::Core::UARTCore::begin(unsigned int baudRate)
{
  this->baudRate = baudRate;
  status = true;
  setBaudRate(baudRate);
  BIT_WRITE_REG(UCSR0A, U2X0, true);
  BIT_WRITE_REG(UCSR0B, UCSZ02, false);
  BIT_WRITE_REG(UCSR0C, USBS0, false);
  enableTransmission();
  enableReception();
}

void SimpleOS::Core::UARTCore::send(unsigned char data)
{
  if (status == false)
    return;
  while (!(BIT_CHECK(UCSR0A, UDRE0)))
    ;
  UDR0 = data;
  while (!(BIT_CHECK(UCSR0A, TXC0)))
    ;
}

void SimpleOS::Core::UARTCore::send(const char *data)
{
  if (data || status == false)
    for (unsigned int i = 0x00; i < (unsigned int)strlen(data); i++)
      send(data[i]);
}

char SimpleOS::Core::UARTCore::receive()
{
  if (status == false)
    return false;
  while (!(BIT_CHECK(UCSR0A, RXC0)))
    if (BIT_CHECK(UCSR0A, DOR0) || BIT_CHECK(UCSR0A, FE0))
    {
      UDR0;
      BIT_WRITE_REG(UCSR0B, RXEN0, false);
      BIT_WRITE_REG(UCSR0B, RXEN0, true);
      return false;
    }
  return UDR0;
}

void SimpleOS::Core::UARTCore::flush(void)
{
  while (BIT_CHECK(UCSR0A, RXC0))
      [[maybe_unused]]
    unsigned char f = UDR0;
}

bool SimpleOS::Core::UARTCore::isStarted() const { return status; }

unsigned int SimpleOS::Core::UARTCore::getBaudRate() const { return baudRate; }

void SimpleOS::Core::UARTCore::setBaudRate(unsigned int baudRate)
{
  this->baudRate = baudRate;
  ubrr = ubrrcalc(HW_CLOCK, prescaler, this->baudRate);
  UBRR0H = (unsigned char)SHIFT_BYTE(ubrr);
  UBRR0L = (unsigned char)ubrr;
}

void SimpleOS::Core::UARTCore::disableReception()
{
  BIT_WRITE_REG(UCSR0B, RXEN0, false);
  BIT_WRITE_REG(UCSR0B, RXCIE0, false);
}

void SimpleOS::Core::UARTCore::enableReception()
{
  BIT_WRITE_REG(UCSR0B, RXEN0, true);
  BIT_WRITE_REG(UCSR0B, RXCIE0, true);
}

void SimpleOS::Core::UARTCore::disableTransmission() { BIT_WRITE_REG(UCSR0B, TXEN0, false); }

void SimpleOS::Core::UARTCore::enableTransmission() { BIT_WRITE_REG(UCSR0B, TXEN0, true); }

float SimpleOS::Core::UARTCore::ubrrcalc(unsigned long clock, unsigned int prescaler, unsigned int baudRate) const { return (clock / prescaler / baudRate) - 1; }