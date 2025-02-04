#pragma once
#include "DataTypes/String/StringAddons/StringAddons.h"
#include <string.h>

namespace SimpleOS
{
  namespace Data
  {
    class String : public StringAddons
    {
    public:
      String();
      String(CString str);
      String(const String &other);
      String(String &&other) noexcept;
      ~String();

      String &operator=(CString str);
      String &operator=(const String &other);
      String &operator=(String &&other) noexcept;

      String operator+(CString str) const;
      String operator+(const String &other) const;
      String &operator+=(CString str);
      String &operator+=(const String &other);

      bool operator==(CString str) const;
      bool operator==(const String &other) const;
      bool operator!=(CString str) const;
      bool operator!=(const String &other) const;
      bool operator<(CString str) const;
      bool operator<(const String &other) const;
      bool operator>(CString str) const;
      bool operator>(const String &other) const;
      bool operator<=(CString str) const;
      bool operator<=(const String &other) const;
      bool operator>=(CString str) const;
      bool operator>=(const String &other) const;

      char &operator[](Index index);
      const char &operator[](Index index) const;
    };
  }
}
