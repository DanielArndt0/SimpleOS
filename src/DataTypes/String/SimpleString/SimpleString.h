#pragma once
#include <string.h>
#include "System/Base.h"

namespace SimpleOS
{
  namespace Data
  {
    class SimpleString
    {
    private:
      char *str;
      unsigned int length;

    public:
      SimpleString();
      SimpleString(CString str);
      SimpleString(const SimpleString &str);
      SimpleString(SimpleString &&str);
      ~SimpleString();

    private:
      void init();
      char *alloc(Size size);
      void desalloc();
      void loadToBuffer(char *str, unsigned int length);

    protected:
      SimpleString &copy(CString str);
      SimpleString &copy(const SimpleString &str);

      SimpleString &append(char chr);
      SimpleString &append(CString str);
      SimpleString &append(const SimpleString &str);

    public:
      CString CStr() const;
      unsigned int getLength() const;
      char at(unsigned int index) const;

    public:
      SimpleString &operator=(CString str);
      SimpleString &operator=(const SimpleString &str);

      SimpleString &operator+=(char chr);
      SimpleString &operator+=(CString cstr);
      SimpleString &operator+=(const SimpleString &str);

      char operator[](unsigned int index);
    };
  } // namespace Data
} // namespace  SimpleOS
