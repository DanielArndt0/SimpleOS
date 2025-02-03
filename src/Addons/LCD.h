#pragma once
#include "Time/Delay/Delay.h"
#include "Hardware/Pin/Pin.h"
#include "Hardware/PinMode.h"
#include "DataTypes/Number.h"
#include "DataTypes/String/SimpleString/SimpleString.h"

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

    private:
      void sendCmd(unsigned char hexCmd);
      void pulse();
      void wChar(char data);
      void wString(const char *str);

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
      void displayOn();
      void displayOff();

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
