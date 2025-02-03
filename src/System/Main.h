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
  using namespace SimpleOS::Addons;

  class Main final : extends System
  {
  public:
    Status boot() override
    { 
      LCD display = LCD(12, 13, 8, 9, 10, 11);
      display.begin();


      



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
