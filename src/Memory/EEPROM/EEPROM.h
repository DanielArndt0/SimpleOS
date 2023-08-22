#pragma once
#include <stdlib.h>
#include <string.h>
#include "System/Macros.h"
#include "Core/EEPROM/EECore.h"
#include "DataTypes/String/SimpleString/SimpleString.h"

namespace SimpleOS
{
  namespace Memory
  {
    class EEPROM : extends Core::EECore
    {
    protected:
      static SimpleOS::Data::SimpleString *buffer;

      static unsigned int used_mem(unsigned int addr1, unsigned int addr2);

    public:
      EEPROM() = default;
      ~EEPROM() = default;

    public:
      /**
       * @return Returns the used memory space in bytes.
       */
      static unsigned int used();

      /**
       * @return Returns the free space in memory in bytes.
       */
      static unsigned int empty();

      template <typename T>
      static void write(T data, unsigned int addr);

      /**
       * @brief Read data from EEPROM memory.
       *
       * @param addr Memory address to be read.
       */
      template <typename T>
      static T read(unsigned int addr);

      /**
       * @brief Clear EEPROM memory address.
       *
       * @param addr Address to be cleared.
       */
      static void clear(unsigned int addr);

      /**
       * @brief Clears an address block from the EEPROM memory.
       *
       * @param addr1 Block start address.
       *
       * @param addr2 End address of the block.
       */
      static void clear(unsigned int addr1, unsigned int addr2);

      static void deleteBuffer();
    };

    template <class T>
    inline void SimpleOS::Memory::EEPROM::write(T data, unsigned int addr)
    {
      if (addr >= eeprom_size)
        return;
      for (unsigned int i = 0x00; i < sizeof(data); i++)
        eepromClearWrite(0x01, (data >> (8 * i) & 0xFF), addr + i);
    }

    template <>
    inline void SimpleOS::Memory::EEPROM::write<const char *>(const char *data, unsigned int addr)
    {
      if (addr >= size())
        return;
      unsigned char len = (unsigned char)strlen(data) + 1;
      for (unsigned int i = 0; i <= len; i++)
        eepromClearWrite(0x01, data[i], addr + i);
    }

    template <>
    inline void SimpleOS::Memory::EEPROM::write<float>(float data, unsigned int addr)
    {
      if (addr >= size())
        return;
      unsigned char size = sizeof(float);
      unsigned char *ptr = reinterpret_cast<unsigned char *>(&data);
      for (unsigned int i = 0; i <= size; i++)
        eepromClearWrite(0x01, ptr[i], addr + i);
    }

    template <>
    inline void SimpleOS::Memory::EEPROM::write<double>(double data, unsigned int addr)
    {
      if (addr >= size())
        return;
      unsigned char size = sizeof(double);
      unsigned char *ptr = reinterpret_cast<unsigned char *>(&data);
      for (unsigned int i = 0; i <= size; i++)
        eepromClearWrite(0x01, ptr[i], addr + i);
    }

    template <class T>
    inline T SimpleOS::Memory::EEPROM::read(unsigned int addr)
    {
      T t;
      if (addr >= eeprom_size)
        return t;
      for (unsigned int i = 0x00; i < sizeof(t); i++)
        t |= (T)readChar(addr + i) << (i * 8);
      return t;
    }

    template <>
    inline const char *SimpleOS::Memory::EEPROM::read<const char *>(unsigned int addr)
    {
      if (addr >= size())
        return "";
      if (buffer == nullptr)
        buffer = new SimpleOS::Data::SimpleString();
      char currentChar = 0;
      for (unsigned int i = 0; (currentChar = readChar(addr + i)) != 0x00; i++)
        *buffer += currentChar;
      return buffer->CStr();
    }

    template <>
    inline float SimpleOS::Memory::EEPROM::read<float>(unsigned int addr)
    {
      float result = 0.00;
      if (addr >= size())
        return result;
      unsigned char size = sizeof(float);
      unsigned char *ptr = reinterpret_cast<unsigned char *>(&result);
      for (unsigned int i = 0; i <= size; i++)
        ptr[i] = readChar(addr + i);
      return result;
    }

    template <>
    inline double SimpleOS::Memory::EEPROM::read<double>(unsigned int addr)
    {
      double result = 0.00;
      if (addr >= size())
        return result;
      unsigned char size = sizeof(double);
      unsigned char *ptr = reinterpret_cast<unsigned char *>(&result);
      for (unsigned int i = 0; i <= size; i++)
        ptr[i] = readChar(addr + i);
      return result;
    }
  }
}