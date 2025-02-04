#pragma once
#include "DataTypes/String/SimpleString/SimpleString.h"
#include "DataTypes/Typedefs.h"
#include <string.h>
#include <ctype.h>

namespace SimpleOS
{
  namespace Data
  {
    class StringAddons : public SimpleString
    {
    public:
      StringAddons();
      StringAddons(CString str);
      StringAddons(const StringAddons &other);
      StringAddons(StringAddons &&other);
      ~StringAddons();

      StringAddons &assign(const StringAddons &other);
      StringAddons &assign(StringAddons &&other);

      bool equals(CString str) const;
      bool equals(const StringAddons &other) const;
      bool notEquals(CString str) const;
      bool notEquals(const StringAddons &other) const;
      bool isLessThan(CString str) const;
      bool isLessThan(const StringAddons &other) const;
      bool isGreaterThan(CString str) const;
      bool isGreaterThan(const StringAddons &other) const;
      bool isLessOrEqual(CString str) const;
      bool isLessOrEqual(const StringAddons &other) const;
      bool isGreaterOrEqual(CString str) const;
      bool isGreaterOrEqual(const StringAddons &other) const;

      int toInt() const;
      float toFloat() const;
      double toDouble() const;
      bool isNumeric() const;

      static StringAddons fromInt(int value);
      static StringAddons fromFloat(float value, int precision = 2);
      static StringAddons fromDouble(double value, int precision = 2);

      void remove(Char chr);
      void remove(Char chr, Index fromIndex);
      void remove(Char chr, Index fromIndex, Index untilIndex);
      void remove(Index index);
      void remove(Index fromIndex, Index untilIndex);

      Index find(Char chr) const;
      Index find(Char chr, Index cursor) const;
      Index find(Char chr, Index fromIndex, Index untilIndex) const;
      StringAddons findLimited(CString delimiters) const;
      StringAddons findLimited(const StringAddons &delimiters) const;

      bool exists(CString cstr) const;
      bool exists(const StringAddons &str) const;

      bool isUpper(Index index) const;
      bool isLower(Index index) const;
      bool isAlpha(Index index) const;
      bool isNumber(Index index) const;
      bool isPunctuation(Index index) const;
      bool isPrintable(Index index) const;
      bool isControl(Index index) const;

      void toUpper();
      void toUpper(Index index);
      void toLower();
      void toLower(Index index);
    };
  } // namespace Data
} // namespace SimpleOS
