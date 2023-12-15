#pragma once
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "System/Macros.h"

namespace SimpleOS
{
  namespace Core
  {
    class EECore
    {
    private:
      static unsigned int eeprom_size;

    protected:
      /**
       * @param selectWriteOp 0x01 for write operation and 0x00 for clear operation.
       */
      static void eepromClearWrite(unsigned char selectWriteOp, char data, unsigned int addr); // Primitive

      /**
       * @param addr read the value of an address.
       */
      static char readChar(unsigned int addr); // Primitive

    public:
      /**
       * @return Returns the memory size.
       */
      static unsigned int size();
    };
  }
}