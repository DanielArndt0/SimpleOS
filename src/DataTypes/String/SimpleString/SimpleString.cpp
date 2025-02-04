#include "SimpleString.h"

using namespace SimpleOS::Data;

SimpleString::SimpleString() { this->init(); }

SimpleString::SimpleString(CString str) { copy(str); }

SimpleString::SimpleString(const SimpleString &str) { copy(str); }

SimpleString::SimpleString(SimpleString &&str) noexcept
{
  this->str = str.str;
  this->length = str.length;
  str.str = nullptr;
  str.length = 0;
}

SimpleString::~SimpleString() { this->desalloc(); }

void SimpleString::init()
{
  str = alloc(1);
  str[0] = '\0';
  length = 0;
}

char *SimpleString::alloc(Size size)
{
  return static_cast<char *>(calloc(size, sizeof(char)));
}

void SimpleString::desalloc()
{
  if (this->str)
  {
    free(this->str);
    this->str = nullptr;
    this->length = 0;
  }
}

void SimpleString::loadToBuffer(char *newStr, Size newLength)
{
  if (this->str == newStr)
    return;
  this->desalloc();
  this->str = newStr;
  this->length = newLength - 1;
}

SimpleString &SimpleString::copy(CString str)
{
  if (!str)
    return *this;

  Size newLength = strlen(str) + 1;
  loadToBuffer(strcpy(alloc(newLength), str), newLength);
  return *this;
}

SimpleString &SimpleString::copy(const SimpleString &str) { return this->copy(str.CStr()); }

SimpleString &SimpleString::append(char chr)
{
  Size newLength = this->length + 2;
  char *temp = alloc(newLength);
  strcpy(temp, this->str);
  temp[this->length] = chr;
  temp[this->length + 1] = '\0';
  loadToBuffer(temp, newLength);
  return *this;
}

SimpleString &SimpleString::append(CString str)
{
  if (!str)
    return *this;

  Size newLength = this->length + strlen(str) + 1;
  char *temp = alloc(newLength);
  strcpy(temp, this->str);
  strcat(temp, str);
  loadToBuffer(temp, newLength);
  return *this;
}

SimpleString &SimpleString::append(const SimpleString &str) { return this->append(str.CStr()); }

CString SimpleString::CStr() const { return str; }

Size SimpleString::getLength() const { return length; }

char SimpleString::at(Size index) const
{
  if (index >= length)
    return '\0';
  return str[index];
}

SimpleString &SimpleString::operator=(CString str) { return copy(str); }

SimpleString &SimpleString::operator=(const SimpleString &str) { return copy(str); }

SimpleString &SimpleString::operator=(SimpleString &&str) noexcept
{
  if (this != &str)
  {
    this->desalloc();
    this->str = str.str;
    this->length = str.length;
    str.str = nullptr;
    str.length = 0;
  }
  return *this;
}

SimpleString &SimpleString::operator+=(char chr) { return append(chr); }

SimpleString &SimpleString::operator+=(CString str) { return append(str); }

SimpleString &SimpleString::operator+=(const SimpleString &str) { return append(str); }

char SimpleString::operator[](Size index) const { return at(index); }
