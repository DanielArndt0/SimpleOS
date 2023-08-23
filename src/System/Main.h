#pragma once
#include "System/System.h"

namespace SimpleOS
{
  using namespace SimpleOS::Com;
  using namespace SimpleOS::Memory;
  using namespace SimpleOS::Data;
  using namespace SimpleOS::Utils;
  using namespace SimpleOS::Hardware;
  using namespace SimpleOS::Core;
  using namespace SimpleOS::Interrupt;
  using namespace SimpleOS::Root;
  using namespace SimpleOS::Time;
  using namespace SimpleOS::Error;
  using namespace SimpleOS::Handler;

  class Main final : extends System<SYS_HEAP_SIZE>
  {
  public:
    Status boot() override
    {
      return Status();
    }

    Status execute() override
    {
      return Status();
    }

  public:
    ~Main() = default;
  };
}
