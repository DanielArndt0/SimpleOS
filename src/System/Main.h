#pragma once
#include "System/System.h"

namespace SimpleOS
{
  using namespace SimpleOS::Data;
  using namespace SimpleOS::Instance;
  using namespace SimpleOS::Com;
  using namespace SimpleOS::Time;
  using namespace SimpleOS::Memory;
  using namespace SimpleOS::Core;
  using namespace SimpleOS::Interrupt;
  using namespace SimpleOS::Utils;
  using namespace SimpleOS::Error;
  using namespace SimpleOS::Handler;

  class Main final : extends System
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
