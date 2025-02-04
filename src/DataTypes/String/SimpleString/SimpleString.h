#pragma once
#include <string.h>
#include <stdlib.h>
#include "System/Base.h"

namespace SimpleOS
{
  namespace Data
  {
    using CString = const char *;
    using Size = unsigned int;

    class SimpleString
    {
    protected:
      char *str;
      Size length;

    protected:
      void init();
      char *alloc(Size size);
      void desalloc();
      void loadToBuffer(char *str, Size length);

    public:
      SimpleString();
      SimpleString(CString str);
      SimpleString(const SimpleString &str);
      SimpleString(SimpleString &&str) noexcept;
      ~SimpleString();

    protected:
      SimpleString &copy(CString str);
      SimpleString &copy(const SimpleString &str);

      SimpleString &append(char chr);
      SimpleString &append(CString str);
      SimpleString &append(const SimpleString &str);

    public:
      CString CStr() const;
      Size getLength() const;
      char at(Size index) const;

    public:
      SimpleString &operator=(CString str);
      SimpleString &operator=(const SimpleString &str);
      SimpleString &operator=(SimpleString &&str) noexcept;

      SimpleString &operator+=(char chr);
      SimpleString &operator+=(CString str);
      SimpleString &operator+=(const SimpleString &str);

      char operator[](Size index) const;
    };
  }
}
