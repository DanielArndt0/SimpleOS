#include "DataTypes/String/String.h"

inline void SimpleOS::Data::String::init()
{
  buffer = nullptr;
  length = 0x00;
}

void SimpleOS::Data::String::copy_to_buffer(SimpleOS::Data::Char *cstr)
{
  if (buffer)
    free(buffer);
  buffer = cstr;
}

SimpleOS::Data::Char *SimpleOS::Data::String::alloc_buffer(Size size)
{
  length = size;
  SimpleOS::Data::Char *temp = (SimpleOS::Data::Char *)calloc(size, sizeof(SimpleOS::Data::Char));
  return temp;
}

bool SimpleOS::Data::String::exists_in_the_range(Index Index, SimpleOS::Data::Char min, SimpleOS::Data::Char max) const { return at(Index) >= min && at(Index) <= max ? true : false; }

void SimpleOS::Data::String::shift_str(Index cursor)
{
  for ( Index i = cursor; i < (signed)length; i++)
    buffer[i] = buffer[i + 0x01];
}

SimpleOS::Data::String &SimpleOS::Data::String::copy(SimpleOS::Data::Char chr)
{
  SimpleOS::Data::Char *temp = alloc_buffer(0x02);
  if (temp == nullptr)
    return *this;
  temp[0x00] = chr;
  temp[0x01] = 0x00;
  copy_to_buffer(temp);
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::copy(C_String cstr)
{
  if (cstr)
  {
    SimpleOS::Data::Char *temp = alloc_buffer(strlen(cstr) + 0x01);
    if (temp == nullptr)
      return *this;
    strcpy(temp, cstr);
    copy_to_buffer(temp);
    return *this;
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::attach(SimpleOS::Data::Char chr)
{
  if (chr)
  {
    SimpleOS::Data::Char tempBuff[0x02] = {chr, 0x00};
    SimpleOS::Data::Char *temp = alloc_buffer(strlen(buffer) + 0x02);
    if (temp == nullptr)
      return *this;
    strcpy(temp, buffer);
    strcat(temp, tempBuff);
    copy_to_buffer(temp);
    return *this;
  }
  return *this;
}

SimpleOS::Data::String &SimpleOS::Data::String::attach(C_String cstr)
{
  if (cstr)
  {
    SimpleOS::Data::Char *temp = alloc_buffer(strlen(buffer) + strlen(cstr) + 0x01);
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
    free(buffer);
}

SimpleOS::Data::String::String(SimpleOS::Data::Char chr)
{
  init();
  *this = chr;
}

SimpleOS::Data::String::String(C_String cstr)
{
  init();
  *this = cstr;
}

SimpleOS::Data::String::String(SimpleOS::Data::UChar value, SimpleOS::Data::UChar base)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(SimpleOS::Data::UChar)];
  *this = utoa(value, l_buf, base);
}

SimpleOS::Data::String::String(SimpleOS::Data::Int value, SimpleOS::Data::UChar base)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(SimpleOS::Data::Int)];
  *this = itoa(value, l_buf, base);
}

SimpleOS::Data::String::String(SimpleOS::Data::UInt value, SimpleOS::Data::UChar base)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(SimpleOS::Data::UInt)];
  *this = utoa(value, l_buf, base);
}

SimpleOS::Data::String::String(SimpleOS::Data::Long value, SimpleOS::Data::UChar base)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(SimpleOS::Data::Long)];
  *this = ltoa(value, l_buf, base);
}

SimpleOS::Data::String::String(SimpleOS::Data::ULong value, SimpleOS::Data::UChar base)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(SimpleOS::Data::ULong)];
  *this = ultoa(value, l_buf, base);
}

SimpleOS::Data::String::String(float value, SimpleOS::Data::UChar precision)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(float)];
  *this = dtostrf(value, (precision + 0x01), precision, l_buf);
}

SimpleOS::Data::String::String(double value, SimpleOS::Data::UChar precision)
{
  init();
  SimpleOS::Data::Char l_buf[BUFFER_SIZE_STR(double)];
  *this = dtostrf(value, (precision + 0x01), precision, l_buf);
}

SimpleOS::Data::C_String SimpleOS::Data::String::c_str() const { return buffer; }

SimpleOS::Data::Char SimpleOS::Data::String::at(Index Index) const
{
  if (buffer)
    return buffer[Index];
  return 0x00;
}

SimpleOS::Data::String &SimpleOS::Data::String::remove(SimpleOS::Data::Char chr) { return remove(chr, 0); }

SimpleOS::Data::String &SimpleOS::Data::String::remove(SimpleOS::Data::Char chr, SimpleOS::Data::Index fromIndex) { return remove(chr, fromIndex, size()); }

SimpleOS::Data::String &SimpleOS::Data::String::remove(SimpleOS::Data::Char chr, SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex)
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
    buffer = (SimpleOS::Data::Char *)realloc(buffer, length);
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

SimpleOS::Data::Size SimpleOS::Data::String::count(SimpleOS::Data::Char chr) const
{
  SimpleOS::Data::UInt counter = 0;
  for ( SimpleOS::Data::UInt i = 0; i < length; i++)
    if (at(i) == chr)
      counter++;
  return counter;
}

SimpleOS::Data::Index SimpleOS::Data::String::find(SimpleOS::Data::Char chr) const { return find(chr, 0); }

SimpleOS::Data::Index SimpleOS::Data::String::find(SimpleOS::Data::Char chr, Index cursor) const { return find(chr, cursor, size()); }

SimpleOS::Data::Index SimpleOS::Data::String::find(SimpleOS::Data::Char chr, Index fromIndex, Index untilIndex) const
{
  if (untilIndex < (signed)length && fromIndex <= untilIndex)
    for ( Index i = fromIndex; i <= untilIndex; i++)
      if (at(i) == chr)
        return i;
  return -1;
}

SimpleOS::Data::String SimpleOS::Data::String::findLimited(SimpleOS::Data::C_String delimiters) const
{
  if (delimiters)
    return strtok(buffer, delimiters);
  return NULL_STR;
}

SimpleOS::Data::String SimpleOS::Data::String::findLimited(const SimpleOS::Data::String &delimiters) const { return findLimited(delimiters.c_str()); }

SimpleOS::Data::String SimpleOS::Data::String::find(SimpleOS::Data::C_String precedent) const
{
  if (precedent)
    return strstr(buffer, precedent);
  return NULL_STR;
}

SimpleOS::Data::String SimpleOS::Data::String::find(SimpleOS::Data::String precedent) const { return find(precedent); }

// TODO
SimpleOS::Data::String SimpleOS::Data::String::findBetween(SimpleOS::Data::C_String initialStr, SimpleOS::Data::C_String delimiterStr) { return strtok(strstr(buffer, initialStr), delimiterStr); }

// TODO
SimpleOS::Data::String SimpleOS::Data::String::findBetween(const SimpleOS::Data::String &initialStr, const SimpleOS::Data::String &delimiterStr) { return findBetween(initialStr.c_str(), delimiterStr.c_str()); }

bool SimpleOS::Data::String::exists(SimpleOS::Data::C_String cstr) const { return strstr(buffer, cstr) != nullptr ? true : false; }

bool SimpleOS::Data::String::exists(SimpleOS::Data::String str) const { return exists(str.c_str()); }

bool SimpleOS::Data::String::equals(C_String cstr) const
{
  if (cstr)
    if (!strcmp(buffer, cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::equals(const String &str) const { return this->equals(str.buffer); }

bool SimpleOS::Data::String::different(C_String cstr) const { return !equals(cstr); }

bool SimpleOS::Data::String::different(const String &str) const { return !this->equals(str.buffer); }

bool SimpleOS::Data::String::biggerThan(C_String cstr) const
{
  if (cstr)
    if (strlen(buffer) > strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::biggerThan(const String &str) const { return this->biggerThan(str.buffer); }

bool SimpleOS::Data::String::biggerEqualsThan(C_String cstr) const
{
  if (cstr)
    if (strlen(buffer) >= strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::biggerEqualsThan(const String &str) const { return this->biggerEqualsThan(str.buffer); }

bool SimpleOS::Data::String::lessThan(C_String cstr) const
{
  if (cstr)
    if (strlen(buffer) < strlen(cstr))
      return true;
  return false;
}

bool SimpleOS::Data::String::lessThan(const String &str) const { return this->lessThan(str.buffer); }

bool SimpleOS::Data::String::lessEqualsThan(C_String cstr) const
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

SimpleOS::Data::Char SimpleOS::Data::String::toChar(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (Char)strtol(buffer, nullptr, base);
  return 0x00;
}

SimpleOS::Data::UChar SimpleOS::Data::String::toUChar(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (SimpleOS::Data::UChar)strtoul(buffer, nullptr, base);
  return 0x00;
}

SimpleOS::Data::Int SimpleOS::Data::String::toInt(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (SimpleOS::Data::Int)strtol(buffer, nullptr, base);
  return 0x00;
}

SimpleOS::Data::UInt SimpleOS::Data::String::toUInt(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (SimpleOS::Data::UInt)strtoul(buffer, nullptr, base);
  return 0x00;
}

SimpleOS::Data::Long SimpleOS::Data::String::toLong(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (SimpleOS::Data::Long)atol(buffer);
  return 0x00;
}

SimpleOS::Data::ULong SimpleOS::Data::String::toULong(SimpleOS::Data::UChar base)
{
  if (buffer)
    return (SimpleOS::Data::ULong)strtoul(buffer, nullptr, base);
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

SimpleOS::Data::String &SimpleOS::Data::String::operator=(SimpleOS::Data::Char chr) { return copy(chr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(C_String cstr) { return copy(cstr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(const String &str) { return this->copy(str.buffer); }

SimpleOS::Data::String &SimpleOS::Data::String::operator=(const String &&str) { return this->copy(str.buffer); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(SimpleOS::Data::Char chr) { return this->attach(chr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(C_String cstr) { return this->attach(cstr); }

SimpleOS::Data::String &SimpleOS::Data::String::operator+=(const String &str) { return this->attach(str.buffer); }

bool SimpleOS::Data::String::operator==(C_String cstr) const { return equals(cstr); }

bool SimpleOS::Data::String::operator==(const String &str) const { return this->equals(str.buffer); }

bool SimpleOS::Data::String::operator!=(C_String cstr) const { return different(cstr); }

bool SimpleOS::Data::String::operator!=(const String &str) const { return this->different(str.buffer); }

bool SimpleOS::Data::String::operator>(C_String cstr) const { return biggerThan(cstr); }

bool SimpleOS::Data::String::operator>(const String &str) const { return this->biggerThan(str.buffer); }

bool SimpleOS::Data::String::operator>=(C_String cstr) const { return biggerEqualsThan(cstr); }

bool SimpleOS::Data::String::operator>=(const String &str) const { return this->biggerEqualsThan(str.buffer); }

bool SimpleOS::Data::String::operator<(C_String cstr) const { return lessThan(cstr); }

bool SimpleOS::Data::String::operator<(const String &str) const { return this->lessThan(str.buffer); }

bool SimpleOS::Data::String::operator<=(C_String cstr) const { return lessEqualsThan(cstr); }

bool SimpleOS::Data::String::operator<=(const String &str) const { return this->lessEqualsThan(str.buffer); }

SimpleOS::Data::Char SimpleOS::Data::String::operator[](Index Index) const { return buffer[Index]; }