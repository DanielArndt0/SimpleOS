#pragma once
#include <stdlib.h>
#include <string.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/Typedefs.h"
#include "Root/RamAllocator/RamAllocator.h"

namespace SimpleOS
{
  namespace Data
  {
    // TODO Adicionar metodos Replace
    // TODO Otimizar metodos Remove utlizando memmove
    // TODO Adicionar métodos e operadores concat
    // TODO Otimizar metodos findBetween
    class String
    {
    private:
      Char *buffer;
      Data::UInt length;

    private:
      Root::RamAllocator<SYSM_HEAP_SIZE> vram;

    protected:
      // Primitives
      inline void init();
      void copy_to_buffer(Char *cstr);
      Char *alloc_buffer(Size size);

      // Essentials
      String &copy(Char chr);
      String &copy(C_String cstr);
      String &attach(Char chr);
      String &attach(C_String cstr);

      // Others
      bool exists_in_the_range(Index Index, Char min, Char max) const;
      void shift_str(Index cursor);

    public:
      // Base Constructors
      String(const String &str);
      String(const String &&str);
      ~String(void);

      // Convert Constructors
      String(Char chr);
      String(C_String cstr = "");
      String(Data::UChar value, Data::UChar base = 10);
      String(Int value, Data::UChar base = 10);
      String(Data::UInt toUIntvalue, Data::UChar base = 10);
      String(Data::Long toLongvalue, Data::UChar base = 10);
      String(Data::ULong toLongvalue, Data::UChar base = 10);
      String(float value, Data::UChar precision = 2);
      String(double value, Data::UChar precision = 2);

    public:
      // Convert
      C_String c_str() const;

      // Access
      Char at(Index Index) const;

      // Modifiers
      String &remove(Char chr);
      String &remove(Char chr, Index fromIndex);
      String &remove(Char chr, Index fromIndex, Index untilIndex);
      String &remove(Index Index);
      String &remove(Index fromIndex, Index untilIndex);
      // String &remove(C_String cstr); //TODO
      /*
      String &replace();
      */

      // Others
      Size size() const;
      Size count(Char chr) const;
      Index find(Char chr) const;
      Index find(Char chr, Index cursor) const;
      Index find(Char chr, Index fromIndex, Index untilIndex) const;
      String find(C_String precedent) const;
      String find(const String precedent) const;
      String findLimited(C_String delimiters) const;
      String findLimited(const String &delimiters) const;
      String findBetween(C_String initialStr, C_String delimiterStr);
      String findBetween(const String &initialStr, const String &delimiterStr);
      bool exists(C_String cstr) const;
      bool exists(const String str) const;
      // TODO Retornar uma lista de todos os caracteres encontrados na string ex: List<char> find(char chr);

      // Compare
      bool equals(C_String cstr) const;
      bool equals(const String &str) const;

      bool different(C_String cstr) const;
      bool different(const String &str) const;

      bool biggerThan(C_String cstr) const;
      bool biggerThan(const String &str) const;

      bool biggerEqualsThan(C_String cstr) const;
      bool biggerEqualsThan(const String &str) const;

      bool lessThan(C_String cstr) const;
      bool lessThan(const String &str) const;

      bool lessEqualsThan(C_String cstr) const;
      bool lessEqualsThan(const String &str) const;

      bool isUpper(Index Index) const;
      bool isLower(Index Index) const;
      bool isAlpha(Index Index) const;
      bool isNumber(Index Index) const;
      bool isPunctation(Index Index) const;
      bool isPrint(Index Index) const;
      bool isControl(Index Index) const;

      // Conversion
      void toUpper();
      void toUpper(Index Index);

      void toLower();
      void toLower(Index Index);

      Char toChar(Data::UChar base = 10);
      Data::UChar toUChar(Data::UChar base = 10);
      Int toInt(Data::UChar base = 10);
      Data::UInt toUInt(Data::UChar base = 10);
      Data::Long toLong(Data::UChar base = 10);
      Data::ULong toULong(Data::UChar base = 10);
      float toFloat();
      double toDouble();

    public:
      // Copy
      String &operator=(Char chr);
      String &operator=(C_String cstr);
      String &operator=(const String &str);
      String &operator=(const String &&str);

      // Attach
      String &operator+=(Char chr);
      String &operator+=(C_String cstr);
      String &operator+=(const String &str);

      // Compare
      bool operator==(C_String cstr) const;
      bool operator==(const String &str) const;

      bool operator!=(C_String cstr) const;
      bool operator!=(const String &str) const;

      bool operator>(C_String cstr) const;
      bool operator>(const String &str) const;

      bool operator>=(C_String cstr) const;
      bool operator>=(const String &str) const;

      bool operator<(C_String cstr) const;
      bool operator<(const String &str) const;

      bool operator<=(C_String cstr) const;
      bool operator<=(const String &str) const;

      // Access
      Char operator[](Index Index) const;
    };
  }
}
