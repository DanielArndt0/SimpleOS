#include "LCD.h"

void SimpleOS::Addons::LCD::sendCmd(unsigned char hexCmd)
{
  SimpleOS::Hardware::Pin(RS).write(false);
  SimpleOS::Hardware::Pin(D4).write(BIT_CHECK(hexCmd, 0));
  SimpleOS::Hardware::Pin(D5).write(BIT_CHECK(hexCmd, 1));
  SimpleOS::Hardware::Pin(D6).write(BIT_CHECK(hexCmd, 2));
  SimpleOS::Hardware::Pin(D7).write(BIT_CHECK(hexCmd, 3));
  pulse();
}

void SimpleOS::Addons::LCD::pulse()
{
  SimpleOS::Hardware::Pin(EN).write(false);
  SimpleOS::Hardware::Pin(EN).write(true);
  SimpleOS::Hardware::Pin(EN).write(false);
}

void SimpleOS::Addons::LCD::wChar(char data)
{
  SimpleOS::Hardware::Pin(RS).write(true);
  SimpleOS::Hardware::Pin(D4).write(BIT_CHECK(data, 4));
  SimpleOS::Hardware::Pin(D5).write(BIT_CHECK(data, 5));
  SimpleOS::Hardware::Pin(D6).write(BIT_CHECK(data, 6));
  SimpleOS::Hardware::Pin(D7).write(BIT_CHECK(data, 7));
  pulse();
  SimpleOS::Hardware::Pin(D4).write(BIT_CHECK(data, 0));
  SimpleOS::Hardware::Pin(D5).write(BIT_CHECK(data, 1));
  SimpleOS::Hardware::Pin(D6).write(BIT_CHECK(data, 2));
  SimpleOS::Hardware::Pin(D7).write(BIT_CHECK(data, 3));
  pulse();
}

void SimpleOS::Addons::LCD::wString(const char *str)
{
  for (size_t i = 0; i < strlen(str); i++)
    wChar(str[i]);
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(char data)
{
  wChar(data);
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(unsigned char data)
{
  wChar(data);
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(int data)
{
  wString(SimpleOS::Data::Number<int>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(unsigned int data)
{
  wString(SimpleOS::Data::Number<unsigned int>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(long data)
{
  wString(SimpleOS::Data::Number<long>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(unsigned long data)
{
  wString(SimpleOS::Data::Number<unsigned long>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(float data)
{
  wString(SimpleOS::Data::Number<float>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(double data)
{
  wString(SimpleOS::Data::Number<double>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(bool data)
{
  wString(SimpleOS::Data::Number<bool>(data).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(void* data)
{
  if (data == nullptr || data == NULL)
    wString("null");
  else
    wString(SimpleOS::Data::Number<uintptr_t>(reinterpret_cast<uintptr_t>(data)).toString());
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(const char *str)
{
  wString(str);
  return *this;
}

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(const SimpleOS::Data::SimpleString &data)
{
  wString(data.CStr());
  return *this;
}

template <class T>
SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(const SimpleOS::Data::Number<T> &data)
{
  wString(data.toString());
  return *this;
}

SimpleOS::Addons::LCD::LCD(unsigned char RS, unsigned char EN, unsigned char D4, unsigned char D5, unsigned char D6, unsigned char D7)
    : RS(RS), EN(EN), D4(D4), D5(D5), D6(D6), D7(D7)
{
}

void SimpleOS::Addons::LCD::home()
{
  sendCmd(0x00);
  sendCmd(0x02);
}

void SimpleOS::Addons::LCD::clear()
{
  sendCmd(0x00);
  sendCmd(0x01);
}

void SimpleOS::Addons::LCD::displayOn()
{
  sendCmd(0x00);
  sendCmd(0x0F);
}

void SimpleOS::Addons::LCD::displayOff()
{
  sendCmd(0x00);
  sendCmd(0x0B);
}

void SimpleOS::Addons::LCD::begin()
{
  SimpleOS::Hardware::Pin(RS).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(EN).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D4).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D5).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D6).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D7).config(SimpleOS::Hardware::PinMode::OUTPUT);

  tmr.delay(2);
  sendCmd(0x02);

  tmr.delay(2);
  sendCmd(0x02);
  sendCmd(0x08);

  tmr.delay(2);
  sendCmd(0x00);
  sendCmd(0x0E);

  tmr.delay(2);
  sendCmd(0x00);
  sendCmd(0x06);
}
