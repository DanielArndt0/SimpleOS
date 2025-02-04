#include "String.h"

using namespace SimpleOS::Data;

SimpleOS::Data::String::String() : StringAddons() {}

SimpleOS::Data::String::String(CString str) : StringAddons(str) {}

SimpleOS::Data::String::String(const String &other) : StringAddons(other) {}

SimpleOS::Data::String::String(String &&other) : StringAddons(other) {}

SimpleOS::Data::String::~String() {}

SimpleOS::Data::String &SimpleOS::Data::String::operator=(CString str)
{
  if (CStr() != str)
    assign(str);
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::operator=(const SimpleOS::Data::String &other)
{
  if (this != &other)
    assign(other);
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::operator=(SimpleOS::Data::String &&other)
{
  if (this != &other)
    assign(other);
  return *this;
}

SimpleOS::Data::String SimpleOS::Data::String::operator+(CString str) const
{
  SimpleOS::Data::String result(*this);
  result += str;
  return result;
}

SimpleOS::Data::String SimpleOS::Data::String::operator+(const SimpleOS::Data::String &other) const
{
  return *this + other.CStr();
}

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(CString str)
{
  append(str);
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(const SimpleOS::Data::String &other)
{
  return (*this += other.CStr());
}

bool SimpleOS::Data::String::operator==(CString str) const
{
  return equals(str);
}

bool SimpleOS::Data::String::operator==(const SimpleOS::Data::String &other) const
{
  return equals(other);
}

bool SimpleOS::Data::String::operator!=(CString str) const
{
  return !equals(str);
}

bool SimpleOS::Data::String::operator!=(const SimpleOS::Data::String &other) const
{
  return !equals(other);
}

bool SimpleOS::Data::String::operator<(CString str) const
{
  return isLessThan(str);
}

bool SimpleOS::Data::String::operator<(const SimpleOS::Data::String &other) const
{
  return isLessThan(other);
}

bool SimpleOS::Data::String::operator>(CString str) const
{
  return isGreaterThan(str);
}

bool SimpleOS::Data::String::operator>(const SimpleOS::Data::String &other) const
{
  return isGreaterThan(other);
}

bool SimpleOS::Data::String::operator<=(CString str) const
{
  return isLessOrEqual(str);
}

bool SimpleOS::Data::String::operator<=(const SimpleOS::Data::String &other) const
{
  return isLessOrEqual(other);
}

bool SimpleOS::Data::String::operator>=(CString str) const
{
  return isGreaterOrEqual(str);
}

bool SimpleOS::Data::String::operator>=(const SimpleOS::Data::String &other) const
{
  return isGreaterOrEqual(other);
}

char &SimpleOS::Data::String::operator[](Index index)
{
  if (index >= getLength())
    return str[0];
  return str[index];
}

const char &SimpleOS::Data::String::operator[](Index index) const
{
  if (index >= getLength())
    return str[0];
  return str[index];
}
