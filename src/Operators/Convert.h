#pragma once
#include <stdlib.h>
#include "Operators/Typeof.h"

namespace SimpleOS
{
  namespace Operators
  {
    template <typename U>
    struct convert
    {
      static const char *toString(U data, char *buffer, char base = 10) { return Typeof<U>(); }
    };

    template <>
    struct convert<int>
    {
      static const char * toString(int data, char *buffer, char base = 10) { return itoa(data, buffer, base); }
    };

    template <>
    struct convert<unsigned int>
    {
      static const char * toString(int data, char *buffer, char base = 10) { return utoa(data, buffer, base); }
    };

    template <>
    struct convert<char>
    {
      static const char * toString(char data, char *buffer, char base = 10) { return itoa(data, buffer, 10); }
    };

    template <>
    struct convert<unsigned char>
    {
      static const char * toString(char data, char *buffer, char base = 10) { return utoa(data, buffer, 10); }
    };

    template <>
    struct convert<long>
    {
      static const char * toString(long data, char *buffer, char base = 10) { return ltoa(data, buffer, 10); }
    };

    template <>
    struct convert<unsigned long>
    {
      static const char * toString(long data, char *buffer, char base = 10) { return ultoa(data, buffer, 10); }
    };

    template <>
    struct convert<float>
    {
      static const char * toString(float data, char *buffer, char precision = 2) { return dtostrf(data, (precision + 1), precision, buffer); }
    };

    template <>
    struct convert<double>
    {
      static const char * toString(double data, char *buffer, char precision = 2) { return dtostrf(data, (precision + 1), precision, buffer); }
    };
  }
}