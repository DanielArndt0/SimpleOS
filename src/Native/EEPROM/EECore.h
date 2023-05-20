#pragma once
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

namespace SimpleOS
{
  namespace Native
  {
    class EECore
    {
    private:
      static Data::UInt eeprom_size;

    protected:
      /**
       * @param selectWriteOp 0x01 for write operation and 0x00 for clear operation.
       */
      static void eepromClearWrite(Data::UChar selectWriteOp, Data::UChar data, Data::UInt addr); // Primitive

      /**
       * @param addr read the value of an address.
       */
      static Data::UChar readChar(Data::UInt addr); // Primitive

    public:
      /**
       * @return Returns the memory size.
       */
      static Data::UInt size();
    };
  }
}