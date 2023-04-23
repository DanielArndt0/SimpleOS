#pragma once
#include "SimpleOS/Base.h"

namespace SimpleOS
{
  namespace Beta
  {
    namespace Data
    {
      class String
      {
      private:
        SimpleOS::Data::Char *m_buffer;
        SimpleOS::Data::Size m_size;

        void copy(SimpleOS::Data::C_String cstr, SimpleOS::Data::Size size);
        void move(SimpleOS::Data::Char *buffer, SimpleOS::Data::Size size);

        void append(SimpleOS::Data::Char chr);
        void append(SimpleOS::Data::C_String cstr);
        void append(const String &str);

        bool isUpper(SimpleOS::Data::Char c) const;
        bool isLower(SimpleOS::Data::Char c) const;
        bool isAlpha(SimpleOS::Data::Char c) const;
        bool isNumber(SimpleOS::Data::Char c) const;
        bool isPunctuation(SimpleOS::Data::Char c) const;
        bool isPrint(SimpleOS::Data::Char c) const;
        SimpleOS::Data::Char toUpper(SimpleOS::Data::Char c) const;
        SimpleOS::Data::Char toLower(SimpleOS::Data::Char c) const;

      public:
        // Construtores
        String();
        String(SimpleOS::Data::C_String cstr);
        String(const String &str);
        String(String &&str) noexcept;

        // Destrutor
        ~String();

        // Métodos
        SimpleOS::Data::Size size() const;
        SimpleOS::Data::Size find(SimpleOS::Data::C_String cstr, SimpleOS::Data::Size pos = 0) const;
        bool exists(SimpleOS::Data::C_String cstr) const;
        bool isUpper(SimpleOS::Data::Size index) const;
        bool isLower(SimpleOS::Data::Size index) const;
        bool isAlpha(SimpleOS::Data::Size index) const;
        bool isNumber(SimpleOS::Data::Size index) const;
        bool isPunctuation(SimpleOS::Data::Size index) const;
        bool isPrint(SimpleOS::Data::Size index) const;
        void toUpper();
        void toUpper(SimpleOS::Data::Size index);
        void toLower();
        void toLower(SimpleOS::Data::Size index);

        // Sobrecarga de operadores
        String &operator=(SimpleOS::Data::Char c);
        String &operator=(SimpleOS::Data::C_String cstr);
        String &operator=(const String &str);
        String &operator=(String &&str) noexcept;

        String &operator+=(SimpleOS::Data::Char c);
        String &operator+=(SimpleOS::Data::C_String cstr);
        String &operator+=(const String &str);

        bool operator==(SimpleOS::Data::C_String cstr) const;
        bool operator==(const String &str) const;

        bool operator!=(SimpleOS::Data::C_String cstr) const;
        bool operator!=(const String &str) const;

        bool operator>(SimpleOS::Data::C_String cstr) const;
        bool operator>(const String &str) const;

        bool operator>=(SimpleOS::Data::C_String cstr) const;
        bool operator>=(const String &str) const;

        bool operator<(SimpleOS::Data::C_String cstr) const;
        bool operator<(const String &str) const;

        bool operator<=(SimpleOS::Data::C_String cstr) const;
        bool operator<=(const String &str) const;

        SimpleOS::Data::Char operator[](SimpleOS::Data::Size index) const;
      };
    }
  }
}