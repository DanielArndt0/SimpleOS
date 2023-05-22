#pragma once
#include <stdlib.h>
#include <string.h>
#include "System/Macros.h"
#include "DataTypes/String/String.h"
#include "Native/EEPROM/EECore.h"

namespace SimpleOS
{
  namespace Memory
  {
    class EEPROM : extends Native::EECore
    {
    private:
      static unsigned char *mem_buff;

    protected:
      static unsigned int used_mem(unsigned int addr1, unsigned int addr2);

    public:
      ~EEPROM();

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
       * @brief Write string to EEPROM memory.
       *
       * @param data String to be written.
       *
       * @param addr Memory address to be written.
       */
      static void write(const char* data, unsigned int addr);

      /**
       * @brief Write string to EEPROM memory.
       *
       * @param data String to be written.
       *
       * @param addr Memory address to be written.
       */
      static void write(const Data::String &data, unsigned int addr);

      /**
       * @brief Read data from EEPROM memory.
       *
       * @param addr Memory address to be read.
       */
      template <typename T>
      static T read(unsigned int addr);

      /**
       * @brief Read string from EEPROM memory.
       *
       * @param addr Memory address to be read.
       */
      static Data::String readString(unsigned int addr);

      /**
       * @brief Clear EEPROM memory address.
       *
       * @param addr Address to be cleared.
       */
      static void free(unsigned int addr);

      /**
       * @brief Clears an address block from the EEPROM memory.
       *
       * @param addr1 Block start address.
       *
       * @param addr2 End address of the block.
       */
      static void free(unsigned int addr1, unsigned int addr2);

      // /**
      //  * @brief Load array into EEPROM memory.
      //  *
      //  * @param buffer
      //  */
      // static void commitArray(Data::Buffer &buffer);

      /**
       * @brief Copy all data in EEPROM memory to an array in Heap memory.
       *
       * @return Returns all data from EEPROM memory in array format.
       */
      static unsigned char *toArray();

      static unsigned char *toArray(unsigned int addr1, unsigned int addr2);

      

      /**
       * @brief Frees data allocated on the memory heap. It will only take effect if the Array() method is invoked previously.
       */
      static void releaseArray();
    };

    template <class T>
    T EEPROM::read(unsigned int addr)
    {
      T t;
      if (addr >= eeprom_size)
        return t;
      for (unsigned int i = 0x00; i < sizeof(t); i++)
        t |= (T)readChar(addr + i) << (i * 8);
      return t;
    }

    template <class T>
    void EEPROM::write(T data, unsigned int addr)
    {
      if (addr >= eeprom_size)
        return;
      for (unsigned int i = 0x00; i < sizeof(data); i++)
        eepromClearWrite(0x01, (data >> (8 * i) & 0xFF), addr + i);
    }
  }
}