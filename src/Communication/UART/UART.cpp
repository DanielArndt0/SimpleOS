#include "Communication/UART/UART.h"

SimpleOS::Com::UART::UART(unsigned int baudRate) { begin(baudRate); }

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(char command)
{
  send(command);
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(const char *data)
{
  send(data);
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(const SimpleOS::Data::SimpleString &data)
{
  send(data.CStr());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(int data)
{
  send(SimpleOS::Data::Number<int>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(unsigned int data)
{
  send(SimpleOS::Data::Number<unsigned int>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(long data)
{
  send(SimpleOS::Data::Number<long>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(unsigned long data)
{
  send(SimpleOS::Data::Number<unsigned long>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(float data)
{
  send(SimpleOS::Data::Number<float>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(double data)
{
  send(SimpleOS::Data::Number<double>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(bool data)
{
  send(SimpleOS::Data::Number<bool>(data).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(void *ptr)
{
  if (ptr == nullptr || ptr == NULL )
    send("null");
  else
    send(SimpleOS::Data::Number<uintptr_t>(reinterpret_cast<uintptr_t>(ptr)).toString());
  return *this;
}

SimpleOS::Com::UART &SimpleOS::Com::UART::operator<<(SimpleOS::Concepts::Printable &printable)
{
  send(printable.print());
  return *this;
}
