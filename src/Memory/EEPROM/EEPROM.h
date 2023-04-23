#pragma once
#include <stdlib.h>
#include <string.h>
#include "SimpleOS/Macros.h"
#include "DataTypes/Typedefs.h"
#include "DataTypes/Object/Object.h"
#include "Memory/EEPROM/NativeEEPROM.h"
#include "DataTypes/String/String.h"
// #include "DataTypes/Buffer/Buffer.h"

namespace SimpleOS
{
  namespace Memory
  {
    class EEPROM extends Native::Memory::EEPROM, virtual public Root::Object // TODO implementar Object
    {
    private:
      static Data::UChar *mem_buff;

    protected:
      static Data::UInt used_mem(Data::UInt addr1, Data::UInt addr2);

    public:
      ~EEPROM();

    public:
      /**
       * @return Returns the used memory space in bytes.
       */
      static Data::UInt used();

      /**
       * @return Returns the free space in memory in bytes.
       */
      static Data::UInt empty();

      template <typename T>
      static void write(T data, Data::UInt addr);

      /**
       * @brief Write string to EEPROM memory.
       *
       * @param data String to be written.
       *
       * @param addr Memory address to be written.
       */
      static void write(Data::C_String data, Data::UInt addr);

      /**
       * @brief Write string to EEPROM memory.
       *
       * @param data String to be written.
       *
       * @param addr Memory address to be written.
       */
      static void write(const Data::String &data, Data::UInt addr);

      /**
       * @brief Read data from EEPROM memory.
       *
       * @param addr Memory address to be read.
       */
      template <typename T>
      static T read(Data::UInt addr);

      /**
       * @brief Read string from EEPROM memory.
       *
       * @param addr Memory address to be read.
       */
      static Data::String readString(Data::UInt addr);

      /**
       * @brief Clear EEPROM memory address.
       *
       * @param addr Address to be cleared.
       */
      static void free(Data::UInt addr);

      /**
       * @brief Clears an address block from the EEPROM memory.
       *
       * @param addr1 Block start address.
       *
       * @param addr2 End address of the block.
       */
      static void free(Data::UInt addr1, Data::UInt addr2);

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
      static Data::UChar *toArray();

      static Data::UChar *toArray(unsigned int addr1, unsigned int addr2);

      

      /**
       * @brief Frees data allocated on the memory heap. It will only take effect if the Array() method is invoked previously.
       */
      static void releaseArray();
    };

    template <class T>
    T EEPROM::read(Data::UInt addr)
    {
      T t;
      if (addr >= eeprom_size)
        return t;
      for (Data::UInt i = 0x00; i < sizeof(t); i++)
        t |= (T)readChar(addr + i) << (i * 8);
      return t;
    }

    template <class T>
    void EEPROM::write(T data, Data::UInt addr)
    {
      if (addr >= eeprom_size)
        return;
      for (Data::UInt i = 0x00; i < sizeof(data); i++)
        eepromClearWrite(0x01, (data >> (8 * i) & 0xFF), addr + i);
    }
  }
}