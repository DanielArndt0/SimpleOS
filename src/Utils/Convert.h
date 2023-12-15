#pragma once
#include <stdlib.h>

namespace SimpleOS
{
  namespace Utils
  {
    template <typename U>
    struct Convert
    {
      static const char *toString(U data, char *buffer, char base) { return "Unknown"; }
    };

    template <>
    struct Convert<bool>
    {
      static const char *toString(bool data, char *buffer, char base) { return data ? "true" : "false"; }
    };

    template <>
    struct Convert<int>
    {
      static const char *toString(int data, char *buffer, char base) { return itoa(data, buffer, base); }
    };

    template <>
    struct Convert<unsigned int>
    {
      static const char *toString(int data, char *buffer, char base) { return utoa(data, buffer, base); }
    };

    template <>
    struct Convert<char>
    {
      static const char *toString(char data, char *buffer, char base) { return itoa(data, buffer, base); }
    };

    template <>
    struct Convert<unsigned char>
    {
      static const char *toString(char data, char *buffer, char base) { return utoa(data, buffer, base); }
    };

    template <>
    struct Convert<long>
    {
      static const char *toString(long data, char *buffer, char base) { return ltoa(data, buffer, base); }
    };

    template <>
    struct Convert<unsigned long>
    {
      static const char *toString(long data, char *buffer, char base) { return ultoa(data, buffer, base); }
    };

    template <>
    struct Convert<float>
    {
      static const char *toString(float data, char *buffer, char precision) { return dtostrf(data, (precision + 1), precision, buffer); }
    };

    template <>
    struct Convert<double>
    {
      static const char *toString(double data, char *buffer, char precision) { return dtostrf(data, (precision + 1), precision, buffer); }
    };
  }
}