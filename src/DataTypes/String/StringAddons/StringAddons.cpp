#include "StringAddons.h"

SimpleOS::Data::StringAddons::StringAddons() : SimpleString() {}

SimpleOS::Data::StringAddons::StringAddons(CString str) : SimpleString(str) {}

SimpleOS::Data::StringAddons::StringAddons(const StringAddons &other) : SimpleString(other) {}

SimpleOS::Data::StringAddons::StringAddons(StringAddons &&other) { this->assign(other); }

SimpleOS::Data::StringAddons::~StringAddons() {}

SimpleOS::Data::StringAddons &SimpleOS::Data::StringAddons::assign(const StringAddons &other)
{
  if (this != &other)
    SimpleString::operator=(other);
  return *this;
}

SimpleOS::Data::StringAddons &SimpleOS::Data::StringAddons::assign(StringAddons &&other)
{
  if (this != &other)
  {
    this->desalloc();

    this->str = other.str;
    this->length = other.length;

    other.str = nullptr;
    other.length = 0;
  }
  return *this;
}

bool SimpleOS::Data::StringAddons::equals(CString str) const
{
  if (!str)
    return false;
  return strcmp(CStr(), str) == 0;
}

bool SimpleOS::Data::StringAddons::equals(const StringAddons &other) const { return equals(other.CStr()); }

bool SimpleOS::Data::StringAddons::notEquals(CString str) const { return !equals(str); }

bool SimpleOS::Data::StringAddons::notEquals(const StringAddons &other) const { return !equals(other); }

bool SimpleOS::Data::StringAddons::isLessThan(CString str) const
{
  if (!str)
    return false;
  return strcmp(CStr(), str) < 0;
}

bool SimpleOS::Data::StringAddons::isLessThan(const StringAddons &other) const { return isLessThan(other.CStr()); }

bool SimpleOS::Data::StringAddons::isGreaterThan(CString str) const
{
  if (!str)
    return false;
  return strcmp(CStr(), str) > 0;
}

bool SimpleOS::Data::StringAddons::isGreaterThan(const StringAddons &other) const { return isGreaterThan(other.CStr()); }

bool SimpleOS::Data::StringAddons::isLessOrEqual(CString str) const { return !isGreaterThan(str); }

bool SimpleOS::Data::StringAddons::isLessOrEqual(const StringAddons &other) const { return isLessOrEqual(other.CStr()); }

bool SimpleOS::Data::StringAddons::isGreaterOrEqual(CString str) const { return !isLessThan(str); }

bool SimpleOS::Data::StringAddons::isGreaterOrEqual(const StringAddons &other) const { return isGreaterOrEqual(other.CStr()); }

// Conversão de string para número
int SimpleOS::Data::StringAddons::toInt() const
{
  return strtol(CStr(), nullptr, 10);
}

float SimpleOS::Data::StringAddons::toFloat() const
{
  return strtod(CStr(), nullptr);
}

double SimpleOS::Data::StringAddons::toDouble() const
{
  return strtod(CStr(), nullptr);
}

// Verifica se a string é numérica
bool SimpleOS::Data::StringAddons::isNumeric() const
{
  if (length == 0)
    return false;

  const char *s = CStr();
  if (*s == '-' || *s == '+')
    s++;

  bool hasDecimal = false;
  while (*s)
  {
    if (*s == '.')
    {
      if (hasDecimal)
        return false;
      hasDecimal = true;
    }
    else if (*s < '0' || *s > '9')
    {
      return false;
    }
    s++;
  }
  return true;
}


SimpleOS::Data::StringAddons SimpleOS::Data::StringAddons::fromInt(int value)
{
  char buffer[12]; 
  int i = 0;
  bool isNegative = false;

  if (value < 0)
  {
    isNegative = true;
    value = -value;
  }
  do
  {
    buffer[i++] = '0' + (value % 10);
    value /= 10;
  } while (value > 0);

  if (isNegative)
    buffer[i++] = '-';
  buffer[i] = '\0';

  for (int j = 0; j < i / 2; j++)
  {
    char temp = buffer[j];
    buffer[j] = buffer[i - j - 1];
    buffer[i - j - 1] = temp;
  }

  return StringAddons(buffer);
}

SimpleOS::Data::StringAddons SimpleOS::Data::StringAddons::fromFloat(float value, int precision)
{
  StringAddons result = fromInt(static_cast<int>(value)); 
  result.append('.');

  float decimalPart = value - static_cast<int>(value);
  if (decimalPart < 0)
    decimalPart = -decimalPart;

  for (int i = 0; i < precision; i++)
    decimalPart *= 10;

  result.append(fromInt(static_cast<int>(decimalPart)).CStr());

  return result;
}

SimpleOS::Data::StringAddons SimpleOS::Data::StringAddons::fromDouble(double value, int precision) { return fromFloat(static_cast<float>(value), precision); }

void SimpleOS::Data::StringAddons::remove(Char chr)
{
  remove(chr, 0, length);
}

void SimpleOS::Data::StringAddons::remove(Char chr, SimpleOS::Data::Index fromIndex)
{
  remove(chr, fromIndex, length);
}

void SimpleOS::Data::StringAddons::remove(Char chr, SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex)
{
  if (fromIndex >= length || untilIndex > length)
    return;

  char *temp = alloc(length);
  int j = 0;
  for (SimpleOS::Data::Index i = 0; i < length; i++)
  {
    if (i >= fromIndex && i < untilIndex && str[i] == chr)
      continue;
    temp[j++] = str[i];
  }
  temp[j] = '\0';
  loadToBuffer(temp, j + 1);
}

void SimpleOS::Data::StringAddons::remove(SimpleOS::Data::Index index)
{
  remove(index, index + 1);
}

void SimpleOS::Data::StringAddons::remove(SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex)
{
  if (fromIndex >= length || untilIndex > length || fromIndex >= untilIndex)
    return;

  char *temp = alloc(length);
  int j = 0;
  for (SimpleOS::Data::Index i = 0; i < length; i++)
  {
    if (i >= fromIndex && i < untilIndex)
      continue;
    temp[j++] = str[i];
  }
  temp[j] = '\0';
  loadToBuffer(temp, j + 1);
}

SimpleOS::Data::Index SimpleOS::Data::StringAddons::find(Char chr) const
{
  return find(chr, 0, length);
}

SimpleOS::Data::Index SimpleOS::Data::StringAddons::find(Char chr, SimpleOS::Data::Index cursor) const
{
  return find(chr, cursor, length);
}

SimpleOS::Data::Index SimpleOS::Data::StringAddons::find(Char chr, SimpleOS::Data::Index fromIndex, SimpleOS::Data::Index untilIndex) const
{
  if (fromIndex >= length || untilIndex > length)
    return -1;

  for (SimpleOS::Data::Index i = fromIndex; i < untilIndex; i++)
  {
    if (str[i] == chr)
      return i;
  }
  return -1;
}

SimpleOS::Data::StringAddons SimpleOS::Data::StringAddons::findLimited(CString delimiters) const
{
  SimpleOS::Data::Index pos = find(delimiters[0]);
  return (pos != -1) ? StringAddons(str + pos) : StringAddons();
}

SimpleOS::Data::StringAddons SimpleOS::Data::StringAddons::findLimited(const StringAddons &delimiters) const
{
  return findLimited(delimiters.CStr());
}

bool SimpleOS::Data::StringAddons::exists(CString cstr) const
{
  return strstr(CStr(), cstr) != nullptr;
}

bool SimpleOS::Data::StringAddons::exists(const StringAddons &str) const
{
  return exists(str.CStr());
}

bool SimpleOS::Data::StringAddons::isUpper(SimpleOS::Data::Index index) const
{
  return index < length && isupper(str[index]);
}

bool SimpleOS::Data::StringAddons::isLower(SimpleOS::Data::Index index) const
{
  return index < length && islower(str[index]);
}

bool SimpleOS::Data::StringAddons::isAlpha(SimpleOS::Data::Index index) const
{
  return index < length && isalpha(str[index]);
}

bool SimpleOS::Data::StringAddons::isNumber(SimpleOS::Data::Index index) const
{
  return index < length && isdigit(str[index]);
}

bool SimpleOS::Data::StringAddons::isPunctuation(SimpleOS::Data::Index index) const
{
  return index < length && ispunct(str[index]);
}

bool SimpleOS::Data::StringAddons::isPrintable(SimpleOS::Data::Index index) const
{
  return index < length && isprint(str[index]);
}

bool SimpleOS::Data::StringAddons::isControl(SimpleOS::Data::Index index) const
{
  return index < length && iscntrl(str[index]);
}

void SimpleOS::Data::StringAddons::toUpper()
{
  for (SimpleOS::Data::Index i = 0; i < length; i++)
    str[i] = toupper(str[i]);
}

void SimpleOS::Data::StringAddons::toUpper(SimpleOS::Data::Index index)
{
  if (index < length)
    str[index] = toupper(str[index]);
}

void SimpleOS::Data::StringAddons::toLower()
{
  for (SimpleOS::Data::Index i = 0; i < length; i++)
    str[i] = tolower(str[i]);
}

void SimpleOS::Data::StringAddons::toLower(SimpleOS::Data::Index index)
{
  if (index < length)
    str[index] = tolower(str[index]);
}