#pragma once
#include "SimpleOS/System.h"
#include "Models/Person.h"

namespace SimpleOS
{
  
  using namespace Com;
  using namespace Memory;
  using namespace Data;
  using namespace Operators;
  using namespace Hardware;
  using namespace Native;

#define S_ADDR 0x0100
#define E_ADDR 0x08FF
#define VALUE(addr) ((unsigned)(*(volatile unsigned char *)(addr)))
  class Main : extends System<SYSM_HEAP_SIZE>
  {
  public:
    Int startup() override
    {
      serial << "Free heap: " << getFreeHeap() << endl;
      serial << "Used heap: " << getUsedHeap() << endl;
      serial << "Heap size: " << getHeapSize() << endl;
      serial << "Total size: " << getTotal() << endl;

      return 0;
    }

    Int run() override
    {
      return 0;
    }
  };
}