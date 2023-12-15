#pragma once
#include "System/Base.h"
#include "Interrupt/Executors/ThreadExecutor.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class TimerExecutor : extends ThreadExecutor
    {
    private:
      Data::ArrayList<Core::Thread *> threadList;
      Data::ArrayList<SimpleOS::Core::Thread *> &list() override { return threadList; }

    }; // class TimerExecutor
  }  // namespace Interrupt
} // namespace SimpleOS
