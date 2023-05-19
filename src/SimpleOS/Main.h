#pragma once
#include "SimpleOS/System.h"
#include "Models/Person.h"

#define S_ADDR 0x0100
#define E_ADDR 0x08FF
#define VALUE(addr) ((unsigned)(*(volatile unsigned char *)(addr)))

namespace SimpleOS
{
  using namespace Com;
  using namespace Memory;
  using namespace Data;
  using namespace Operators;
  using namespace Hardware;
  using namespace Native;
  using namespace Interrupt;
  using namespace Root;

  class Main : extends System<SYSM_HEAP_SIZE>
  {
    static void print(void *args)
    {
      serial << "Thread 1" << endl;
    }

  public:
    Int startup() override
    {
      serial << "init" << endl;
      serial << getFreeHeap() << endl;
      return 0;
    }

    Int run() override
    {
      return 0;
    }
  };
}