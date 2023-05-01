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

  class Main : extends System<SYSM_HEAP_SIZE>
  {
  public:
    Int startup() override
    {
      return 0;
    }

    Int run() override
    {
      return 0;
    }
  };
}