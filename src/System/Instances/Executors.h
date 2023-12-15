#include "Interrupt/Executors/WatchdogExecutor.h"
#include "Interrupt/Executors/TimerExecutor.h"
#include "Interrupt/Executors/ThreadExecutor.h"

namespace SimpleOS
{
  namespace Instance
  {
    class Executors
    {
    public:
      static SimpleOS::Interrupt::WatchdogExecutor watchdogExecutor;
      static SimpleOS::Interrupt::TimerExecutor timerExecutor;
    };
    SimpleOS::Interrupt::WatchdogExecutor SimpleOS::Instance::Executors::watchdogExecutor;
    SimpleOS::Interrupt::TimerExecutor SimpleOS::Instance::Executors::timerExecutor;
  } // namespace Instance
} // namespace SimpleOS
