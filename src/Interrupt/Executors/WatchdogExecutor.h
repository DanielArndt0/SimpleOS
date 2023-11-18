#pragma once
#include "System/Base.h"
#include "Interrupt/Executors/ThreadExecutor.h"

namespace SimpleOS
{
  namespace Interrupt
  {
    class WatchdogExecutor : extends ThreadExecutor
    {
    private:
      Data::ArrayList<Core::Thread *> threadList;
      Data::ArrayList<Core::Thread *> &list() override { return threadList; }
    }; // class WatchdogExecutor
  }    // namespace Interrupt
} // namespace SimpleOS
