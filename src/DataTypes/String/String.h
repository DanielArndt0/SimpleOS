#pragma once
#include <stdlib.h>
#include <string.h>
#include "System/Macros.h"
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
      char *buffer;
      unsigned int length;

    private:
      Root::RamAllocator<SYSM_HEAP_SIZE> vram;

    protected:
      // Primitives
      inline void init();
      void copy_to_buffer(char *cstr);
      char *alloc_buffer(Size size);

      // Essentials
      String &copy(char chr);
      String &copy(CString cstr);
      String &attach(char chr);
      String &attach(CString cstr);

      // Others
      bool exists_in_the_range(Index Index, char min, char max) const;
      void shift_str(Index cursor);

    public:
      // Base Constructors
      String(const String &str);
      String(const String &&str);
      ~String(void);

      // Convert Constructors
      String(char chr);
      String(CString cstr = "");
      String(unsigned char value, unsigned char base = 10);
      String(int value, unsigned char base = 10);
      String(unsigned int toUIntvalue, unsigned char base = 10);
      String(long toLongvalue, unsigned char base = 10);
      String(unsigned long toLongvalue, unsigned char base = 10);
      String(float value, unsigned char precision = 2);
      String(double value, unsigned char precision = 2);

    public:
      // Convert
      CString c_str() const;

      // Access
      char at(Index Index) const;

      // Modifiers
      String &remove(char chr);
      String &remove(char chr, Index fromIndex);
      String &remove(char chr, Index fromIndex, Index untilIndex);
      String &remove(Index Index);
      String &remove(Index fromIndex, Index untilIndex);
      // String &remove(CString cstr); //TODO
      /*
      String &replace();
      */

      // Others
      Size size() const;
      Size count(char chr) const;
      Index find(char chr) const;
      Index find(char chr, Index cursor) const;
      Index find(char chr, Index fromIndex, Index untilIndex) const;
      String find(CString precedent) const;
      String find(const String precedent) const;
      String findLimited(CString delimiters) const;
      String findLimited(const String &delimiters) const;
      String findBetween(CString initialStr, CString delimiterStr);
      String findBetween(const String &initialStr, const String &delimiterStr);
      bool exists(CString cstr) const;
      bool exists(const String str) const;
      // TODO Retornar uma lista de todos os caracteres encontrados na string ex: List<char> find(char chr);

      // Compare
      bool equals(CString cstr) const;
      bool equals(const String &str) const;

      bool different(CString cstr) const;
      bool different(const String &str) const;

      bool biggerThan(CString cstr) const;
      bool biggerThan(const String &str) const;

      bool biggerEqualsThan(CString cstr) const;
      bool biggerEqualsThan(const String &str) const;

      bool lessThan(CString cstr) const;
      bool lessThan(const String &str) const;

      bool lessEqualsThan(CString cstr) const;
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

      char toChar(unsigned char base = 10);
      unsigned char toUChar(unsigned char base = 10);
      int toInt(unsigned char base = 10);
      unsigned int toUInt(unsigned char base = 10);
      long toLong(unsigned char base = 10);
      unsigned long toULong(unsigned char base = 10);
      float toFloat();
      double toDouble();

    public:
      // Copy
      String &operator=(char chr);
      String &operator=(CString cstr);
      String &operator=(const String &str);
      String &operator=(const String &&str);

      // Attach
      String &operator+=(char chr);
      String &operator+=(CString cstr);
      String &operator+=(const String &str);

      // Compare
      bool operator==(CString cstr) const;
      bool operator==(const String &str) const;

      bool operator!=(CString cstr) const;
      bool operator!=(const String &str) const;

      bool operator>(CString cstr) const;
      bool operator>(const String &str) const;

      bool operator>=(CString cstr) const;
      bool operator>=(const String &str) const;

      bool operator<(CString cstr) const;
      bool operator<(const String &str) const;

      bool operator<=(CString cstr) const;
      bool operator<=(const String &str) const;

      // Access
      char operator[](Index Index) const;
    };
  }
}
