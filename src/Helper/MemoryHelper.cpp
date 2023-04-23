#include "MemoryHelper.h"

/**
 * @brief Print a memory map
 *
 * @param array Memory Buffer
 * @param row Number of lines.
 * @param base Base = 16 -> for hexadecimal, 10 -> for decimal, 0 for char
 */
void SimpleOS::Helpers::MemoryHelper::printMemoryMap(SimpleOS::Data::UChar *array, SimpleOS::Data::UInt arraySize, SimpleOS::Com::UART &uart, SimpleOS::Data::UInt row, SimpleOS::Data::UInt base)
{
  for (SimpleOS::Data::UInt i = 0; i < arraySize; i++)
  {
    if (!(i % row))
      uart << endl;
    if (base == HEX)
    {
      if (array[i] > (HEX - 1))
        uart << "0x" << SimpleOS::Data::String((SimpleOS::Data::UChar)array[i], (HEX - 1)) << ' ';
      else
        uart << "0x0" << SimpleOS::Data::String((SimpleOS::Data::UChar)array[i], (HEX - 1)) << ' ';
    }
    else if (base == DEC)
    {
      if (array[i] < DEC)
        uart << "00" << SimpleOS::Data::String(array[i]) << ' ';
      else if (array[i] < 100 && array[i] > 9)
        uart << "0" << SimpleOS::Data::String(array[i]) << ' ';
      else
        uart << SimpleOS::Data::String(array[i]) << ' ';
    }
    else if (!base)
      uart << (SimpleOS::Data::Char)array[i] << ' ';
  }
}