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
  breakRowIf();
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

SimpleOS::Addons::LCD &SimpleOS::Addons::LCD::operator<<(void *data)
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
  setCursor(0, 0);
}

void SimpleOS::Addons::LCD::clear()
{
  sendCmd(0x00);
  sendCmd(0x01);
}

void SimpleOS::Addons::LCD::displayCtrlRefresh()
{
  sendCmd(0x00);
  SimpleOS::Hardware::Pin(D7).write(true);
  SimpleOS::Hardware::Pin(D6).write(displayOn);
  SimpleOS::Hardware::Pin(D5).write(cursorEn);
  SimpleOS::Hardware::Pin(D4).write(blinkEn);
  pulse();
}

void SimpleOS::Addons::LCD::on()
{
  displayOn = true;
  displayCtrlRefresh();
}

void SimpleOS::Addons::LCD::off()
{
  displayOn = false;
  displayCtrlRefresh();
}

void SimpleOS::Addons::LCD::blink(bool enable)
{
  blinkEn = enable;
  displayCtrlRefresh();
}

void SimpleOS::Addons::LCD::cursor(bool enable)
{
  cursorEn = enable;
  displayCtrlRefresh();
}

void SimpleOS::Addons::LCD::breakRowIf()
{
  if (columnOverflowPositive() && isInFirstRow())
  {
    currentColumn = 0;
    currentRow--;
    setCursor(currentColumn, currentRow);
  }
  else if (columnOverflowPositive() && isInSecondRow())
  {
    currentColumn = 0;
    currentRow++;
    setCursor(currentColumn, currentRow);
  }
  else if (columnOverflowNegative() && isInFirstRow())
  {
    currentColumn = 15;
    currentRow++;
    setCursor(currentColumn, currentRow); 
  }
  else if (columnOverflowNegative() && isInSecondRow())
  {
    currentColumn = 15;
    currentRow--;
    setCursor(currentColumn, currentRow); 
  }
  else
  {
    currentColumn++;
  }
}

bool SimpleOS::Addons::LCD::rowOverflowPositive() { return currentRow > 1; }

bool SimpleOS::Addons::LCD::columnOverflowPositive() { return currentColumn >= 15; }

bool SimpleOS::Addons::LCD::rowOverflowNegative() { return currentRow < 0; }

bool SimpleOS::Addons::LCD::columnOverflowNegative() { return currentColumn < 0; }

bool SimpleOS::Addons::LCD::isInFirstRow() { return currentRow <= 0; }

bool SimpleOS::Addons::LCD::isInSecondRow() { return currentRow >= 1; }

void SimpleOS::Addons::LCD::setCursor(unsigned char column, unsigned char row)
{
  currentColumn = column;
  currentRow = row;
  SimpleOS::Hardware::Pin(RS).write(false);
  SimpleOS::Hardware::Pin(D7).write(true);
  SimpleOS::Hardware::Pin(D6).write(currentRow);
  SimpleOS::Hardware::Pin(D5).write(BIT_CHECK(currentColumn, 5));
  SimpleOS::Hardware::Pin(D4).write(BIT_CHECK(currentColumn, 4));
  pulse();

  SimpleOS::Hardware::Pin(D7).write(BIT_CHECK(currentColumn, 3));
  SimpleOS::Hardware::Pin(D6).write(BIT_CHECK(currentColumn, 2));
  SimpleOS::Hardware::Pin(D5).write(BIT_CHECK(currentColumn, 1));
  SimpleOS::Hardware::Pin(D4).write(BIT_CHECK(currentColumn, 0));
  pulse();
}

SimpleOS::Data::Duet<unsigned char, unsigned char> SimpleOS::Addons::LCD::getCurrentCursorPosition() { return Data::Duet<unsigned char, unsigned char>(currentColumn, currentRow); }

void SimpleOS::Addons::LCD::begin()
{
  currentColumn = 0;
  currentRow = 0;
  SimpleOS::Hardware::Pin(RS).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(EN).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D4).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D5).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D6).config(SimpleOS::Hardware::PinMode::OUTPUT);
  SimpleOS::Hardware::Pin(D7).config(SimpleOS::Hardware::PinMode::OUTPUT);

  tmr.delay(40);
  sendCmd(0x02); // 16x2

  tmr.delay(2);
  sendCmd(0x02);
  sendCmd(0x08); // 5x8 dots

  tmr.delay(2);
  on();
  blink(true);
  cursor(true);
  clear();

  tmr.delay(2);
  sendCmd(0x00);
  sendCmd(0x06);
}
