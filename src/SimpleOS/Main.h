#pragma once
#include "SimpleOS/System.h"
#include "Models/Person.h"

#define S_ADDR 0x0100
#define E_ADDR 0x08FF
#define VALUE(addr) ((unsigned)(*(volatile unsigned char *)(addr)))

namespace SimpleOS
{
  using namespace SimpleOS::Com;
  using namespace SimpleOS::Memory;
  using namespace SimpleOS::Data;
  using namespace SimpleOS::Operators;
  using namespace SimpleOS::Hardware;
  using namespace SimpleOS::Native;
  using namespace SimpleOS::Interrupt;
  using namespace SimpleOS::Root;

  class Main : extends System<SYSM_HEAP_SIZE>
  {
  public:
    Int boot() override
    {
      return 0;
    }

    Int execute() override
    {
      serial << watchdog.ticks.get() << endl;

      return 0;
    }
  };
}