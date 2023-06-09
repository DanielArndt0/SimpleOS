#include "Communication/UART/UART.h"

SimpleOS::Com::UART::UART(SimpleOS::Data::UInt baudRate) { begin(baudRate); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Char command)
{
  send(command);
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::C_String data)
{
  send(data);
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(const SimpleOS::Data::String &data)
{
  send(data.c_str());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Int data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::Int>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::UInt data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::UInt>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Long data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::Long>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::ULong data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::ULong>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Float data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::Float>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Data::Double data)
{
  send(SimpleOS::Data::Number<SimpleOS::Data::Double>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(void *ptr)
{
  send(SimpleOS::Data::Number<uintptr_t>(reinterpret_cast<uintptr_t>(ptr)).toString());
  return *this;
}