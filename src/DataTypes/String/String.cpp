#include "DataTypes/String/String.h"

inline void SimpleOS::Data::String::init()
{
  buffer = nullptr;
  length = 0x00;
}

void SimpleOS::Data::String::copy_to_buffer(char *cstr)
{
  if (buffer)
    vram.free(buffer);
  buffer = cstr;
}

char *SimpleOS::Data::String::alloc_buffer(Size size)
{
  length = size;
  char *temp = (char *)vram.malloc(sizeof(char) * size);
  return temp;
}

bool SimpleOS::Data::String::exists_in_the_range(Index Index, char min, char max) const { return at(Index) >= min && at(Index) <= max ? true : false; }

void SimpleOS::Data::String::shift_str(Index cursor)
{
  for ( Index i = cursor; i < (signed)length; i++)
    buffer[i] = buffer[i + 0x01];
}

SimpleOS::Data::String &SimpleOS::Data::String::copy(char chr)
{
  char *temp = alloc_buffer(0x02);
  if (temp == nullptr)
    return *this;
  temp[0x00] = chr;
  temp[0x01] = 0x00;
  copy_to_buffer(temp);
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::copy(CString cstr)
{
  if (cstr)
  {
    char *temp = alloc_buffer(strlen(cstr) + 0x01);
    if (temp == nullptr)
      return *this;
    strcpy(temp, cstr);
    copy_to_buffer(temp);
    return *this;
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::attach(char chr)
{
  if (chr)
  {
    char tempBuff[0x02] = {chr, 0x00};
    char *temp = alloc_buffer(strlen(buffer) + 0x02);
    if (temp == nullptr)
      return *this;
    strcpy(temp, buffer);
    strcat(temp, tempBuff);
    copy_to_buffer(temp);
    return *this;
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::attach(CString cstr)
{
  if (cstr)
  {
    char *temp = alloc_buffer(strlen(buffer) + strlen(cstr) + 0x01);
    if (temp == nullptr)
      return *this;
    strcpy(temp, buffer);
    strcat(temp, cstr);
    copy_to_buffer(temp);
    return *this;
  }
  return *this;
}

SimpleOS::Data::String::String(const String &str)
{
  init();
  *this = str;
}

SimpleOS::Data::String::String(const SimpleOS::Data::String &&str)
{
  init();
  *this = str;
}

SimpleOS::Data::String::~String(void)
{
  if (buffer)
    vram.free(buffer);
}

SimpleOS::Data::String::String(char chr)
{
  init();
  *this = chr;
}

SimpleOS::Data::String::String(CString cstr)
{
  init();
  *this = cstr;
}

SimpleOS::Data::String::String(unsigned char value, unsigned char base)
{
  init();
  char l_buf[BUFFER_SIZE_STR(unsigned char)];
  *this = utoa(value, l_buf, base);
}

SimpleOS::Data::String::String(int value, unsigned char base)
{
  init();
  char l_buf[BUFFER_SIZE_STR(int)];
  *this = itoa(value, l_buf, base);
}

SimpleOS::Data::String::String(unsigned int value, unsigned char base)
{
  init();
  char l_buf[BUFFER_SIZE_STR(unsigned int)];
  *this = utoa(value, l_buf, base);
}

SimpleOS::Data::String::String(long value, unsigned char base)
{
  init();
  char l_buf[BUFFER_SIZE_STR(long)];
  *this = ltoa(value, l_buf, base);
}

SimpleOS::Data::String::String(unsigned long value, unsigned char base)
{
  init();
  char l_buf[BUFFER_SIZE_STR(unsigned long)];
  *this = ultoa(value, l_buf, base);
}

SimpleOS::Data::String::String(float value, unsigned char precision)
{
  init();
  char l_buf[BUFFER_SIZE_STR(float)];
  *this = dtostrf(value, (precision + 0x01), precision, l_buf);
}

SimpleOS::Data::String::String(double value, unsigned char precision)
{
  init();
  char l_buf[BUFFER_SIZE_STR(double)];
  *this = dtostrf(value, (precision + 0x01), precision, l_buf);
}

const char* SimpleOS::Data::String::c_str() const { return buffer; }

char SimpleOS::Data::String::at(Index Index) const
{
  if (buffer)
    return buffer[Index];
  return 0x00;
}

SimpleOS::Data::String &SimpleOS::Data::String::remove(char chr) { return remove(chr, 0); }

SimpleOS::Data::String &SimpleOS::Data::String::remove(char chr, SimpleOS::Data::Index fromIndex) { return remove(chr, fromIndex, size()); }

SimpleOS::Data::String &SimpleOS::Data::String::remove(char chr, SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex)
{
  if (untilIndex < (signed)length && fromIndex <= untilIndex)
  {
    Index pos, cnt = 0;
    while ((pos = find(chr, fromIndex, untilIndex)) != -1)
    {
      shift_str(pos);
      cnt++;
    }
    length -= cnt;
    buffer = (char *)realloc(buffer, length);
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::remove(SimpleOS::Data::Index Index)
{
  if (Index < (signed)length)
  {
    String str = *this;
    str.shift_str(Index);
    *this = str;
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::remove(SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex)
{
  if (untilIndex < (signed)length && fromIndex <= untilIndex)
    for (Index i = fromIndex; i <= untilIndex; i++)
      remove(fromIndex);
  return *this;
}

SimpleOS::Data::Size SimpleOS::Data::String::size() const { return length - 1; }

SimpleOS::Data::Size SimpleOS::Data::String::count(char chr) const
{
  unsigned int counter = 0;
  for ( unsigned int i = 0; i < length; i++)
    if (at(i) == chr)
      counter++;
  return counter;
}

SimpleOS::Data::Index SimpleOS::Data::String::find(char chr) const { return find(chr, 0); }

SimpleOS::Data::Index SimpleOS::Data::String::find(char chr, Index cursor) const { return find(chr, cursor, size()); }

SimpleOS::Data::Index SimpleOS::Data::String::find(char chr, Index fromIndex, Index untilIndex) const
{
  if (untilIndex < (signed)length && fromIndex <= untilIndex)
    for ( Index i = fromIndex; i <= untilIndex; i++)
      if (at(i) == chr)
        return i;
  return -1;
}

SimpleOS::Data::String SimpleOS::Data::String::findLimited(const char* delimiters) const
{
  if (delimiters)
    return strtok(buffer, delimiters);
  return NULL_STR;
}

SimpleOS::Data::String SimpleOS::Data::String::findLimited(const SimpleOS::Data::String &delimiters) const { return findLimited(delimiters.c_str()); }

SimpleOS::Data::String SimpleOS::Data::String::find(const char* precedent) const
{
  if (precedent)
    return strstr(buffer, precedent);
  return NULL_STR;
}

SimpleOS::Data::String SimpleOS::Data::String::find(SimpleOS::Data::String precedent) const { return find(precedent); }

// TODO
SimpleOS::Data::String SimpleOS::Data::String::findBetween(const char* initialStr, const char* delimiterStr) { return strtok(strstr(buffer, initialStr), delimiterStr); }

// TODO
SimpleOS::Data::String SimpleOS::Data::String::findBetween(const SimpleOS::Data::String &initialStr, const SimpleOS::Data::String &delimiterStr) { return findBetween(initialStr.c_str(), delimiterStr.c_str()); }

bool SimpleOS::Data::String::exists(const char* cstr) const { return strstr(buffer, cstr) != nullptr ? true : false; }

bool SimpleOS::Data::String::exists(SimpleOS::Data::String str) const { return exists(str.c_str()); }

bool SimpleOS::Data::String::equals(CString cstr) const
{
  if (cstr)
    if (!strcmp(buffer, cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::equals(const String &str) const { return this->equals(str.buffer); }

bool SimpleOS::Data::String::different(CString cstr) const { return !equals(cstr); }

bool SimpleOS::Data::String::different(const String &str) const { return !this->equals(str.buffer); }

bool SimpleOS::Data::String::biggerThan(CString cstr) const
{
  if (cstr)
    if (strlen(buffer) > strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::biggerThan(const String &str) const { return this->biggerThan(str.buffer); }

bool SimpleOS::Data::String::biggerEqualsThan(CString cstr) const
{
  if (cstr)
    if (strlen(buffer) >= strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::biggerEqualsThan(const String &str) const { return this->biggerEqualsThan(str.buffer); }

bool SimpleOS::Data::String::lessThan(CString cstr) const
{
  if (cstr)
    if (strlen(buffer) < strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::lessThan(const String &str) const { return this->lessThan(str.buffer); }

bool SimpleOS::Data::String::lessEqualsThan(CString cstr) const
{
  if (cstr)
    if (strlen(buffer) <= strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::lessEqualsThan(const String &str) const { return this->lessEqualsThan(str.buffer); }

bool SimpleOS::Data::String::isUpper(Index Index) const { return exists_in_the_range(Index, 0x41, 0x5A); }

bool SimpleOS::Data::String::isLower(Index Index) const { return exists_in_the_range(Index, 0x61, 0x7A); }

bool SimpleOS::Data::String::isAlpha(Index Index) const { return isUpper(Index) || isLower(Index) ? true : false; }

bool SimpleOS::Data::String::isNumber(Index Index) const { return exists_in_the_range(Index, 0x30, 0x39); }

bool SimpleOS::Data::String::isPunctation(Index Index) const { return exists_in_the_range(Index, 0x21, 0x2F) || exists_in_the_range(Index, 0x3A, 0x40) || exists_in_the_range(Index, 0x5B, 0x60) || exists_in_the_range(Index, 0x7B, 0x7E) ? true : false; }

bool SimpleOS::Data::String::isPrint(Index Index) const { return exists_in_the_range(Index, 0x20, 0x7E); }

bool SimpleOS::Data::String::isControl(Index Index) const { return exists_in_the_range(Index, 0x00, 0x1F) || exists_in_the_range(Index, 0x7F, 0x7F) ? true : false; }

void SimpleOS::Data::String::toUpper(Index Index)
{
  if (isAlpha(Index))
    if (!isUpper(Index))
      buffer[Index] -= 0x20;
}

void SimpleOS::Data::String::toUpper()
{
  for ( Index i = 0; i < (signed)length; i++)
    toUpper(i);
}

void SimpleOS::Data::String::toLower(Index Index)
{
  if (isAlpha(Index))
    if (!isLower(Index))
      buffer[Index] += 0x20;
}

void SimpleOS::Data::String::toLower()
{
  for ( Index i = 0; i < (signed)length; i++)
    toLower(i);
}

char SimpleOS::Data::String::toChar(unsigned char base)
{
  if (buffer)
    return (char)strtol(buffer, nullptr, base);
  return 0x00;
}

unsigned char SimpleOS::Data::String::toUChar(unsigned char base)
{
  if (buffer)
    return (unsigned char)strtoul(buffer, nullptr, base);
  return 0x00;
}

int SimpleOS::Data::String::toInt(unsigned char base)
{
  if (buffer)
    return (int)strtol(buffer, nullptr, base);
  return 0x00;
}

unsigned int SimpleOS::Data::String::toUInt(unsigned char base)
{
  if (buffer)
    return (unsigned int)strtoul(buffer, nullptr, base);
  return 0x00;
}

long SimpleOS::Data::String::toLong(unsigned char base)
{
  if (buffer)
    return (long)atol(buffer);
  return 0x00;
}

unsigned long SimpleOS::Data::String::toULong(unsigned char base)
{
  if (buffer)
    return (unsigned long)strtoul(buffer, nullptr, base);
  return 0x00;
}

float SimpleOS::Data::String::toFloat()
{
  if (buffer)
    return (float)atof(buffer);
  return 0x00;
}

double SimpleOS::Data::String::toDouble()
{
  if (buffer)
    return (double)atof(buffer);
  return 0x00;
}

SimpleOS::Data::String &SimpleOS::Data::String::operator=(char chr) { return copy(chr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(CString cstr) { return copy(cstr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(const String &str) { return this->copy(str.buffer); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(const String &&str) { return this->copy(str.buffer); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(char chr) { return this->attach(chr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(CString cstr) { return this->attach(cstr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(const String &str) { return this->attach(str.buffer); }

bool SimpleOS::Data::String::operator==(CString cstr) const { return equals(cstr); }

bool SimpleOS::Data::String::operator==(const String &str) const { return this->equals(str.buffer); }

bool SimpleOS::Data::String::operator!=(CString cstr) const { return different(cstr); }

bool SimpleOS::Data::String::operator!=(const String &str) const { return this->different(str.buffer); }

bool SimpleOS::Data::String::operator>(CString cstr) const { return biggerThan(cstr); }

bool SimpleOS::Data::String::operator>(const String &str) const { return this->biggerThan(str.buffer); }

bool SimpleOS::Data::String::operator>=(CString cstr) const { return biggerEqualsThan(cstr); }

bool SimpleOS::Data::String::operator>=(const String &str) const { return this->biggerEqualsThan(str.buffer); }

bool SimpleOS::Data::String::operator<(CString cstr) const { return lessThan(cstr); }

bool SimpleOS::Data::String::operator<(const String &str) const { return this->lessThan(str.buffer); }

bool SimpleOS::Data::String::operator<=(CString cstr) const { return lessEqualsThan(cstr); }

bool SimpleOS::Data::String::operator<=(const String &str) const { return this->lessEqualsThan(str.buffer); }

char SimpleOS::Data::String::operator[](Index Index) const { return buffer[Index]; }