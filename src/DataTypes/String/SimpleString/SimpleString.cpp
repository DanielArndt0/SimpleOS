#include "SimpleString.h"

SimpleOS::Data::SimpleString::SimpleString() { this->init(); }

SimpleOS::Data::SimpleString::SimpleString(SimpleOS::Data::CString str) { copy(str); }

SimpleOS::Data::SimpleString::SimpleString(const SimpleOS::Data::SimpleString &str) { copy(str); }

SimpleOS::Data::SimpleString::SimpleString(SimpleOS::Data::SimpleString &&str)
{
  this->desalloc();
  this->str = str.str;
  this->length = str.length;
  str.str = nullptr;
  str.length = 0;
}

SimpleOS::Data::SimpleString::~SimpleString() { this->desalloc(); }

void SimpleOS::Data::SimpleString::init()
{
  str = alloc(1);
  str[0] = '\0';
  length = 0;
}

char *SimpleOS::Data::SimpleString::alloc(Data::Size size) { return (char *)calloc(size, sizeof(char)); }

void SimpleOS::Data::SimpleString::desalloc()
{
  if (this->str)
    delete[] this->str;
}

void SimpleOS::Data::SimpleString::loadToBuffer(char *str, unsigned int length)
{
  if (this->str == str)
    return;
  this->desalloc();
  this->str = str;
  this->length = length - 1;
}

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::copy(SimpleOS::Data::CString str)
{
  if (str == nullptr)
    return *this;
  unsigned int length = strlen(str) + 1;
  loadToBuffer(strcpy(alloc(length), str), length);
  return *this;
}

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::copy(const SimpleString &str) { return this->copy(str.CStr()); }

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::append(char chr)
{
  unsigned int length = strlen(this->str) + 2;
  char *temp = alloc(length);
  strcpy(temp, this->str);
  temp[length - 2] = chr;
  temp[length - 1] = '\0';
  loadToBuffer(temp, length);
  return *this;
}

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::append(SimpleOS::Data::CString str)
{
  if (str == nullptr)
    return *this;
  unsigned int length = strlen(this->str) + strlen(str) + 1;
  char *temp = alloc(length);
  strcpy(temp, this->str);
  strcat(temp, str);
  loadToBuffer(temp, length);
  return *this;
}

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::append(const SimpleString &str) { return this->append(str.CStr()); }

SimpleOS::Data::CString SimpleOS::Data::SimpleString::CStr() const { return str; }

unsigned int SimpleOS::Data::SimpleString::getLength() const { return length; }

char SimpleOS::Data::SimpleString::at(unsigned int index) const
{
  if (index >= length || index <= 0)
    return 0;
  return str[index];
}

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::operator=(SimpleOS::Data::CString str) { return copy(str); }

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::operator=(const SimpleOS::Data::SimpleString &str) { return copy(str); }

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::operator+=(char chr) { return append(chr); }

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::operator+=(SimpleOS::Data::CString str) { return append(str); }

SimpleOS::Data::SimpleString &SimpleOS::Data::SimpleString::operator+=(const SimpleOS::Data::SimpleString &str) { return append(str); }

char SimpleOS::Data::SimpleString::operator[](unsigned int index) { return at(index); }
