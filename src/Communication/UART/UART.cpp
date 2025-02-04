#include "Communication/UART/UART.h"
#include "UART.h"

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
  if (ptr == nullptr || ptr == NULL)
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

char SimpleOS::Com::UART::operator>>(char &data)
{
  if (available())
    return (data = v_buffer.remove(0));
  return 0x00;
}

void SimpleOS::Com::UART::echo()
{
  char c;
  *this << (*this >> c);
}

bool SimpleOS::Com::UART::available() { return !v_buffer.isEmpty(); }

unsigned int SimpleOS::Com::UART::size() { return v_buffer.getSize(); }

char SimpleOS::Com::UART::read()
{
  if (available())
    return v_buffer.remove(0);
  return 0x00;
}

const char *SimpleOS::Com::UART::readString() 
{
  if (available())
  {
    const char *buff = v_buffer.toString();
    for (size_t i = 0; i < v_buffer.getSize(); i++)
      read();
    return buff;
  }

  return 0x00;
}

void SimpleOS::Com::UART::virtualReceiverBufferTask()
{
  if (v_buffer.getSize() < 64)
    v_buffer.add(receive());
}
