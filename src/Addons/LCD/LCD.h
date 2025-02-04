#pragma once
#include "Time/Delay/Delay.h"
#include "Hardware/Pin/Pin.h"
#include "Hardware/PinMode.h"
#include "DataTypes/Number.h"
#include "DataTypes/String/SimpleString/SimpleString.h"
#include "DataTypes/Duet.h"

namespace SimpleOS
{
  namespace Addons
  {
    class LCD
    {
    private:
      SimpleOS::Time::Delay tmr;
      unsigned char RS;
      unsigned char EN;
      unsigned char D4;
      unsigned char D5;
      unsigned char D6;
      unsigned char D7;
      unsigned char currentRow;
      unsigned char currentColumn;
      bool displayOn;
      bool blinkEn;
      bool cursorEn;

    private:
      void sendCmd(unsigned char hexCmd);
      void pulse();
      void wChar(char data);
      void wString(const char *str);
      void breakRowIf();
      bool rowOverflowPositive();
      bool columnOverflowPositive();
      bool rowOverflowNegative();
      bool columnOverflowNegative();
      bool isInFirstRow();
      bool isInSecondRow();
      void displayCtrlRefresh();


    public:
      LCD(
          unsigned char RS,
          unsigned char EN,
          unsigned char D4,
          unsigned char D5,
          unsigned char D6,
          unsigned char D7);
      ~LCD() {}

    public:
      void begin();
      void home();
      void clear();
      void on();
      void off();
      void blink(bool enable);
      void cursor(bool enable);
      void setCursor(unsigned char column, unsigned char row);
      SimpleOS::Data::Duet<unsigned char, unsigned char> getCurrentCursorPosition();

      template <typename T>
      LCD &operator<<(const Data::Number<T> &data);
      LCD &operator<<(const SimpleOS::Data::SimpleString &data);
      LCD &operator<<(const char *str);
      LCD &operator<<(char data);
      LCD &operator<<(unsigned char data);
      LCD &operator<<(int data);
      LCD &operator<<(unsigned int data);
      LCD &operator<<(long data);
      LCD &operator<<(unsigned long data);
      LCD &operator<<(float data);
      LCD &operator<<(double data);
      LCD &operator<<(bool data);
      LCD &operator<<(void *ptr);
    };
  } // namespace Addons
} // namespace SimpleOS
