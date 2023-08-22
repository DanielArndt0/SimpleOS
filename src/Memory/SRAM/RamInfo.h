#pragma once
#include "System/Macros.h"
#include "DataTypes/Typedefs.h"

#include "Memory/SRAM/Sections/DataSection.h"
#include "Memory/SRAM/Sections/BssSection.h"
#include "Memory/SRAM/Sections/HeapSection.h"
#include "Memory/SRAM/Sections/StackSection.h"

namespace SimpleOS
{
  namespace Memory
  {
    class RamInfo
    {
    public:
      static Data::Size totalSize() { return (RAMEND - RAMSTART) + 1; }
      static DataSection data;
      static BssSection bss;
      static HeapSection heap;
      static StackSection stack;
    };
    SimpleOS::Memory::BssSection SimpleOS::Memory::RamInfo::bss;
    SimpleOS::Memory::DataSection SimpleOS::Memory::RamInfo::data;
    SimpleOS::Memory::HeapSection SimpleOS::Memory::RamInfo::heap;
    SimpleOS::Memory::StackSection SimpleOS::Memory::RamInfo::stack;
  }
}